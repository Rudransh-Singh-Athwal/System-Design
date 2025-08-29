#include <bits/stdc++.h>
using namespace std;

class BankAccount
{
protected:
  double balance;

public:
  BankAccount(double b)
  {
    if (b < 0)
    {
      throw invalid_argument("Balance can't be negative");
      return;
    }
    balance = b;
    cout << "New account opened with balance: $" << balance << endl;
  }

  virtual void withdraw(double amount)
  {
    if (amount > balance)
    {
      throw runtime_error("Insufficient funds!!!");
      return;
    }
    balance -= amount;
    cout << "$" << amount << " withdrawn. New balance: " << balance << endl;
  }
};

// Breaks invariance: Should not be allowed
class CheatAccount : public BankAccount
{
public:
  CheatAccount(double b) : BankAccount(b) {};

  void withdraw(double amount) override
  {
    balance -= amount; // LSP Broken: Negative balance allowed
    cout << "$" << amount << " withdrawn. New balance: " << balance << endl;
  }
};

int main()
{
  BankAccount *acc1 = new BankAccount(20000);
  CheatAccount *acc2 = new CheatAccount(20000);
  try
  {
    acc1->withdraw(21250);
  }
  catch (const runtime_error &e)
  {
    cout << "Exception: " << e.what() << endl;
  }
  acc2->withdraw(21250);

  return 0;
}