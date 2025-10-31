/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:03:22 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/10/29 19:27:44 by gyasminalve      ###   ########.fr       */
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

