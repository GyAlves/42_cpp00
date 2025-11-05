/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:28:41 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/05 18:33:37 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB {

    private:
        std::string name;
        Weapon  *weapon;

    public:
        
        HumanB(std::string name);
        ~HumanB();

        // Setter
        void    setWeapon(Weapon &weapon);

        void    attack();    
};

#endif