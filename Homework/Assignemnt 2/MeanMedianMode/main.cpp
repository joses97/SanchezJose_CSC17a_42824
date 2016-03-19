/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Created on March 18 2016
 * Purpose: Mean Median Mode
 *  */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
int* allMem(int& number);
float avg(int [], int);
float median(int [], int);
int* mode(int a[], int n);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variables
    int number=0;       //set number to initial value of 0
    int *array;         //create pointer
    
    //accuracy 2 decimal places
    cout<<fixed<<showpoint<<setprecision(2);
    
    //create array
    array=allMem(number); //make array
    
    //display mean
    avg(array, number);
    cout<<endl;
    
    //display the median
    median(array, number);
    
    //display the mode
    mode(array, number);
    
    delete [] array; //delete array
    array = NULL;   //delete pointer
    
    //exit
    return 0;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
int* allMem(int& number){
    cout<<"Please enter the size of the array"<<endl;
    cin>>number;//input number
    
    //create dynamic array based on number
    int *array=new int[number]; //create dynamic array
    
    //fill the array with a repeated number set
    for(int i=0; i<number; i++){
        array[i]=(i)%10;
    }
    
    return array;
    
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
float avg(int a[], int n){
    //declare and initialize variables
    float average=0; //set initial value to 0
    
    //create loop to find total value
    for(int i=0; i<n; i++)
    {
        average += a[i];
    }
    //calculate average
    average/=n;
    cout<<"The mean is: "<<average;
    return average;
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
//******************************************************************************
//******************************************************************************
//******************************************************************************
int* mode(int a[], int n){  
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

    
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
