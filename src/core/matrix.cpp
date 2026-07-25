#include "matrix.h"

std::vector<float> v = {1,4,6,3,5,6};


matrix::matrix(std::vector<float>& vi, int ri, int ci)
    : v(vi), rows(ri), columns(ci)
{}

// Print out all the values in the matrix
void matrix::list_contents() {
    std::cout << "Printing matrix:";
    for (int i = 0; i < rows; i++) {
        std::cout << "\n";
        for (int j = 0; j < columns; j++) {
            std::cout << v[i * columns + j] << " ";
        }
    }
}

int main() {
    matrix m(v, 2, 3);
    m.list_contents();
    return 0;
}