#include <bits/stdc++.h>
using namespace std;

class Car
{
public:
  virtual void startEngine() = 0;
  virtual void shiftGear(int gear) = 0;
  virtual void accelerate() = 0;
  virtual void brake() = 0;
  virtual void stopEngine() = 0;
  virtual ~Car() {};
};

class SportsCar : public Car
{
public:
  string brand, model;
  bool isEngineOn;
  int currentSpeed, currentGear;

  SportsCar(string brand, string model)
  {
    this->brand = brand;
    this->model = model;
    isEngineOn = false;
    currentSpeed = 0;
    currentGear = 0; // neutral
  }

  void startEngine()
  {
    isEngineOn = true;
    cout << brand << " " << model << ": Engine started with a roar!\n";
  }

  void shiftGear(int n)
  {
    if (!isEngineOn)
    {
      cout << brand << " " << model << ": Engine is OFF! Cannot shift gear\n";
      return;
    }
    currentGear = n;
    cout << brand << " " << model << ": Gear shifted to " << currentGear << endl;
  }

  void accelerate()
  {
    if (!isEngineOn)
    {
      cout << brand << " " << model << ": Engine is OFF! Cannot accelerate\n";
      return;
    }
    currentSpeed += 20;
    cout << brand << " " << model << ": Accelerating to " << currentSpeed << " Km/h" << endl;
  }

  void brake()
  {
    currentSpeed -= 20;
    currentSpeed = max(currentSpeed, 0);
    cout << brand << " " << model << ": Braking! Speed is now " << currentSpeed << " Km/h" << endl;
  }

  void stopEngine()
  {
    isEngineOn = false;
    currentSpeed = 0;
    currentGear = 0;
    cout << brand << " " << model << ": Engine turned off!" << endl;
  }
};

int main()
{
  Car *myCar = new SportsCar("BMW", "M5");
  myCar->startEngine();
  myCar->shiftGear(1);
  myCar->accelerate();
  myCar->shiftGear(2);
  myCar->accelerate();
  myCar->shiftGear(4);
  myCar->accelerate();
  myCar->accelerate();
  myCar->accelerate();
  myCar->accelerate();
  myCar->brake();
  myCar->brake();
  myCar->stopEngine();

  delete myCar;

  return 0;
}