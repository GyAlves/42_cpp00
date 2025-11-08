/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:37:46 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/07 17:55:26 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ClapTrap.hpp"

int main()
{
    ClapTrap    claptrap("clappy");
    
    claptrap.attack("Zod");
    claptrap.takeDamage(10);
    claptrap.beRepaired(15);
    return (0);
}