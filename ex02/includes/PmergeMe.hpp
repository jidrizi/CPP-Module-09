/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:59:40 by jidrizi           #+#    #+#             */
/*   Updated: 2026/01/31 20:07:48 by jidrizi          ###   ########.fr       */
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
# include <deque>
# include <type_traits>
# include <cctype>
# include <chrono>
# include <ratio>
# include <string>
# include <algorithm>
# include <cassert>
# include <cmath>
# include <cstddef>
# include <utility>
# include <vector>
# include <sstream>
# include <iostream>
# include <climits>
# include <cstring>
# include <ctime>

//CLASSES
class PmergeMe
{
	private:
		// Only created 'name' because I think we are required to make a 
		// constructor with a parameter...
		std::string						name; 
		
		std::vector<int>				toBeSortedVector;
		std::deque<int>					toBeSortedDeque;
		std::vector< std::vector<int> >	firstHalfSequence;


	public:
		// Constructors
		PmergeMe();
		PmergeMe(std::string	nameParameter);
		PmergeMe(PmergeMe &src);
		PmergeMe	operator=(PmergeMe &src);
		~PmergeMe();

		// Member functions
		void							getAndPushNumbers(char **argv);
		void							printContainerElements(std::string msg);
		std::vector< std::vector<int> > adjustContainer(std::vector < std::vector<int> > result,
											unsigned long n);
		std::vector<int>				adjustResult(std::vector < std::vector<int> > result);
		std::vector< std::vector<int> >	adjustSequence(std::vector< std::vector<int> > sequence,
											unsigned long &n);
		void							firstCall(std::vector< std::vector<int> >	&pendingChain,
											std::vector< std::vector<int> >	&mainChain,
											unsigned long &n);
		unsigned long					jacobsthal(unsigned long call);
		void							executeFirstHalf(unsigned long n);
		void							executeSecondHalf(unsigned long jacobNbr);
		void	debugResult(std::vector < std::vector<int> > result, std::string s, unsigned long n);
};

//PROTOTYPES
int	errorMsg(std::string msgStr);
int	findArgQuantity(char **argv);



#endif