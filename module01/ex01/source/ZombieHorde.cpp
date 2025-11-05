/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 01:53:06 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/11/05 02:15:58 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    Zombie *zombie_horde = new Zombie[N];

    for (int counter = 0; counter < N; counter++)
        zombie_horde[counter].setName(name);

    return zombie_horde;
}