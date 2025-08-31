#include <bits/stdc++.h>
using namespace std;

// A precondition must be satisfied before a method can be executed
// Sub classes can weaken pre conditions but cannot strengthen it

class User
{
public:
  // Precondition: Password must be at least 8 characters long
  virtual void createPassword(string pass)
  {
    if (pass.length() < 8)
      throw invalid_argument("Password must be at least 8 characters long!!!");
    cout << "Password set successfully\n";
  }
};

// This follows Precondition rule because the precondition is weakened and not strengthened by reducing the required password length

class AdminUser : public User
{
public:
  // Precondition: Password must be at least 6 characters long -> WEAKER
  void createPassword(string pass) override
  {
    if (pass.length() < 6)
      throw invalid_argument("Password must be at least 6 characters long!!!");
    cout << "Password set successfully\n";
  }
};

int main()
{
  User *user = new AdminUser();
  AdminUser *adminUser = new AdminUser();
  try
  {
    user->createPassword("srgvf4g3c");
  }
  catch (const invalid_argument &e)
  {
    cout << "Exception: " << e.what() << endl;
  }
  try
  {
    adminUser->createPassword("srgvf4g3c");
  }
  catch (const invalid_argument &e)
  {
    cout << "Exception: " << e.what() << endl;
  }

  return 0;
}