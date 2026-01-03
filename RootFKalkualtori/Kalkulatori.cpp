#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

// ===== Function Prototypes =====
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double a, double b);
double squareRoot(double a);
void showMenu();
bool getDouble(double& value);

// ===== Main Function =====
int main() {
    int choice;
    double num1, num2;
    bool running = true;

    cout << "=== Advanced C++ Calculator ===" << endl;

    while (running) {
        showMenu();

        cout << "Choose an option: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
        case 1: // Addition
            cout << "Enter first number: ";
            if (!getDouble(num1)) break;
            cout << "Enter second number: ";
            if (!getDouble(num2)) break;
            cout << "Result: " << add(num1, num2) << endl;
            break;

        case 2: // Subtraction
            cout << "Enter first number: ";
            if (!getDouble(num1)) break;
            cout << "Enter second number: ";
            if (!getDouble(num2)) break;
            cout << "Result: " << subtract(num1, num2) << endl;
            break;

        case 3: // Multiplication
            cout << "Enter first number: ";
            if (!getDouble(num1)) break;
            cout << "Enter second number: ";
            if (!getDouble(num2)) break;
            cout << "Result: " << multiply(num1, num2) << endl;
            break;

        case 4: // Division
            cout << "Enter numerator: ";
            if (!getDouble(num1)) break;
            cout << "Enter denominator: ";
            if (!getDouble(num2)) break;

            if (num2 == 0) {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            else {
                cout << "Result: " << divide(num1, num2) << endl;
            }
            break;

        case 5: // Power
            cout << "Enter base: ";
            if (!getDouble(num1)) break;
            cout << "Enter exponent: ";
            if (!getDouble(num2)) break;
            cout << "Result: " << power(num1, num2) << endl;
            break;

        case 6: // Square root
            cout << "Enter number: ";
            if (!getDouble(num1)) break;

            if (num1 < 0) {
                cout << "Error: Cannot calculate square root of a negative number." << endl;
            }
            else {
                cout << "Result: " << squareRoot(num1) << endl;
            }
            break;

        case 0: // Exit
            running = false;
            cout << "Exiting calculator. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid option. Please choose again." << endl;
        }

        cout << endl;
    }

    return 0;
}

// ===== Function Definitions =====
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double power(double a, double b) {
    return pow(a, b);
}

double squareRoot(double a) {
    return sqrt(a);
}

void showMenu() {
    cout << "\n--- Calculator Menu ---" << endl;
    cout << "1. Addition (+)" << endl;
    cout << "2. Subtraction (-)" << endl;
    cout << "3. Multiplication (*)" << endl;
    cout << "4. Division (/)" << endl;
    cout << "5. Power (a^b)" << endl;
    cout << "6. Square Root (sqrt)" << endl;
    cout << "0. Exit" << endl;
}

bool getDouble(double& value) {
    cin >> value;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid number input." << endl;
        return false;
    }
    return true;
}