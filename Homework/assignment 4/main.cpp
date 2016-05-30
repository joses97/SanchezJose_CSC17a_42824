//Jose Sanchez
//April 4th, 2016
//Menu for assignment 4
//homework 

//Library includes Here!!!
#include <iostream>
#include <string>
#include <iomanip>
#include "probsC.h"
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
    cout<<"Menu for the Midterm"<<endl;
    cout<<"Type 1 for problem 1"<<endl;
    cout<<"Type 2 for problem 2"<<endl;
    cout<<"Type 3 for problem 3"<<endl;
    cout<<"Type 4 for problem 4"<<endl;
    cout<<"Type 5 for problem 5"<<endl;
    cout<<"Type 6 for problem 1"<<endl;
    cout<<endl<<"Chapter 14 problems"<<endl;
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
    //problem 1
    cout<<"In problem # 1 chapter 13"<<endl<<endl;
    int day=0, month=0, year=0; //day month and year ints
    
    //enter the day in int
    cout<<"Enter day in integers: ";
    cin>>day;
    //while days >3 or  <1
    while(day>31||day<1){
        cout<<"Invalid day. Enter Day: ";
        cin>>day;
    }
    //enter month
    cout<<endl<<"Enter month in integers: ";
    cin>>month;
    //while month >12 or <1 
    while(month>12||month<1){
        cout<<"Invalid month. Enter Month: ";
        cin>>month;
    }
    //enter year
    cout<<endl<<"Enter year: ";
    cin>>year;
    
    //declare class
    date conver(day, month, year);
    //convert to the 3 asked by the question
    conver.getConv();
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void problem2(){
    //problem 2
    cout<<"In problem # 2 chpater 13"<<endl<<endl;
    int numMem=3; //number of employees
    int idnum=0; //initialize id num to 0 
    string depart, post, name; //name department position of the worker
    info1 pInfo[numMem];    //array of employee objects
    //for loop to enter info
    for(int i=0; i<numMem; i++){
        cout<<endl<<"Enter Id Number: ";
        cin>>idnum;
        cin.ignore();
        
        cout<<endl<<"Enter name: ";
        getline(cin, name);

        
        cout<<endl<<"Enter Department: ";
        getline(cin, depart);

        
        cout<<endl<<"Enter Position: ";
        getline(cin, post);
        pInfo[i].setInfo(idnum, name, depart, post);
        
        cout<<"Next Employee"<<endl;
    }
    cout<<left<<setw(15)<<setfill(' ')<<"Name";
    cout<<left<<setw(15)<<setfill(' ')<<"ID Number";
    cout<<left<<setw(15)<<setfill(' ')<<"Department";
    cout<<left<<setw(15)<<setfill(' ')<<"Position";
    cout<<endl;
    for(int i=0; i<numMem; i++){
        pInfo[i].dispInfo();
    }
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void problem3(){
    //problem 3
    cout<<"In problem # 3  chapter 13"<<endl<<endl;
    car test(2008, "Corolla"); //create car object named test with constructor
    //number of time loop is executed
    int number=5;
    
    //loop to accelerate
    for(int i=0; i<number; i++){
        test.accl();
    }
    //loop to slow down
    for(int i=0; i<number; i++){
        test.brake();
    }   
        
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void problem4(){
    //problem 4
    cout<<"In problem # 4 chapter 13"<<endl<<endl;
    //create 3 instances
    int num=3; //size of the array
    int age=0; //age
    string name, addr, phone; //name address and phone number
    //array of 3 info2 objects to hold 3 persons info.
    info2 stats[num];
    
    for(int i=0; i<num; i++){
        cout<<"Enter name"<<endl;
        cin.ignore();   
        getline(cin, name);
        cout<<"Enter Address"<<endl;
        getline(cin, addr);
        cout<<"Enter Phone Number"<<endl;
        getline(cin, phone);
        cout<<"Enter Age"<<endl;
        cin>>age;
        stats[i].setInfo(age, name, addr, phone);
    }
    
    for(int i=0; i<num; i++){
        cout<<"Name:    "<<stats[i].getName()<<endl;
        cout<<"Age:     "<<stats[i].getAge()<<endl;
        cout<<"Address: "<<stats[i].getAdd()<<endl;
        cout<<"Phone:   "<<stats[i].getPhne()<<endl;
        cout<<endl<<endl;
    }
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void problem5(){
    cout<<"In problem #5 chapter 13"<<endl;
    RetailItem item1("Jacket", 12, 59.95);
    RetailItem item2("Designer Jeans", 40, 34.95);
    RetailItem item3("Shirt", 20, 24.95);
    
    //display 
    cout<<"         ";
    cout<<left<<setw(20)<<setfill(' ')<<"Description";
    cout<<left<<setw(20)<<setfill(' ')<<"Units on Hand";
    cout<<left<<setw(20)<<setfill(' ')<<"Price";
    cout<<endl;
    //item 1
    cout<<"Item 1  ";
    cout<<left<<setw(20)<<setfill(' ')<<item1.getDesc();
    cout<<left<<setw(20)<<setfill(' ')<<item1.getUnit();
    cout<<left<<setw(20)<<setfill(' ')<<item1.getPrce();
    cout<<endl;
    //item 2
    cout<<"Item 2   ";
    cout<<left<<setw(20)<<setfill(' ')<<item2.getDesc();
    cout<<left<<setw(20)<<setfill(' ')<<item2.getUnit();
    cout<<left<<setw(20)<<setfill(' ')<<item2.getPrce();
    cout<<endl;
    //item 3
    cout<<"Item 3   ";
    cout<<left<<setw(20)<<setfill(' ')<<item3.getDesc();
    cout<<left<<setw(20)<<setfill(' ')<<item3.getUnit();
    cout<<left<<setw(20)<<setfill(' ')<<item3.getPrce();
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void problem6(){
        cout<<"In problem # 6 chapter 13"<<endl<<endl;
        Invtry test(334, 23, 44.23);
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
void problem7(){
    //number to be entered
    int number=0;
    
    cout<<"Entering problem 1 chapter 14"<<endl;
    //enter a number 1-9999
    cout<<"Enter a number 1-9999"<<endl;
    cin>>number;
    numbers num(number);
    num.print();
}
void problem8(){
    //number to be entered
    int number=0;
    
    cout<<"Entering problem 2 chapter 14"<<endl;
    //enter a number 1-365 for days
    cout<<"Enter a number 1-365 to find the date"<<endl;
    cin>>number;
    dOfYear days(number);
    days.print();
}
void problem9(){
    //number to be entered
    int number=0;
    string month;
    
    cout<<"Entering problem 3 chapter 14"<<endl;
    //enter month and year
    cout<<"Enter the Month EX: March"<<endl;
    cin>>month;
    cout<<"Enter the day"<<endl;
    cin>>number;
    
    dOfYear2 days(month, number);
    days.display();
    cout<<"Adding one to the day"<<endl;
    ++days;
    days.display();
    cout<<"Subtracting one to the day"<<endl;
    --days;
    days.display();
}
void problem10(){
    
}
void problem11(){
    
}