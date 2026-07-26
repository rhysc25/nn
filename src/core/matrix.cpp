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

int matrix::get_columns() {return columns;}
void matrix::set_columns(int c) {columns = c;}
int matrix::get_rows() {return rows;}
void matrix::set_rows(int r) {rows = r;}

void multiply(matrix& a, matrix& b) {
    a.list_contents();
    b.list_contents();

    if (a.get_columns() != b.get_rows()) {
        std::cout << "Error: Rows of A must equal columns of B."; 
        return;
    }

    std::vector<float> cv(a.get_rows() * b.get_columns(), 0.0f);
    matrix c(cv, a.get_rows(), b.get_columns());

    c.list_contents();

    for (int i = 0; i < c.get_rows(); i++) {
        for (int j = 0; j < c.get_columns(); j++) {
            float temp = 0;
            for (int k = 0; k < a.get_columns(); k++) {
                temp += (a.get_element(i, k) * b.get_element(k, j));
            }
            c.set_element(i, j, temp);
        }
    }

    c.list_contents();
}

int main() {
    matrix m1(v1, 2, 3);
    matrix m2(v2, 3, 2);
    m2.set_element(1, 1, 3.4f);
    multiply(m1, m2);
    return 0;
}