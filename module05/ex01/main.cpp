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
#include "headers/Form.hpp"

int main() {
    std::cout << "========== BUREAUCRAT TESTS ==========" << std::endl;
    std::cout << "\n=== Test 1: Create and print ===" << std::endl;
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
    std::cout << "\n========== FORM TESTS ==========" << std::endl;
    std::cout << "\n=== Test 5: Create valid Form ===" << std::endl;
    try {
        Form f1("Tax Form", 50, 25);
        std::cout << f1 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== Test 6: Create Form with grade too high (0) ===" << std::endl;
    try {
        Form f2("Invalid Form", 0, 25);
        std::cout << f2 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== Test 7: Create Form with grade too low (151) ===" << std::endl;
    try {
        Form f3("Invalid Form", 50, 151);
        std::cout << f3 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== Test 8: Bureaucrat signs Form successfully ===" << std::endl;
    try {
        Bureaucrat b5;
        b5.setName("Eve");
        b5.setGrade(30);
        Form f4("Contract", 50, 25);
        std::cout << "Before: " << f4 << std::endl;
        b5.signForm(f4);
        std::cout << "After: " << f4 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== Test 9: Bureaucrat fails to sign Form (grade too low) ===" << std::endl;
    try {
        Bureaucrat b6;
        b6.setName("Frank");
        b6.setGrade(100);
        Form f5("Top Secret", 50, 25);
        std::cout << "Bureaucrat: " << b6 << std::endl;
        std::cout << "Form: " << f5 << std::endl;
        b6.signForm(f5);
        std::cout << "After attempt: " << f5 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== Test 10: Form copy constructor ===" << std::endl;
    try {
        Form original("Original Form", 75, 50);
        Form copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== Test 11: Bureaucrat with exact required grade ===" << std::endl;
    try {
        Bureaucrat b7;
        b7.setName("Grace");
        b7.setGrade(50);
        Form f6("Exact Match Form", 50, 25);
        std::cout << "Bureaucrat: " << b7 << std::endl;
        std::cout << "Form requires grade: " << f6.getGradeToSign() << std::endl;
        b7.signForm(f6);
        std::cout << "Result: " << f6 << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
