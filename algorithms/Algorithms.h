#ifndef STRINGSORTANALYZER_ALGORITHMS_H
#define STRINGSORTANALYZER_ALGORITHMS_H

#include <iostream>
#include <vector>

class Algorithms {
private:
    static const int ALFABET_SIZE = 74;
    static int operationCount;

    static int getCharNumberInAlfabet(char c);

    static std::vector<std::string> ternaryMergeSort(std::vector<std::string> R, int L);

    static std::vector<std::string> MSDRadixSort(std::vector<std::string> R, int L);

    static std::vector<std::string> MSDRadixSortOther(std::vector<std::string> R, int L);

    static int compareStrings(const std::string& s1, const std::string& s2);

    static std::vector<std::string> quickSort(std::vector<std::string> R);

    static std::vector<std::string> mergeSort(std::vector<std::string> R);

public:
    static std::vector<std::string> ternaryQuickSort(std::vector<std::string> R, int L);

    static std::vector<std::string> checkTernaryQuickSort(std::vector<std::string> R);

    static std::vector<std::string> checkMSDRadixSort(std::vector<std::string> R);

    static std::vector<std::string> checkMSDRadixiOtherSort(std::vector<std::string> R);

    static std::vector<std::string> checkQuickSort(std::vector<std::string> R);

    static std::vector<std::string> checkMergeSort(std::vector<std::string> R);

    static int getOperationCount();
};


#endif
