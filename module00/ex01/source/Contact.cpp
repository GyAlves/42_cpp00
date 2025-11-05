/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:03:22 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/11/02 19:21:52 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../headers/Contact.hpp"

Contact::Contact()
{
    firstName = "";
    lastName = "";
    nickname = "";
    phoneNumber = "";
    darkestSecret = "";
}

Contact::~Contact()
{
    
}

void Contact::setFirstName(std::string FirstName)
{
    firstName = FirstName;
}

void Contact::setLastName(std::string LastName)
{
    lastName = LastName;
}

void Contact::setNickname(std::string Nickname)
{
    nickname = Nickname;
}

void Contact::setPhoneNumber(std::string PhoneNumber)
{
    phoneNumber = PhoneNumber;
}
void Contact::setDarkestSecret(std::string DarkestSecret)
{
    darkestSecret = DarkestSecret;
}

std::string Contact::getFirstName() const
{
    return firstName;
}

std::string Contact::getLastName() const
{
    return lastName;
}

std::string Contact::getNickname() const
{
    return nickname;
}

std::string Contact::getPhoneNumber() const
{
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return darkestSecret;
}

std::string Contact::readNonEmptyInput(const std::string& prompt)
{
    std::string input;
    
    while (true)
    {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!input.empty())
            break;
        std::cout << "Data cannot be empty. Please try again." << std::endl;
    }
    return input;
}

void    Contact::createContact()
{
    setFirstName(readNonEmptyInput("Enter First Name: "));
    setLastName(readNonEmptyInput("Enter Last Name: "));
    setNickname(readNonEmptyInput("Enter Nickname: "));
    setPhoneNumber(readNonEmptyInput("Enter Phone Number: "));
    setDarkestSecret(readNonEmptyInput("Enter Darkest Secret: "));
}