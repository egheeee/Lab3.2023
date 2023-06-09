#pragma once
#ifndef BankAccount_h
#define BankAccount_h
#include <string>

// Состояние счета
enum class AccountStatus {
    Active,
    Frozen,
    Closed
};

class BankAccount {
private:
    std::string ownerName;
    std::string ownerAddress;
    std::string passportData;
    AccountStatus status;
    double income;
    double expenses;
    std::string BIK;
    std::string accountNumber;

public:
    // Конструктор
    BankAccount(const std::string& ownerName, const std::string& ownerAddress,
        const std::string& passportData, const std::string& BIK,
        const std::string& accountNumber);

    // Геттеры и сеттеры
    std::string getOwnerName() const;
    void setOwnerName(const std::string& name);

    std::string getOwnerAddress() const;
    void setOwnerAddress(const std::string& address);

    std::string getPassportData() const;
    void setPassportData(const std::string& passportData);

    AccountStatus getStatus() const;

    double getIncome() const;

    double getExpenses() const;

    std::string getBIK() const;

    std::string getAccountNumber() const;

    double getBalance() const;

    bool canOperate() const;

    // Методы для операций с деньгами
    void deposit(double amount);
    void withdraw(double amount);
};
#endif BankAccount_h