//Jose Sanchez
//April 4th, 2016
//Menu for assignment 4
//homework 

//Library includes Here!!!
#include <iostream>
#include <string>
#include <iomanip>
#include "assgnt5.h"
using namespace std;

//Global Constants Here!!!

//Function Prototypes Here!!!
void Menu();
int getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();
void problem10();
void problem11();

//Begin Execution Here!!!
int main(int argv,char *argc[]){
    int inN;
    do{
        Menu();
        inN=getN();
        switch(inN){
        case 1:    problem1();break;
        case 2:    problem2();break;
        case 3:    problem3();break;
        case 4:    problem4();break;
        case 5:    problem5();break;
        case 6:    problem6();break;
        case 7:    problem7();break;
        case 8:    problem8();break;
        case 9:    problem9();break;
        case 10:   problem10();break;
        case 11:   problem11();break;

        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;//
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void Menu(){
    cout<<endl<<endl;
    cout<<"Menu for Chapter 15"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 1"<<endl;
    cout<<endl<<"Chapter 16 problems"<<endl;
    cout<<"Type 7 for problem 1"<<endl;
    cout<<"Type 8 for problem 2"<<endl;
    cout<<"Type 9 for problem 3"<<endl;
    cout<<"Type 10 for problem 4"<<endl;
    cout<<"Type 11 for problem 5"<<endl;

    
    cout<<"Type anything else to exit \n"<<endl;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
int getN(){
        int inN;
        cin>>inN;
        return inN;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void problem1(){
    //problem 1 chapter 15
    cout<<"Entering problem 1 chapter 15"<<endl;
    pWorker person("Jose", 2324, "Jan 12 2020", 1, 35.50);
    cout<<"Employee join date: "<<person.getDate()<<endl;
    cout<<"Employee Name:      "<<person.getName()<<endl;
    cout<<"Employee Number:    "<<person.getNum()<<endl;
    cout<<"Employee Hour Pay:  "<<person.getPay()<<endl;
    cout<<"Employee Shift:     "<<person.getShft()<<endl;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void problem2(){
    //problem 2
    cout<<"Entering Problem 6 Chapter 15"<<endl;
    Essay essay1(20, 25, 25, 20);
    essay1.calcGr();
    cout<<"Students essay score:  "<<essay1.getScore()<<endl;
    cout<<"Students letter grade: "<<essay1.getLetterGrade()<<endl;
    
}
//******************************************************************************
//******************************************************************************
//*********************
void problem3(){
    cout<<"Entering Problem 4 chapter 15"<<endl;
    milTime times(1230, 23);
    times.setTime();
    cout<<"1230 hours and 23 seconds is: "<<times.getHour()<<" Hours "
            ""<<" and "<<times.getMin()<<" minutes and "<<times.getSec()<<""
            "seconds"<<endl;
        
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void problem4(){
    cout<<"Entering Problem 5 chapter 15"<<endl;
    TimeClock  times(12, 6);
    times.findDif();
    cout<<"Time 1 is 12, Time 2 is 6"<<endl;
    cout<<"The difference in time is: "<<times.getTime()<<endl;
    
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void problem5(){
    cout<<"Entering Problem 2 Chapter 15"<<endl;
    shiftS super(153000.34, 5000.34, "Jose", 4343, "Jan 15 2023");
    cout<<"Super visor info"<<endl;
    cout<<"Salary:    "<<super.getSal()<<endl;
    cout<<"Bonus:     "<<super.getBs()<<endl;
    cout<<"Name:      "<<super.getName()<<endl;
    cout<<"ID:        "<<super.getNum()<<endl;
    cout<<"Join Date: "<<super.getDate()<<endl;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void problem6(){
      
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
void problem7(){
    
}
void problem8(){
   
}
void problem9(){
    
}
void problem10(){
    
}
void problem11(){
  
}