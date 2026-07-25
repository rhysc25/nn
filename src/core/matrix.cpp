#include "matrix.h"

std::vector<float> v1 = {1,4,6,3,5,6};
std::vector<float> v2 = {1,4,6,3,5,6};


matrix::matrix(std::vector<float>& vi, int ri, int ci)
    : v(vi), rows(ri), columns(ci)
{}

// Print out all the values in the matrix
void matrix::list_contents() {
    std::cout << "Printing matrix: \n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << get_element(i, j) << " ";
        }
        std::cout << "\n";
    }
}

float matrix::get_element(int r, int c) {
    return v[r * columns + c];
}

void matrix::set_element(int r, int c, float val) {
    v[r * columns + c] = val;
}

void multiply(matrix& a, matrix& b) {
    a.list_contents();
    b.list_contents();
}

int main() {
    matrix m1(v1, 2, 3);
    matrix m2(v2, 3, 2);
    m2.set_element(1, 1, 3.4f);
    multiply(m1, m2);
    return 0;
}