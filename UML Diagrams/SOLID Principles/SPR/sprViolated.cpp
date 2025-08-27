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

  // 1. Calculate total price of the cart
  double calculateTotal()
  {
    double total = 0;
    for (auto p : products)
    {
      total += p->price;
    }

    return total;
  }

  // 2. Violating SPR: should be in a separate class
  void printInvoice()
  {
    cout << "Shopping cart invoice:-\n";
    for (auto p : products)
    {
      cout << "   " << p->name << " -$ " << p->price << endl;
    }
    cout << "Total: $" << calculateTotal() << endl;
  }

  // 3. Violating SPR
  void saveToDatabase()
  {
    cout << "Shopping cart saved to database\n";
  }
};

int main()
{
  ShoppingCart *cart = new ShoppingCart();

  cart->addProduct(new Product("Laptop", 105000));
  cart->addProduct(new Product("Mouse", 500));

  cart->printInvoice();
  cart->saveToDatabase();

  return 0;
}