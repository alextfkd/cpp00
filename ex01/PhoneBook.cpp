#include "PhoneBook.hpp"

#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

#include "Contact.hpp"

int PhoneBook::Add(const Contact& contact) {
  this->contacts_[this->available_idx_] = contact;
  this->available_idx_++;
  this->available_idx_ %= PhoneBook::max_contact_;
  if (this->n_info_ < PhoneBook::max_contact_) {
    this->n_info_++;
  }
  return (0);
}

PhoneBook::PhoneBook(void) {
  this->n_info_        = 0;
  this->available_idx_ = 0;
}

PhoneBook::~PhoneBook() {}

int PhoneBook::ShowTable(void) const {
  std::stringstream sstream;

  std::cout << std::setw(PhoneBook::clim_) << "index"
            << "|";
  std::cout << std::setw(PhoneBook::clim_) << "first name"
            << "|";
  std::cout << std::setw(PhoneBook::clim_) << "last name"
            << "|";
  std::cout << std::setw(PhoneBook::clim_) << "nick name" << std::endl;
  if (this->n_info_ == 0) {
    std::cout << "You will need to ADD contact information before using SEARCH."
              << std::endl;
    return (1);
  }
  size_t idx = 0;
  while (idx < this->n_info_) {
    std::cout << std::setw(PhoneBook::clim_) << idx << "|";
    this->contacts_[idx].PrintName();
    idx++;
  }
  return (0);
}

int PhoneBook::ShowInfo(size_t idx) const {
  if (idx >= this->n_info_) {
    std::cout << "Enter valid numeric id." << std::endl;
    return (1);
  }
  this->contacts_[idx].PrintInfo(idx);
  return (0);
}

int PhoneBook::Search(void) const {
  const std::string PROMPT_ID = "Enter the index to display: ";
  size_t            user_id;
  std::string       user_id_input;
  if (this->ShowTable()) {
    return (1);
  }
  while (true) {
    std::cout << PROMPT_ID;
    if (!std::getline(std::cin, user_id_input)) {
      std::cout << std::endl;
      return (1);
    };
    std::stringstream sstream(user_id_input);
    sstream >> user_id;
    if (sstream.fail() || !sstream.eof()) {
      std::cout << "Invalid input." << std::endl;
      continue;
    }
    if (this->ShowInfo(user_id)) {
      continue;
    }
    return (0);
  }
}

int PhoneBook::Run(void) {
  const std::string PROMPT        = "PhoneBook: ";
  const std::string CMD_ADD       = "ADD";
  const std::string CMD_SEARCH    = "SEARCH";
  const std::string CMD_EXIT      = "EXIT";
  const std::string CMD_UNDEFINED = "Invalid command. Use ADD, SEARCH or EXIT";
  std::string       cmd;

  while (1) {
    std::cout << PROMPT;
    if (!std::getline(std::cin, cmd)) {
      std::cout << CMD_EXIT << std::endl;
      return (1);
    };
    if (cmd == CMD_ADD) {
      Contact new_contact;
      if (!Contact::FillData(new_contact)) {
        return (1);
      }
      this->Add(new_contact);
    } else if (cmd == CMD_SEARCH) {
      this->Search();
    } else if (cmd == CMD_EXIT) {
      std::cout << CMD_EXIT << std::endl;
      break;
    } else {
      std::cout << CMD_UNDEFINED << std::endl;
    }
  }
  return (0);
}
