#include "radixSort_LSD.h"


char charAt(std::string s, int index) {
    return s[index];
}

void LSDStringSort(std::string *a, int n, int radix) {

    int R = 256;
    auto *aux = new std::string[n];

    // Counting occurence of digits
    for (int d = radix - 1; d >= 0; d--) {
        int *count = new int[R + 1];
        for (int i = 0; i < n; i++) {
            count[charAt(a[i], d) + 1]++;
        }

        // Changing the position of count so that it appears at actual position in result.
        for (int r = 0; r < R; r++)
            count[r + 1] += count[r];

        // Resultant output array
        for (int i = 0; i < n; i++)
            aux[count[charAt(a[i], d)]++] = a[i];

        for (int i = 0; i < n; i++)
            a[i] = aux[i];
    }
}

void LSDIntegerSort(int *a, int n) {
    int BITS_PER_BYTE = 8;
    int BITS = 32;
    int R = 1 << BITS_PER_BYTE;
    int MASK = R - 1;
    int w = BITS / BITS_PER_BYTE;

    auto *aux = new int[n];

    for (int d = 0; d < w; d++) {

        auto *count = new int[R + 1];

        for (int i = 0; i < n; i++) {
            int c = (a[i] >> BITS_PER_BYTE * d) & MASK;
            count[c + 1]++;
        }

        for (int r = 0; r < R; r++)
            count[r + 1] += count[r];

        if (d == w - 1) {
            int shift1 = count[R] - count[R / 2];
            int shift2 = count[R / 2];
            for (int r = 0; r < R / 2; r++)
                count[r] += shift1;
            for (int r = R / 2; r < R; r++)
                count[r] -= shift2;
        }

        for (int i = 0; i < n; i++) {
            int c = (a[i] >> BITS_PER_BYTE * d) & MASK;
            aux[count[c]++] = a[i];
        }

        for (int i = 0; i < n; i++)
            a[i] = aux[i];
    }
}


void readFromFile(std::ifstream &file, std::string *mass, int n) {

    for (int i = 0; i < n; i++) {
        file >> mass[i];
    }
}

void print(std::string *a, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << std::endl;
    }
}

void readFromFile(std::ifstream &file, int *mass, int n) {

    for (int i = 0; i < n; i++) {
        file >> mass[i];
    }
}

void print(int *a, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << std::endl;
    }
}