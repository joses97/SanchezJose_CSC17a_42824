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


//Execution Begins Here
int main(int argc, char** argv) {
    //declare and initialize variables
    const int SIZE=40;
    char file1[SIZE];
    char file2[SIZE];
    string steam;
    ifstream inFile;
    fstream outFile;
    
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
    
    outFile.close();
    inFile.close();
    
    
    return 0;
}