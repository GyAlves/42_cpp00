#ifndef PMERGE_ME_HPP
# define PMERGE_ME_HPP

#include <deque>
#include <string>
#include <vector>
#include <utility>

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

	static std::vector<std::pair<int, int> > makePairsVec(std::vector<int>& arr, size_t pairCount);
	static std::deque<std::pair<int, int> > makePairsDeq(std::deque<int>& arr, size_t pairCount);

	static std::vector<std::pair<int, int> > reorderPairsVec(
		std::vector<std::pair<int, int> >& pairs, std::vector<int>& largers);
	static std::deque<std::pair<int, int> > reorderPairsDeq(
		std::deque<std::pair<int, int> >& pairs, std::deque<int>& largers);

	static std::vector<size_t> buildInsertionOrder(size_t pendSize);

	static void insertPendVec(std::vector<int>& chain,
		std::vector<int>& pend, std::vector<std::pair<int, int> >& pairs);
	static void insertPendDeq(std::deque<int>& chain,
		std::deque<int>& pend, std::deque<std::pair<int, int> >& pairs);
};

#endif
