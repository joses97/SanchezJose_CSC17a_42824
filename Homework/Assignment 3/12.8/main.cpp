/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Purpose: 
 * Created on 
 */

//System Libraries
#include <iostream> //i/o
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
void arrayToFile(string name, int *array, int size);
void fileToArray(string name, int *array, int size);

//Execution Begins Here
int main(int argc, char** argv) {
    //declare and initialize variables
    const int SIZE=10;
    string fileNm;
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    //user enters file name
    cout<<"Enter File Name"<<endl;
    cin>>fileNm;
    
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