#include "PmergeMe.hpp"
#include <algorithm>
#include <ctime>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <utility>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const& other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(PmergeMe const& other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

static std::vector<size_t> makeJacVec(size_t n) {
    std::vector<size_t> jac;
    jac.push_back(0);
    jac.push_back(1);
    while (jac.back() < n) {
        size_t sz = jac.size();
        jac.push_back(jac[sz - 1] + 2 * jac[sz - 2]);
    }
    return jac;
}

void PmergeMe::mergeInsertVec(std::vector<int>& arr) {
    size_t n = arr.size();
    if (n <= 1)
        return;
    bool hasStraggler = (n % 2 != 0);
    int straggler = hasStraggler ? arr[n - 1] : 0;
    size_t pairCount = n / 2;
    std::vector<std::pair<int, int> > pairs(pairCount);
    for (size_t i = 0; i < pairCount; i++) {
        int a = arr[i * 2], b = arr[i * 2 + 1];
        if (a > b)
            std::swap(a, b);
        pairs[i] = std::make_pair(a, b);
    }
    std::vector<int> largers;
    for (size_t i = 0; i < pairCount; i++)
        largers.push_back(pairs[i].second);
    mergeInsertVec(largers);
    std::vector<std::pair<int, int> > sortedPairs;
    std::vector<bool> used(pairCount, false);
    for (size_t i = 0; i < largers.size(); i++) {
        for (size_t j = 0; j < pairCount; j++) {
            if (!used[j] && pairs[j].second == largers[i]) {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }
    pairs = sortedPairs;
    std::vector<int> chain;
    chain.push_back(pairs[0].first);
    for (size_t i = 0; i < pairCount; i++)
        chain.push_back(pairs[i].second);
    std::vector<int> pend;
    for (size_t i = 1; i < pairCount; i++)
        pend.push_back(pairs[i].first);
    if (!pend.empty()) {
        std::vector<size_t> jac = makeJacVec(pend.size());
        std::vector<bool> done(pend.size(), false);
        std::vector<size_t> order;
        for (size_t k = 1; k < jac.size(); k++) {
            size_t hi = jac[k];
            size_t lo = jac[k - 1];
            if (hi > pend.size())
                hi = pend.size();
            for (size_t idx = hi; idx > lo; idx--) {
                size_t i = idx - 1;
                if (i < pend.size() && !done[i]) {
                    order.push_back(i);
                    done[i] = true;
                }
            }
        }
        for (size_t i = 0; i < pend.size(); i++) {
            if (!done[i])
                order.push_back(i);
        }
        for (size_t k = 0; k < order.size(); k++) {
            size_t idx = order[k];
            int val = pend[idx];
            int boundVal = pairs[idx + 1].second;
            std::vector<int>::iterator bIt = std::upper_bound(chain.begin(), chain.end(), boundVal);
            std::vector<int>::iterator pos = std::lower_bound(chain.begin(), bIt, val);
            chain.insert(pos, val);
        }
    }
    if (hasStraggler) {
        std::vector<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(pos, straggler);
    }
    arr = chain;
}

static std::deque<size_t> makeJacDeq(size_t n) {
    std::deque<size_t> jac;
    jac.push_back(0);
    jac.push_back(1);
    while (jac.back() < n) {
        size_t sz = jac.size();
        jac.push_back(jac[sz - 1] + 2 * jac[sz - 2]);
    }
    return jac;
}

void PmergeMe::mergeInsertDeq(std::deque<int>& arr) {
    size_t n = arr.size();
    if (n <= 1)
        return;
    bool hasStraggler = (n % 2 != 0);
    int straggler = hasStraggler ? arr[n - 1] : 0;
    size_t pairCount = n / 2;
    std::deque<std::pair<int, int> > pairs(pairCount);
    for (size_t i = 0; i < pairCount; i++) {
        int a = arr[i * 2], b = arr[i * 2 + 1];
        if (a > b)
            std::swap(a, b);
        pairs[i] = std::make_pair(a, b);
    }
    std::deque<int> largers;
    for (size_t i = 0; i < pairCount; i++)
        largers.push_back(pairs[i].second);
    mergeInsertDeq(largers);
    std::deque<std::pair<int, int> > sortedPairs;
    std::deque<bool> used(pairCount, false);
    for (size_t i = 0; i < largers.size(); i++) {
        for (size_t j = 0; j < pairCount; j++) {
            if (!used[j] && pairs[j].second == largers[i]) {
                sortedPairs.push_back(pairs[j]);
                used[j] = true;
                break;
            }
        }
    }
    pairs = sortedPairs;
    std::deque<int> chain;
    chain.push_back(pairs[0].first);
    for (size_t i = 0; i < pairCount; i++)
        chain.push_back(pairs[i].second);
    std::deque<int> pend;
    for (size_t i = 1; i < pairCount; i++)
        pend.push_back(pairs[i].first);
    if (!pend.empty()) {
        std::deque<size_t> jac = makeJacDeq(pend.size());
        std::deque<bool> done(pend.size(), false);
        std::deque<size_t> order;
        for (size_t k = 1; k < jac.size(); k++) {
            size_t hi = jac[k];
            size_t lo = jac[k - 1];
            if (hi > pend.size())
                hi = pend.size();
            for (size_t idx = hi; idx > lo; idx--) {
                size_t i = idx - 1;
                if (i < pend.size() && !done[i]) {
                    order.push_back(i);
                    done[i] = true;
                }
            }
        }
        for (size_t i = 0; i < pend.size(); i++) {
            if (!done[i])
                order.push_back(i);
        }
        for (size_t k = 0; k < order.size(); k++) {
            size_t idx = order[k];
            int val = pend[idx];
            int boundVal = pairs[idx + 1].second;
            std::deque<int>::iterator bIt = std::upper_bound(chain.begin(), chain.end(), boundVal);
            std::deque<int>::iterator pos = std::lower_bound(chain.begin(), bIt, val);
            chain.insert(pos, val);
        }
    }
    if (hasStraggler) {
        std::deque<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), straggler);
        chain.insert(pos, straggler);
    }
    arr = chain;
}

void PmergeMe::parseInput(int argc, char** argv) {
    for (int i = 1; i < argc; i++) {
        std::istringstream ss(argv[i]);
        std::string token;
        while (ss >> token) {
            for (size_t j = 0; j < token.size(); j++) {
                if (token[j] < '0' || token[j] > '9')
                    throw std::invalid_argument("Error");
            }
            if (token.empty())
                throw std::invalid_argument("Error");
            long val = std::atol(token.c_str());
            if (val <= 0 && token != "0")
                throw std::invalid_argument("Error");
            if (val > 2147483647)
                throw std::invalid_argument("Error");
            _vec.push_back(static_cast<int>(val));
            _deq.push_back(static_cast<int>(val));
        }
    }
    if (_vec.empty())
        throw std::invalid_argument("Error");
}

void PmergeMe::run(int argc, char** argv) {
    parseInput(argc, argv);
    std::cout << "Before:";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << " " << _vec[i];
    std::cout << std::endl;
    clock_t startVec = clock();
    mergeInsertVec(_vec);
    clock_t endVec = clock();
    clock_t startDeq = clock();
    mergeInsertDeq(_deq);
    clock_t endDeq = clock();
    std::cout << "After:";
    for (size_t i = 0; i < _vec.size(); i++)
        std::cout << " " << _vec[i];
    std::cout << std::endl;
    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}
