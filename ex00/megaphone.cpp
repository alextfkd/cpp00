/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:32:28 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/22 20:13:40 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

static std::string& str2upper(std::string& str);

int main(int argc, char* argv[]) {
  if (argc == 1) {
    const std::string NOISE = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << NOISE << std::endl;
    return (0);
  }
  int idx = 1;
  while (idx < argc) {
    std::string argv_i(argv[idx]);
    argv_i = str2upper(argv_i);
    std::cout << argv_i;
    idx++;
  }
  std::cout << std::endl;
  return (0);
}

static std::string& str2upper(std::string& str) {
  size_t idx = 0;
  size_t len = str.length();

  while (idx < len) {
    str[idx] = static_cast<char>(std::toupper(static_cast<int>(str[idx])));
    idx++;
  }
  return (str);
}
