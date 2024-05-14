#include <iostream>

#include "generator/StringGenerator.h"
#include "metter/SortsMetter.h"

void printInformationAboutTime(std::vector<std::vector<std::string>> data) {
    SortsMetter sortsMetters;
    for (int i = 0; i < data.size(); ++i) {
        auto resQuickSort = sortsMetters.tryQuickSort(data[i]);
        auto resQuickTernarySort = sortsMetters.tryTernaryQuickSort(data[i]);
        auto resMSDSort = sortsMetters.tryMSDRadixSortSort(data[i]);
        auto resMSDOtherSort = sortsMetters.tryMSDRadixOtherSortSort(data[i]);
        std::cout << resQuickSort.first << " " << resQuickTernarySort.first << " " << resMSDSort.first  << " " << resMSDOtherSort.first << "\n";
    }
}

void printInformationAboutCompares(std::vector<std::vector<std::string>> data) {
    SortsMetter sortsMetters;
    for (int i = 0; i < data.size(); ++i) {
        auto resQuickSort = sortsMetters.tryQuickSort(data[i]);
        auto resQuickTernarySort = sortsMetters.tryTernaryQuickSort(data[i]);
        auto resMSDSort = sortsMetters.tryMSDRadixSortSort(data[i]);
        auto resMSDOtherSort = sortsMetters.tryMSDRadixOtherSortSort(data[i]);
        std::cout << resQuickSort.second << " " << resQuickTernarySort.second << " " << resMSDSort.second  << " " << resMSDOtherSort.second << "\n";
    }
}

int main() {
    StringGenerator stringGenerator;
    SortsMetter sortsMetters;

    auto randomTestData = stringGenerator.generateTestData();
    auto antiSortedTestData = stringGenerator.generateAntiSortedTestData();
    auto almostSortedTestData = stringGenerator.generateAlmostSortedTestData();

    // Compare on random data - time
    printInformationAboutTime(randomTestData);

    std::cout << "OK";
}
