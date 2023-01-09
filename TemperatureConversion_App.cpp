#include <iostream>
#include <iomanip>

using namespace std;


//Create an array to store the Fahrenheit temperatures
#define MAX_INPUT 10

//Define function prototypes
void showMenu();
int getOption();
void showCelsius(double tempurature);
void showKelvin(double tempurature);
void printMatrix(double arr[][MAX_INPUT], int row, int col);
void convert(double arr[][MAX_INPUT], int row, int col);
double convertCelsius(double tempurature);
double convertKelvin(double tempurature);


int main() {
    int count = 0;
    //Initialize a variable to store the user's menu selection
    int option = 1;
    double tempurature;
    double table[3][MAX_INPUT];

    //Process the user's selection
    while (option != 4) {
        showMenu();
        option = getOption();
        //Option 1
        if (option == 1) {
            // Check if user enter over 10 inputs.
            if (count == MAX_INPUT) {
                cout << "Error. User already enter 10 temperature inputs" << endl << endl;
                continue;
            }
            cout << "Enter a Fahrenheit temperature: ";
            cin >> tempurature;
            showCelsius(tempurature);
            // Store data into 2D array
            table[0][count] = tempurature;
            convert(table, 3, count);
            count++;

        }
        //Option 2
        else if (option == 2) {
            // Check over 10 inputs?
            if (count == MAX_INPUT) {
                cout << "Error. User already enter 10 temperature inputs" << endl << endl;
                continue;
            }
            cout << "Enter a Fahrenheit temperature: ";
            cin >> tempurature;
            showKelvin(tempurature);
            while (convertKelvin(tempurature) < 0) {
                cout << "Error! Kelvin tempurature cannot be negative. Please try again." << endl;
                cout << "Enter a Fahrenheit temperature: ";
                cin >> tempurature;
            }
            // Store data into 2D array
            table[0][count] = tempurature;
            convert(table, 3, count);
            count++;
        }
        //Option 3
        else if (option == 3) {
            printMatrix(table, 3, count);
        }
        //Option 4
        else {
            cout << "Quit! Good bye" << endl;
        }
        cout << endl;


    }

    return 0;
}

void showMenu() {
    //Display the menu and get the user's selection
    cout << "Select one of the following options:" << endl;
    cout << "\t1. Convert Fahrenheit to Celsius (Centigrade) " << endl;
    cout << "\t2. Convert Fahrenheit to Kelvin " << endl;
    cout << "\t3. Display Data " << endl;
    cout << "\t4. Quit Program " << endl;
}

int getOption() {
    // Get valid option 1-> 4
    int op;
    cout << "Enter your choice: ";
    cin >> op;
    // Validate user selection
    while (op != 1 && op != 2 && op != 3 && op != 4) {
        //Display the menu and get the user's selection again
        cout << "Invalid option. Please try again (1-4)" << endl;
        cout << "Enter your choice: ";
        cin >> op;
    }
    return op;
}

//Converts a F to C, and stores it in the array
void showCelsius(double tempurature) {
    double Celsius = 0;
    //Find the corresponding Celsius temperature
    Celsius = ((double)5 / 9) * (tempurature - 32);
    //Print out Celsius.
    cout << setprecision(1) << fixed;
    cout << "\t" << tempurature << " Fahrenheit = " << Celsius << " Celsius" << endl;

}

//Converts a F to K, and stores it in the array
void showKelvin(double tempurature) {
    double K = 0;

    //the corresponding Kelvin temperature
    K = (5 / 9) * (tempurature - 32) + 273.15;
    //Print out Kevin.
    cout << "\t" << tempurature << " Fahrenheit = " << K << " Kelvin" << endl;
}

//Displays all of the data stored in the array
void printMatrix(double arr[][MAX_INPUT], int row, int col) {
    cout << "Data Entered:" << endl;
    cout << setprecision(1) << fixed;
    for (int i = 0; i < row; i++) {
        cout << setw(12) << left;
        if (i == 0) {
            cout << "Farenheit: ";
        }
        else if (i == 1) {
            cout << "Celsius: ";
        }
        else {
            cout << "Kelvin: ";
        }

        for (int j = 0; j < col; j++) {
            cout << setw(6) << right << arr[i][j] << "   ";
        }
        cout << endl;
    }
}


double convertCelsius(double tempurature) {
    double Celsius = 0;
    //Convert degrees Fahrenheit to Celsius degrees.
    Celsius = ((double)5 / (double)9) * (tempurature - 32);
    //Print out Celsius.
    return Celsius;
}

double convertKelvin(double tempurature) {
    double K = 0;
    //Calculate Kevin interm of Fahrenheit.
    K = ((double)5 / (double)9) * (tempurature - 32) + 273.15;
    //Print out Kevin.
    return K;
}

void convert(double arr[][MAX_INPUT], int row, int col) {
    // Handle Celsius
    for (int j = 0; j <= col; j++) {
        // Take F degree -> double 
        double F = arr[0][j];
        // Call fucntion convet F to C
        double C = convertCelsius(F);
        // Store C into suitable position in arr
        arr[1][j] = C;
    }

    // Handle Kevin
    for (int j = 0; j <= col; j++) {
        // Take F degree -> double 
        double F = arr[0][j];
        //Call function convert F to K.
        double K = convertKelvin(F);
        // Store K into suitable position in arr
        arr[2][j] = K;
    }

}
