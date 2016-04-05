/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Purpose: advanced file i/o
 * Created on April 3, 2016
 */

//System Libraries
#include <iostream> //i/o
#include <fstream>  //file i/o
#include <string>   //strings
#include <cctype>   //to upper
using namespace std;

//User Libraries

//Global Constants

//Function prototypes


//Execution Begins Here
int main(int argc, char** argv) {
    //declare and initialize variables
    const int SIZE=40; //size of the array
    char file1[SIZE];   //file name 1
    char file2[SIZE];   //file name 2
    string steam;       //string 
    ifstream inFile;    //infile
    fstream outFile;    //outfile
    
    cout<<"Gaddis 8thEd Chapter 12 Problem 7"<<endl;
    cout<<"This program takes a file, and capitalizes the"
            " letter after the period"<<endl;
    cout<<"The program then sends that data to another file"<<endl;
    
    
    //enter file name 1
    cout<<"Enter Name of file 1 (File1.txt)"<<endl;
    cin.getline(file1, SIZE);
    //enter file name 1=2
    cout<<"Enter Name of file 2"<<endl;
    cin.getline(file2, SIZE);
    
    //opening input file
    inFile.open(file1, ios::in);
    //opening output file
    outFile.open(file2, ios::out);
    if(inFile){
        getline(inFile, steam);
        for(int i=0; i<steam.size(); i++){
            if(i==0){
                steam[i]=toupper(steam[i]);
            }
            if(steam[i]=='.'){
                steam[i+2]=toupper(steam[i+2]);
            }
        }
      
    }
    else{
        cout<<"Error: File could not be found"<<endl;
    }
    
    //out out to file
    outFile<<steam;
    
    //close files
    outFile.close();
    inFile.close();
    
    
    return 0;
}