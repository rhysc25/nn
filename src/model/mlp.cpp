#include "mlp.h"
#include <iostream>

Activation ReLU (
    [] (float x) {return (x > 0.0f ? x : 0.0f);},
    [] (float x) {return (x > 0.0f ? 1.0f : 0.0f);}
);

layer::layer(size_t r, size_t c, Activation act) : weights(r, c), bias(r, 1), activation(act) {};
//layer::forward(MatrixView& x) {};

int main() {

    layer alpha = layer(3, 3, ReLU);

    alpha.loadWeights({3.0f, 4.0f, 2.0f, 1.0f, 8.0f, 5.0f, 3.0f, 4.0f, 2.0f});
    alpha.loadBias({3.0f, 4.0f, 2.0f, 1.0f});

    MatrixView alphaView = alpha.weightsView();

    alphaView.list_contents();

    size_t iter = 10;
    multi_test(iter);
    
    return 0;
}
