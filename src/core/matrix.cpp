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
                temp += (a(i, k) * b(k, j));
            }
            out(i, j) = temp;
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
    

int main() {
    // Set up test
    MatrixOwner A(2,3);
    A.fill(std::vector<float> {3.0f, 4.0f, 2.0f, 1.0f, 8.0f, 5.0f});
    MatrixView AView = A.view();
    MatrixOwner B(3,2);
    B.fill(std::vector<float> {3.0f, 4.0f, 2.0f, 1.0f, 8.0f, 5.0f});
    MatrixView BView = B.view();
    MatrixOwner C(2,2);
    C.fill(std::vector<float> {0.0f, 0.0f, 0.0f, 0.0f});
    MatrixView CView = C.view();
    MatrixOwner D(2,3);
    D.fill(std::vector<float> {0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f});
    MatrixView DView = D.view();

    // Test multiply function
    MatrixOwner H = multiply(AView, BView);

    MatrixOwner E(1,1);
    E.fill(std::vector<float> {3.0f});
    MatrixView EView = E.view();
    MatrixOwner F(3,1);
    F.fill(std::vector<float> {3.0f, 4.0f, 2.0f});
    MatrixView FView = F.view();
    
    MatrixOwner G(3,3);
    G.fill(std::vector<float> {3.0f, 4.0f, 2.0f, 1.0f, 5.0f, 6.0f, 2.0f, 8.0f, 6.0f});
    MatrixView GView = G.view();

    H.view().list_contents();

    return 0;
}
