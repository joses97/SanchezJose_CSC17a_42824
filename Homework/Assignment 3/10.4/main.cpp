/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Purpose: average number of letters per word
 * Created on April 3, 2016
 */

//System Libraries
#include <iostream> //i/o
#include <iomanip>  //formatting
#include <cstring>  //strings
#include <cctype>   //to upper
#include <string> //string
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
float avg(char *input); //avg function

//Execution Begins Here
int main(int argc, char** argv) {
    //declare and initialize variables
    const int SIZE=100; //size of character array
    char menu;          //selection for the menu
    char input[SIZE];    //character array
    
    //Explain
    cout<<"Gaddis 8thEd Chapter 10 Problem 4"<<endl;
    cout<<"This problem takes a string and finds the average number of letters "
            "per word"<<endl;
    
    //output to 2 decimal places
    cout<<fixed<<showpoint<<setprecision(2)<<endl;
    
    //input
    cout<<"Enter string"<<endl;
    cin.getline(input, SIZE);
    
    //output average letters per word
    cout<<"Average number letters per word: "<<avg(input);

    return 0;
}
//******************************************************************************
//*******************************Vowels Function ******************************
//******************************************************************************
float avg(char *input){
    //declare and initialize variables
    int size=strlen(input);
    float num=0.0f;
    float num2=0.0f;
    
    //for loop
    for(int i=0; i<size; i++){
        if(input[i]!=' '){
            num++;
        }
        else if(input[i]==' '){
            num2++;
        }
    }
    
    //find average number of letters in the string
    num/=(num2+1);
    //return number of vowels
    return num;
}