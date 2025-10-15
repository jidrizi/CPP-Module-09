/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:20:19 by jidrizi           #+#    #+#             */
/*   Updated: 2025/10/15 14:43:23 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

// Constructors

RPN::RPN() : numAmountInStack(0)
{
	std::cout << "\033[32mRPN default constructor called.\033[0m" 
			<< std::endl;
}

RPN::RPN(RPN& src) : numAmountInStack(src.numAmountInStack) , rpnStack(src.rpnStack)
{
	std::cout << "\033[32mRPN copy constructor called.\033[0m" << std::endl;
}

RPN& RPN::operator=(RPN& src)
{
	std::cout << "\033[32mRPN copy assigment operator called.\033[0m" 
			<< std::endl;
	if (this != &src)
	{
		this->numAmountInStack = src.numAmountInStack;
		this->rpnStack = src.rpnStack;
	}
	return (*this);
}

RPN::~RPN()
{
	std::cout << "\033[32mRPN destructor called.\033[0m" << std::endl;
}


// Member functions

void	RPN::receive(char numChar)
{
	int	numInt = numChar - '0';
	this->rpnStack.push(numInt);
	this->numAmountInStack++;
}

void	RPN::execute(char operand)
{
	int	result = 0;

	int	second = this->rpnStack.top();
	this->rpnStack.pop();
	int	first = this->rpnStack.top();
	this->rpnStack.pop();
	
	if (operand == '*')
		result = first * second;
	else if (operand == '/')
		result = first / second;
	else if (operand == '+')
		result = first + second;
	else if (operand == '-')
		result = first - second;

	this->rpnStack.push(result);
}

int		RPN::receiveAndExecute(char* givenEquasion)
{
	int	i = 0;

	while (givenEquasion[i])
	{
		while (givenEquasion[i] && givenEquasion[i] == ' ')
			i++;

		if (givenEquasion[i] && isOperand(givenEquasion[i]) == true && this->numAmountInStack < 2)
			return (std::cerr << "Error: notation is not correct\n", EXIT_FAILURE);
		else if (givenEquasion[i] && isOperand(givenEquasion[i]) == true && this->numAmountInStack >= 2)
			this->execute(givenEquasion[i]);
		else if (givenEquasion[i] && isOperand(givenEquasion[i]) == false)
			this->receive(givenEquasion[i]);
		i++;
	}

	std::cout << this->rpnStack.top() << std::endl;
	return (EXIT_SUCCESS);
}