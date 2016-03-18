/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Created on March 2 2016
 * Purpose: Temperatures
 *  */

//System Libraries
#include <iostream> //file i/o
#include <fstream>  //file i/o
#include <iomanip>  //formatting
using namespace std;

//User Libraries

//Global Constants
 
//Function prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    ifstream inFile;    //name of the variable for input file
    const int ROW=3;    //number of rows
    const int COL=30;   //number of columns
    const int MAX=90;   //max number of days 
    char array[ROW][COL]{0};    //2-D character array 
    string month[ROW]{"June", "July", "August"}; //string array names of months
    int rain[MAX]{0};   //array to keep track of rain
    int cloudy[MAX]{0}; //array to keep track of cloudy
    int sunny[MAX]{0};  //array to keep track of sunny
    int rainT=0, sunnT=0, cloudT=0; //variables for total number of rainy days
    int max=0;          //find the max number
    int count=0;        //counter for month
    
    //explain
    cout<<"Gaddis 8th Ed Chapter 7 Problem 6"<<endl;
    cout<<"This program takes information from a file and find the max rainy days"<<endl;
    cout<<"The program also finds stats per month"<<endl;
      
    //open file
    inFile.open("RainOrShine.txt");
    
    //for loop to enter the array 
    for(int i=0; i<ROW; i++){
        for(int j=0; j<COL; j++){
            inFile>>array[i][j]; //enter file into array
            if(array[i][j]=='R') rain[i]++; //test for rain in month
            else if(array[i][j]=='S') sunny[i]++;   //test for sunny in month
            else if(array[i][j]=='C') cloudy[i]++;  //test for cloudy in month 
            
            if(array[i][j]=='R') rainT++;           //add total days of rain
            else if(array[i][j]=='S') sunnT++;      //add total days of sunny
            else if(array[i][j]=='C') cloudT++;     //add total days of cloudy
        }
    }
    
    //output the rainy days 
    //for loop for month
    for(int i=0; i<ROW; i++){
        cout<<left<<setw(7)<<setfill(' ')<<month[i]<<' '; //output month
        for(int j=0; j<COL; j++){   //for loop for days
            cout<<array[i][j];  //output array at [i][j]
        }
        cout<<endl;
    }
    
    //add endl;
    cout<<endl;
    
    //output total for rain, cloudy, and sunny days
    cout<<"The total number of rainy days was  "<<rainT<<endl;
    cout<<"The total amount of cloudy days was "<<cloudT<<endl;
    cout<<"The total amount of sunny days was  "<<sunnT<<endl;
    
    //add endl;
    cout<<endl;
    
    for(int i=0; i<ROW; i++){ //for loop displays the rain, cloud, and sun per month
        cout<<month[i]<<" total number of rainy days : "<<rain[i]<<endl; //output rain
        cout<<month[i]<<" total number of cloudy days: "<<cloudy[i]<<endl;  //output cloudy
        cout<<month[i]<<" total number of sunny days : "<<sunny[i]<<endl;   //output sunny
        cout<<endl;
    }
    
    max=rain[0];//set the max to array initial 
    count=0;    //set count to 0
    
    //find the max 
    if(rain[0]<rain[1]){
        max=rain[1]; //set the max to rain[1]
        count=1;    //set count to 1 
    }
    //find the max
    if(max<rain[2]){ 
        max=rain[2]; //set max to rain[2]
        count=2;     //set count to 2
    }
    
    //add endl;
    cout<<endl;
    
    //if to display
    if(count==0){ //cout == 0 output max
        cout<<"June was the month with the highest number rainy days with "<<max<<endl;
    }else if(count==1){ //cout == 1 output max
        cout<<"July was the month with the highest number of rainy days with "<<max<<endl;
    }else if(count==2){ //cout == 2 output max
        cout<<"August was the month with the highest number of rainy days with"<<max<<endl;
    }
    
    //close inFile
    inFile.close();
    
    return 0;
}
