/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 18:12:37 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/08 16:54:01 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name)
{
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    
    std::cout << "ScavTrap " << this->name << " is constructed!" << std::endl;
}

ClapTrap::~ScavTrap() {
    std::cout << "ScavTrap <" << this->name << ">: has been eliminated" << std:: endl;
}s