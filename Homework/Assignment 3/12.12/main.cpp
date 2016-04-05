/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Purpose: to get data from user, to file, back to user
 * Created on   April 4, 2016
 */

//System Libraries
#include <iostream> //i/o
#include <fstream>  //file i/o
#include <string>   //strinfs
#include <iomanip>  //formatting
using namespace std;

//User Libraries

//Global Constants
const int SIZE=4; //size of the array within the structs and main

//Function prototypes

//Structures
struct info{
    string name[SIZE];          //string array
    float sales[SIZE][SIZE];    //2-d sales array  
};

//Execution Begins Here
int main(int argc, char** argv) {
    //declare and initialize variables
    info comp;              //struct  
    fstream file;           //file 1
    fstream file2;          //file 2
    float sales[SIZE]={0, 0, 0, 0}; //array to hold q sales
    float totSale=0.0f;         //total sales
    float avg=0.0f;             //average
    float max=0.0f;             //max value
    float low=0.0f;             //lowest value
    int counta=0;               //max value position
    int countb=0;               //low value position

    //fixed to two decimal places
    cout<<fixed<<showpoint<<setprecision(2)<<endl;
    
    
    //open the file
    file.open("testFile.dat", ios::out | ios::binary ); 

    //for loop to fill struct
    for(int i=0; i<SIZE; i++){
        //enter division name
        cout<<"Enter Division name "<<i+1<<endl;
        cin>>comp.name[i];
        
        
        //input sales for each quarter
        for(int j=0; j<SIZE; j++){
            //enter number of sales
            cout<<"Enter Sales for Quarter "<<j+1<<endl;
            cin>>comp.sales[i][j];
        }

        //write to file
        file.write(reinterpret_cast<char *>(&comp), sizeof(comp));
    }
    
    //close the file
    file.close();
    
    
    //reading file
    cout<<"Reading data from file..."<<endl;
    file2.open("testFile.dat", ios::in | ios::binary);   
    file2.read(reinterpret_cast<char *>(&comp), sizeof(comp));
    
    //for loop to see results
    for(int i=0; i<SIZE; i++){
            file2.read(reinterpret_cast<char *>(&comp), sizeof(comp));
            cout<<"Division:"<<comp.name[i]<<endl;
            //for loop to see all the sales per quarter
            for(int j=0; j<SIZE; j++){
                cout<<"Quarter "<<j+1<<" Sales: "<<comp.sales[i][j]<<endl<<endl;
            }
    }
    //display total yearly sales for each quarter
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE; j++){
            sales[i]+=comp.sales[j][i];
        }
        cout<<"Total sales for Quarter "<<i+1<<": "<<sales[i]<<endl;
    }
    //calculate total sales for the year
    for(int i=0; i<SIZE; i++){
        totSale+=sales[i];
    }
    
    //cout total sales for the year
    cout<<"Total sales for the year: "<<totSale<<endl;
    
    
    //calculate average sale per quarter
    avg=totSale/SIZE;
    //output average sale per quarter
    cout<<endl<<"Avergae sale per quarter: "<<avg<<endl;
    
    //find the max and low quarter
    max=sales[0];
    low=sales[0];
    
    //loop to find low and high
    for(int i=0; i<SIZE; i++){
        if(sales[i]>max){
            max=sales[i];
            counta=i;
        }
        if(sales[i]<low){
            low=sales[i];
            countb=i;
        }
    }
    
    //output the low and the high
    cout<<"Highest quarter was "<<counta+1<<" with "<<max<<endl;
    cout<<"Lowest quarter was "<<countb+1<<" with "<<low<<endl;
    
    //close the file
    file2.close();
    
    return 0;
}