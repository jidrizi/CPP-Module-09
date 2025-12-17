/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:28:49 by jidrizi           #+#    #+#             */
/*   Updated: 2025/12/18 00:24:11 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructors

PmergeMe::PmergeMe()
{
	std::cout << "\033[32mDefault PmergeMe constructor called\033[0m"
		<< std::endl;
}

PmergeMe::PmergeMe(PmergeMe& src) : sortingVector(src.sortingVector), sortingDeque(src.sortingDeque)
{
	std::cout << "\033[32mCopy PmergeMe constructor called\033[0m"
		<< std::endl;
}

PmergeMe& PmergeMe::operator=(PmergeMe& src)
{
	std::cout << "\033[32mCopy PmergeMe assigment operator called\033[0m"
		<< std::endl;
	if (this != &src)
	{
		this->sortingVector = src.sortingVector;
		this->sortingDeque = src.sortingDeque;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << "\033[32mPmergeMe destructor called\033[0m"
		<< std::endl;
}

// Functions

void	PmergeMe::getVectorElements(char** argv)
{

	argv++;
	std::cout << findArgQuantity(argv) << std::endl;
	this->sortingVector.reserve(findArgQuantity(argv));
	while (argv[0])
	{
		std::stringstream	elementStr(argv[0]);
		unsigned int		elementUnsigInt;

		elementStr >> elementUnsigInt;
		this->sortingVector.push_back(elementUnsigInt);

		argv++;
	}

	std::cout << "Before: ";
	for (size_t i = 0; i < this->sortingVector.size(); i++)
		std::cout << this->sortingVector[i] << " ";
	std:: cout << std::endl;
}

// void	PmergeMe::executeVectorSort(int n)
// {
// 	std::vector<int>						pair;
// 	static std::vector<std::vector<int>>	pairHolder;

	

	
// }
