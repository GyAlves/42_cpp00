/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:38:47 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/10 14:05:45 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    this->name = "Unnamed";
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;

    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->attackDamage = 0;

    std::cout << "Warrior <" << this->name << "> has been summoned!! " << std:: endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    this->name = other.name;
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;

    std::cout << "ClapTrap <" << this->name << "> has been copied!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;

    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }

    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Warrior <" << this->name << ">: has been defeated" << std:: endl;
}

void    ClapTrap::attack(const std::string &target)
{
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap <" << this->name << "> has no energy to attack!" << std::endl;
        return;
    }

    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap <" << this->name << "> is already destroyed!" << std::endl;
        return;
    }

    this->energyPoints--;

    std::cout << "ClapTrap <" << this->name << "> attacks " << target
              << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap <" << this->name << "> is already destroyed!" << std::endl;
        return;
    }

    if (amount >= (unsigned int)this->hitPoints)
    {
        this->hitPoints = 0;
        std::cout << "ClapTrap <" << this->name << "> takes " << amount
                  << " points of damage and is destroyed!" << std::endl;
    }
    else
    {
        this->hitPoints -= amount;
        std::cout << "ClapTrap <" << this->name << "> takes " << amount
                  << " points of damage! (" << this->hitPoints << " HP remaining)" << std::endl;
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoints == 0)
    {
        std::cout << "ClapTrap <" << this->name << "> has no energy to repair!" << std::endl;
        return;
    }

    if (this->hitPoints == 0)
    {
        std::cout << "ClapTrap <" << this->name << "> is already destroyed and cannot repair!" << std::endl;
        return;
    }

    this->energyPoints--;
    this->hitPoints += amount;

    std::cout << "ClapTrap <" << this->name << "> repairs itself for " << amount
              << " hit points! (" << this->hitPoints << " HP total)" << std::endl;
}