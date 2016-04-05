/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Purpose: send file to array, and array to file
 * Created on April 4, 2016
 */

//System Libraries
#include <iostream> //i/o
#include <fstream>  //file i/0
#include <string>   //strings
#include <cctype>   //to upper
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void arrayToFile(string name, int *array, int size); //array to file
void fileToArray(string name, int *array, int size); //file to array

//Execution Begins Here
int main(int argc, char** argv) {
    //declare and initialize variables
    const int SIZE=10;  //size
    string fileNm;  //name of string
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  //array
    
    cout<<"Gaddis 8thEd Chapter 12 Problem 8"<<endl;
    cout<<"This program takes a file, writes an array to it,  then reads "
            "it back"<<endl;
    
    //user enters file name
    cout<<"Enter File Name"<<endl;
    cin>>fileNm;
    
    //call arrayToFile, fileToArray
    arrayToFile(fileNm, array, SIZE);
    fileToArray(fileNm, array, SIZE);
    
    
    return 0;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void arrayToFile(string name, int *array, int size){
    //declare and initialize variables
    fstream file;
    
    //open file under file name
    file.open(name.c_str(), ios::out | ios::binary );
    
    //write to file in binary
    file.write(reinterpret_cast<char *>(array), sizeof(array));
    
    file.close();
    
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void fileToArray(string name, int *array, int size){
    fstream file;
    //open file
    file.open(name.c_str(), ios::in | ios::binary );
    
    //read from file 
    file.read(reinterpret_cast<char *>(array), sizeof(array));
    
    //display contents of the array
    cout<<"Contents of the array"<<endl;
    for(int i=0; i<size; i++){
        cout<<array[i]<<endl;
    }
    
    //close the file
    file.close(); 
    
    
}