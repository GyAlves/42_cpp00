/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:03:31 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/11/02 19:08:15 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include "../headers/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    contactCount = 0;
}

PhoneBook::~PhoneBook()
{
    
}

void PhoneBook::setContactCount(int count)
{
    contactCount = count;
}

int PhoneBook::getContactCount() const
{
    return (contactCount < 8) ? contactCount : 8;
}

void PhoneBook::addContact(const Contact& contact)
{
    int insertIndex = contactCount % 8;
    contacts[insertIndex] = contact;

    contactCount++;
}

std::string PhoneBook::formatField(const std::string& field) const
{
    if (field.length() > 10)
        return field.substr(0, 9) + ".";
    return field;
}

void PhoneBook::displayContacts() const
{
    std::cout << std::right;
    std::cout << std::setw(10) << "Index" << "|";
    std::cout << std::setw(10) << "First Name" << "|";
    std::cout << std::setw(10) << "Last Name" << "|";
    std::cout << std::setw(10) << "Nickname" << std::endl;

    for (int index = 0; index < getContactCount(); index++)
    {
        std::cout << std::setw(10) << (index + 1) << "|";
        std::cout << std::setw(10) << formatField(contacts[index].getFirstName()) << "|";
        std::cout << std::setw(10) << formatField(contacts[index].getLastName()) << "|";
        std::cout << std::setw(10) << formatField(contacts[index].getNickname()) << std::endl;
    }
}

void PhoneBook::displayContactDetails(int index) const
{
    int arrayIndex = index - 1;

    std::cout << "\n--- Contact Details ---" << std::endl;
    std::cout << "First Name: " << contacts[arrayIndex].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[arrayIndex].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[arrayIndex].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[arrayIndex].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[arrayIndex].getDarkestSecret() << std::endl;
    std::cout << "-----------------------\n" << std::endl;
}