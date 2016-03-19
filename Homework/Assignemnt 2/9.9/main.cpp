/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Created on March 18 2016
 * Purpose: problem 9.9
 *  */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
float median(int [], int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variable
    int *array; //pointer
    int size=0; //size
    
    //explain
    cout<<"Gaddis 8th Edition Chpater 9 Problem 9"<<endl;
    cout<<"This program find the median of a set of numbers"<<endl;
    
    //enter array size
    cout<<"Enter the number of numbers to be entered"<<endl;
    cin>>size;
    
    //create array
    array = new int[size];
    
    //enter values into array
    for(int i=0; i<size; i++){
        cout<<"Enter value "<<i+1<<": ";
        cin>>array[i];
        cout<<endl;
    }
    //find median
    median(array, size);
    
    //deallocate memory 
    delete [] array;
    //exit
    return 0;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
float median(int a[], int n){
    //declare and initialize variables
    int median=0;
    int num1=0;
    int num2=0;
    float medianf=0;
    float number=n;
    float number2=n;
    //create an array to copy to
    float *array=new float[n];
    //fill the array with values
    for(int i=0; i<n; i++){
        array[i]=a[i];
    }
    //sort the array using a marksort
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(array[i]>array[j]){
                float temp=array[j];
                array[j]=array[i];
                array[i]=temp;
            }
        }
    }
    //find the median from the sorted array
    if(n%2==1){
        median=number/2.0f-0.5f;
        cout<<"The median is: "<<array[median]<<endl;
    }
    if(n%2==0){
        number=number/2.0f+0.5f;
        number2=number2/2.0f-0.5f;
        num1=number;
        num2=number2;
        medianf=(array[num1]+array[num2])/2.0f;
        cout<<"The median is: "<<medianf<<endl; 
    }
    //deallocate memory
    delete [] array;
}