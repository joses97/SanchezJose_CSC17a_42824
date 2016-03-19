/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Created on March 18 2016
 * Purpose: problem 9.11
 *  */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
int* allMem(int&);          //allocate mem
int fillAry(int [], int);   //fill the array
int* dubArr(int [], int);   //double the array and fill rest w/0
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare and initialize variable
    int num=0;      //set num to 0
    int *array;     //create pointer array
    int *newArr;    //create pointer newArr
    
    //explain
    cout<<"Gaddis 8thEd Chapter 9 Problem 11"<<endl;
    cout<<"This program creates an array with user defined size, copies and "
            " doubles it, fills rest with 0"<<endl;
    
    
    //create array
    array=allMem(num);
    //fill the array
    fillAry(array, num); 
    //create array twice the size
    newArr=dubArr(array, num);
    
    //delete allocated memory
    delete [] array;
    delete [] newArr;
    array = NULL;
    newArr = NULL;
    
    //exit
    return 0;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
int* allMem(int& number){
    //create size;
    cout<<"Enter the size of the array"<<endl;
    cin>>number;
    
    //allocate size
    int *array= new int[number];
    
    return array;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
int fillAry(int a[], int n){
    //fill the array with values
    cout<<"Fill the array"<<endl;
    for(int i=0; i<n; i++){
        cout<<"Array at "<<i<<" :";
        cin>>a[i];
    }
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
int* dubArr(int a[], int n){
    //create array twice the size of the original
    int n2=n*2; //create 2x size
    int *array = new int[n2];   //create array with twice the size
    //copy the array up to original size
    for(int i=0; i<n; i++){
        array[i]=a[i];
    }
    //fill the rest with 0
    for(int i=n; i<n2; i++){
        array[i]=0;
    }
    return array;
}