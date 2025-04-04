#include "Circuit.h"
#include "Volvo.h"
#include "BMW.h"

#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
using namespace std;

int main()
{
    Circuit c;
    Volvo *x;
    x= new Volvo();
    c.SetLength(100);
    c.SetWeather(Weather::Rain);
    c.AddCar(new Volvo());
    c.AddCar(new BMW());
    c.AddCar(new BMW());
    c.AddCar(new BMW());
    c.AddCar(new BMW());
    c.AddCar(new BMW());
    c.AddCar(new Volvo());
   //c.AddCar(new Seat());
   //c.AddCar(new Fiat());
  // c.AddCar(new RangeRover());
    c.Race();
    c.ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the slowest.
    c.ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit
   return 0;
}
