/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Created on March 18 2016
 * Purpose: problem 9.7
 *  */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void showArray(int [], int);  //show array
int* marksrt(int [], int);  //mark sorts the array
//Execution Begins Here
int main(){
    //declare and initialize variables
    int dons=0;     //number of donations
    int *donations; //pointer
    int *newDons;   //copy of array
    
    //explain
    cout<<"Gaddis 8thEd Chapter 9 problem 7"<<endl;
    cout<<"This program takes the creates a dynamic array and fills it with"
            " integers."<<endl;
    cout<<"Then the array is copied and sorted. Both the original and sorted "
            "array are displayed"<<endl;
    
    
    //enter number of donations
    cout<<"Enter the number of donations"<<endl;
    cin>>dons;

    // An array containing the donation amounts.
    donations = new int[dons];
    
    //fill the array with vales
    for(int i=0; i<dons; i++){
        cout<<"Enter donation "<<i+1<<" : ";
        cin>>donations[i];
        cout<<endl;
    }
    //mark sort
    newDons=marksrt(donations, dons);
    
    // display the new array
    cout << "The donations from leat to greatest "<<endl;
    showArray(newDons, dons);
    
    cout << "The donations in original order"<<endl;
    showArray(donations, dons);
    
    //delete the array
    delete [] donations;
    delete [] newDons;
    
    //exit
    return 0;
}
//****************************************************************
//****************************************************************
//                              Mark Sort
int* marksrt(int a[], int n){
    //outside element
    int *arr= new int[n];
    
    //copy array
    for(int i=0; i<n; i++){
        arr[i]=a[i];
    }
    
    for(int i=0; i<n-1; i++)
    { //inside element
        for(int j=i+1; j<n; j++)
        {   //find highest and place at top
            if(*(arr+i) > *(arr+j))
            {
                int temp = *(arr+j);
                *(arr+j) = *(arr+i);
                *(arr+i) = temp;
            }
        }
    }
    return arr;
}
//***********************************************************
// Definition of function showArray. *
// This function displays the contents of arr. size is the *
// number of elements. *
//***********************************************************
void showArray(int arr[], int size){
    for (int count = 0; count < size; count++){
        cout << arr[count] << " ";
    }
    cout << endl;
}