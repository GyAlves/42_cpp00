/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 01:53:08 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/11/05 02:01:27 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Zombie.hpp"

Zombie:: Zombie()
{
    this->name = "";
}

Zombie:: ~Zombie()
{
    std:: cout << "Zombie " << name << " destroyed! Aaaaagghhh" << std:: endl;
}

void Zombie:: announce() const
{
    std:: cout << name << ": BraiiiiiiinnnzzzZ..." << std:: endl;
}

void Zombie:: setName(std:: string name)
{
    this->name = name;
}