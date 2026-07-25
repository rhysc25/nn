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
        
        void list_contents() const;
};

void multiply(const matrix& a, const matrix& b);