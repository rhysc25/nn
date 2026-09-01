#pragma once

#include <vector>
#include <iostream>

class MatrixView {
    private:
        float* data; // Pointer to data vector
        size_t rows, cols;
        size_t stride; // distance between rows

    public:
        MatrixView(float* d, size_t r, size_t c, size_t s);
        float& operator()(size_t r, size_t c);
        size_t get_columns();
        void set_columns(size_t c);
        size_t get_rows();
        void set_rows(size_t r);
        size_t get_stride();
        void set_stride(size_t s);
        void list_contents();
};

class MatrixOwner {
    private:
        std::vector<float> v;
        size_t rows, cols;

    public:
        MatrixOwner(size_t r, size_t c);
        MatrixView view();
        void fill(std::vector<float> vin);
};

void multiply_imp(MatrixView& a, MatrixView& b, MatrixView& out);
void add_imp(MatrixView& a, MatrixView& b, MatrixView& out);
MatrixOwner multiply(MatrixView& a, MatrixView& b);
MatrixOwner add(MatrixView& a, MatrixView& b);

void worker_multiply_imp(MatrixView& a, MatrixView& b, MatrixView& out, size_t start, size_t end);
void join_multiply_imp(MatrixView& a, MatrixView& b, MatrixView& out);
MatrixOwner join_multiply(MatrixView& a, MatrixView& b);
void worker_add_imp(MatrixView& a, MatrixView& b, MatrixView& out, size_t start, size_t end);
void join_add_imp(MatrixView& a, MatrixView& b, MatrixView& out);
MatrixOwner join_add(MatrixView& a, MatrixView& b);

void print_num_threads();
size_t multiplication_test();
void multi_test(size_t iter);