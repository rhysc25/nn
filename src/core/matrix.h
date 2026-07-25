#pragma once

#include <vector>
#include <iostream>

class matrix {
    private:
        std::vector<float>& v;
        int rows;
        int columns;

    public:
        matrix(std::vector<float>& vi, int ri, int ci);
        
        void list_contents();
        float get_element(int r, int c);
        void set_element(int r, int c, float val);
};

void multiply(matrix& a, matrix& b);