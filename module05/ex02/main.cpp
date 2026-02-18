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
#include "headers/ShrubberyCreationForm.hpp"
#include "headers/RobotomyRequestForm.hpp"
#include "headers/PresidentialPardonForm.hpp"
int main() {
    std::cout << "========== SHRUBBERY CREATION FORM TESTS ==========" << std::endl;
    std::cout << "\n=== Test 1: ShrubberyCreationForm - Success ===" << std::endl;
    try {
        Bureaucrat bob;
        bob.setName("Bob");
        bob.setGrade(130);
        ShrubberyCreationForm shrub("home");
        std::cout << bob << std::endl;
        std::cout << shrub << std::endl;
        bob.signForm(shrub);
        bob.executeForm(shrub);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== Test 2: ShrubberyCreationForm - Not signed ===" << std::endl;
    try {
        Bureaucrat alice;
        alice.setName("Alice");
        alice.setGrade(130);
        ShrubberyCreationForm shrub2("garden");
        alice.executeForm(shrub2);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== Test 3: ShrubberyCreationForm - Grade too low to execute ===" << std::endl;
    try {
        Bureaucrat lowGrade;
        lowGrade.setName("LowGrade");
        lowGrade.setGrade(140);
        Bureaucrat highGrade;
        highGrade.setName("HighGrade");
        highGrade.setGrade(100);
        ShrubberyCreationForm shrub3("office");
        highGrade.signForm(shrub3);
        lowGrade.executeForm(shrub3);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n========== ROBOTOMY REQUEST FORM TESTS ==========" << std::endl;
    std::cout << "\n=== Test 4: RobotomyRequestForm - Success ===" << std::endl;
    try {
        Bureaucrat charlie;
        charlie.setName("Charlie");
        charlie.setGrade(40);
        RobotomyRequestForm robo("Bender");
        std::cout << charlie << std::endl;
        std::cout << robo << std::endl;
        charlie.signForm(robo);
        charlie.executeForm(robo);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== Test 5: RobotomyRequestForm - Grade too low to sign ===" << std::endl;
    try {
        Bureaucrat diana;
        diana.setName("Diana");
        diana.setGrade(80);
        RobotomyRequestForm robo2("Robot");
        diana.signForm(robo2);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n========== PRESIDENTIAL PARDON FORM TESTS ==========" << std::endl;
    std::cout << "\n=== Test 6: PresidentialPardonForm - Success ===" << std::endl;
    try {
        Bureaucrat president;
        president.setName("President");
        president.setGrade(1);
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << president << std::endl;
        std::cout << pardon << std::endl;
        president.signForm(pardon);
        president.executeForm(pardon);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== Test 7: PresidentialPardonForm - Grade too low ===" << std::endl;
    try {
        Bureaucrat eve;
        eve.setName("Eve");
        eve.setGrade(30);
        PresidentialPardonForm pardon2("Ford Prefect");
        eve.signForm(pardon2);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    std::cout << "\n=== Test 8: PresidentialPardonForm - Signed but grade too low to execute ===" << std::endl;
    try {
        Bureaucrat signer;
        signer.setName("Signer");
        signer.setGrade(20);
        Bureaucrat executor;
        executor.setName("Executor");
        executor.setGrade(10);
        PresidentialPardonForm pardon3("Marvin");
        signer.signForm(pardon3);
        executor.executeForm(pardon3);
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
