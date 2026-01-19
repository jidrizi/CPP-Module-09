/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:28:49 by jidrizi           #+#    #+#             */
/*   Updated: 2026/01/19 23:13:47 by jidrizi          ###   ########.fr       */
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


//DEBUG THINGY

void	debugResult(std::vector < std::vector<int> > result, std::string s, unsigned long n)
{
	unsigned long	x = 0;
	unsigned long	y = 0;
	
	if (result.empty())
		return ;
	std::cout << n << s;
	while (x < result.size())
	{
		y = 0;
		std::cout << "[";
		while (y < result[x].size())
		{
			std::cout << result[x][y] << " ";
			y++;
		}
		std::cout << "]";
		x++;
	}
	std::cout << std::endl;
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

std::vector< std::vector<int> > 	PmergeMe::adjustContainer(std::vector < std::vector<int> > result,
										unsigned long n)
{
	std::vector< std::vector<int> >	newResult;
	std::vector<int>				newPair;
	unsigned long					currPair;

	newPair.reserve(n * 2);
	currPair = 0;
	
	if (n == 1)
	{
		while (currPair + 1 < this->toBeSortedVector.size())
		{
			newPair.push_back(toBeSortedVector[currPair++]);
			newPair.push_back(toBeSortedVector[currPair++]);
			newResult.push_back(newPair);
			newPair.clear();
		}
		return (newResult);
	}

	while (currPair + 1 < result.size())
	{
		for (unsigned long	i = 0; i < result[currPair++].size(); i++)
			newPair.push_back(result[currPair][i]);
		for (unsigned long	i = 0; i < result[currPair++].size(); i++)
			newPair.push_back(result[currPair][i]);
		newResult.push_back(newPair);
		newPair.clear();
	}

	return (newResult);
}

void	PmergeMe::executeFirstHalf(unsigned long n)
{
	static std::vector< std::vector<int> >	result;
	if ( (n * 2) > this->toBeSortedVector.size() )
	{
		this->firstHalfSequence = result;
		return ;
	}
	
	result = this->adjustContainer(result, n);
	for (unsigned long currPair = 0; currPair < result.size(); currPair++)
	{
		if (result[currPair][n * 2] < result[currPair][n])
			std::swap(result[currPair][n], result[currPair][n * 2]);
	}

	debugResult(result, " /Sequence:  ", n);
	this->executeFirstHalf(n * 2);
}
