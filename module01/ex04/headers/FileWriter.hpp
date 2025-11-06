/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileWriter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyasminalves <gyasminalves@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 02:59:00 by gyasminalve      #+#    #+#             */
/*   Updated: 2025/11/06 02:59:00 by gyasminalve      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILEWRITER_HPP
# define FILEWRITER_HPP

#include <string>
#include <fstream>
#include <iostream>

bool writeFileContent(const std::string& filename, const std::string& content);

#endif
