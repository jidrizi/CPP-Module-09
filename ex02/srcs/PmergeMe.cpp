/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jidrizi <jidrizi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 16:28:49 by jidrizi           #+#    #+#             */
/*   Updated: 2025/12/20 04:37:50 by jidrizi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
static void printDebugs(T container, const std::string debug) {

  std::cout << "\n========================" << debug
            << "========================" << std::endl;
  for (auto it = container.begin(); it != container.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
}

static int jacobNumber(int n) {
  return std::round((std::pow(2, n + 1) + std::pow(-1, n)) / 3);
}

template <typename T>
static size_t findAofNIndex(const T container, size_t pendingValue, size_t n) {
  for (auto i = n - 1; i < container.size(); i += n) {
    if (pendingValue == container[i]) {
      return container[i - n];
    }
  }
  return 0;
}

template <typename T>
static size_t
checkDistanceOfAofNplusOne(const T container, size_t bounds, size_t n,
                           const std::vector<unsigned long> main) {
  size_t temp = 0;
  for (auto i = n - 1; i < container.size(); i += n) {
    if (bounds == container[i] && i + 2 * n < container.size()) {
      temp = container[i + 2 * n];
    }
  }
  if (temp == 0) {
    return 0;
  }

  for (size_t i = n - 1; i < main.size(); i += n) {
    if (i + n >= main.size()) {
      return 0;
    }
    if (main[i] == bounds && temp != main[i + n]) {
      return temp;
    }
  }

  return 0;
}

template <typename T> static void jacob(T &container, unsigned long n) {

  if (n > container.size()) {
    return;
  }

  if (n != 1) {
    auto containerParticipants = container.size() - container.size() % n;
    for (size_t i = n - 1; i < containerParticipants; i += n) {
      size_t offset = n / 2;
      assert(i >= offset);
      if (i % n == n - 1 && container[i - offset] > container[i]) {

        for (size_t temp = i; temp > i - offset; --temp) {
          assert(temp < container.size());
          assert(temp - offset < container.size());
          std::swap(container[temp], container[temp - offset]);

          if (temp == offset)
            break;
        }
      }
    }
  }

  n = n << 1;

  jacob(container, n);

  if (n > container.size()) {
    return;
  }

  n = n >> 1;
  int jacobIndex = 2;
  int Jnum = jacobNumber(jacobIndex);

  std::vector<unsigned long> main;
  std::vector<unsigned long> pending;


  bool stop = false;
  unsigned long j = 0;

  while (j < n * 2 && j < container.size()) {
    main.push_back(container[j++]);
  }

  size_t partisipating = container.size() - (container.size() % n);
  assert(partisipating <= container.size());
  while (j < partisipating) {
    for (size_t k = 0; k < n && j < partisipating; ++k, ++j) {
      if (stop) {
        main.push_back(container[j]);
      } else {
        pending.push_back(container[j]);
      }
    }
    stop = !stop;
  }


  int counter = 1;
  size_t startingBounds = n - 1;
  size_t endingBounds;
  size_t comparingIndex;

  while (pending.size() != 0) {

    size_t jprev = Jnum;
    long int temp = (Jnum - counter) * n - 1;
    if (temp < 0) {
      counter = jprev;
      Jnum = jacobNumber(++jacobIndex);
      comparingIndex = (Jnum - counter) * n - 1;

      while (comparingIndex >= pending.size()) {
        counter++;
        comparingIndex = (Jnum - counter) * n - 1;
      }

    } else {
      comparingIndex = temp;
      while (comparingIndex >= pending.size()) {
        comparingIndex--;
      }
    }

    assert(comparingIndex < pending.size());
    endingBounds = findAofNIndex(container, pending[comparingIndex], n);

    for (size_t k = startingBounds; k <= main.size(); k += n) {

      if (comparingIndex >= pending.size() || pending.size() == 0) {
        break;
      }

      auto posForInsert = main.begin() + k - n + 1;
      auto groupStartingPos = pending.begin() + comparingIndex - n + 1;
      auto groupLastPos = pending.begin() + comparingIndex + 1;
      auto posForInsertAfterBounds = main.begin() + k + 1;
      auto ofsetOfBounds =
          checkDistanceOfAofNplusOne(container, endingBounds, n, main);
      if (ofsetOfBounds != 0) {
        endingBounds = ofsetOfBounds;

      }

      if (pending[comparingIndex] < main[k]) {

        if (n != 1) {
          main.insert(posForInsert, groupStartingPos, groupLastPos);
          pending.erase(groupStartingPos, groupLastPos);
        } else {
          main.insert(posForInsert, pending[comparingIndex]);
          pending.erase(pending.begin() + comparingIndex);
        }

        break;

      } else if (main[k] == endingBounds) {
        if (n != 1) {
          main.insert(posForInsertAfterBounds, groupStartingPos, groupLastPos);
          pending.erase(groupStartingPos, groupLastPos);
        } else {
          main.insert(posForInsertAfterBounds, endingBounds);
          pending.erase(pending.begin() + comparingIndex);
        }

        break;
      }

    }
    counter++;
  }

  int nonPartisipating = container.size() % n;
  if (n != 1 || nonPartisipating != 0) {
    while (nonPartisipating--) {
      main.push_back(container[container.size() - nonPartisipating - 1]);
    }
  }

  container.clear();
  container.insert(container.end(), main.begin(), main.end());
  main.clear();
  pending.clear();

}




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