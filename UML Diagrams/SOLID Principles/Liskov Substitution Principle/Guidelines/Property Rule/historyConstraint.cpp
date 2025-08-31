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
      throw invalid_argument("Balance can't be negative\n");
    balance = b;
    cout << "New account opened with balance: $" << balance << endl;
  }

  // History constraint: Withdrawal should be allowed
  virtual void withdraw(double amount)
  {
    if (amount > balance)
      throw runtime_error("Insufficient funds!!!\n");
    balance -= amount;
    cout << "$" << amount << " withdrawn from the account. Remaining balance: $" << balance << endl;
  }
};

class FixedDepositAccount : public BankAccount
{
public:
  FixedDepositAccount(double b) : BankAccount(b) {}

  // This breaks LSP History constraint because the base class mentioned that withdrawal should always be allowed but here we didn't follow that constraint and throw an error on withdrawal
  // The parent class's behaviour changed here which is not allowed in history constraint
  void withdraw(double amount) override
  {
    throw runtime_error("Withdrawal not allowed in Fixed Deposit account\n");
  }
};

int main()
{
  BankAccount *acc = new BankAccount(10000);
  acc->withdraw(2500);
  BankAccount *fixedDeposit = new FixedDepositAccount(12000);
  try
  {
    fixedDeposit->withdraw(1250);
  }
  catch (const runtime_error &e)
  {
    cout << "Exception: " << e.what() << endl;
  }

  return 0;
}