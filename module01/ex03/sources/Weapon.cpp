/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:34:11 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/05 18:44:38 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Weapon.hpp"

Weapon::Weapon()
{
    type = "";
}

Weapon::~Weapon()
{
    
}

void    Weapon::setType(std::string type)
{
    this->type = type;
}

const std::string& Weapon::getType() const
{
    return type;
}