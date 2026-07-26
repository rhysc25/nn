#pragma once

#include <vector>

class MatrixView {
    private:
        float* data; // Pointer to data vector
        size_t rows, cols;
        size_t stride; // distance between rows

    public:
        MatrixView(float* d, size_t r, size_t c, size_t s);
        float& operator()(size_t r, size_t c);
};

class MatrixOwner {
    private:
        std::vector<float> v;
        size_t rows, cols;

    public:
        MatrixOwner(size_t r, size_t c);
        MatrixView view();
};