//
//  main.cpp
//  Newton's Method Project
//
//  Created by Samuel Peters on 11/2/17.
//  Copyright © 2017 Samuel Peters. All rights reserved.
//  Description: A program that accepts coefficients that determine a polynomial expression and a guess at an x-intercept as inputs. It should output an "improved guess" as the x-intercept.

#include <iostream>
using namespace std;

//*******************************************************************************************************
void user_input(int & a, int & b, int & c, int & d, int & e);
// Summary: Explains the purpose of this program, then Takes in 4 values from the user regarding all 4 coefficients
// Preconditions: Values entered must be of data type int.
// Postconditions: Values used in parameter will be set equal to the user's input.
//*******************************************************************************************************
void print_equation(int a, int b, int c, int d, int e);
// Summary: This equations uses 4 number inputs and prints out a quadratic of 4th degree with the inputs as coefficients
// Preconditions: All inputs must be numbers
// Postconditions: Quadratic equation is printed out
//*******************************************************************************************************
double round_to_4th_decimal(double a);
// Summary: This function takes in a value of type double and returns that double rounded to the 4th decimal point.
// Preconditions: Value entered is of type double
// Postconditions: a double is returned that has been rounded to the 4th decimal point
//*******************************************************************************************************
double f(double x, int a, int b, int c, int d, int e);
// Summary: Takes in an x value and 4 values that correlate to a fourth degree polynomial functions, then returns f(x) of
// that function.
// Preconditions: Takes in 5 int values, 1st is the x, the next 4 parameters are coefficients of the function.
// Postconditions: Returns a double value which corresponds to f(x).
//*******************************************************************************************************
double f_prime(double x, int a, int b, int c, int d, int e);
// Summary: Takes in an x value and 4 values that correlate to a fourth degree polynomial functions, then returns f'(x) of
// that function.
// Preconditions: Takes in 5 int values, 1st is the x, the next 4 parameters are coefficients of the function.
// Postconditions: Returns a double value which corresponds to f'(x).
//*******************************************************************************************************
void print_equation_no_endl(int a, int b, int c, int d, int e);
// Summary: This equations uses 4 number inputs and prints out a quadratic of 4th degree with the inputs as coefficients
// Preconditions: All inputs must be numbers
// Postconditions: Quadratic equation is printed out
//*******************************************************************************************************

int main()
{
    // USER INPUT
    int coefficient_4th_exponent, coefficient_3th_exponent, coefficient_2th_exponent, coefficient_1th_exponent, coefficient_0th_exponent;
    user_input(coefficient_4th_exponent, coefficient_3th_exponent, coefficient_2th_exponent, coefficient_1th_exponent, coefficient_0th_exponent);
    
    // PRINT EQUATION
    print_equation(coefficient_4th_exponent, coefficient_3th_exponent, coefficient_2th_exponent, coefficient_1th_exponent, coefficient_0th_exponent);
    
    // TAKING IN INITIAL GUESS FROM USER
    double initial_guess;
    cout << "\nEnter your initial guess of an x intercept:\n";
    cin >> initial_guess;
   
    
    // FINDING CLOSEST X-INTERCEPT TO INITIAL GUESS
    double x2 = initial_guess - (f(initial_guess, coefficient_4th_exponent, coefficient_3th_exponent, coefficient_2th_exponent, coefficient_1th_exponent, coefficient_0th_exponent) / f_prime(initial_guess, coefficient_4th_exponent, coefficient_3th_exponent, coefficient_2th_exponent, coefficient_1th_exponent, coefficient_0th_exponent));
    while( round_to_4th_decimal(x2) != round_to_4th_decimal(initial_guess) )
    {
        initial_guess = x2;
        x2 = x2 - (f(x2, coefficient_4th_exponent, coefficient_3th_exponent, coefficient_2th_exponent, coefficient_1th_exponent, coefficient_0th_exponent) / f_prime(x2, coefficient_4th_exponent, coefficient_3th_exponent, coefficient_2th_exponent, coefficient_1th_exponent, coefficient_0th_exponent));
    }
    
    // PRINTING OUT GUESS OF X-INTERCEPT ACCURATE TO 4 DECIMAL PLACES
    cout << "I found the closest x-intercept!!! It is ";
    print_equation_no_endl(coefficient_4th_exponent, coefficient_3th_exponent, coefficient_2th_exponent, coefficient_1th_exponent, coefficient_0th_exponent);
    cout << " is " << x2 << ". This guess is EXTREMELY ACCURATE to the 4th decimal point.\n";
    
    
    
    return 0;
}

void user_input(int & a, int & b, int & c, int & d, int & e)
{
    cout << "This program takes in 4 coefficients of a polynomial expression of the 4th degree and an initial guess of one of this equations's x-intercepts. It will then output an \"improved guess\" accurate to 4 decimal points of that x-intercept using Newton's Method.\n\n";
    cout << "Slam in the coefficient for x^4?:\n";
    cin >> a;
    cout << "\nDrop in that coefficient for x^3?:\n";
    cin >> b;
    cout << "\nKey in the coefficient for x^2?:\n";
    cin >> c;
    cout << "\nWhat is the coefficient for x^1?:\n";
    cin >> d;
    cout << "\nSlam in the last coefficient for x^0?:\n";
    cin >> e;
}

void print_equation(int a, int b, int c, int d, int e)
{
    cout << "\nYou are calculating the principle root of";
    if (a != 0)
        cout << " " << a << "x^4";
    if (b != 0)
    {
        if (a == 0 and b > 0)
            cout << " " << b << "x^3";
        else if (b > 0)
            cout << " + " << b << "x^3";
        else
            cout << " " << b << "x^3";
    }
    if (c != 0)
    {
        if (a == 0 && b == 0 && c > 0)
            cout << " " << c << "x^2";
        else if (c > 0)
            cout << " + " << c << "x^2";
        else
            cout << " " << c << "x^2";
    }
    if (d != 0)
    {
        if (a == 0 && b == 0 && c == 0 && d > 0)
            cout << " " << d << "x";
        else if (d > 0)
            cout << " + " << d << "x";
        else
            cout << " " << d << "x";
    }
    if (e != 0)
    {
        if (a == 0 && b == 0 && c == 0 && d == 0 && e > 0)
            cout << " " << e;
        else if (e > 0)
            cout << " + " << e;
        else
            cout << " " << e;
    }
    cout << " = 0\n";
}

double round_to_4th_decimal(double a)
{
    if (a >= 0)
        a = a + .00005;
    else
        a = a - .00005;
    a = a * 10 * 10 * 10 * 10;
    a = int(a);
    a = a / 10 / 10 / 10 / 10;
    return a;
}

double f(double x, int a, int b, int c, int d, int e)
{
    double f_of_x = (a * x * x * x * x) + (b * x * x * x) + (c * x * x) + (d * x) + e;
    return f_of_x;
}

double f_prime(double x, int a, int b, int c, int d, int e)
{
    double f_prime_of_x = (4 * a * x * x * x) + (3 * b * x * x) + (2 * c * x) + d;
    return f_prime_of_x;
}

void print_equation_no_endl(int a, int b, int c, int d, int e)
{
    if (a != 0)
        cout << " " << a << "x^4";
    if (b != 0)
    {
        if (a == 0 and b > 0)
            cout << " " << b << "x^3";
        else if (b > 0)
            cout << " + " << b << "x^3";
        else
            cout << " " << b << "x^3";
    }
    if (c != 0)
    {
        if (a == 0 && b == 0 && c > 0)
            cout << " " << c << "x^2";
        else if (c > 0)
            cout << " + " << c << "x^2";
        else
            cout << " " << c << "x^2";
    }
    if (d != 0)
    {
        if (a == 0 && b == 0 && c == 0 && d > 0)
            cout << " " << d << "x";
        else if (d > 0)
            cout << " + " << d << "x";
        else
            cout << " " << d << "x";
    }
    if (e != 0)
    {
        if (a == 0 && b == 0 && c == 0 && d == 0 && e > 0)
            cout << " " << e;
        else if (e > 0)
            cout << " + " << e;
        else
            cout << " " << e;
    }
    cout << " = 0";
}
