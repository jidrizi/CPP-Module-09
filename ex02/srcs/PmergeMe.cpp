/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:28:49 by jidrizi           #+#    #+#             */
/*   Updated: 2026/01/10 21:33:53 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructors
PmergeMe::PmergeMe() : name("Default")
{
	std::cout << "[Default PmergeMe constructor called]" << std::endl;
}

PmergeMe::PmergeMe(std::string nameParameter)
{
	std::cout << "[PmergeMe constructor with parameters called]" << std::endl;
	this->name = nameParameter;
}

PmergeMe::PmergeMe(PmergeMe &src)
	: name(src.name), toBeSortedVector(src.toBeSortedVector), toBeSortedDeque(src.toBeSortedDeque)
{
	std::cout << "[PmergeMe copy constructor called]" << std::endl;
}

PmergeMe	PmergeMe::operator=(PmergeMe &src)
{
	std::cout << "[PmergeMe copy assigment operator called]" << std::endl;

	if (this != &src)
	{
		this->name = src.name;
		this->toBeSortedVector = src.toBeSortedVector;
		this->toBeSortedDeque = src.toBeSortedDeque;
	}

	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << "[PmergeMe destructor called]" << std::endl;
}



// Member functions
void	PmergeMe::getAndPushNumbers(char **argv)
{
	argv++;
	this->toBeSortedVector.reserve(findArgQuantity(argv));

	while (argv[0])
	{
		std::stringstream	elementStr(argv[0]);
		unsigned int		elementUnsigInt;

		elementStr >> elementUnsigInt;
		this->toBeSortedVector.push_back(elementUnsigInt);
		this->toBeSortedDeque.push_back(elementUnsigInt);

		argv++;
	}
}

void	PmergeMe::printContainerElements(std::string msg)
{
	std::cout << msg;
	for (unsigned long  i = 0; i < this->toBeSortedVector.size(); i++)
		std::cout << toBeSortedVector[i] << " ";
	std::cout << std::endl;
}


void	PmergeMe::handleFirstCall(std::vector<int> toBeSortedVector,
						std::vector< std::vector<int> > &endResult)
{
	std::vector<int>	group;
	group.reserve(n * 2);

	for(unsigned long i = 0; i < this->toBeSortedVector.size(); )
	{
		group.push_back(toBeSortedVector[i++]);
		group.push_back(toBeSortedVector[i++]);
		endResult.push_back(group);
		group.clear();
	}

	return ;
}

void	PmergeMe::executeAlgorithm(unsigned long n)
{
	static std::vector< std::vector<int> >	endResult;

	if (n == 1)
	{
		this->handleFirstCall(toBeSortedVector, endResult);
		this->executeAlgorithm(n * 2);
		return ;
	}

	for (int	i = 0; i + 1 < endResult.size(); i++)
	{
		if (endResult[i].back() > endResult[i + 1].back())
			std::swap(endResult[i], endResult[i + 1]);
	}
	
}