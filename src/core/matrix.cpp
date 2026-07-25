#include "matrix.h"

std::vector<float> v1 = {1,4,6,3,5,6};
std::vector<float> v2 = {1,4,6,3,5,6};


matrix::matrix(std::vector<float>& vi, int ri, int ci)
    : v(vi), rows(ri), columns(ci)
{}

// Print out all the values in the matrix
void matrix::list_contents() const {
    std::cout << "Printing matrix: \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << v[i * columns + j] << " ";
        }
        std::cout << "\n";
    }
}

void multiply(const matrix& a, const matrix& b) {
    a.list_contents();
    b.list_contents();
}

int main() {
    const matrix m1(v1, 2, 3);
    const matrix m2(v2, 3, 2);
    multiply(m1, m2);
    return 0;
}