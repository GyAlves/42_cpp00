/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ValidateInput.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:00:53 by galves-a          #+#    #+#             */
/*   Updated: 2025/11/06 01:29:37 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATEINPUT_HPP
# define VALIDATEINPUT_HPP

# include <string>
#include <iostream>

bool parseAndValidateArgs(int argc, char *argv[], std::string& filename, std::string& s1, std::string& s2);

#endif
