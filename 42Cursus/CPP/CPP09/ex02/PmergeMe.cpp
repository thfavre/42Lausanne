#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::list<int> unsortedList, std::deque<int> unsortedDeque) : _list(unsortedList), _deque(unsortedDeque)
{
	std::cout << "----- Before -----";
	this->display();

	clock_t	startDeque = clock();
	fordJohnsonSort(this->_deque);
	clock_t	endDeque = clock();

	clock_t	startList = clock();
	fordJohnsonSort(this->_list);
	clock_t	endList = clock();

	std::cout << std::endl << "----- After -----";
	this->display();
	std::cout << std::endl << "\033[1;33mTime to process a range of " << this->_list.size() << " elements with std::list<int>: \033[0m" << static_cast<double>(endList - startList) / CLOCKS_PER_SEC * 1000 << std::endl;
	std::cout << "\033[1;33mTime to process a range of " << this->_deque.size() << " elements with std::deque<int>: \033[0m" << static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000 << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe::~PmergeMe()
{

}

PmergeMe	&PmergeMe::operator=(const PmergeMe &src)
{
	this->_list = src._list;
	this->_deque = src._deque;

	return *this;
}

// ---------- List functions ----------

void	PmergeMe::pairing(std::list<int> &inputList, std::list<int> &sortedSubList, std::list<int> &unsortedSubList)
{
	if (inputList.size() <= 1) {
		return;
	}

	std::list<int>::iterator it = inputList.begin();
	while (it != inputList.end()) {
		int first = *it;
		++it;
		if (it != inputList.end()) {
			int second = *it;
			++it;
			if (first > second) {
				sortedSubList.push_back(first);
				unsortedSubList.push_back(second);
			} else {
				sortedSubList.push_back(second);
				unsortedSubList.push_back(first);
			}
		} else {
			sortedSubList.push_back(first);
		}
	}
}

void	PmergeMe::recursiveSort(std::list<int> &sortedSubList)
{
	if (sortedSubList.size() <= 1) {
		return;
	}

	size_t mid = sortedSubList.size() / 2;
	std::list<int> left(sortedSubList.begin(), std::next(sortedSubList.begin(), mid));
	std::list<int> right(std::next(sortedSubList.begin(), mid), sortedSubList.end());

	recursiveSort(left);
	recursiveSort(right);

	sortedSubList.clear();
	std::list<int>::iterator it_left = left.begin();
	std::list<int>::iterator it_right = right.begin();
	while (it_left != left.end() && it_right != right.end()) {
		if (*it_left < *it_right) {
			sortedSubList.push_back(*it_left);
			++it_left;
		} else {
			sortedSubList.push_back(*it_right);
			++it_right;
		}
	}

	while (it_left != left.end()) {
		sortedSubList.push_back(*it_left);
		++it_left;
	}
	while (it_right != right.end()) {
		sortedSubList.push_back(*it_right);
		++it_right;
	}
}

void	PmergeMe::binarySearchInsertion(std::list<int> &sortedSubList, std::list<int> &unsortedSubList)
{
	for (std::list<int>::iterator it = unsortedSubList.begin(); it != unsortedSubList.end(); ++it)
	{
		int element = *it;

		std::list<int>::iterator low = sortedSubList.begin();
		std::list<int>::iterator high = sortedSubList.end();
		while (low != high) {
			std::list<int>::iterator mid = low;
			std::advance(mid, std::distance(low, high) / 2);
			if (*mid < element) {
				++low;
			} else {
				high = mid;
			}
		}

		sortedSubList.insert(low, element);
	}
}

void	PmergeMe::fordJohnsonSort(std::list<int> &inputList)
{
	if (inputList.size() <= 1) return;

	std::list<int> sortedSubList;
	std::list<int> unsortedSubList;

	// Pairing (2x2) and extracting bigger numbers
	pairing(inputList, sortedSubList, unsortedSubList);

	// Sorting in ascending order half of bigger numbers
	recursiveSort(sortedSubList);

	// Inserting half smaller elements using binary search
	binarySearchInsertion(sortedSubList, unsortedSubList);

	inputList = sortedSubList;
}




// ---------- Deque functons ----------

void	PmergeMe::pairing(std::deque<int> &inputDeque, std::deque<int> &sortedSubDeque, std::deque<int> &unsortedSubDeque)
{
	if (inputDeque.size() <= 1) {
		return;
	}

	for (size_t i = 0; i < inputDeque.size(); i += 2) {
		if (i + 1 < inputDeque.size()) {
			if (inputDeque[i] > inputDeque[i + 1]) {
				sortedSubDeque.push_back(inputDeque[i]);
				unsortedSubDeque.push_back(inputDeque[i + 1]);
			} else {
				sortedSubDeque.push_back(inputDeque[i + 1]);
				unsortedSubDeque.push_back(inputDeque[i]);
			}
		} else {
			sortedSubDeque.push_back(inputDeque[i]);
		}
	}
}

void	PmergeMe::recursiveSort(std::deque<int> &sortedSubDeque)
{
	if (sortedSubDeque.size() <= 1) {
		return;
	}

	size_t mid = sortedSubDeque.size() / 2;
	std::deque<int> left(sortedSubDeque.begin(), sortedSubDeque.begin() + mid);
	std::deque<int> right(sortedSubDeque.begin() + mid, sortedSubDeque.end());

	recursiveSort(left);
	recursiveSort(right);

	sortedSubDeque.clear();
	size_t i = 0, j = 0;
	while (i < left.size() && j < right.size()) {
		if (left[i] < right[j]) {
			sortedSubDeque.push_back(left[i]);
			++i;
		} else {
			sortedSubDeque.push_back(right[j]);
			++j;
		}
	}

	while (i < left.size()) {
		sortedSubDeque.push_back(left[i]);
		++i;
	}
	while (j < right.size()) {
		sortedSubDeque.push_back(right[j]);
		++j;
	}
}

void	PmergeMe::binarySearchInsertion(std::deque<int> &sortedSubDeque, std::deque<int> &unsortedSubDeque)
{
	for (size_t i = 0; i < unsortedSubDeque.size(); ++i)
	{
		int element = unsortedSubDeque[i];

		size_t low = 0;
		size_t high = sortedSubDeque.size();
		while (low < high) {
			size_t mid = (low + high) / 2;
			if (sortedSubDeque[mid] < element) {
				low = mid + 1;
			} else {
				high = mid;
			}
		}

		sortedSubDeque.insert(sortedSubDeque.begin() + low, element);
	}
}

void	PmergeMe::fordJohnsonSort(std::deque<int> &inputDeque)
{
	if (inputDeque.size() <= 1) return;

	std::deque<int> sortedSubDeque;
	std::deque<int> unsortedSubDeque;

	// pairing and extracting bigger numbers
	pairing(inputDeque, sortedSubDeque, unsortedSubDeque);

	// sorting in ascending order half of bigger numbers
	recursiveSort(sortedSubDeque);

	// inserting half smaller elements using binary search
	binarySearchInsertion(sortedSubDeque, unsortedSubDeque);

	inputDeque = sortedSubDeque;
}

void	PmergeMe::display()
{
	int	sizeDeque = this->_deque.size();
	std::cout << std::endl << "deque : ";
	for (int i =  0; i < sizeDeque; ++i)
	{
		std::cout << this->_deque[i] << " ";
	}
	std::cout << std::endl << std::endl;

	std::list<int>::iterator it;
	std::cout << std::endl << "list  : ";
	for (it = this->_list.begin(); it != this->_list.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
