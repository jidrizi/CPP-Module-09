/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:59:40 by jidrizi           #+#    #+#             */
/*   Updated: 2025/12/21 15:56:09 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

// MACROS
# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif

# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif

// LIBRARIES
#include <deque>
#include <type_traits>
#include <vector>
#include <algorithm>
#include <cctype>
#include <chrono>
#include <iostream>
#include <ratio>
#include <string>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

//CLASSES
class PmergeMe
{
	private:
	// Constructors
		PmergeMe() = delete;
		PmergeMe(int n) = delete;
		PmergeMe(PmergeMe const &src)  = delete;
		PmergeMe	operator=(PmergeMe const &src) = delete;
		~PmergeMe() = delete;

	public:
		
}