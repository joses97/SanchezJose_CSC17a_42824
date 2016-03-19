/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Created on March 18 2016
 * Purpose: problem 9.5
 *  */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
int doSomething(int *x, int *y); //function name provided by text

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variable
    int a=0; //initialize a to 0    
    int b=0; //initialize b to 0
    
    //explain
    cout<<"Gaddis 8thEd Chapter 9 problem 5"<<endl;
    cout<<"This program takes two numbers entered by the user then multiplies "
            "each by 10 using pointer, then sums them"<<endl;

    cout<<"Enter a number"<<endl;
    cin>>a;
    
    cout<<"Enter another number"<<endl;
    cin>>b;
    
    cout<<doSomething(&a, &b)<<endl;
    
    //exit
    return 0;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
int doSomething(int *x, int *y) //takes in pointers
{
    int temp = *x;  //set temp to pointer x 
    *x = *y * 10;   //set pointer x  equal to pointer y * 10
    *y = temp * 10; //set pointer y equal to temp * 10
    return *x + *y; //return pointer x+ pointer y
}