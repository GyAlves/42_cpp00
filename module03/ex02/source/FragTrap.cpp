/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:40:00 by gyasminalve      #+#    #+#             */
/*   Updated: 2025/11/10 17:40:00 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("Anonymous")
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;

    std::cout << "FragTrap default constructor called for " << this->name << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;

    std::cout << "FragTrap " << this->name << " has been assembled!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
    std::cout << "FragTrap " << this->name << " has been cloned!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
    std::cout << "FragTrap assignment operator called" << std::endl;

    if (this != &other)
    {
        ClapTrap::operator=(other);
    }

    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->name << " has been disassembled!" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->name << " says: High five, everyone! ✋😄" << std::endl;
}
