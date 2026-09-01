#include <chrono>
#include <iostream>
#include <thread>
#include <functional>
#include <random>
#include "matrix.h"

MatrixView::MatrixView(float* d, size_t r, size_t c, size_t s)
    : data(d), rows(r), cols(c), stride(s) {}

float& MatrixView::operator()(size_t r, size_t c) {
    return data[r * stride + c];
}

size_t MatrixView::get_columns() {return cols;}
void MatrixView::set_columns(size_t c) {cols = c;}
size_t MatrixView::get_rows() {return rows;}
void MatrixView::set_rows(size_t r) {rows = r;}
size_t MatrixView::get_stride() {return stride;}
void MatrixView::set_stride(size_t s) {stride = s;}

// Print out all the values in the matrix
void MatrixView::list_contents() {
    std::cout << "Printing matrix: \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << (*this)(i, j) << " ";
        }
        std::cout << "\n";
    }
}

MatrixOwner::MatrixOwner(size_t r, size_t c) 
    : rows(r), cols(c), v(r * c) {}

MatrixView MatrixOwner::view(){
    return MatrixView(v.data(), rows, cols, cols);
}

void MatrixOwner::fill(std::vector<float> vin) {
    if (vin.size() != v.size()) { return; }
    std::copy(vin.begin(), vin.end(), v.begin());
}

void multiply_imp(MatrixView& a, MatrixView& b, MatrixView& out) {
    for (int i = 0; i < out.get_rows(); i++) {
        for (int j = 0; j < out.get_columns(); j++) {
            float temp = 0;
            for (int k = 0; k < a.get_columns(); k++) {
                out(i, j) += (a(i, k) * b(k, j));
            }
        }
    }
}

void add_imp(MatrixView& a, MatrixView& b, MatrixView& out) { 	
    for (int i = 0; i < out.get_rows(); i++) {
        for (int j = 0; j < out.get_columns(); j++) {
            out(i, j) = a(i, j) + b(i, j);
        }
    }
}

MatrixOwner multiply(MatrixView& a, MatrixView& b) {
    if (a.get_columns() != b.get_rows()) {
        std::cout << "Error: Rows of A must equal columns of B."; 
        MatrixOwner C(0, 0);
        return C;
    }
    MatrixOwner C(a.get_rows(), b.get_columns());
    MatrixView c = C.view();

    multiply_imp(a, b, c);

    return C;
}

MatrixOwner add(MatrixView& a, MatrixView& b) {
    if (a.get_rows() != b.get_rows() || a.get_columns() != b.get_columns()) {
        std::cout << "Error: Matrices A and B must be the same shape for addition."; 
        MatrixOwner C(0, 0);
        return C;
    }
    MatrixOwner C(a.get_rows(), b.get_columns());
    MatrixView c = C.view();

    add_imp(a, b, c);

    return C;
}

void worker_multiply_imp(MatrixView& a, MatrixView& b, MatrixView& out, size_t start, size_t end) {
    size_t a_cols = a.get_columns();
    size_t out_cols = out.get_columns();

    for (int i = start; i < end; i++) {
        for (int k = 0; k < a_cols; k++) {
            float aik = a(i, k);
            for (int j = 0; j < out_cols; j++) {
                out(i, j) += aik * b(k, j);
            }
        }
    }
}

void join_multiply_imp(MatrixView& a, MatrixView& b, MatrixView& out) {
    size_t num_threads = std::min((int)std::thread::hardware_concurrency(), 12);
    size_t out_rows = out.get_rows();

    std::vector<std::thread> threads;
    size_t chunk_size = out_rows / num_threads;

    if (chunk_size) {
        for (size_t i = 0; i < num_threads; i++) {
            size_t start = chunk_size * i;
            size_t end = i == (num_threads - 1) ? out_rows : chunk_size * (i + 1);
            threads.emplace_back(worker_multiply_imp, std::ref(a), std::ref(b), std::ref(out), start, end);
        }
    } 
    else {
        for (size_t i = 0; i < out.get_rows(); i++) {
            size_t start = i;
            size_t end = (i + 1);
            threads.emplace_back(worker_multiply_imp, std::ref(a), std::ref(b), std::ref(out), start, end);
        }
    }

    for (auto& thread : threads) {
        thread.join();
    }
}

MatrixOwner join_multiply(MatrixView& a, MatrixView& b) {
    if (a.get_columns() != b.get_rows()) {
        std::cout << "Error: Rows of A must equal columns of B."; 
        MatrixOwner C(0, 0);
        return C;
    }
    MatrixOwner C(a.get_rows(), b.get_columns());
    MatrixView c = C.view();

    join_multiply_imp(a, b, c);

    return C;
}

void print_num_threads() {
    std::cout << "The number of available threads: ";
    std::cout << std::thread::hardware_concurrency();
    std::cout << "\n";
}

size_t multiplication_test() {
    // Set up test
    std::mt19937 gen(std::random_device{}());
    std::uniform_real_distribution<float> dist(0.0f, 1.0f);

    std::vector<float> values(100000);

    for (float& x : values)
        x = dist(gen);

    MatrixOwner A(1000,100);
    A.fill(values);
    MatrixView AView = A.view();

    MatrixOwner B(100,1000);
    B.fill(values);
    MatrixView BView = B.view();

    // Time test
    auto start = std::chrono::high_resolution_clock::now(); 

    // Test multiply function
    MatrixOwner C = join_multiply(AView, BView);
    //MatrixOwner C = multiply(AView, BView);

    auto end = std::chrono::high_resolution_clock::now(); 

    //C.view().list_contents();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Time for multiplication: " << duration.count() << " microseconds.\n";

    return (size_t) duration.count();
}

void multi_test(size_t iter) {
    size_t result = 0;
    for (size_t i = 0; i < iter; i++) {
        result += multiplication_test();
    }

    std::cout << "The average over " << iter << " tests is: " << (result / iter) << " microseconds.\n";
}

int main() {
    
    size_t iter = 10;
    multi_test(iter);

    return 0;
}
