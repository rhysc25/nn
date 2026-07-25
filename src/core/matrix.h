#pragma once

#include <vector>
#include <iostream>

class matrix {
    public:
        std::vector<float>& v;
        int rows;
        int columns;

        matrix(std::vector<float>& vi, int ri, int ci);
        
        void list_contents();
};