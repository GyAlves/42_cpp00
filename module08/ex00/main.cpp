#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main(void) {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    vec.push_back(5);
    std::cout << "Vector: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    try {
        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Found 3 in vector: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::vector<int>::iterator it = easyfind(vec, 10);
        std::cout << "Found 10 in vector: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "10 not found: " << e.what() << std::endl;
    }
    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);
    lst.push_back(40);
    std::cout << "\nList: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    try {
        std::list<int>::iterator it = easyfind(lst, 20);
        std::cout << "Found 20 in list: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        std::list<int>::iterator it = easyfind(lst, 100);
        std::cout << "Found 100 in list: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << "100 not found: " << e.what() << std::endl;
    }
    std::deque<int> deq;
    deq.push_back(5);
    deq.push_back(15);
    deq.push_back(25);
    std::cout << "\nDeque: ";
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    try {
        std::deque<int>::iterator it = easyfind(deq, 15);
        std::cout << "Found 15 in deque: " << *it << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
