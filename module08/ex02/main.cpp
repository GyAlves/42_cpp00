/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 00:00:00 by gyasminalve       #+#    #+#             */
/*   Updated: 2026/03/27 00:00:00 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main(void)
{
    std::cout << "Test with MutantStack:" << std::endl;

    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);

    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size after pop: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it  = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;

    std::cout << "Elements: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    std::cout << "\nTest with std::list (for comparison):" << std::endl;

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);

    std::cout << "Back: " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "Size after pop: " << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator lit  = lst.begin();
    std::list<int>::iterator lite = lst.end();
    ++lit;
    --lit;

    std::cout << "Elements: ";
    while (lit != lite)
    {
        std::cout << *lit << " ";
        ++lit;
    }
    std::cout << std::endl;

    std::cout << "\nTest copy constructor:" << std::endl;

    MutantStack<int> mstack2(mstack);
    std::cout << "Copied stack elements: ";
    for (MutantStack<int>::iterator it2 = mstack2.begin(); it2 != mstack2.end(); ++it2)
        std::cout << *it2 << " ";
    std::cout << std::endl;

    std::cout << "\nTest with strings:" << std::endl;

    MutantStack<std::string> strStack;
    strStack.push("Hello");
    strStack.push("World");
    strStack.push("!");

    std::cout << "String stack: ";
    for (MutantStack<std::string>::iterator sit = strStack.begin(); sit != strStack.end(); ++sit)
        std::cout << *sit << " ";
    std::cout << std::endl;

    return 0;
}
