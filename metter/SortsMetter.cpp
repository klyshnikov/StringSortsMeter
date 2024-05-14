#include "SortsMetter.h"

std::pair<double, int> SortsMetter::tryQuickSort(std::vector<std::string> strings) {
    clock_t start = clock();
    Algorithms::checkQuickSort(strings);
    clock_t end = clock();
    auto sec = (double) (end-start) / CLOCKS_PER_SEC;
    return {sec, Algorithms::getOperationCount()};
}

std::pair<double, int> SortsMetter::tryTernaryQuickSort(std::vector<std::string> strings) {
    clock_t start = clock();
    Algorithms::checkTernaryQuickSort(strings);
    clock_t end = clock();
    auto sec = (double) (end-start) / CLOCKS_PER_SEC;
    return {sec, Algorithms::getOperationCount()};
}

std::pair<double, int> SortsMetter::tryMSDRadixSortSort(std::vector<std::string> strings) {
    clock_t start = clock();
    Algorithms::checkMSDRadixSort(strings);
    clock_t end = clock();
    auto sec = (double) (end-start) / CLOCKS_PER_SEC;
    return {sec, Algorithms::getOperationCount()};
}

std::pair<double, int> SortsMetter::tryMSDRadixOtherSortSort(std::vector<std::string> strings) {
    clock_t start = clock();
    Algorithms::checkMSDRadixiOtherSort(strings);
    clock_t end = clock();
    auto sec = (double) (end-start) / CLOCKS_PER_SEC;
    return {sec, Algorithms::getOperationCount()};
}