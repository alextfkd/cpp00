/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 02:16:17 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/15 21:22:17 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <sstream>

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(int argc, char** argv) {
  const std::string MSG_INVALID_ARGC = "This program takes no arguments.";
  PhoneBook         phonebook;
  (void)argv;
  if (argc != 1) {
    std::cout << MSG_INVALID_ARGC << std::endl;
    return (1);
  }
  return (phonebook.Run());
}
