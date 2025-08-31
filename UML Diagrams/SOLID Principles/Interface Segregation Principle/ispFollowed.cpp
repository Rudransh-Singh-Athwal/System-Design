#include <bits/stdc++.h>
using namespace std;

class Shape2D
{
public:
  virtual void area() = 0;
};

class Shape3D
{
public:
  virtual void area() = 0;
  virtual void volume() = 0;
};

class Square : public Shape2D
{
public:
  void area()
  {
    cout << "Success: Area for square calculated successfully\n";
  }
};

class Rectangle : public Shape2D
{
public:
  void area()
  {
    cout << "Success: Area for rectangle calculated successfully\n";
  }
};

class Cube : public Shape3D
{
public:
  void area()
  {
    cout << "Success: Area for cube calculated successfully\n";
  }

  void volume()
  {
    cout << "Success: Volume for cube calculated successfully\n";
  }
};

int main()
{
  Shape2D *sq = new Square();
  Shape2D *rec = new Rectangle();
  Shape3D *cube = new Cube();
  cout << "Calculating areas...\n";
  sq->area();
  rec->area();
  cube->area();

  cout << "\nCalculating volumes...\n";
  cube->volume();

  return 0;
}