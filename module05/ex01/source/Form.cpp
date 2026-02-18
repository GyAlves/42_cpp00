/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:40:00 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/12 01:40:00 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Form.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), isSigned(false)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), isSigned(other.isSigned)
{
}

Form& Form::operator=(const Form& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return (*this);
}

Form::~Form()
{
    std::cout << "A form has been destroyed!" << std::endl;
}

const std::string Form::getName() const
{
    return (this->name);
}

int Form::getGradeToSign() const
{
    return (this->gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (this->gradeToExecute);
}

bool Form::getIsSigned() const
{
    return (this->isSigned);
}

void Form::setName(const std::string name)
{
    (void)name;
}

void Form::setGradeToSign(const int gradeToSign)
{
    (void)gradeToSign;
}

void Form::setGradeToExecute(const int gradeToExecute)
{
    (void)gradeToExecute;
}

void Form::setIsSigned(bool isSigned)
{
    this->isSigned = isSigned;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw GradeTooLowException();
    this->isSigned = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form: " << form.getName()
       << ", Grade to sign: " << form.getGradeToSign()
       << ", Grade to execute: " << form.getGradeToExecute()
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No");
    return (os);
}
