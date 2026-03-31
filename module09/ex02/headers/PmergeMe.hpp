#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

#include <deque>
#include <string>
#include <vector>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(PmergeMe const& other);
    ~PmergeMe();
    PmergeMe& operator=(PmergeMe const& other);
    void run(int argc, char** argv);

private:
    std::vector<int> _vec;
    std::deque<int> _deq;
    void parseInput(int argc, char** argv);
    static void mergeInsertVec(std::vector<int>& arr);
    static void mergeInsertDeq(std::deque<int>& arr);
};

#endif
