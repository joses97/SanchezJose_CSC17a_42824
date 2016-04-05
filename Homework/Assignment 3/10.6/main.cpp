/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Purpose: find number of consonants and vowels
 * Created on April 3, 2016
 */

//System Libraries
#include <iostream> //i/o
#include <cstring>  //string
#include <cctype>   //to upper
#include <string>   //string
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
int vowels(char *input); //vowels
int cons(char *input);  //consonant


//Execution Begins Here
int main(int argc, char** argv) {
    const int SIZE=100; //size of character array
    char menu;          //selection for the menu
    char input[SIZE];    //character array
    bool cont=true;      //answer for continuing 
    char ansr='Y';      //asnwr
    
    //explain
    cout<<"Gaddis 8thEd Chapter 10 Problem 6"<<endl;
    cout<<"This program finds the number of vowels and or consonants "<<endl;
    
    //While loop
    while(cont==true){
        //input the string
        ansr='Y';
        cout<<"Enter a string"<<endl;
        cin.getline(input, SIZE);
        
        //while loop
        while(ansr=='Y'){
            //show what user entered
            cout<<endl<<"String received: "<<input<<endl;

            //show menu
            cout<<"Enter 'A' for number of vowels"<<endl;
            cout<<"Enter 'B' for number of consonants"<<endl;
            cout<<"Enter 'C' for number of both vowels and consonants"<<endl;
            cout<<"Enter 'D' for to enter another string"<<endl;
            cout<<"Enter 'E' to Exit"<<endl;

            //enter selection for menu
            cin>>menu;
            //case switch menu
            switch(toupper(menu)){
                case 'A':{
                    cout<<"Number of Vowels: "<<vowels(input)<<endl;;
                    ansr='N';
                    break;
                }
                case 'B':{
                    cout<<"Number of Consonants: "<<cons(input)<<endl;;
                    ansr='N';
                    break;
                }
                case 'C':{
                    cout<<"Number of Vowels and Consonants:"
                            " "<<vowels(input)+cons(input)<<endl;
                    ansr='N';
                    break;
                }
                case 'D':{
                    ansr='N';
                    break;
                }
                case 'E': {
                    cont=false;
                    ansr='N';    
                    break;
                }
                default:              
                    break; 
            }
        }cin.ignore();
    }
    return 0;
}
//******************************************************************************
//*******************************Vowels Function ******************************
//******************************************************************************
int vowels(char *input){
    //declare and initialize variables
    int size=strlen(input);
    int num=0;
    char vowel[] = { 'A', 'E', 'I', 'O', 'U' };
    
    //Loop to find vowels
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            if(toupper(input[i])==vowel[j]){
                num++;
            }
        }
    }
    //return number of vowels
    return num;
}
//******************************************************************************
//*******************************Cons Function**********************************
//******************************************************************************
int cons(char *input){
    //declare and initialize variables
    int vowel=vowels(input);
    int size=strlen(input);
    int num=size-vowel;
    
    //find the amount of spaces
    for(int i=0; i<size; i++){
            if((input[i])==' '){
                num--;
            }
    }
    return num;
    
}