/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:28:49 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/19 18:10:48 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructors

PmergeMe::PmergeMe()
{
	std::cout << "Default PmergeMe constructor called" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe& src) : SortingVector(src.SortingVector), SortingDeque(src.SortingDeque)
{
	std::cout << "Copy PmergeMe constructor called" << std::endl;
}

PmergeMe& PmergeMe::operator=(PmergeMe& src)
{
	std::cout << "Copy PmergeMe assigment operator called" << std::endl;
	if (this != &src)
	{
		this->SortingVector = src.SortingVector;
		this->SortingDeque = src.SortingDeque;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeMe destructor called" << std::endl;
}

// Functions

