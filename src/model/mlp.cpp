#include "mlp.h"
#include "matrix.h"
#include <iostream>

MLP::MLP(std::vector<float*> l) : layers(l) {}

int main() {
    MatrixOwner A(1,1);
    A.fill(std::vector<float> {3.0f});
    MatrixView AView = A.view();
    MatrixOwner B(3,1);
    B.fill(std::vector<float> {3.0f, 4.0f, 2.0f});
    MatrixView BView = B.view();
    MatrixOwner C(3,3);
    C.fill(std::vector<float> {3.0f, 4.0f, 2.0f, 1.0f, 8.0f, 5.0f, 3.0f, 4.0f, 2.0f});
    MatrixView CView = C.view();

    std::cout << "Hi" << "\n";

    size_t iter = 10;
    multi_test(iter);
    
    return 0;
}
