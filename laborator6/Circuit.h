#include "Car.h"

class Circuit
{
private:
    int dist;
    Car *masini[100];
    int nrm;
    Weather condition;
    int endtimes[100];
public:
    void SetLength(int val);
    void SetWeather();
    void AddCar(Car *c);
    void SetWeather(Weather w);
    void Race();
    void ShowFinalRanks();
    void ShowWhoDidNotFinish();
    Circuit();
};
