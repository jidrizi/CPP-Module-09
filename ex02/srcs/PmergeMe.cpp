/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:28:49 by jidrizi           #+#    #+#             */
/*   Updated: 2025/12/21 16:31:56 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructors
PmergeMe::PmergeMe() : name("Default")
{
	std::cout << "Default PmergeMe constructor called" << std::endl;
}

PmergeMe::PmergeMe(std::string nameParameter)
{
	std::cout << "PmergeMe constructor with parameters called" << std::endl;
	this->name = nameParameter;
}

PmergeMe::PmergeMe(PmergeMe const &src)
	: name(src.name), sortingVector(src.sortingVector), sortingDeque(src.sortingDeque)
{
	std::cout << "PmergeMe copy constructor called" << std::endl;
}

PmergeMe::PmergeMe&	operator=(PmergeMe &src)
{
	std::cout << "PmergeMe copy assigment operator called" << std::endl;

	if (*this != src)
	{
		this->name = src.name;
		this->sortingVector = src.sortingVector;
		this->sortingDeque = src.sortingDeque;
	}
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe destructor called" << std::endl;
}



// Member functions