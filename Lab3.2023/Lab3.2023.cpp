#include "BankAccount.h"
#include <iostream>
#include <locale.h>
#include <stdexcept>

BankAccount::BankAccount(const std::string& ownerName, const std::string& ownerAddress,
    const std::string& passportData, const std::string& BIK,
    const std::string& accountNumber)
    : ownerName(ownerName), ownerAddress(ownerAddress), passportData(passportData),
    BIK(BIK), accountNumber(accountNumber), status(AccountStatus::Active), income(0), expenses(0) {}

std::string BankAccount::getOwnerName() const {
    return ownerName;
}

void BankAccount::setOwnerName(const std::string& name) {
    ownerName = name;
}

std::string BankAccount::getOwnerAddress() const {
    return ownerAddress;
}

void BankAccount::setOwnerAddress(const std::string& address) {
    ownerAddress = address;
}

std::string BankAccount::getPassportData() const {
    return passportData;
}

void BankAccount::setPassportData(const std::string& passportData) {
    this->passportData = passportData;
}

AccountStatus BankAccount::getStatus() const {
    return status;
}

double BankAccount::getIncome() const {
    return income;
}

double BankAccount::getExpenses() const {
    return expenses;
}

std::string BankAccount::getBIK() const {
    return BIK;
}

std::string BankAccount::getAccountNumber() const {
    return accountNumber;
}

double BankAccount::getBalance() const {
    return income - expenses;
}

bool BankAccount::canOperate() const {
    return status == AccountStatus::Active;
}

void BankAccount::deposit(double amount) {
    if (status != AccountStatus::Active) {
        throw std::runtime_error("Невозможно внести депозит на неактивный счет");
    }
    income += amount;
}

void BankAccount::withdraw(double amount) {
    if (status != AccountStatus::Active) {
        throw std::runtime_error("Невозможно снять средства с неактивного аккаунта");
    }
    if (getBalance() < amount) {
        throw std::runtime_error("Недостаточно средств");
    }
    expenses += amount;
}
int main() {
    setlocale(0, "RUS");
    BankAccount account("Антон Глех", "Пушкина 46", "AB123456", "346298347", "00023482565");

    std::cout << "Владелец учетной записи: " << account.getOwnerName() << std::endl;

    std::cout << "Внесение депозита в размере $500..." << std::endl;
    account.deposit(500);
    std::cout << "Текущий баланс: $" << account.getBalance() << std::endl;

    std::cout << "Вывод $200..." << std::endl;
    account.withdraw(200);
    std::cout << "Текущий баланс: $" << account.getBalance() << std::endl;

    try {
        std::cout << "Попытка перерасчета..." << std::endl;
        account.withdraw(500);
    }
    catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}