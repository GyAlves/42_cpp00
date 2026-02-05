/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:40:00 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/12 01:40:00 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Bureaucrat.hpp"

int main() {

    std::cout << "=== Test 1: Create and print ===" << std::endl;
    try {
        Bureaucrat b;
        b.setName("Alice");
        b.setGrade(50);
        std::cout << b << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: Increment to grade 1 ===" << std::endl;
    try {
        Bureaucrat b2;
        b2.setName("Bob");
        b2.setGrade(1);
        std::cout << b2 << std::endl;
        b2.incrementGrade();
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: Decrement to grade 150 ===" << std::endl;
    try {
        Bureaucrat b3;
        b3.setName("Charlie");
        b3.setGrade(150);
        std::cout << b3 << std::endl;
        b3.decrementGrade();
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Normal operations ===" << std::endl;
    try {
        Bureaucrat b4;
        b4.setName("Diana");
        b4.setGrade(75);
        std::cout << "Before: " << b4 << std::endl;
        b4.incrementGrade();
        std::cout << "After increment: " << b4 << std::endl;
        b4.decrementGrade();
        std::cout << "After decrement: " << b4 << std::endl;
    } catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
