#ifndef STRINGSORTANALYZER_STRINGGENERATOR_H
#define STRINGSORTANALYZER_STRINGGENERATOR_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "../algorithms/Algorithms.h"

class StringGenerator {
private:
    int minLength = 10;
    int maxLength = 200;
    std::string alfabet = "abcdefghijklmnoqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#%:;^&*()-";
public:
    int normalizeValue(int value, int minValue, int maxValue);

    int getRandomValue(int minValue, int maxValue);

    char getRandomAlfabetChar();

    std::string generateWord();

    std::vector<std::vector<std::string>> generateTestData();

    std::vector<std::vector<std::string>> generateAntiSortedTestData();

    std::vector<std::vector<std::string>> generateAlmostSortedTestData();
};


#endif
