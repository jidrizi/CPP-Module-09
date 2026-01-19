/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:28:49 by jidrizi           #+#    #+#             */
/*   Updated: 2026/01/19 03:53:17 by jidrizi          ###   ########.fr       */
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

	newPair.reserve(n);
	currPair = 0;

	while (currPair + 1 < result.size())
	{
		for (unsigned long	i = 0; i < result[currPair].size(); i++)
			newPair.push_back(result[currPair][i]);
		currPair++;
		for (unsigned long	i = 0; i < result[currPair].size(); i++)
			newPair.push_back(result[currPair][i]);
		currPair++;
		newResult.push_back(newPair);
		newPair.clear();
	}

	return (newResult);
}

std::vector<int>	PmergeMe::adjustResult(std::vector < std::vector<int> > result)
{
	std::vector<int>	adjustedRes;
	adjustedRes.reserve(result.size());
	
	
	unsigned long	x = 0;
	while (x < result.size())
	{
		unsigned long	y = 0;
		while (y < result[x].size())
		{
			adjustedRes.push_back(result[x][y]);
			y++;
		}
		x++;
	}

	return(adjustedRes);
}


void	PmergeMe::executeFirstHalf(unsigned long n)
{
	static std::vector< std::vector<int> >	result;

	if (n  * 2 > this->toBeSortedVector.size())
	{
		this->toBeSortedVector = adjustResult(result);
		return ;
	}
	
	if (n == 1)
	{
		std::vector<int>	pair;
		for (unsigned long i = 0; i < this->toBeSortedVector.size(); i++)
		{
			pair.push_back(toBeSortedVector[i]);
			result.push_back(pair);
			pair.clear();
		}
	}
	else
		result = this->adjustContainer(result, n);

	for (unsigned long i = 0; (i + 1) < result.size(); i += 2)
	{
		if (result[i + 1].back() < result[i].back())
			std::swap(result[i], result[i + 1]);
	}

	debugResult(result, " /Sequence:  ", n);
	this->executeFirstHalf(n * 2);
}
	

	// for (int	i = 0; i + 1 < result.size(); i++)
	// {
	// 	if (result[i].back() > result[i + 1].back())
	// 		std::swap(result[i], result[i + 1]);
	// }
	