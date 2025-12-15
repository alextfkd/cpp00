#include "Account.hpp"

#include <ctime>
#include <iostream>

// public
int Account::_nbAccounts         = 0;
int Account::_totalAmount        = 0;
int Account::_totalNbDeposits    = 0;
int Account::_totalNbWithdrawals = 0;

// Getter, Done.
int Account::getNbAccounts(void) { return Account::_nbAccounts; }
// Getter, Done.
int Account::getTotalAmount(void) { return Account::_totalAmount; }
// Getter, Done.
int Account::getNbDeposits(void) { return Account::_totalNbDeposits; }
// Getter, Done.
int Account::getNbWithdrawals(void) { return Account::_totalNbWithdrawals; }

/*
Expected output;
[19920104_091532] accounts:8;total:21524;deposits:8;withdrawals:0
*/
void Account::displayAccountsInfos(void) {
  Account::_displayTimestamp();
  std::cout << "accounts:" << Account::getNbAccounts() << ";";
  std::cout << "total:" << Account::getTotalAmount() << ";";
  std::cout << "deposits:" << Account::getNbDeposits() << ";";
  std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

/*
Expected output;
[19920104_091532] index:0;amount:42;created
*/
Account::Account(int initial_deposit) {
  this->_accountIndex  = Account::_nbAccounts;
  this->_amount        = initial_deposit;
  this->_nbDeposits    = 0;
  this->_nbWithdrawals = 0;
  Account::_nbAccounts++;
  Account::_totalAmount += initial_deposit;
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "created" << std::endl;
}

/*
Expected output;
[19920104_091532] index:0;amount:42;closed
*/
Account::~Account(void) {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "closed" << std::endl;
}

/*
Expected output;
[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
*/
void Account::makeDeposit(int deposit) {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "p_amount:" << this->_amount << ";";
  std::cout << "deposit:" << deposit << ";";
  this->_amount += deposit;
  this->_nbDeposits++;
  Account::_totalAmount += deposit;
  Account::_totalNbDeposits++;
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

/*
Expected output;
[19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
[19920104_091532] index:5;p_amount:23;withdrawal:refused
*/
bool Account::makeWithdrawal(int withdrawal) {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "p_amount:" << this->_amount << ";";
  if (this->_amount < withdrawal) {
    std::cout << "withdrawal:refused" << std::endl;
    return (1);
  }
  std::cout << "withdrawal:" << withdrawal << ";";
  this->_amount -= withdrawal;
  this->_nbWithdrawals++;
  Account::_totalAmount -= withdrawal;
  Account::_totalNbWithdrawals++;
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "nb_withdrawals:" << this->_nbDeposits << std::endl;
  return (0);
}

/*
Getter.
*/
int Account::checkAmount(void) const { return (this->_amount); }

/*
Expected output;
[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
*/
void Account::displayStatus(void) const {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";";
  std::cout << "amount:" << this->_amount << ";";
  std::cout << "deposits:" << this->_nbDeposits << ";";
  std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

// private:

void Account::_displayTimestamp(void) {
  /*
  std::cout << "[19920104_091532] ";
  return;
  */
  const int   buflen = 100;
  std::time_t now    = std::time(NULL);
  std::tm    *tm_now = std::localtime(&now);
  char        buf[buflen];
  std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", tm_now);
  std::cout << buf;
}

Account::Account(void) {}
