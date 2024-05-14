#include "StringGenerator.h"

int StringGenerator::normalizeValue(int value, int minValue, int maxValue) {
    double updatedValue = double(value) * double(maxValue-minValue)/INT32_MAX;
    double shiftedValue = updatedValue+minValue;
    return int(shiftedValue);
}

int StringGenerator::getRandomValue(int minValue, int maxValue) {
    return normalizeValue(std::rand(), minValue, maxValue);
}

char StringGenerator::getRandomAlfabetChar() {
    return alfabet[getRandomValue(0, alfabet.size()-1)];
}

std::string StringGenerator::generateWord() {
    int randomLength = getRandomValue(minLength, maxLength);
    std::string result(randomLength, 'a');
    for (int i = 0; i < randomLength; ++i) {
        result[i] = getRandomAlfabetChar();
    }
    return result;
}

std::vector<std::vector<std::string>> StringGenerator::generateTestData() {
    std::vector<std::vector<std::string>> result;

    std::vector<std::string> fullData(3000);
    for (int i = 0; i < 3000; ++i) {
        fullData[i] = generateWord();
    }

    for (int len = 100; len <= 3000; len += 100) {
        std::vector<std::string> current(len);
        for (int i = 0; i<len; ++i) {
            current[i] = fullData[i];
        }
        result.emplace_back(current);
    }

    return result;
}

std::vector<std::vector<std::string>> StringGenerator::generateAntiSortedTestData() {
    std::vector<std::vector<std::string>> result;

    std::vector<std::string> fullData(3000);
    for (int i = 0; i < 3000; ++i) {
        fullData[i] = generateWord();
    }

    for (int len = 100; len <= 3000; len += 100) {
        std::vector<std::string> current(len);
        for (int i = 0; i<len; ++i) {
            current[i] = fullData[i];
        }
        current = Algorithms::ternaryQuickSort(current, 0);
        std::reverse(current.begin(), current.end());
        result.emplace_back(current);
    }

    return result;
}

std::vector<std::vector<std::string>> StringGenerator::generateAlmostSortedTestData() {
    std::vector<std::vector<std::string>> result;

    std::vector<std::string> fullData(3000);
    for (int i = 0; i < 3000; ++i) {
        fullData[i] = generateWord();
    }

    for (int len = 100; len <= 3000; len += 100) {
        std::vector<std::string> current(len);
        for (int i = 0; i<len; ++i) {
            current[i] = fullData[i];
        }
        current = Algorithms::ternaryQuickSort(current, 0);
        for (int swapNum = 0; swapNum < 10; ++swapNum) {
            std::swap(current[getRandomValue(0, current.size()-1)],
                      current[getRandomValue(0, current.size()-1)]);
        }

        result.emplace_back(current);
    }

    return result;
}


