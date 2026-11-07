
#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

// Get the journey distance in miles
double getDistance() {
    double distance;

    cout << "Enter journey distance in miles: ";
    cin >> distance;

    return distance;
}

// Get the fuel type from the user
int getFuelType() {
    int fuel;

    cout << "\nSelect fuel type:" << endl;
    cout << "1. Petrol" << endl;
    cout << "2. Diesel" << endl;
    cout << "Enter your choice (1 or 2): ";
    cin >> fuel;

    return fuel;
}

// Calculate estimated CO2 emissions in kilograms
double calculateCO2(double miles, int fuel) {
    const double consumption = 9.66;
    const double petrolFactor = 2.31;
    const double dieselFactor = 2.68;

    double litres = (miles / 100.0) * consumption;

    if (fuel == 1) {
        return litres * petrolFactor;
    }
    else {
        return litres * dieselFactor;
    }
}

int main() {
    cout << "CO2 Emissions Calculator" << endl;

    double miles = getDistance();

    if (!cin || miles < 0) {
        cout << "Invalid distance." << endl;
        return 1;
    }

    int fuel = getFuelType();

    if (!cin || (fuel != 1 && fuel != 2)) {
        cout << "Invalid fuel selection." << endl;
        return 1;
    }

    double emissions = calculateCO2(miles, fuel);

    cout << fixed << setprecision(2);
    cout << "\nJourney distance: " << miles << " miles" << endl;

    if (fuel == 1) {
        cout << "Fuel type: Petrol" << endl;
    }
    else {
        cout << "Fuel type: Diesel" << endl;
    }

    cout << "Estimated CO2 emissions: "
         << emissions << " kg" << endl;

    return 0;
}
