/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:59:40 by jidrizi           #+#    #+#             */
/*   Updated: 2025/12/21 16:32:07 by jidrizi          ###   ########.fr       */
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
		// Only created 'name' because I think we are required to make a 
		// constructor with a parameter...
		std::string			name; 
		
		std::vector<int>	sortingVector;
		std::deque<int>		sortingDeque;


	public:
		// Constructors
		PmergeMe();
		PmergeMe(std::string	nameParameter);
		PmergeMe(PmergeMe const &src);
		PmergeMe	operator=(PmergeMe const &src);
		~PmergeMe();

		// Member functions
		void	getAndPushNumbers();
		void	executeAlgorithm(int n);
};

//PROTOTYPES
int	error_msg(std::string error_str);

#endif