#include <iostream>
#include <iomanip> // For setting precision

using namespace std;

double CelsiusToFahrenheit(double celsius) {
    return (celsius * 9.0/5.0) + 32.0;
}

double FahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0/9.0;
}

double CelsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double KelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

void displayMenu() {
    cout << "Temperature Converter" << endl;
    cout << "1. Celsius to Fahrenheit" << endl;
    cout << "2. Fahrenheit to Celsius" << endl;
    cout << "3. Celsius to Kelvin" << endl;
    cout << "4. Kelvin to Celsius" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice (1-5): ";
}

int main() {
    int choice;
    double temperature, convertedTemperature;

    do {
        displayMenu();
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter the temperature: ";
            cin >> temperature;
        }

        switch (choice) {
            case 1:
                convertedTemperature = CelsiusToFahrenheit(temperature);
                cout << "Converted Temperature: " << fixed << setprecision(2) << convertedTemperature << " Fahrenheit" << endl;
                break;
            case 2:
                convertedTemperature = FahrenheitToCelsius(temperature);
                cout << "Converted Temperature: " << fixed << setprecision(2) << convertedTemperature << " Celsius" << endl;
                break;
            case 3:
                convertedTemperature = CelsiusToKelvin(temperature);
                cout << "Converted Temperature: " << fixed << setprecision(2) << convertedTemperature << " Kelvin" << endl;
                break;
            case 4:
                convertedTemperature = KelvinToCelsius(temperature);
                cout << "Converted Temperature: " << fixed << setprecision(2) << convertedTemperature << " Celsius" << endl;
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}
