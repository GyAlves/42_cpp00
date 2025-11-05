/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 22:20:56 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/11/05 01:48:03 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/Zombie.hpp"

int main()
{
    std::string zomie_name;
    Zombie *zoomie;

    std::cout << "Write your zombie's name: ";
    std::cin >> zomie_name;
    
    zoomie = newZombie(zomie_name);
    zoomie->announce();

    randomChump("MeatyMcFleshFace");

    delete zoomie;
    return (0);
}