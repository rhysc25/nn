#include "matrix.h"

MatrixView::MatrixView(float* d, size_t r, size_t c, size_t s)
    : data(d), rows(r), cols(c), stride(s) {}

float& MatrixView::operator()(size_t r, size_t c) {
    return data[r * stride + c];
}

MatrixOwner::MatrixOwner(size_t r, size_t c) 
    : rows(r), cols(c), v(r * c) {}

MatrixView MatrixOwner::view(){
    return MatrixView(v.data(), rows, cols, cols);
}

int main() {
    return 0;
}