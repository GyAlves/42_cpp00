/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-a <galves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:14:19 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/05 18:33:33 by galves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {

    private:
        std::string name;
        Weapon  weapon;

    public:
        
        HumanA(std::string name, Weapon weapon);
        ~HumanA();

        void    attack();    
};

#endif