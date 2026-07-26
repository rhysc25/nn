#include "matrix.h"

MatrixView::MatrixView(float* d, size_t r, size_t c, size_t s)
    : data(d), rows(r), cols(c), stride(s) {}

float& MatrixView::operator()(size_t r, size_t c) {
    return data[r * stride + c];
}

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

int main() {
    MatrixOwner A(2,3);
    A.fill(std::vector<float> {3.0f, 4.0f, 2.0f, 1.0f, 8.0f, 5.0f});
    MatrixView AView = A.view();
    AView.list_contents();
    return 0;
}