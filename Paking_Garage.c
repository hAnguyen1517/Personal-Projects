
//This program prompts user input the number of a car was parked, 
//designs a charge by hours from the user input
//and display parking garage summary for private parking garage owner

#include<stdio.h>
#include<math.h>

//Define global constants
#define MIN_HOURS_AT_FLAT_RATE 3
#define MIN_FLAT_RATE_CHARGE 3
#define ADDITIONAL_HOURS_RATE 0.75
#define MAX_HOURS_ALLOWED 24
#define MAX_CHARGE 12


//Function Prototypes - Declaring the functions
double getValidInputHour();
double calcChargeByHour(double hours);
printInformation(int id, double hours, double charge);


//Algorithm function mamanages the parking garage system
int main()
{
    //Initialize car id
    int id = 0;
    //Initialize total hours to 0
    double total_hours = 0;
    //Initialize total charge to 0
    double total_charge = 0;
    //Get user input for valid hours
    double hours = getValidInputHour();

    //Process hours then calculate total hours, toal charge
    //then print out the information of car id, hours, charge base on the hours enter by user 
    // until user enter -1 exit program and print out Parking Garage summary
    while (hours != -1) {
        double charge = calcChargeByHour(hours);
        total_hours += hours;
        total_charge += charge;
        id = id + 1;  //Update car to next car then process display information
        printInformation(id, hours, charge);
        //Clear input buffer
        while ((getchar()) != '\n');
        hours = getValidInputHour(); //Get hours until valid
    }//end while loop


    puts("Parking Garage Summary");
    //Check for total hours, then print out the parking garage summary
    if (total_hours != 0) {
        printf("%-18s%-18s%-18s\n", "Total Cars", "Total Hours", "Total Charge");
        printf("%-18d%-18.1lf%-18.2lf\n", id, total_hours, total_charge);
    }

    else
        puts("There were no cars parked today.");
    return 0;
}//end of main


//Task 1: Get number of valid hours follow by the user. 
//Function will return value when input is validated. Keep
// looping until a validate input
double getValidInputHour()
{
    //Initialize input hours
    double hours = 1;
    // Get user input 
    puts("Enter the number of hours the car was parked or enter -1 to quit. ");
    //Read the hours into the variable hours and store the result in scanfReturnValue
    int scanfReturnValue = scanf("%lf", &hours);

    //Check return value for valid input, check the range of the input
    while (scanfReturnValue != 1 || (hours < 0 && hours != -1)) {
        //print out the error message to re-enter hours
        puts("You did not enter a number");
        //Clear the input buffer
        while ((getchar()) != '\n');  // ; means do nothing inside b.c it will ignore newline
        puts("Enter the number of hours the car was parked or enter -1 to quit. ");
        scanfReturnValue = scanf("%lf", &hours); // get hours until valid
    }//end while loop

    return hours;  // for valid hour
}// end of getValidInputHour()

//Task 2: Function calculates the charge based on the number of hours a car was parked
//and return the calculated charge
double calcChargeByHour(double hours) {
    //Initialize price to 0.0
    double price = 0.0;
    //Check for hours entered by user less than or equal MIN_HOURS_AT_FLAT_RATE
    if (hours <= MIN_HOURS_AT_FLAT_RATE) {
        price = MIN_FLAT_RATE_CHARGE;  //Update the price
    }
    else {
        //Calculate price for input greater than MIN_HOURS_AT_FLAT_RATE
        price = ceil(hours - MIN_HOURS_AT_FLAT_RATE) * ADDITIONAL_HOURS_RATE + MIN_FLAT_RATE_CHARGE;
    }
    //Check for the price is over or equal the maximum charge
    if (price >= MAX_CHARGE)
        price = MAX_CHARGE;//update the price
    else
        return price;
}//end of calcChargeByHour()


//Task 3: Function displays the information of a parked car, including id, number of hours parked, the caculated charge
printInformation(int id, double hours, double charge) {
    puts("Parking Garage Summary");
    printf("%-18s%-18s%-18s\n", "Car", "Hours", "Charge");
    printf("%-18d%-18.1lf%-18.2lf\n", id, hours, charge);
}//end of printInformation()
