#ifndef STRINGSORTANALYZER_SORTSMETTER_H
#define STRINGSORTANALYZER_SORTSMETTER_H

#include <iostream>
#include <vector>
#include <time.h>

#include "../algorithms/Algorithms.h"

class SortsMetter {
public:
    std::pair<double, int> tryQuickSort(std::vector<std::string> strings);

    std::pair<double, int> tryTernaryQuickSort(std::vector<std::string> strings);
    std::pair<double, int> tryMSDRadixSortSort(std::vector<std::string> strings);
    std::pair<double, int> tryMSDRadixOtherSortSort(std::vector<std::string> strings);
};


#endif
