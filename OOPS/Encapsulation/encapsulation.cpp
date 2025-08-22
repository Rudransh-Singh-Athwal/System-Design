#include <bits/stdc++.h>
using namespace std;

class SportsCar
{
private:
  // Characters
  string brand, model, tyre;
  bool isEngineOn;
  int currentSpeed, currentGear;

public:
  SportsCar(string brand, string model)
  {
    this->brand = brand;
    this->model = model;
    isEngineOn = false;
    currentSpeed = 0;
    currentGear = 0; // neutral
  }

  // getters and setters
  int getCurrentSpeed()
  {
    // cout << "Current speed of your " << brand << " " << model << " is " << currentSpeed << endl;
    return this->currentSpeed;
  }

  string getTyre()
  {
    return this->tyre;
  }

  void setTyre(string tyre)
  {
    this->tyre = tyre;
  }

  // Behaviours / Methods
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
  SportsCar *myCar = new SportsCar("BMW", "M5");
  myCar->startEngine();
  myCar->shiftGear(1);
  myCar->accelerate();
  myCar->shiftGear(2);
  myCar->accelerate();
  myCar->brake();
  myCar->stopEngine();

  // myCar->currentSpeed = 800;
  // cout << "Speed set to " << myCar->currentSpeed << endl;

  // cout << "Current speed of your car is " << myCar->getCurrentSpeed() << endl;

  cout << myCar->getCurrentSpeed();

  delete myCar;

  return 0;
}