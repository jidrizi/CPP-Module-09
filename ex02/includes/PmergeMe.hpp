/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:59:40 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/15 15:01:57 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

// LIBRARIES
# include <string>
# include <iostream>


// CLASSES
class PmergeMe
{
	private:

	public:
	// Constructors
		PmergeMe();
		PmergeMe(PmergeMe& src);
		PmergeMe&	operator=(PmergeMe& src);
		~PmergeMe();
	
};

// FUNCTIONS

#endif