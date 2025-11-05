/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:52:14 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/05 19:04:17 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB()
{
    
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void    HumanB::attack()
{
   if (this->weapon != NULL)
   {
        std::cout << name << " attacks with their " << this->weapon.getType() << std::endl;
   }
   else
        std::cout << name << " has no weapon!!" << this->weapon.getType() << std::endl;

}

