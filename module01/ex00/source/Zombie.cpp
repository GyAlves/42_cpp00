/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 01:09:55 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/11/05 01:46:35 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Zombie.hpp"

Zombie:: Zombie(std:: string name)
{
    this->name = name;
}

Zombie:: ~Zombie()
{
    std:: cout << "Zombie " << name << " destroyed! Aaaaagghhh" << std:: endl;
}

void Zombie:: announce() const
{
    std:: cout << name << ": BraiiiiiiinnnzzzZ..." << std:: endl;
}