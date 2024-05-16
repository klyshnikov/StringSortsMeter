#ifndef STRINGSORTANALYZER_SORTSMETER_H
#define STRINGSORTANALYZER_SORTSMETER_H

#include <iostream>
#include <vector>
#include <time.h>

#include "../algorithms/Algorithms.h"

class SortsMeter {
public:
    std::pair<double, int> tryQuickSort(std::vector<std::string> strings);
    std::pair<double, int> tryMergeSort(std::vector<std::string> strings);

    std::pair<double, int> tryTernaryQuickSort(std::vector<std::string> strings);
    std::pair<double, int> tryMSDRadixSortSort(std::vector<std::string> strings);
    std::pair<double, int> tryMSDRadixOtherSortSort(std::vector<std::string> strings);
};


#endif
