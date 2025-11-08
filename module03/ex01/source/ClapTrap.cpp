/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:38:47 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/08 16:51:27 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hitPoints = 10;
    this->energyPoints = 10;
    this->damagePoints = 0;

    std::cout << "Warrior <" << this->name << "> has been summoned!! " << std:: endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "Warrior <" << this->name << ">: has been eliminated" << std:: endl;
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