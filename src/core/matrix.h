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
        int get_columns();
        void set_columns(int c);
        int get_rows();
        void set_rows(int r);
};

void multiply(matrix& a, matrix& b);