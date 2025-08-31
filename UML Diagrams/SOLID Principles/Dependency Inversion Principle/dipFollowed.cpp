#include <bits/stdc++.h>
using namespace std;

// Abstraction (Interface)
class Database
{
public:
  virtual void save(string data) = 0;
};

// MySQL implementation: Low-level module
class MySQLDatabase : public Database
{
public:
  void save(string data) override
  {
    cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << endl;
  }
};

// MongoDB implementation: Low-level module
class MongoDBDatabase : public Database
{
public:
  void save(string data) override
  {
    cout << "Executing MongoDB function: db.users.insert({name: '" << data << "'})" << endl;
  }
};

// High level module (now loosely coupled)
class UserService
{
  Database *db; // dependency injection: passing an object of a class or its reference in some other class

public:
  UserService(Database *db)
  {
    this->db = db;
  }

  void storeUser(string data)
  {
    db->save(data);
  }
};

int main()
{
  MySQLDatabase mySQL;
  MongoDBDatabase mongoDB;

  UserService service1(&mySQL);
  service1.storeUser("Aditya");

  UserService service2(&mongoDB);
  service2.storeUser("Raj");

  return 0;
}