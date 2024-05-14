#include "Algorithms.h"

int Algorithms::operationCount = 0;

int Algorithms::getCharNumberInAlfabet(char c) {
    if (isalpha(c)) {
        if (islower(c)) {
            return c-'a';
        } else {
            return c-'A'+26;
        }
    } else if (isdigit(c)) {
        return c-'0'+52;
    } else {
        std::string r = "!@#%:;^&*()-";
        for (int i = 0; i<r.size(); ++i) {
            if (r[i] == c) {
                return i+62;
            }
        }
    }

    return '-';
}

std::vector<std::string> Algorithms::ternaryQuickSort(std::vector<std::string> R, int L) {
    if (R.size() <= 1) {
        return R;
    }

    std::vector<std::string> R_excl;
    std::vector<std::string> R_rest;
    for (auto word : R) {
        if (word.size() == L) {
            R_excl.emplace_back(word);
        } else {
            R_rest.emplace_back(word);
        }
    }

    auto pivod = R_rest[0];

    std::vector<std::string> R_less;
    std::vector<std::string> R_equal;
    std::vector<std::string> R_great;

    for (auto word : R_rest) {
        if (word[L] < pivod[L]) {
            R_less.emplace_back(word);
        } else if (word[L] == pivod[L]) {
            R_equal.emplace_back(word);
        } else {
            R_great.emplace_back(word);
        }
        operationCount++;
    }

    R_less = ternaryQuickSort(R_less, L);
    R_equal = ternaryQuickSort(R_equal, L+1);
    R_great = ternaryQuickSort(R_great, L);

    for (auto word : R_less) {
        R_excl.emplace_back(word);
    }
    for (auto word : R_equal) {
        R_excl.emplace_back(word);
    }
    for (auto word : R_great) {
        R_excl.emplace_back(word);
    }

    return R_excl;
}

std::vector<std::string> Algorithms::MSDRadixSort(std::vector<std::string> R, int L) {
    if (R.size() < ALFABET_SIZE) {
        return ternaryQuickSort(R, L);
    }

    std::vector<std::string> countStrings[ALFABET_SIZE];
    std::vector<std::string> R_excl;
    for (auto s : R) {
        if (s.size() > L)
            countStrings[getCharNumberInAlfabet(s[L])].emplace_back(s);
        else
            R_excl.emplace_back(s);
        operationCount++;
    }

    for (int i = 0; i < ALFABET_SIZE; ++i) {
        countStrings[i] = MSDRadixSort(countStrings[i], L+1);
    }

    for (int i = 0; i < ALFABET_SIZE; ++i) {
        for (auto s : countStrings[i]) {
            R_excl.emplace_back(s);
        }
    }

    return R_excl;
}

std::vector<std::string> Algorithms::MSDRadixSortOther(std::vector<std::string> R, int L) {
    if (R.size() <= 1) {
        return R;
    }

    std::vector<std::string> countStrings[ALFABET_SIZE];
    std::vector<std::string> R_excl;
    for (auto s : R) {
        if (s.size() > L)
            countStrings[getCharNumberInAlfabet(s[L])].emplace_back(s);
        else
            R_excl.emplace_back(s);
        ++operationCount;
    }

    for (int i = 0; i < ALFABET_SIZE; ++i) {
        countStrings[i] = MSDRadixSort(countStrings[i], L+1);
    }

    for (int i = 0; i < ALFABET_SIZE; ++i) {
        for (auto s : countStrings[i]) {
            R_excl.emplace_back(s);
        }
    }

    return R_excl;
}

std::vector<std::string> Algorithms::checkTernaryQuickSort(std::vector<std::string> R) {
    operationCount = 0;
    return Algorithms::ternaryQuickSort(R, 0);
}

std::vector<std::string> Algorithms::checkMSDRadixSort(std::vector<std::string> R) {
    operationCount = 0;
    return Algorithms::MSDRadixSort(R, 0);
}

std::vector<std::string> Algorithms::checkMSDRadixiOtherSort(std::vector<std::string> R) {
    Algorithms::operationCount = 0;
    return Algorithms::MSDRadixSortOther(R, 0);
}

int Algorithms::getOperationCount() {
    return operationCount;
}

int Algorithms::compareStrings(const std::string &s1, const std::string &s2) {
    int s1Idx = 0;
    int s2Idx = 0;
    while (s1Idx < s1.size() && s2Idx < s2.size()) {
        if (s1[s1Idx] > s2[s2Idx])
            return 1;
        else if (s1[s1Idx] < s2[s2Idx])
            return -1;
        ++s1Idx;
        ++s2Idx;
        ++operationCount;
    }

    if (s1.size() > s2.size()) {
        return 1;
    } else {
        return -1;
    }
}

std::vector<std::string> Algorithms::quickSort(std::vector<std::string> R) {
    if (R.size() <= 1) {
        return R;
    }

    auto pivod = R[R.size()/2];
    std::vector<std::string> left;
    std::vector<std::string> right;

    R.erase(R.begin());

    for (auto s : R) {
        if (compareStrings(s, pivod) == -1) {
            left.emplace_back(s);
        } else {
            right.emplace_back(s);
        }
    }

    left = quickSort(left);
    right = quickSort(right);

    left.emplace_back(pivod);
    for (auto s : right) {
        left.emplace_back(s);
    }

    return left;
}

std::vector<std::string> Algorithms::checkQuickSort(std::vector<std::string> R) {
    operationCount = 0;
    return Algorithms::quickSort(R);
}




