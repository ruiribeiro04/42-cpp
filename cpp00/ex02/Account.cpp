/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ruiferma <ruiferma@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 11:00:00 by ruiferma          #+#    #+#             */
/*   Updated: 2025/04/11 11:00:00 by ruiferma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * EX02 - Account Class Implementation
 * 
 * This exercise teaches us about static members and initialization lists.
 * 
 * Learning objectives:
 * - Static members (shared across all instances)
 * - Initialization lists (efficient way to initialize members)
 * - const methods (promising not to modify the object)
 * - Reading existing code to understand requirements
 * - Time formatting and display
 */

#include "Account.hpp"
#include <iostream>
#include <ctime>

/*
 * STATIC MEMBER INITIALIZATION
 * 
 * Static members are shared across ALL instances of the class.
 * They must be initialized outside the class definition.
 * This is done once at program startup, not for each object.
 * 
 * Think of these as global variables that belong to the Account class:
 * - _nbAccounts: How many Account objects have been created
 * - _totalAmount: Sum of money in all accounts
 * - _totalNbDeposits: Total number of deposits across all accounts
 * - _totalNbWithdrawals: Total number of withdrawals across all accounts
 */
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/*
 * Constructor with initial deposit
 * Uses an INITIALIZATION LIST - a C++ feature for efficient initialization
 * 
 * Syntax: ClassName(parameters) : member1(value1), member2(value2) { }
 * 
 * The initialization list is more efficient than assigning in the constructor body
 * because it initializes members directly rather than default-constructing then assigning.
 */
Account::Account(int initial_deposit) :
    _accountIndex(_nbAccounts),  // This account gets the current count as its index
    _amount(initial_deposit),     // Set the initial balance
    _nbDeposits(0),               // No deposits yet
    _nbWithdrawals(0)             // No withdrawals yet
{
    // Now we're inside the constructor body
    // Update the static counters
    _nbAccounts++;                // One more account exists
    _totalAmount += initial_deposit;  // Add this account's money to the total

    // Display the account creation
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "created" << std::endl;
}

/*
 * Default constructor (private - not used in this exercise)
 * This is defined but not implemented because it's private
 */
Account::Account(void) {
    // This should never be called
}

/*
 * Destructor
 * Called when an Account object is destroyed
 * We display the account closure information
 */
Account::~Account(void) {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "closed" << std::endl;
}

/*
 * STATIC GETTER METHODS
 * These methods return the values of static members
 * They're static because they don't need a specific object to work
 */

int Account::getNbAccounts(void) {
    return _nbAccounts;
}

int Account::getTotalAmount(void) {
    return _totalAmount;
}

int Account::getNbDeposits(void) {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) {
    return _totalNbWithdrawals;
}

/*
 * Display global account information
 * Shows statistics for ALL accounts combined
 */
void Account::displayAccountsInfos(void) {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

/*
 * Make a deposit to this account
 * Updates both the account's individual data and the global totals
 */
void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    
    // Add deposit to total amount
    _totalAmount += deposit;
    
    // Display the deposit information
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << checkAmount() << ";";  // p_amount = previous amount
    std::cout << "deposit:" << deposit << ";";
    
    // Update this account's balance and counters
    _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

/*
 * Make a withdrawal from this account
 * Returns true if successful, false if insufficient funds
 */
bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << checkAmount() << ";";
    std::cout << "withdrawal:";
    
    // Check if there's enough money
    if (withdrawal > checkAmount()) {
        std::cout << "refused" << std::endl;
        return false;
    }
    
    // Withdrawal is possible
    std::cout << withdrawal << ";";
    
    // Update balances and counters
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
    
    return true;
}

/*
 * Check the current amount in this account
 * This is a const method - it promises not to modify the object
 */
int Account::checkAmount(void) const {
    return _amount;
}

/*
 * Display the status of this specific account
 * Shows individual account information
 */
void Account::displayStatus(void) const {
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << checkAmount() << ";";
    std::cout << "deposits:" << _nbDeposits << ";";
    std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

/*
 * Display a timestamp in the format [YYYYMMDD_HHMMSS]
 * This is a private static helper method
 * 
 * Example output: [20250411_143022]
 */
void Account::_displayTimestamp(void) {
    time_t      raw_time;
    struct tm*  time_info;
    char        buffer[32];

    // Get current time
    time(&raw_time);
    time_info = localtime(&raw_time);
    
    // Format the time as [YYYYMMDD_HHMMSS]
    strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", time_info);
    std::cout << buffer;
}
