/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:32:28 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/10 03:02:23 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void str2upper(char* str) {
  char* ptr;

  ptr = str;
  while (*ptr != '\0') {
    *ptr = std::toupper(*ptr);
    ptr++;
  }
}

int main(int argc, char* argv[]) {
  int idx;

  idx = 1;
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n" << std::endl;
    return (0);
  }
  while (idx < argc) {
    str2upper(argv[idx]);
    std::cout << argv[idx++];
  }
  std::cout << std::endl;
  return (0);
}
