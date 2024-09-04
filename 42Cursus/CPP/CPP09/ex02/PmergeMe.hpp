#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <iterator>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include <ctime>

class PmergeMe
{
	std::list<int>	_list;
	std::deque<int>	_deque;

	public:
		PmergeMe(std::list<int> unsortedList, std::deque<int> unsortedDeque);
		PmergeMe(const PmergeMe &src);
		~PmergeMe();

		PmergeMe	&operator=(const PmergeMe &src);

		void		pairing(std::list<int> &inputList, std::list<int> &sortedSubList, std::list<int> &unsortedSubList);
		void		recursiveSort(std::list<int> &sortedSubList);
		void		binarySearchInsertion(std::list<int> &sortedSubList, std::list<int> &unsortedSubList);
		void		fordJohnsonSort(std::list<int> &inputList);

		void		pairing(std::deque<int> &inputDeque, std::deque<int> &sortedSubDeque, std::deque<int> &unsortedSubDeque);
		void		recursiveSort(std::deque<int> &sortedSubDeque);
		void		binarySearchInsertion(std::deque<int> &sortedSubDeque, std::deque<int> &unsortedSubDeque);
		void		fordJohnsonSort(std::deque<int> &inputDeque);

		void		display();
};

#endif
