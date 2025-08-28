#include <bits/stdc++.h>
using namespace std;

class depositOnlyAccount
{
public:
  virtual void deposit(double amount) = 0;
};

class withdrawableAccount : public depositOnlyAccount
{
public:
  virtual void withdraw(double amount) = 0;
};

class SavingsAccount : public withdrawableAccount
{
  double balance;

public:
  SavingsAccount(double balance)
  {
    this->balance = balance;
  }

  void deposit(double amount)
  {
    balance += amount;
    cout << "$" << amount << " deposited in your Savings account. New balance: $" << balance << endl;
  }

  void withdraw(double amount)
  {
    if (balance < amount)
    {
      cout << "Insufficient funds in your account!!!\n";
      return;
    }
    balance -= amount;
    cout << "$" << amount << " withdrawn from your Savings account. New balance: $" << balance << endl;
  }
};

class CurrentAccount : public withdrawableAccount
{
  double balance;

public:
  CurrentAccount(double balance)
  {
    this->balance = balance;
  }

  void deposit(double amount)
  {
    balance += amount;
    cout << "$" << amount << " deposited in your Current account. New balance: $" << balance << endl;
  }

  void withdraw(double amount)
  {
    if (balance < amount)
    {
      cout << "Insufficient funds in your account!!!\n";
      return;
    }
    balance -= amount;
    cout << "$" << amount << " withdrawn from your Current account. New balance: $" << balance << endl;
  }
};

class FixedDepositsAccount : public depositOnlyAccount
{
  double balance;

public:
  FixedDepositsAccount(double balance)
  {
    this->balance = balance;
  }

  void deposit(double amount)
  {
    balance += amount;
    cout << "$" << amount << " deposited in your Fixed Term account. New balance: $" << balance << endl;
  }
};

class BankClient
{
  vector<depositOnlyAccount *> depositOnlyAccounts;
  vector<withdrawableAccount *> withdrawableAccounts;

public:
  BankClient(vector<depositOnlyAccount *> depositOnlyAccounts, vector<withdrawableAccount *> withdrawableAccounts)
  {
    this->depositOnlyAccounts = depositOnlyAccounts;
    this->withdrawableAccounts = withdrawableAccounts;
  }

  void processTransactions()
  {
    for (auto acc : depositOnlyAccounts)
    {
      acc->deposit(15000);
    }

    for (auto acc : withdrawableAccounts)
    {
      acc->deposit(5000);
      acc->withdraw(1500);
    }
  }
};

int main()
{
  vector<depositOnlyAccount *> depositOnlyAccounts;
  depositOnlyAccounts.push_back(new FixedDepositsAccount(50000));

  vector<withdrawableAccount *> withdrawableAccounts;
  withdrawableAccounts.push_back(new CurrentAccount(10000));
  withdrawableAccounts.push_back(new SavingsAccount(20000));

  BankClient *client = new BankClient(depositOnlyAccounts, withdrawableAccounts);
  client->processTransactions();

  return 0;
}