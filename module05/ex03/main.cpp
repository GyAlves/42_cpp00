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
#include "headers/Intern.hpp"
int main() {
    Intern someRandomIntern;
    std::cout << "========== INTERN TESTS ==========" << std::endl;
    std::cout << "\n=== Test 1: Create ShrubberyCreationForm ===" << std::endl;
    {
        AForm* form = someRandomIntern.makeForm("shrubbery creation", "garden");
        if (form)
        {
            std::cout << *form << std::endl;
            Bureaucrat bob;
            bob.setName("Bob");
            bob.setGrade(130);
            bob.signForm(*form);
            bob.executeForm(*form);
            delete form;
        }
    }
    std::cout << "\n=== Test 2: Create RobotomyRequestForm ===" << std::endl;
    {
        AForm* form = someRandomIntern.makeForm("robotomy request", "Bender");
        if (form)
        {
            std::cout << *form << std::endl;
            Bureaucrat alice;
            alice.setName("Alice");
            alice.setGrade(40);
            alice.signForm(*form);
            alice.executeForm(*form);
            delete form;
        }
    }
    std::cout << "\n=== Test 3: Create PresidentialPardonForm ===" << std::endl;
    {
        AForm* form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
        if (form)
        {
            std::cout << *form << std::endl;
            Bureaucrat president;
            president.setName("President");
            president.setGrade(1);
            president.signForm(*form);
            president.executeForm(*form);
            delete form;
        }
    }
    std::cout << "\n=== Test 4: Create unknown form ===" << std::endl;
    {
        AForm* form = someRandomIntern.makeForm("unknown form", "target");
        if (form)
        {
            std::cout << *form << std::endl;
            delete form;
        }
        else
        {
            std::cout << "Form creation failed (as expected)" << std::endl;
        }
    }
    std::cout << "\n=== Test 5: Create form and fail to sign (grade too low) ===" << std::endl;
    {
        AForm* form = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
        if (form)
        {
            std::cout << *form << std::endl;
            Bureaucrat lowGrade;
            lowGrade.setName("LowGrade");
            lowGrade.setGrade(50);
            lowGrade.signForm(*form);
            delete form;
        }
    }
    return 0;
}
