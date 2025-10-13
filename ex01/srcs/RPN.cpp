/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:20:19 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/10 14:29:48 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Constructors
RPN::RPN()
{
	std::cout << "\033[32mRPN default constructor called.\033[0m" 
			<< std::endl;
}

RPN::RPN(RPN& src) :	rpnStack(src.rpnStack)
{
	std::cout << "\033[32mRPN copy constructor called.\033[0m" << std::endl;
}

RPN& RPN::operator=(RPN& src)
{
	std::cout << "\033[32mRPN copy assigment operator called.\033[0m" 
			<< std::endl;
	if (this != &src)
		this->rpnStack = src.rpnStack;
	return (*this);
}

RPN::~RPN()
{
	std::cout << "\033[32mRPN destructor called.\033[0m" << std::endl;
}


// Member functions

void	RPN::RecieveAndExecute()
{

}