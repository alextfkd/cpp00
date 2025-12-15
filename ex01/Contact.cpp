/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkatsuma <tkatsuma@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 04:12:03 by tkatsuma          #+#    #+#             */
/*   Updated: 2025/12/14 01:00:16 by tkatsuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>

const std::string Contact::kDigits = "0123456789";
const std::string Contact::kMsgErrNonNumeric =
    "The phone number must be numeric";
const std::string Contact::kMsgErrDigitNum =
    "The phone number must be between 10 to 16 digits";

Contact::Contact(void) {
  this->first_name_   = "";
  this->last_name_    = "";
  this->nick_name_    = "";
  this->phone_number_ = "";
  this->secret_       = "";
}

Contact::Contact(const Contact &other) { *this = other; }

Contact::Contact(const std::string data[Contact::Contact::kDataLen]) {
  this->first_name_   = data[0];
  this->last_name_    = data[1];
  this->nick_name_    = data[2];
  this->phone_number_ = data[3];
  this->secret_       = data[4];
}

Contact &Contact::operator=(const Contact &other) {
  if (this != &other) {
    this->first_name_   = other.first_name_;
    this->last_name_    = other.last_name_;
    this->nick_name_    = other.nick_name_;
    this->phone_number_ = other.phone_number_;
    this->secret_       = other.secret_;
  }
  return *this;
}

Contact::~Contact() {}

std::string Contact::Truncate(const std::string     &str,
                              std::string::size_type len) {
  std::string res;

  if (str.length() <= len) {
    res = str;
  } else {
    res = str.substr(0, len - 1) + ".";
  }
  return (res);
}

void Contact::PrintName() const {
  size_t wlim = Contact::kPrintWidth;

  std::cout << std::setw((int)wlim)
            << Contact::Truncate(this->first_name_, wlim) << "|";
  std::cout << std::setw((int)wlim) << Contact::Truncate(this->last_name_, wlim)
            << "|";
  std::cout << std::setw((int)wlim) << Contact::Truncate(this->nick_name_, wlim)
            << std::endl;
}

void Contact::PrintInfo(size_t idx) const {
  const std::string prompts[Contact::kDataLen] = {
      "- First name: ", "- Last name: ", "- Nickname: ", "- Phone number: ",
      "- Darkest secret: "};

  std::stringstream sstream;
  sstream << idx;
  std::string sidx = sstream.str();

  std::cout << "Contact info, index: " << sidx << std::endl;
  std::cout << prompts[0] << this->first_name_ << std::endl;
  std::cout << prompts[1] << this->last_name_ << std::endl;
  std::cout << prompts[2] << this->nick_name_ << std::endl;
  std::cout << prompts[3] << this->phone_number_ << std::endl;
  std::cout << prompts[4] << this->secret_ << std::endl;
}

std::string Contact::TrimSpace(std::string str) {
  const std::string      space_letters = "\v\t\n\f\r ";
  std::string::size_type end;
  end = str.find_first_not_of(space_letters);
  str.erase(0, end);
  return (str);
}

bool Contact::IsInvalidPhoneNumber(const std::string &str) {
  if (!str.find_first_not_of(Contact::kDigits)) {
    std::cout << Contact::kMsgErrNonNumeric << std::endl;
    return (true);
  }
  if (str.length() < Contact::kMinDigit - 1 ||
      str.length() > Contact::kMaxDigit + 1) {
    std::cout << Contact::kMsgErrDigitNum << std::endl;
    return (true);
  }
  return (false);
}

Contact Contact::Create(void) {
  const std::string MSG_ADD       = "Creating a new contact information.";
  const std::string MSG_ERR_EMPTY = "Please fill in the form.";
  const std::string prompts[Contact::kDataLen] = {
      "- First name: ", "- Last name: ", "- Nickname: ", "- Phone number: ",
      "- Darkest secret: "};
  std::string contact_data[Contact::kDataLen];

  std::cout << MSG_ADD << std::endl;
  int idx = 0;
  while (idx < Contact::kDataLen) {
    std::cout << prompts[idx] << std::flush;
    if (!std::getline(std::cin, contact_data[idx])) {
      std::exit(1);
    };
    contact_data[idx] = Contact::TrimSpace(contact_data[idx]);
    if (contact_data[idx].empty()) {
      std::cout << MSG_ERR_EMPTY << std::endl;
      continue;
    }
    if (idx == 3 && Contact::IsInvalidPhoneNumber(contact_data[idx])) {
      continue;
    }
    idx++;
  }
  Contact new_contact(contact_data);
  return (new_contact);
}
