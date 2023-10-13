#include <iostream>
#include "huffman.h"

int main() {
    int w[3];
    w[0] = 1;
    w[1] = 2;
    w[2] = 3;
    double a[3] = {3,4,5};
    HuffmanNode<int> *b = BestBinaryTree(w,a,3);
    std::cout << b[1].weight;
    return 0;
}
