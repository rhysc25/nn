#pragma once

#include <functional>
#include "matrix.h"

class Activation {
    private:
        std::function<float(float)> function;
        std::function<float(float)> derivative;
    
    public:
        Activation(std::function<float(float)> func, std::function<float(float)> der) 
            : function(std::move(func)), derivative(std::move(der)) {};
        float activate(float x) {return function(x);};
        float differentiate(float x) {return derivative(x);};
};

class layer {
    private:
        MatrixOwner weights;
        MatrixOwner bias;
        Activation activation;

    public:
        MatrixOwner forward(MatrixView& x);
        layer(size_t r, size_t c, Activation act);
        void loadWeights(const std::vector<float>& vin) {weights.fill(vin);};
        void loadBias(const std::vector<float>& vin) {bias.fill(vin);};
        MatrixView weightsView() {return weights.view();};
        MatrixView biasView() {return bias.view();};
};