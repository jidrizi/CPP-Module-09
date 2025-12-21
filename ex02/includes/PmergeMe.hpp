/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:59:40 by jidrizi           #+#    #+#             */
/*   Updated: 2025/12/21 02:52:09 by jidrizi          ###   ########.fr       */
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


// CLASSES
class PmergeMe
{
	private:
		// constructors
		PmergeMe() = delete;
		~PmergeMe() = delete;
		PmergeMe(int container) = delete;
		PmergeMe(const PmergeMe &src) = delete;
		PmergeMe	&operator=(const PmergeMe &src) = delete;
	
	public:
		template <typename T>
  		static typename std::enable_if<
		std::is_same<T, std::vector<unsigned long>>::value ||
			std::is_same<T, std::deque<unsigned long>>::value,
		void>::type
		executeMerge(T container);
};

// FUNCTIONS


#endif