/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:28:49 by jidrizi           #+#    #+#             */
/*   Updated: 2026/02/05 03:48:39 by jidrizi          ###   ########.fr       */
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

void	PmergeMe::debugResult(std::vector < std::vector<int> > result, std::string s, unsigned long n)
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
	std::vector<int>				pair;
	unsigned long					currPair;

	pair.reserve(n / 2);
	currPair = 0;

	if (n == 2)
	{
		while (currPair < this->toBeSortedVector.size())
		{
			pair.push_back(toBeSortedVector[currPair++]);
			result.push_back(pair);
			pair.clear();
		}
		return (result);
	}
	else
	{
		while (currPair < result.size())
		{
			for (unsigned long	i = 0; i < result[currPair].size(); i++)
				pair.push_back(result[currPair][i]);
			currPair++;
			if (currPair < result.size())
			{
				for (unsigned long	i = 0; i < result[currPair].size(); i++)
					pair.push_back(result[currPair][i]);
			}
			currPair++;
			newResult.push_back(pair);
			pair.clear();
		}
		return (newResult);
	}
}

void	PmergeMe::executeFirstHalf(unsigned long n)
{
	static std::vector< std::vector<int> >	result;
	std::vector<int>						pair;

	if (n > this->toBeSortedVector.size())
	{
		this->firstHalfSequence = result;
		return ;
	}
	
	result = this->adjustContainer(result, n);

	for (unsigned long currPair = 0; currPair + 1 <= result.size() 
			&& result[currPair + 1].size() == (n / 2); currPair++)
	{
		if (currPair % 2 != 0)
			continue ;
		if (result[currPair].back() > result[currPair + 1].back())
			std::swap(result[currPair], result[currPair + 1]);
	}
		
	// debugResult(result, "Sequence: ", n);
	this->executeFirstHalf(n * 2);
	return ;
}


std::vector< std::vector<int> >	PmergeMe::adjustSequence(std::vector< std::vector<int> > sequence,
									unsigned long &n, unsigned long call)
{
	std::vector< std::vector<int> >	newSequence;
	std::vector<int> 				newPairVector;
	unsigned long					i;
	unsigned long					currPair;
	const unsigned long				pairSize = n / 2;

	if (call == 1)
	{
		unsigned long	currPair = 0;
		while (currPair < this->firstHalfSequence.size()currPair)
		{
			if (this->firstHalfSequence[currPair].size() != n / 2)
				break ;
			currPair++;
		}
		if (currPair > 2)
			return ;
	}
	
	newPairVector.reserve(pairSize / 2);
	currPair = 0;
	while (currPair < sequence.size())
	{
		i = 0;
		while (i < sequence[currPair].size() && i < pairSize / 2)
			newPairVector.push_back(sequence[currPair][i++]);
		newSequence.push_back(newPairVector);
		newPairVector.clear();

		while (i < sequence[currPair].size() && i < pairSize)
			newPairVector.push_back(sequence[currPair][i++]);
		newSequence.push_back(newPairVector);
		newPairVector.clear();

		currPair++;
	}
	
	n = n / 2;
	return (newSequence);
}


void	PmergeMe::executeSecondHalf(unsigned long call)
{
	unsigned long	n = this->firstHalfSequence[0].size() * 2;
	unsigned long pairSize = n / 2;
	if (n <= 2)
		return ;

	adjustSequence(this->firstHalfSequence, n, call);

	std::vector< std::vector<int> >	pendingChain;
	std::vector< std::vector<int> >	mainChain;
	mainChain.push_back(this->firstHalfSequence[0]);
	for (unsigned long currPair = 1;
			currPair < this->firstHalfSequence.size(); currPair++)
	{
		if (currPair % 2 == 0 || this->firstHalfSequence[currPair] != pairSize)
			pendingChain.push_back(this->firstHalfSequence[currPair]);
		else if (currPair % 2 != 0)
			mainChain.push_back(this->firstHalfSequence[currPair]);
	}

	for (unsigned long jacobNbr = jacobsthal(pendingChain.size()); jacobNbr != 0)
	{
		unsigned long	i = 0;
		while (pendingChain[jacobNbr - 2].size() == pairSize &&
			pendingChain[jacobNbr - 2].back() > mainChain[i].back())
			i++;
		if (pendingChain[jacobNbr - 2].size() == pairSize)
		{
			mainChain.insert(mainChain.begin() + i, pendingChain[jacobNbr - 2]);
			pendingChain.erase(pendingChain.begin() + (jacobNbr - 2));
		}
	}

	if (this->firstHalfSequence.size() % 2 != 0)
		mainChain.push_back(this->firstHalfSequence.back());
	this->firstHalfSequence = mainChain;
	executeSecondHalf(call + 1);

	return ; 
}
