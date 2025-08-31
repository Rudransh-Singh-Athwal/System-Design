#include <bits/stdc++.h>
using namespace std;

class MySQLDatabase // Low-level module
{
public:
    void saveToSQL(string data)
    {
        cout << "Executing SQL Query: INSERT INTO users VALUES('" << data << "');" << endl;
    }
};

class MongoDBDatabase // Low-level module
{
public:
    void saveToMongo(string data)
    {
        cout << "Executing MongoDB function: db.users.insert({name: '" << data << "'})" << endl;
    }
};

class UserService // Tightly coupled
{
private:
    MySQLDatabase sqlDB;     // direct dependency on MySQLDatabase
    MongoDBDatabase mongoDB; // direct dependency on MongoDBDatabase

public:
    void storeUserToSQL(string user)
    {
        sqlDB.saveToSQL(user);
    }

    void storeUserToMongoDB(string user)
    {
        mongoDB.saveToMongo(user);
    }
};

int main()
{
    UserService service;
    service.storeUserToSQL("Aditya");
    service.storeUserToMongoDB("Raj");

    return 0;
}