#include <bits/stdc++.h>
using namespace std;

class ManualCar
{
private:
  string model, brand;
  bool isEngineOn;
  int currentSpeed, currentGear;

public:
  ManualCar(string brand, string model)
  {
    this->brand = brand;
    this->model = model;
    this->isEngineOn = false;
    this->currentSpeed = 0;
    this->currentGear = 0;
  }

  void startEngine()
  {
    isEngineOn = true;
    cout << brand << " " << model << ": Engine started!" << endl;
  }

  void shiftGear()
  {
    currentGear = 0;
    cout << brand << " " << model << ": Gear shifted to neutral" << endl;
  }

  void shiftGear(int gear)
  {
    currentGear = gear;
    cout << brand << " " << model << ": Gear shifted to " << currentGear << endl;
  }

  void stopEngine()
  {
    isEngineOn = false;
    currentSpeed = 0;
    shiftGear();
    cout << brand << " " << model << ": Engine turned off!" << endl;
  }

  // Overloading accelerate - Static polymorphism
  void accelerate()
  {
    if (!isEngineOn)
    {
      cout << brand << " " << model << ": Engine is off! Cannot accelerate!" << endl;
      return;
    }
    if (!currentGear)
    {
      cout << brand << " " << model << ": The car is in neutral! Shift gear before accelerating\n";
      return;
    }
    currentSpeed += 20;
    cout << brand << " " << model << ": Accelerating to " << currentSpeed << " Km/h" << endl;
  }

  void accelerate(int speed)
  {
    if (!isEngineOn)
    {
      cout << brand << " " << model << ": Engine is off! Cannot accelerate!" << endl;
      return;
    }
    if (!currentGear)
    {
      cout << brand << " " << model << ": The car is in neutral! Shift gear before accelerating\n";
      return;
    }
    currentSpeed += speed;
    cout << brand << " " << model << ": Accelerating to " << currentSpeed << " Km/h" << endl;
  }

  void brake()
  {
    currentSpeed -= 20;
    currentSpeed = max(currentSpeed, 0);
    cout << brand << " " << model << ": Braking! Speed is now " << currentSpeed << " Km/h" << endl;
  }
};

int main()
{
  ManualCar *mCar = new ManualCar("Tata", "Harrier");
  mCar->startEngine();
  mCar->shiftGear(1);
  mCar->accelerate();
  mCar->accelerate(45);
  mCar->brake();
  mCar->stopEngine();

  delete mCar;

  return 0;
}