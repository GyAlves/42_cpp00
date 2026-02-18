/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:40:00 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/12 01:40:00 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Bureaucrat.hpp"
#include "../headers/Form.hpp"

Bureaucrat::Bureaucrat()
{
    this->name = "";
    this->grade = 1;
    std::cout << "A bureaucrat has been born!" << std::endl;
}

Bureaucrat:: Bureaucrat(const Bureaucrat &other)
{
    this->name = other.name;
    this->grade = other.grade;
    std::cout << "A bureaucrat has been copied!" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    this->name = other.name;
    this->grade = other.grade;
    std::cout << "A bureaucrat has been assigned!" << std::endl;
    return (*this);
};

Bureaucrat:: ~Bureaucrat()
{
    std::cout << "A bureaucrat has been destroyed!" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return (this->name);
}

int Bureaucrat::getGrade() const
{
    return (this->grade);
}

void Bureaucrat::incrementGrade()
{
    if (this->grade == 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->grade == 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

void Bureaucrat::setName(std::string name)
{
    this->name = name;
}

void Bureaucrat::setGrade(int grade)
{
    this->grade = grade;
}
void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &error)
    {
        std::cout << this->name << " couldn't sign " << form.getName()
                  << " because " << error.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return (out);
}
