#include <bits/stdc++.h>
using namespace std;

class Shape
{
public:
  virtual void area() = 0;
  virtual void volume() = 0;
};

class Square : public Shape
{
public:
  void area()
  {
    cout << "Success: Area for square calculated successfully\n";
  }

  void volume()
  {
    throw logic_error("Volume doesn't exist for square");
  }
};

class Rectangle : public Shape
{
public:
  void area()
  {
    cout << "Success: Area for rectangle calculated successfully\n";
  }

  void volume()
  {
    throw logic_error("Volume doesn't exist for rectangle");
  }
};

class Cube : public Shape
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
  Shape *sq = new Square();
  Shape *rec = new Rectangle();
  Shape *cube = new Cube();
  cout << "Calculating areas...\n";
  sq->area();
  rec->area();
  cube->area();

  cout << "\nCalculating volumes...\n";
  try
  {
    sq->volume();
  }
  catch (const logic_error &e)
  {
    cout << "Exception: " << e.what() << endl;
  }

  try
  {
    rec->volume();
  }
  catch (const logic_error &e)
  {
    cout << "Exception: " << e.what() << endl;
  }

  cube->volume();

  return 0;
}