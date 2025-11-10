/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:40:00 by gyasminalve      #+#    #+#             */
/*   Updated: 2025/11/10 17:40:00 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {

    private:
        //

    public:

        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &other);
        FragTrap &operator=(const FragTrap &other);
        ~FragTrap();

        void    highFivesGuys(void);
};

#endif
