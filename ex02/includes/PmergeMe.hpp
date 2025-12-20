/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:59:40 by jidrizi           #+#    #+#             */
/*   Updated: 2025/12/20 04:31:24 by jidrizi          ###   ########.fr       */
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
# include <vector>
# include <deque>
# include <string>
# include <sstream>
# include <iostream>
# include <utility>
# include <algorithm>
# include <climits>
# include <cstring>
# include <ctime>


// CLASSES
class PmergeMe
{
	private:
		// constructors
		PmergeMe() = delete;
		~PmergeMe() = delete;
		PmergeMe(int container) = delete;
		pMerge(const PmergeMe &src) = delete;
		PmergeMe	&operator=(const PmergeMe &src) = delete;
	
	public:
		template <typename T>
  		static typename std::enable_if<
		std::is_same<T, std::vector<unsigned long>>::value ||
			std::is_same<T, std::deque<unsigned long>>::value,
		void>::type
		exuciteMerge(T container);
}

// FUNCTIONS


#endif