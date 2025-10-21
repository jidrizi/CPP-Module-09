/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:59:40 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/21 15:58:56 by jidrizi          ###   ########.fr       */
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
		std::vector<int>	sortingVector;
		std::deque<int>		sortingDeque;
		
	public:
	// Constructors
		PmergeMe();
		PmergeMe(PmergeMe& src);
		PmergeMe&	operator=(PmergeMe& src);
		~PmergeMe();
	// Members
		void	getVectorElements(std::vector<int>& container, char** argv);
		void	executeVectorSort(char** argv);
		void	executeDequeSort(char** argv);
	
};

// FUNCTIONS

#endif