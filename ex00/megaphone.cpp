/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 02:32:28 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/10 03:06:07 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define NOISE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

static void str2upper(char* str);

int main(int argc, char* argv[]) {
  if (argc == 1) {
    std::cout << NOISE << std::endl;
    return (0);
  }
  int idx = 1;
  while (idx < argc) {
    str2upper(argv[idx]);
    std::cout << argv[idx++];
  }
  std::cout << std::endl;
  return (0);
}

static void str2upper(char* str) {
  char* ptr;

  ptr = str;
  while (*ptr != '\0') {
    *ptr = std::toupper(*ptr);
    ptr++;
  }
}