// Dynamic polymorphism: Method overriding
// Static polymorphism: Method overloading

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

  void stopEngine()
  {
    isEngineOn = false;
    currentSpeed = 0;
    cout << brand << " " << model << ": Engine turned off!" << endl;
  }

  virtual void accelerate() = 0; // abstract method for dynamic polymorphism
  virtual void brake() = 0;      // abstract method for dynamic polymorphism
  virtual ~Car() {};             // virtual destructor
};

class ManualCar : public Car
{
private:
  int currentGear;

public:
  ManualCar(string b, string m) : Car(b, m)
  {
    this->currentGear = 0;
  }

  void shiftGear(int gear)
  {
    if (!isEngineOn)
    {
      cout << brand << " " << model << "The engine is currently off\n";
      return;
    }
    currentGear = gear;
    cout << brand << " " << model << ": Gear shifted to " << currentGear << endl;
  }

  void accelerate()
  {
    if (!isEngineOn)
    {
      cout << brand << " " << model << ": Engine is OFF! Cannot accelerate\n";
      return;
    }
    if (currentGear == 0)
    {
      cout << brand << " " << model << ": The car is in neutral! Please shift the gear before accelerating\n";
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

  void accelerate()
  {
    if (!isEngineOn)
    {
      cout << brand << " " << model << ": Engine is OFF! Cannot accelerate\n";
      return;
    }
    if (batteryPercentage <= 0)
    {
      cout << "Battery dead! Cannot accelerate" << endl;
      return;
    }
    batteryPercentage -= 10;
    currentSpeed += 15;
    cout << brand << " " << model << ": Accelerating to " << currentSpeed << " Km/h\nBattery down to " << batteryPercentage << "%" << endl;
  }

  void brake()
  {
    currentSpeed -= 15;
    currentSpeed = max(currentSpeed, 0);
    cout << brand << " " << model << ": Regenerative Braking! Speed is now " << currentSpeed << " Km/h" << endl;
  }

  void chargeBattery()
  {
    batteryPercentage = 100;
    cout << brand << " " << model << ": Battery fully charged!" << endl;
  }
};

int main()
{
  // The pointer is of type Car because we don't use any method that is not defined in Car itself, like if we want to shift gear in manual car, we have to define the pointer pointing to ManualCar as the function to shift gear (shiftGear) is in ManualCar and not in Car
  Car *mCar = new ManualCar("Tata", "Harrier");
  mCar->startEngine();
  mCar->accelerate();
  mCar->accelerate();
  mCar->brake();
  mCar->stopEngine();

  cout << "=======================\n";

  Car *eCar = new ElectricCar("Tesla", "Model Y");
  eCar->startEngine();
  eCar->accelerate();
  eCar->accelerate();
  eCar->brake();
  eCar->stopEngine();

  // Cleanup
  delete mCar;
  delete eCar;

  return 0;
}