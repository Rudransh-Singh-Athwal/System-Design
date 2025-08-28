#include <bits/stdc++.h>
using namespace std;

class Account
{
public:
  virtual void deposit(double amount) = 0;
  virtual void withdraw(double amount) = 0;
};

class SavingsAccount : public Account
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

class CurrentAccount : public Account
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

class FixedDepositsAccount : public Account
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

  void withdraw(double amount)
  {
    throw logic_error("Withdrawal is not allowed in a Fixed Term Account\n");
  }
};

class BankClient
{
  vector<Account *> accounts;

public:
  BankClient(vector<Account *> accounts)
  {
    this->accounts = accounts;
  }

  void processTransactions()
  {
    for (auto acc : accounts)
    {
      acc->deposit(1000); // all accounts support deposits

      // Assuming all accounts support withdrawals (LSP violation)
      try
      {
        acc->withdraw(350);
      }
      catch (const logic_error &e)
      {
        cout << "Exception: " << e.what() << endl;
      }
    }
  }
};

int main()
{
  vector<Account *> accounts;
  accounts.push_back(new SavingsAccount(10000));
  accounts.push_back(new CurrentAccount(8500));
  accounts.push_back(new FixedDepositsAccount(20000));

  BankClient *client = new BankClient(accounts);
  client->processTransactions(); // Throws exception when withdrawing from Fixed Term Account

  return 0;
}