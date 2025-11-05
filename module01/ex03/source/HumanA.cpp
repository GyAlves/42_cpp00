/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:45:21 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/05 20:30:16 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): weapon(weapon)
{
    this->name = name;
    this->weapon = weapon;
}

HumanA::~HumanA()
{
    
}

void    HumanA::attack()
{
    std::cout << name <<  " attacks with their " << weapon.getType() << std::endl;
}