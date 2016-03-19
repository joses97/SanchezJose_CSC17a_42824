/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Created on March 18 2016
 * Purpose: Create a dynamic array
 *  */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
int* allMem(int& number); //allocate mem

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    int number=0;       //set number to initial value of 0
    int *array;         //create pointer
    
    //explain
    cout<<"Gaddis 8thEd Chapter 9 Problem 1"<<endl;
    cout<<"This program creates a dynamic array"<<endl;
    array=allMem(number); //make array
    delete [] array; //delete array
    array = NULL;   //delete pointer
    
    //exit
    return 0;
}
//Allocate memory to array
int* allMem(int& number){
    cout<<"Please enter the size of the array"<<endl;
    cin>>number;//input number
    
    //create dynamic array based on number
    int *array=new int[number]; //create dynamic array
    cout<<"Fill the array"<<endl;
    
    //for loop, to input values to the array
    for(int i=0; i<number; i++){
        cout<<"Array at "<<i<<": "; 
        cin>>array[i]; //input values into the array
    }
    
    return array;
    
}
