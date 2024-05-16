#include "SortsMeter.h"

std::pair<double, int> SortsMeter::tryQuickSort(std::vector<std::string> strings) {
    clock_t start = clock();
    Algorithms::checkQuickSort(strings);
    clock_t end = clock();
    auto sec = (double) (end-start) / CLOCKS_PER_SEC;
    return {sec, Algorithms::getOperationCount()};
}

std::pair<double, int> SortsMeter::tryMergeSort(std::vector<std::string> strings) {
    clock_t start = clock();
    Algorithms::checkMergeSort(strings);
    clock_t end = clock();
    auto sec = (double) (end-start) / CLOCKS_PER_SEC;
    return {sec, Algorithms::getOperationCount()};
}

std::pair<double, int> SortsMeter::tryTernaryQuickSort(std::vector<std::string> strings) {
    clock_t start = clock();
    Algorithms::checkTernaryQuickSort(strings);
    clock_t end = clock();
    auto sec = (double) (end-start) / CLOCKS_PER_SEC;
    return {sec, Algorithms::getOperationCount()};
}

std::pair<double, int> SortsMeter::tryMSDRadixSortSort(std::vector<std::string> strings) {
    clock_t start = clock();
    Algorithms::checkMSDRadixSort(strings);
    clock_t end = clock();
    auto sec = (double) (end-start) / CLOCKS_PER_SEC;
    return {sec, Algorithms::getOperationCount()};
}

std::pair<double, int> SortsMeter::tryMSDRadixOtherSortSort(std::vector<std::string> strings) {
    clock_t start = clock();
    Algorithms::checkMSDRadixiOtherSort(strings);
    clock_t end = clock();
    auto sec = (double) (end-start) / CLOCKS_PER_SEC;
    return {sec, Algorithms::getOperationCount()};
}