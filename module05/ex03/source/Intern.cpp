/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:40:00 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/12 01:40:00 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/Intern.hpp"
Intern::Intern()
{
}
Intern::Intern(const Intern& other)
{
    (void)other;
}
Intern& Intern::operator=(const Intern& other)
{
    (void)other;
    return (*this);
}
Intern::~Intern()
{
}
AForm* Intern::createShrubberyForm(const std::string& target)
{
    return (new ShrubberyCreationForm(target));
}
AForm* Intern::createRobotomyForm(const std::string& target)
{
    return (new RobotomyRequestForm(target));
}
AForm* Intern::createPresidentialForm(const std::string& target)
{
    return (new PresidentialPardonForm(target));
}
AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm* (Intern::*formCreators[3])(const std::string&) = {
        &Intern::createShrubberyForm,
        &Intern::createRobotomyForm,
        &Intern::createPresidentialForm
    };
    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << std::endl;
            return ((this->*formCreators[i])(target));
        }
    }
    std::cout << "Intern cannot create form: " << formName << " (unknown form type)" << std::endl;
    return (NULL);
}
