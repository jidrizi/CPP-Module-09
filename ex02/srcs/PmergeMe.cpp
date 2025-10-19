/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:28:49 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/18 06:37:53 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Constructors

PmergeMe::PmergeMe()
{
	std::cout << "Default PmergeMe constructor called" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe& src)
{
	std::cout << "Copy PmergeMe constructor called" << std::endl;
}

PmergeMe& operator=(PmergeMe& src)
{
	std::cout << "Copy PmergeMe assigment operator called" << std::endl;
	return (*this)
}

PmergeMe::~PmergeMe()
{
	std::cout << "PmergeME destructor called" << std::endl;
}

// Functions

