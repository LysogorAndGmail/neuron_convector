#include <iomanip>
#include <iostream>
#include <memory>

using namespace std;

class Neuron { 
  public:
    double weight = 0.5;
    long double smoothing = 0.00001;
    long double lastError;
    long double ProcessInputData(long double input) {
        return input * weight;
    }
    long double RestorInputData(long double output) {
        return output / weight;
    }
    void Train(long double input, long double expectedResult) {
        
        long double actualResult = input * weight;
        lastError = expectedResult - actualResult;
        long double correction = (lastError / actualResult) * smoothing;
        weight += correction;
    }
};

int main() {

    Neuron neuron;
    
    float km = 1;
    float km2 = 587;
    float km3 = 2000;
    long double miles = 0.62137;

    int i = 0;
    do {
        neuron.Train(km, miles);
        if(i%10000 == 0) {
            cout <<"Iteration:"<< i << " Errors:"<< std::to_string(neuron.lastError) << "\n";
        }
        i++;
    }
    while (neuron.lastError > neuron.smoothing || neuron.lastError < -neuron.smoothing);

    cout << "training completed." << endl;

    std::cout << "In " << km << "km " << neuron.ProcessInputData(km) << "miles" << "\n";
    std::cout << "In " << km2 << "km " << neuron.ProcessInputData(km2) << "miles" << "\n";
    std::cout << "In " << km3 << "km " << neuron.ProcessInputData(km3) << "miles" << "\n";

  return 0;
}







