#pragma once

#include <vector>

class MLP {
    private:
        std::vector<float*> layers;
    public:
        MLP(std::vector<float*> l);
};