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
    this->hit = 10;
    this->energy = 10;
    this->damage = 0;

    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hit = 10;
    this->energy = 10;
    this->damage = 0;

    std::cout << "Warrior <" << this->name << "> has been summoned!! " << std:: endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    this->name = other.name;
    this->hit = other.hit;
    this->energy = other.energy;
    this->damage = other.damage;

    std::cout << "ClapTrap <" << this->name << "> has been copied!" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;

    if (this != &other)
    {
        this->name = other.name;
        this->hit = other.hit;
        this->energy = other.energy;
        this->damage = other.damage;
    }

    return *this;
}

ClapTrap::~ClapTrap() {
    std::cout << "Warrior <" << this->name << ">: has been defeated" << std:: endl;
}

void    ClapTrap::attack(const std::string &target)
{
    std::cout << "Warrior <" << this->name << ">: attacks enemy " << target << std::endl;
}

void    ClapTrap::takeDamage(unsigned int amout)
{
    std::cout << "Warrior <" << this->name << ">: takes -" << amout << " of damage" << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amout)
{
    std::cout << "Warrior <" << this->name << ">: receives " << amout << " point(s) of healing" << std::endl;
}