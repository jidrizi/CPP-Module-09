/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:28:49 by jidrizi           #+#    #+#             */
/*   Updated: 2025/12/20 04:25:23 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


template <>
void pMerge::merge<std::vector<unsigned long>>(std::vector<unsigned long> container) 
{
  std::cout << "Sorting a vector container of size: " << container.size()
            << std::endl;
  printDebugs(container, "BEGIN");
  jacob(container, 1);
  printDebugs(container, "END");
  std::cout << std::boolalpha << "Is the container sorted: "
            << std::is_sorted(container.begin(), container.end()) << std::endl;
}

template <>
void pMerge::merge<std::deque<unsigned long>>(std::deque<unsigned long> container) 
{
  std::cout << "\n\nSorting a deque container of size: " << container.size()
            << std::endl;
  printDebugs(container, "BEGIN");
  jacob(container, 1);
  printDebugs(container, "END");
  std::cout << std::boolalpha << "Is the container sorted: "
            << std::is_sorted(container.begin(), container.end()) << std::endl;
}