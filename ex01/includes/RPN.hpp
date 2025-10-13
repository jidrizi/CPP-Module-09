/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:10:38 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/13 15:35:30 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

// MACROS
# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif

# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif

// LIBRARIES
# include <string>
# include <iostream>
# include <stack>

// CLASSES

class RPN
{
	private:
		int				numAmountInStack;
		std::stack<int>	rpnStack;
	public:
		// Constructors
		RPN();
		RPN(RPN& src);
		RPN&	operator=(RPN& src);
		~RPN();

		// Members
		void	RPN::RecieveAndExecute(char* argv1);

};

// FUNCTIONS
bool	isNum(char	c);


#endif