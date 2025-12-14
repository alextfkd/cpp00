/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 04:08:22 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/13 03:59:34 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Contact.hpp"

const std::string kERR_NOTIMPL = "This function is not implemented.";

class PhoneBook {
 private:
  static const size_t max_contact_ = 8;
  static const int    clim_        = 10;
  size_t              n_info_;
  size_t              available_idx_;
  Contact             contacts_[PhoneBook::max_contact_];

 public:
  PhoneBook(void);
  PhoneBook(PhoneBook&);
  PhoneBook(const PhoneBook&, int val);
  PhoneBook& operator=(const PhoneBook& other);
  ~PhoneBook();

  void PrintGuide() const;
  int  Add(const Contact& contact);
  void ShowTable(void) const;
  int  ShowInfo(size_t idx) const;
  int  Search(void) const;
  int  Run(void);
};
