/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:12:37 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/10 17:04:29 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("Nameless") {
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    
    std::cout << "Nameless ScavTrap " << this->name << " is constructed!" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    
    std::cout << "Warrior " << this->name << " is constructed!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap " << this->name << " has been copied!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    std::cout << "ScavTrap has been assigned!" << std::endl;
    
    if (this != &other)
        ClapTrap::operator=(other);

    return *this;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap <" << this->name << ">: has been defeated" << std:: endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (this->energyPoints == 0)
    {
        std::cout << "ScavTrap <" << this->name << "> has no energy to attack!" << std::endl;
        return;
    }

    if (this->hitPoints == 0)
    {
        std::cout << "ScavTrap <" << this->name << "> is already destroyed!" << std::endl;
        return;
    }

    this->energyPoints--;

    std::cout << "ScavTrap <" << this->name << "> attacks " << target
              << ", causing " << this->attackDamage << " points of damage!" << std::endl;
}

void    ScavTrap::guardGate()
{
    std::cout << "ScavTrap <" << this->name << "> is now in Gate keeper mode." << std::endl;
}