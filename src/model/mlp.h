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
        void loadWeights(const std::vector<float>& vin) {weights.fill(vin);};
        void loadBias(const std::vector<float>& vin) {bias.fill(vin);};
        MatrixView weightsView() {return weights.view();};
        MatrixView biasView() {return bias.view();};
};