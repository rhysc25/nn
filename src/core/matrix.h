#pragma once

#include <vector>
#include <iostream>

class matrix {
    public:
        std::vector<float> v;
        int rows;
        int columns;

        matrix(std::vector<float> v, int rows, int columns);
        
        void list_contents();
};

matrix::matrix(std::vector<float> vi, int ri, int ci) {
    v = vi;
    rows = ri;
    columns = ci;
}

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