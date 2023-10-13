//
// Created by 黄奔皓 on 2023/3/4.
//
#include <iostream>
#include <bitset>

using namespace std;

unsigned int transpose(unsigned int matrix) {
    int word_size = sizeof(matrix) * 8;
    unsigned int transposed = 0;
    for (int i = 0; i < word_size; i++) {
        // 用掩码来选择第 i 行的位
        unsigned int row_bits = matrix & ((1 << (word_size * i)) - 1);
        // 将掩码应用于每行的位
        row_bits = row_bits & ((1 << word_size) - 1);
        // 将位移加到转置矩阵中
        transposed |= row_bits << i;
    }
    return transposed;
}

int main() {
    // 示例矩阵为 1011
    unsigned int matrix = 11;
    cout << sizeof(matrix) * 8 << endl;
    cout << matrix << endl;
    unsigned int transposed = transpose(matrix);
    // 预期的转置矩阵为 1101
    cout << bitset<32>(transposed) << endl;
    return 0;
}
