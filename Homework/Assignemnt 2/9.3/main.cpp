/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Created on March 18 2016
 * Purpose: problem 9.3
 *  */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
int marksrt(float a[], int); //mark sort
float avg(float a[], int); //find the average

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variable
    int number=0;   //initial size of the array    
    float *array;     //create
    
    //display results to 2 decimal places
    cout<<fixed<<showpoint<<setprecision(2)<<endl;
    
    //explain
    cout<<"Gaddis 8thEd Chapter 9 problem 2"<<endl;
    cout<<"This program creates a dynamic array, user then fills the array with grades"<<endl;
    cout<<"Average is then calculated with the lowest grade dropped"<<endl;
    
    
    //create  user defined array size
    cout<<"Please enter the number of students"<<endl;
    cin>>number;
    
    //create dynamic array
    array = new float[number];
    
    //loop to enter array values
    for(int i=0; i<number; i++)
    {
        cout<<"Enter grade for student "<<i+1<<": ";
        cin>>array[i];
    }
    
    //sort the array in marksort
    marksrt(array, number);
    
    //display sorted array
    cout<<"The scores from highest to lowest"<<endl;
    for(int i=0; i<number; i++)
    {   //display the sorted array
        cout<<array[i]<<endl;
    }
    
    //calculate average score
    cout<<endl<<"The average score with the lowest score dropped was"<<endl;
    avg(array, number);
    cout<<avg(array, number)<<endl; 
    
    //deallocate memory
    delete []array;
    
    //exit
    return 0;
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                                  Mark Sort
int marksrt(float a[], int n){
    //outside element
    for(int i=0; i<n-1; i++)
    { //inside element
        for(int j=i+1; j<n; j++)
        {   //find highest and place at top
            if(*(a+i) < *(a+j))
            {
                float temp = *(a+j);
                *(a+j) = *(a+i);
                *(a+i) = temp;
            }
        }
    }
}
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                              Calculate average
float avg(float a[], int n){
    //declare and initialize variables
    float average=0; //set initial value to 0
    float low = a[0];
    float temp = 0;
    
    //drop the lowest score
    for(int i=1; i<n; i++){
        if(a[i]<low){
            low=a[i];
        }
    }
    
    //create loop to find total value
    for(int i=0; i<n; i++)
    {
        average += a[i];
    }
    //calculate average
    average=(average-low)/(n-1);
    return average;
    
}