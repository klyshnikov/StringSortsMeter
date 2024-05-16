#include <iostream>
#include <fstream>

#include "generator/StringGenerator.h"
#include "meter/SortsMeter.h"

void printInformationAboutTime(std::vector<std::vector<std::string>> data) {
    SortsMeter sortsMetters;
    for (int i = 0; i < data.size(); ++i) {
        auto resQuickSort = sortsMetters.tryQuickSort(data[i]);
        auto resMergeSort = sortsMetters.tryMergeSort(data[i]);
        auto resQuickTernarySort = sortsMetters.tryTernaryQuickSort(data[i]);
        auto resMSDSort = sortsMetters.tryMSDRadixSortSort(data[i]);
        auto resMSDOtherSort = sortsMetters.tryMSDRadixOtherSortSort(data[i]);
        std::cout << int(resQuickSort.first*1000000) << " " << int(resMergeSort.first*1000000) << " " << int(resQuickTernarySort.first*1000000) << " " << int(resMSDSort.first*1000000)  << " " << int(resMSDOtherSort.first*1000000) << "\n";
    }
}

void printInformationAboutCompares(std::vector<std::vector<std::string>> data) {
    SortsMeter sortsMetters;
    for (int i = 0; i < data.size(); ++i) {
        auto resQuickSort = sortsMetters.tryQuickSort(data[i]);
        auto resMergeSort = sortsMetters.tryMergeSort(data[i]);
        auto resQuickTernarySort = sortsMetters.tryTernaryQuickSort(data[i]);
        auto resMSDSort = sortsMetters.tryMSDRadixSortSort(data[i]);
        auto resMSDOtherSort = sortsMetters.tryMSDRadixOtherSortSort(data[i]);
        std::cout << resQuickSort.second << " " << resMergeSort.second << " " << resQuickTernarySort.second << " " << resMSDSort.second  << " " << resMSDOtherSort.second << "\n";
    }
}

void saveDataToFile(std::vector<std::vector<std::string>> data, std::string name) {
    std::ofstream myfile;
    myfile.open (name);
    for (auto v : data) {
        for (auto w : v) {
            myfile << w << " ";
        }
        myfile << "\n";
    }
    myfile.close();
}

int main() {
    StringGenerator stringGenerator;
    SortsMeter sortsMetters;

    auto randomTestData = stringGenerator.generateTestData();
    auto antiSortedTestData = stringGenerator.generateAntiSortedTestData();
    auto almostSortedTestData = stringGenerator.generateAlmostSortedTestData();

    saveDataToFile(randomTestData, "random");

    // Compare on random data - time
    printInformationAboutCompares( antiSortedTestData);

    std::cout << "OK";
}
