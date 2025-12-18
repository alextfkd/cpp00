/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 04:08:22 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/18 01:41:20 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Contact.hpp"

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

const std::string kERR_NOTIMPL = "This function is not implemented.";

class PhoneBook {
 private:
  static const size_t max_contact_ = 8;
  static const int    clim_        = 10;
  size_t              n_info_;
  size_t              available_idx_;
  Contact             contacts_[PhoneBook::max_contact_];

  // Hide unused constructors.
  PhoneBook(const PhoneBook& other);
  PhoneBook& operator=(const PhoneBook& other);

 public:
  // Expose using constructor & deconstructor only.
  PhoneBook(void);
  ~PhoneBook();

  void PrintGuide() const;
  int  Add(const Contact& contact);
  int  ShowTable(void) const;
  int  ShowInfo(size_t idx) const;
  int  Search(void) const;
  int  Run(void);
};

#endif
