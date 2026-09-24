#pragma once

#include <vector>
#include "matrix.h"

class layer {
    private:
        MatrixOwner weights;
        MatrixOwner bias;
        //MatrixOwner activation;

    public:
        //MatrixOwner forward(MatrixView x, MatrixOwner weights, MatrixOwner bias);
        layer(size_t r, size_t c);
        void loadWeights(std::vector<float> vin) {weights.fill(vin);};
};