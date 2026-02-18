/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 01:40:00 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/12 01:40:00 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../headers/AForm.hpp"
AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
    : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), isSigned(false)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}
AForm::AForm(const AForm& other)
    : name(other.name), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute), isSigned(other.isSigned)
{
}
AForm& AForm::operator=(const AForm& other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return (*this);
}
AForm::~AForm()
{
}
const std::string AForm::getName() const
{
    return (this->name);
}
int AForm::getGradeToSign() const
{
    return (this->gradeToSign);
}
int AForm::getGradeToExecute() const
{
    return (this->gradeToExecute);
}
bool AForm::getIsSigned() const
{
    return (this->isSigned);
}
void AForm::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeToSign)
        throw GradeTooLowException();
    this->isSigned = true;
}
void AForm::execute(Bureaucrat const & executor) const
{
    if (!this->isSigned)
        throw FormNotSignedException();
    if (executor.getGrade() > this->gradeToExecute)
        throw GradeTooLowException();
    this->executeAction();
}
std::ostream &operator<<(std::ostream &os, const AForm &form)
{
    os << "Form: " << form.getName()
       << ", Grade to sign: " << form.getGradeToSign()
       << ", Grade to execute: " << form.getGradeToExecute()
       << ", Signed: " << (form.getIsSigned() ? "Yes" : "No");
    return (os);
}
