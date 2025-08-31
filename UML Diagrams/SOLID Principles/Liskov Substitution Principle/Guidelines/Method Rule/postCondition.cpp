#include <bits/stdc++.h>
using namespace std;

class Car
{
protected:
  int speed;

public:
  void accelerate()
  {
    cout << "Accelerating...\n";
    speed += 20;
  }

  // Postcondition: Speed must reduce after braking
  virtual void brake()
  {
    cout << "Applying brakes...\n";
    speed -= 20;
  }
};

class HybridCar : public Car
{
private:
  int battery;

public:
  // Postcondition: Speed must reduce after braking
  // Postcondition: Battery must increase after braking
  void brake() override
  {
    cout << "Applying brakes...\n";
    speed -= 20;
    battery += 10;
  }
};

int main()
{
  Car *car = new HybridCar();
  HybridCar *hCar = new HybridCar();
  car->accelerate();
  car->accelerate();
  car->accelerate();
  car->brake();

  hCar->accelerate();
  hCar->accelerate();
  hCar->accelerate();
  hCar->brake();

  return 0;
}