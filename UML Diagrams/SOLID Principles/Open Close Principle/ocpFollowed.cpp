#include <bits/stdc++.h>
using namespace std;

class Product
{
public:
  string name;
  double price;

  Product(string n, double p) : name(n), price(p) {}
};

class ShoppingCart
{
private:
  vector<Product *> products;

public:
  void addProduct(Product *p)
  {
    products.push_back(p);
  }

  const vector<Product *> &getProducts()
  {
    return products;
  }

  // Calculate total price of the cart
  double calculateTotal()
  {
    double total = 0;
    for (auto p : products)
    {
      total += p->price;
    }

    return total;
  }
};

class ShoppingCartPrinter
{
  ShoppingCart *cart;

public:
  ShoppingCartPrinter(ShoppingCart *cart)
  {
    this->cart = cart;
  }

  void printInvoice()
  {
    cout << "Shopping cart invoice:-\n";
    for (auto p : cart->getProducts())
    {
      cout << "   " << p->name << " - $ " << p->price << endl;
    }
    cout << "Total: $" << cart->calculateTotal() << endl;
  }
};

class Persistence // ShoppingCartStorage
{
  ShoppingCart *cart;

public:
  virtual void save(ShoppingCart *cart) = 0;
};

class SQLPersistence : public Persistence
{
public:
  void save(ShoppingCart *cart)
  {
    cout << "Cart saved to SQL Database...\n";
  }
};

class MongoDBPersistence : public Persistence
{
public:
  void save(ShoppingCart *cart)
  {
    cout << "Cart saved to MongoDB Database...\n";
  }
};

class FilePersistence : public Persistence
{
public:
  void save(ShoppingCart *cart)
  {
    cout << "Cart saved to Files...\n";
  }
};

int main()
{
  ShoppingCart *cart = new ShoppingCart();

  cart->addProduct(new Product("Laptop", 105000));
  cart->addProduct(new Product("Mouse", 500));

  ShoppingCartPrinter *printer = new ShoppingCartPrinter(cart);
  printer->printInvoice();

  Persistence *sql = new SQLPersistence();
  Persistence *mongoDB = new MongoDBPersistence();
  Persistence *file = new FilePersistence();

  sql->save(cart);
  mongoDB->save(cart);
  file->save(cart);

  return 0;
}