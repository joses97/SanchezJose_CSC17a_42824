/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Purpose: Binary Search 
 * Created on March 2nd 2016
 */

//System Libraries
#include <iostream> //i/o
#include <string> //strings
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void sort5(string [], int);  //sort strings
void showArr5(string [], int);   //show array of strings
int binSrch5(string [], int, string);    //binary search for strings
//Execution Begins Here
int main(int argc, char** argv) {
    const int SIZE = 20;    //max size for the array
    string input;   //users input
    int result=0; //result of the binary search 
    string names[SIZE] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
        "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
        "Taylor, Terri", "Johnson, Jill",
        "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
        "James, Jean", "Weaver, Jim", "Pore, Bob",
        "Rutherford, Greg", "Javens, Renee",
        "Harrison, Rose", "Setzer, Cathy",
        "Pike, Gordon", "Holland, Beth" };  //values for the array
    
    //input the name 
    cout<<"Gaddis 8thed Chapter 8 Problem 7"<<endl;
    cout<<"This program find the users entry using strings"<<endl;
    cout<<"Please enter the name you are looking for: ";
    getline(cin, input);
    
    //sort the array
    sort5(names, SIZE);
    
    //show the array
    showArr5(names, SIZE);
    
    //run the binary search
    result=binSrch5(names, SIZE, input);
    
    //if result = -1
    if(result==-1){
        cout<<" The entry was not found"<<endl;
    }
    //else output result+1, names[result]
    else {cout<<"The entry was found at "<<result+1<<": "<<names[result]<<endl;}
    //Exit stage right and close
    return 0;
}

//******************************************************************************
//*******************************sort function**********************************
//******************************************************************************
void sort5(string array[], int size){
    int srtScan, minIndx;   //start scan, min index
    string minVal;          //min value
    for (srtScan = 0; srtScan < (size-1); srtScan++){ //for loop 
        minIndx = srtScan;  //mind index=srtScan
        minVal = array[srtScan];    //minVa= array[startScan]
        for(int index = srtScan + 1; index < size; index++){ //for loop 
            if (array[index] < minVal){ //if array[index]<ninVal
                minVal = array[index];  //minVal=array[index]
                minIndx = index;        //index
            }
        }
        array[minIndx] = array[srtScan]; //array[minIndx] = array[srtScan]
        array[srtScan] = minVal;        //array[srtScan]  = minVal;   
    }
 }
//******************************************************************************
//*******************************show array*************************************
//******************************************************************************
void showArr5(string arry[], int size){
    for(int i=0; i<size; i++){ //for loop
        cout<<arry[i]<<endl;    //output arry[i]
    }
}
//******************************************************************************
//******************************Binary search***********************************
//******************************************************************************
int binSrch5(string array[], int size, string input){
    int first=0;        //first array element 
    int last=size-1;    //last array element
    int middle=0;         //midpoint of search
    int pos=-1;    //position of search value
    bool found=false;   //set found to false
    while(!found && first <= last){ //while loop
        middle=(first+last)/2;  //middle=(first+last)/2
        if(array[middle]==input){ //if array[middle]==input
            pos=middle;         //pos=middle
            found=true;         //found=true
        }
        else if(array[middle]>input){ //else if array[middle]>input
            last=middle-1;            //last=middle-1
        }
        else{                           //else first=middle+1;
            first=middle+1;
        }
    }
    return pos; //return pos
}