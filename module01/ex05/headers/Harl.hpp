/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 01:19:54 by gyasminalve       #+#    #+#             */
/*   Updated: 2025/11/07 01:44:40 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <string>

class Harl {

    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
        
    public:
        Harl();
        ~Harl();
        
        void complain(std::string level);
};