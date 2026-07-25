#include "matrix.h"

std::vector<float> v = {1,4,6,3,5,6};

int main() {
    matrix m(v, 2, 3);
    m.list_contents();
    return 0;
}