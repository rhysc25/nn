#include "layers.h"
#include <iostream>

Activation ReLU (
    [] (float x) {return (x > 0.0f ? x : 0.0f);},
    [] (float x) {return (x > 0.0f ? 1.0f : 0.0f);}
);

layer::layer(size_t r, size_t c, Activation act) : weights(r, c), bias(r, 1), activation(act) {};

MatrixOwner layer::forward(MatrixView& x) {
    MatrixView weights = weightsView();
    MatrixView bias = biasView();

    MatrixOwner A = join_multiply(weights, x);
    MatrixView AView = A.view();

    MatrixOwner B = add(AView, bias);
    MatrixView BView = B.view();

    size_t rows = BView.get_rows();
    for (size_t i = 0; i < rows; i++) {
        BView(i, 0) = activation.activate(BView(i, 0));
    }

    return B;
};

int main() {

    layer alpha = layer(3, 3, ReLU);

    alpha.loadWeights({3.0f, 4.0f, 2.0f, 1.0f, 8.0f, 5.0f, 3.0f, 4.0f, 2.0f});
    alpha.loadBias({3.0f, 4.0f, 2.0f});

    MatrixOwner A(3, 1);
    A.fill({3.0f, 4.0f, 2.0f});
    MatrixView AView = A.view();

    MatrixOwner output = alpha.forward(AView);
    output.view().list_contents();

    size_t iter = 10;
    multi_test(iter);
    
    return 0;
}
