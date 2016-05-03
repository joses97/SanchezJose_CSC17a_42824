//Dr. Mark E. Lehr
//April 4th, 2016]
//Menu to be used for the midterm
//homework and final, etc....

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
        default:   def(inN);}
    }while(inN>=1&&inN<=6);
    return 0;//If midterm not perfect, return something other than 1
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
    cout<<"Type 6 for problem 6"<<endl;
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
    cout<<"In problem # 1"<<endl<<endl;
    int day=0, month=0, year=0;
    
    cout<<"Enter day: ";
    cin>>day;
    while(day>31||day<1){
        cout<<"Invalid day. Enter Day:";
        cin>>day;
    }
    
    cout<<endl<<"Enter month: ";
    cin>>month;
    while(month>12||month<1){
        cout<<"Invalid month. Enter Month";
        cin>>month;
    }
    cout<<endl<<"Enter year: ";
    cin>>year;
    
    //declare class
    date conver(day, month, year);
    
    conver.getConv();
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void problem2(){
    cout<<"In problem # 2"<<endl<<endl;
    int numMem=3;
    info1 pInfo[numMem];
    for(int i=0; i<numMem; i++){
        pInfo[i].receiveInfo();
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
    cout<<"In problem # 3"<<endl<<endl;
    car test(2008, "Corolla");
    int number=5;
    
    for(int i=0; i<number; i++){
        test.accl();
    }
    for(int i=0; i<number; i++){
        test.brake();
    }   
        
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void problem4(){
    cout<<"In problem # 4"<<endl<<endl;
    //create 3 instances
    int num=3;
    info2 stats[num];
    
    for(int i=0; i<num; i++){
        stats[i].reciInfo();
        stats[i].displInfo();
    }
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void problem5(){
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
    cout<<"Item 3   ";
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
        cout<<"In problem # 6"<<endl<<endl;
        Invtry test(334, 23, 44.23);
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void def(int inN){
        cout<<"You typed "<<inN<<" to exit the program"<<endl;
}
//******************************************************************************
//PROBLEM 1 FUNCTIONS
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
date::date(int d, int m, int y){
    day=d;
    month=m;
    year=y;
    
}
void date::getConv(){
    string mon;
    
    cout<<endl;
    cout<<"MM/DD/YYYY format"<<endl;
    cout<<month<<"/"<<day<<"/"<<year<<endl;
    cout<<endl;
    
    //convert month 
    switch(month){
        case 1:
            mon="January";
            break;
        case 2:
            mon="February";
            break;            
        case 3:
            mon="March";
            break;
        case 4:
            mon="April";
            break;
        case 5:
            mon="May";
            break;
        case 6:
            mon="June";
            break;            
        case 7:
            mon="July";
            break;
        case 8:
            mon="August";
            break;   
        case 9:
            mon="September";
            break;
        case 10:
            mon="October";
            break;            
        case 11:
            mon="November";
            break;
        case 12:
            mon="December";
            break;      
    }
    cout<<"MONTH, DD, YYYY format"<<endl;
    cout<<mon<<" "<<day<<", "<<year<<endl;
    cout<<endl;
    cout<<"DD MONTH YYYY format"<<endl;
    cout<<day<<" "<<mon<<" "<<year<<endl;
}
//******************************************************************************
//problem 2 functions
//******************************************************************************
void info1::receiveInfo(){
    string nam, depar, posit;
    int num=0;
    cout<<endl<<"Enter name: ";
    cin.ignore();
    getline(cin, nam);
    cout<<endl<<"Enter Id Number: ";
    cin>>num;
    cout<<endl<<"Enter Department: ";
    cin.ignore();
    getline(cin, depar);
    cout<<endl<<"Enter Position: ";
    getline(cin, posit);
    
    name=nam;
    idNum=num;
    depart=depar;
    pos=posit;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
info1::info(){
    name="";
    idNum=0;
    depart="";
    pos="";
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void info1::dispInfo(){

    cout<<left<<setw(15)<<setfill(' ')<<name;
    cout<<left<<setw(15)<<setfill(' ')<<idNum;
    cout<<left<<setw(15)<<setfill(' ')<<depart;
    cout<<left<<setw(15)<<setfill(' ')<<pos;
    cout<<endl;
}
//******************************************************************************
//problem 3 functions
//******************************************************************************
car::car(int yr, string maker){
    yrModel=yr;
    make=maker;
    speed=0;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void car::accl(){
    speed+=5;
    cout<<"Speed Accelerating: "<<speed<<endl;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void car::brake(){
    speed-=5;
    cout<<"Speed Braking: "<<speed<<endl;
}
//******************************************************************************
//problem 4 functions
//******************************************************************************
//******************************************************************************
//******************************************************************************
//******************************************************************************
void info2::reciInfo(){
    int ag=0;
    string nam, add, ph;
    cout<<"Enter name"<<endl;
    cin.ignore();   
    getline(cin, nam);
    cout<<"Enter Address"<<endl;
    getline(cin, add);
    cout<<"Enter Phone Number"<<endl;
    getline(cin, ph);
    cout<<"Enter Age"<<endl;
    cin>>ag;
    
    age=ag;
    address=add;
    name=nam;
    phone=ph;  
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void info2::displInfo(){
    cout<<"Name:    "<<name<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"Phone:   "<<phone<<endl;
    cout<<"Age:     "<<age<<endl;
}
//******************************************************************************
//Problem 5 functions
//******************************************************************************
string RetailItem::getDesc(){
    return descr;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
int RetailItem::getUnit(){
    return unitsOH;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
float RetailItem::getPrce(){
    return price;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
RetailItem::RetailItem(string x , int y , float z){
    descr=x;
    unitsOH=y;
    price=z;
}
//******************************************************************************
//Problem 6 functions
//******************************************************************************
Invtry::Invtry(){
    itmNum=0;
    quant=0;
    cost=0;
    totCost=0;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
Invtry::Invtry(int itNum, int qn, float ct){
    cout<<"Item Number:  "<<itNum<<endl;
    cout<<"Quantity:     "<<qn<<endl;
    cout<<"Cost:         "<<ct<<endl;
    setItNum(itNum);
    setQuant(qn);
    setCost(ct);
    
    setTCost();
    
    cout<<"Total cost: "<<getTCost();
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void Invtry::setTCost(){
    totCost = getQuant() * getCost();
}