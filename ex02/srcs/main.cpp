/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:28:08 by jidrizi           #+#    #+#             */
/*   Updated: 2025/12/20 04:25:20 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"



int	main(int argc, char** argv)
{
	if (argc < 4)
		return (error_msg("More than 3 arguments required to run program."));	

	std::vector< unsigned long >	vec;
	std::deque< unsigned long >		deq;
	std::vector< std::string >		arguments;

	for (int i = 1; arguments[i]; ++i)
		argv.push_back(av[i]);
	for (auto it = argv.begin(); it != argv.end(); ++it)
	{
		if (!std::all_of(it->begin, it->end(), ::isdigit))
			return (error_msg("Only digits are accepted."));
	}
	try
	{
		vec.push_back(std::stoul(*it));
		vec.push_back(std::stoul(*it));
	}
	catch (...)
	{
		return (error_msg("Numbers exeeds unsigned long."));
	}
	if (hasDuplicates(vec))
		return (error_msg("Duplicates are not allowed"));

		
	auto vecStartTime = std::chrono::high_resolution_clock::now();
	pMerge::executeMerge(vec);
	auto vecEndTime = std::chrono::high_resolution_clock::now();
	auto vecTime =
		std::chrono::duration<double, std::micro>(vecEndTime - vecStartTime);
	std::cout << "The time that it took the vector container is: "
			<< vectorTime.count() << " microseconds." << std::endl;

	auto deqStartTime = std::chrono::high_resolution_clock::now();
	pMerge::executeMerge(deq);
	auto deqEndTime = std::chrono::high_resolution_clock::now();
	auto deqTime =
		std::chrono::duration<double, std::micro>(deqEndTime - deqStartTime);
	std::cout << "The time that it took the deque container is: "
			<< vectorTime.count() << " microseconds." << std::endl;

			
	return (EXIT_SUCCESS);
}
