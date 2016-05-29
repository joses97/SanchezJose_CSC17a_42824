/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "probsC.h"
#include <iostream>
#include <iomanip>
using namespace std;

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
void info1::setInfo(int num, string nam, string depar, string posit){
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
    yrModel=yr; //year of the car
    make=maker;  //make of the car
    speed=0;  //set speed to 0
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void car::accl(){
    speed+=5; //add 5 to speed each time accl is called
    //output speed at the time accl is called
    cout<<"Speed Accelerating: "<<speed<<endl;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
void car::brake(){
    speed-=5; //take 5 from speed each time brake is pressed
    //display speed when brake is called
    cout<<"Speed Braking: "<<speed<<endl;
}
//******************************************************************************
//problem 4 functions
//******************************************************************************
//******************************************************************************
info2::info2(){
    age=0;
}

//******************************************************************************
//******************************************************************************
void info2::setInfo(int ag, string nam, string add, string ph){
    age=ag;
    address=add;
    name=nam;
    phone=ph;  
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
int info2::getAge(){
    return age;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
string info2::getName(){
    return name;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
string info2::getAdd(){
    return address;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
string info2::getPhne(){
    return phone;
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
//******************************************************************************
//******************************************************************************
//******************************************************************************
//problem 1 chapter 14 functions //NOTE NOTE NOTE 
//note to DR. Lehr, was a bit confused as to how they wanted me to do this problem
//used external help to see and came up with a solution in their format.
//weve done similar problems to this a million times, Roman numerals, checks etc.
//interesting to see the same problem in a different way.
string numbers::less20[SIZE]={"one", "two", "three", "four", "five", "six",
    "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
//******************************************************************************
//declaration for static member variable
string numbers::above20[SIZE2]{"twenty", "thirty", "forty", "fifty", "sixty", 
    "seventy", "eighty", "ninety"};
//declaration for static member variable"}
//******************************************************************************
//declaration for static member variable
string numbers::hundrd="hundred";
//******************************************************************************
//declaration for static member variable
string numbers::thousnd="thousand";
//******************************************************************************
//******************************************************************************
//******************************************************************************
void numbers::print(){
    int num1=number;
    int num2=number;
    int num3=number;
    int num4=number;
    num4=number%10;
    num3=number%100/10;
    num2=number%1000/100;
    num1=number%10000/1000;

    if(num1>0){
        cout<<less20[num1-1]<<" "<<thousnd<<endl;
    }
    if(num2>0){
        cout<<less20[num2-1]<<" "<<hundrd<<endl;
    }
    if(num3>=2){
        cout<<above20[num3-2]<<endl;
        if(num4>0){
            cout<<less20[num4-1]<<endl;
        }
    }
    else{
        num4+=10;
        cout<<less20[num4-1]<<endl;
    }
     
}

