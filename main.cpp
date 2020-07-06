#include <iostream>
#include <fstream>
#include "src/radixSort_LSD.h"


int main() {

    std::ifstream file("/Users/apple/CLionProjects/RadixSort_LSD/file.txt");
    int n = 10;
    auto *mass = new std::string[n];

    readFromFile(file, mass, n);

    LSDStringSort(mass, n, 5);

    print(mass, n);

    return 0;
}