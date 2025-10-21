/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:28:49 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/21 16:04:37 by jidrizi          ###   ########.fr       */
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

void	PmergeMe::getVectorElements(std::vector<int>& containerV, char** argv)
{
	while (argv[0])
	{
		std::stringstream	elementStr(argv[0]);
		unsigned int		elementUnsigInt;

		elementStr >> elementUnsigInt;
		containerV.push_back(elementUnsigInt);

		argv[0]++;
	}
}



void	PmergeMe::executeVectorSort(char** argv)
{
	this->getVectorElements(this->sortingVector, char** argv);
	
}