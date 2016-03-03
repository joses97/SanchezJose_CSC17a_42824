/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Created on February 29 2016
 * Purpose: Leap Year
 *  */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //declare and initialize variables
    float pop=0;       //set population to 0 
    float perIncr=0;    //set the initial daily population increase percent to 0 
    int days=0;         //the number of days they will multiply for 
    
    //Explain
    cout<<"Gaddis 8th Ed Chapter 5 Problem 11"<<endl;
    cout<<"This program finds the future population of an organism"<<endl;
    
    //input Initial population
    do
    {
    cout<<"Please enter the initial population of the organism"<<endl;
    cout<<"Input must be greater or equal to 2"<<endl;
    cin>>pop; //input pop
    }
    while(pop<2); //while pop<2
    cout<<endl;
    
    //Input the percent increase
    do
    {
    cout<<"Please enter the daily population increase as a percentage"<<endl;
    cout<<"Example 50 percent would be 50"<<endl;
    cout<<"Input must be greater or equal to 0"<<endl;
    cin>>perIncr;    //input percIncr
    perIncr/=100.0f; //calculate perIncr/=100.0f
    }
    while(perIncr<0); //while perIncr<0
    cout<<endl;
    
    //Input the population increase
    do
    {
    cout<<"Please enter the number of days the organisms will reproduce for"<<endl;
    cout<<"Input must be greater or equal to 1"<<endl;
    cin>>days; //input days
    }
    while(days<1);  //while days<1
    cout<<endl;
    
    //output inputs
    cout<<"Population size:  "<<pop<<endl; //output pop
    cout<<"Percent Increase: "<<perIncr*100.0f<<"%"<<endl; //output perIncr*100.0f
    cout<<"Days to grow:     "<<days<<endl; //output days
    cout<<endl;
    
    //for loop to find final population
    for(int i=0; i<days; i++)
    {
        pop=pop*perIncr+pop;  //calculate pop=pop*perIncr+pop; 
    }
    
    //output final population
    cout<<"The final population is: "<<static_cast<int>(pop)<<endl;
    
    //exit
    return 0;
}

