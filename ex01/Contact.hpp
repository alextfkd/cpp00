/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 04:08:19 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/14 01:00:22 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#ifndef CONTACT_H
#define CONTACT_H

/**
 * @brief
 *
 * @todo
 * Each member va
 */
class Contact {
 private:
  static const size_t kMaxDigit   = 16;
  static const size_t kMinDigit   = 10;
  static const int    kDataLen    = 5;
  static const size_t kPrintWidth = 10;

  static const std::string kDigits;
  static const std::string kMsgErrNonNumeric;
  static const std::string kMsgErrDigitNum;

  std::string first_name_;
  std::string last_name_;
  std::string nick_name_;
  std::string phone_number_;
  std::string secret_;

 public:
  Contact();
  Contact(const Contact &other);
  Contact(const std::string data[kDataLen]);
  Contact &operator=(const Contact &other);
  ~Contact();

  void        PrintName() const;
  void        PrintInfo(size_t idx) const;

  static std::string Truncate(const std::string     &str,
                              std::string::size_type len);
  static std::string TrimSpace(std::string str);
  static bool        IsInvalidPhoneNumber(const std::string &str);

  static Contact Create();
};

#endif
