/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:59:40 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/19 18:09:34 by jidrizi          ###   ########.fr       */
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
# include <ctime>


// CLASSES
class PmergeMe
{
	private:
		std::vector<int>	SortingVector;
		std::deque<int>		SortingDeque;
		
	public:
	// Constructors
		PmergeMe();
		PmergeMe(PmergeMe& src);
		PmergeMe&	operator=(PmergeMe& src);
		~PmergeMe();
	
};

// FUNCTIONS

#endif