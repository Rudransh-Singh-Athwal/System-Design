#include <bits/stdc++.h>
using namespace std;

class Car
{
protected:
  string brand, model;
  bool isEngineOn;
  int currentSpeed;

public:
  Car(string brand, string model)
  {
    this->brand = brand;
    this->model = model;
    isEngineOn = false;
    currentSpeed = 0;
  }

  void startEngine()
  {
    isEngineOn = true;
    cout << brand << " " << model << ": Engine started!\n";
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
    cout << brand << " " << model << ": Engine turned off!" << endl;
  }

  virtual ~Car() {};
};

class ManualCar : public Car
{
private:
  int currentGear;

public:
  ManualCar(string b, string m) : Car(b, m)
  {
    currentGear = 0;
  }

  void shiftGear(int n)
  {
    if (!isEngineOn)
    {
      cout << brand << " " << model << "The engine is currently off\n";
      return;
    }
    currentGear = n;
    cout << brand << " " << model << ": Gear shifted to " << currentGear << endl;
  }
};

class ElectricCar : public Car
{
private:
  int batteryPercentage;

public:
  ElectricCar(string b, string m) : Car(b, m)
  {
    batteryPercentage = 100;
  }

  void chargeBattery()
  {
    batteryPercentage = 100;
    cout << brand << " " << model << ": Battery fully charged!" << endl;
  }
};

int main()
{
  ManualCar *mCar = new ManualCar("Tata", "Harrier");
  mCar->startEngine();
  mCar->shiftGear(1);
  mCar->accelerate();
  mCar->shiftGear(2);
  mCar->accelerate();
  mCar->brake();
  mCar->stopEngine();

  delete mCar;

  cout << "=======================\n";

  ElectricCar *eCar = new ElectricCar("Tesla", "Model Y");
  eCar->chargeBattery();
  eCar->startEngine();
  eCar->accelerate();
  eCar->accelerate();
  eCar->brake();
  eCar->stopEngine();
  delete eCar;

  return 0;
}