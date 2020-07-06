#ifndef RADIXSORT_LSD_RADIXSORT_LSD_H
#define RADIXSORT_LSD_RADIXSORT_LSD_H

#include <iostream>
#include <string>
#include <fstream>

char charAt(std::string s, int index);

void LSDStringSort(std::string *a, int n, int radix);

void LSDIntegerSort(int *a, int n);

void readFromFile(std::ifstream &file, std::string *mass, int n);

void print(std::string *a, int n);

void readFromFile(std::ifstream &file, int *mass, int n);

void print(int *a, int n);

#endif //RADIXSORT_LSD_RADIXSORT_LSD_H
