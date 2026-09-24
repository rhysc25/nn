#include "mlp.h"
#include <iostream>

layer::layer(size_t r, size_t c) : weights(r, c), bias(r, 1) {};

int main() {

    layer alpha = layer(3, 3);

    alpha.loadWeights({3.0f, 4.0f, 2.0f, 1.0f, 8.0f, 5.0f, 3.0f, 4.0f, 2.0f});

    MatrixView alphaView = alpha.weightsView();

    alphaView.list_contents();

    size_t iter = 10;
    multi_test(iter);
    
    return 0;
}
