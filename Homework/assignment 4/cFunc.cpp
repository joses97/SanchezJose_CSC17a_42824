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
    
    //print the number 
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
//******************************************************************************
//******************************************************************************
//******************************************************************************
//problem 2 chapter 14
string dOfYear::month[SIZE3]={"January", "February", "March", "April", "May", 
    "June", "July", "August", "September", "October", "November", "December"};
dOfYear::print(){
    int num=day;
    if(num<=31){
        cout<<month[0]<<" "<<num<<endl;
    }
    else if(num<=59){
        cout<<month[1]<<" "<<num-31<<endl;
    }
    else if(num<=90){
        cout<<month[2]<<" "<<num-59<<endl;
    }
    else if(num<=120){
        cout<<month[3]<<" "<<num-90<<endl;
    }
    else if(num<=151){
        cout<<month[4]<<" "<<num-120<<endl;
    }
    else if(num<=181){
        cout<<month[5]<<" "<<num-151<<endl;
    }
    else if(num<=212){
        cout<<month[6]<<" "<<num-181<<endl;
    }
    else if(num<=243){
        cout<<month[7]<<" "<<num-212<<endl;
    }
    else if(num<=273){
        cout<<month[8]<<" "<<num-243<<endl;
    }
    else if(num<=304){
        cout<<month[9]<<" "<<num-273<<endl;
    }
    else if(num<=334){
        cout<<month[10]<<" "<<num-304<<endl;
    }
    else if(num<=365){
        cout<<month[11]<<" "<<num-334<<endl;
    }
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
//problem 2 chapter 14
dOfYear2::dOfYear2(string m, int n){
    month=m;
    day=n;
    bool invalid=false;

    if(month=="January"){
        if(day>31||day<0){
            cout<<"Error invalid day for month Jan"<<endl;
            invalid=true;
        }
    }

    if(month=="February"){
        if(day>28||day<0){
            cout<<"Error invalid day for month Feb"<<endl;
            invalid=true;
        }
    }
    if(month=="March"){
        if(day>31||day<0){
            cout<<"Error invalid day for month March"<<endl;
            invalid=true;
        }
    }

    if(month=="April"){
        if(day>30||day<0){
            cout<<"Error invalid day for month Aprl"<<endl;
            invalid=true;
        }
    }
    if(month=="May"){
        if(day>31||day<0){
            cout<<"Error invalid day for month May"<<endl;
            invalid=true;
        }
    }
    if(month=="June"){
        if(day>30||day<0){
            cout<<"Error invalid day for month Jun"<<endl;
            invalid=true;
        }
    }

    if(month=="July"){
        if(day>31||day<0){
            cout<<"Error invalid day for month Jul"<<endl;
            invalid=true;
        }
    }

    if(month=="August"){
        if(day>31||day<0){
            cout<<"Error invalid day for month Aug"<<endl;
            invalid=true;
        }
    }
    if(month=="September"){
        if(day>30||day<0){
            cout<<"Error invalid day for month Sep"<<endl;
            invalid=true;
        }
    }

    if(month=="October"){
        if(day>31||day<0){
            cout<<"Error invalid day for month Oct"<<endl;
            invalid=true;
        }
    }
    if(month=="November"){
        if(day>30||day<0){
            cout<<"Error invalid day for month Nov"<<endl;
            invalid=true;
        }
    }
    if(month=="December"){
        if(day>31||day<0){
            cout<<"Error invalid day for month Dec"<<endl;
            invalid=true;
        }
    }

    if(invalid==true){
        //default day to 2
        day=2;
    }

}
//******************************************************************************
//******************************************************************************
//******************************************************************************
//problem 3 class functions
void dOfYear2::display(){
    cout<<month<<" "<<day<<endl;
}
//assistance of Microsoft website for ++ overloading
//Microsoft example online helped
//Microsoft example online helped 
//******************************************************************************
dOfYear2& dOfYear2::operator ++(){
    day+=1;
    return *this;
}

//******************************************************************************
dOfYear2 dOfYear2::operator ++(int){
    dOfYear2 temp=*this;
    ++*this;
    return temp;
}

//******************************************************************************
dOfYear2& dOfYear2::operator --(){
    day-=1;
    return *this;
}

//******************************************************************************
dOfYear2 dOfYear2::operator --(int){
    dOfYear2 temp=*this;
    --*this;
    return temp;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
//problem 4 class functions
void NumDays::conv(){
    int num=hours;
    float dayS=num/8.0f;
    cout<<"Days Worked: "<<dayS<<endl;
    days=dayS;
}
//******************************************************************************
//******************************************************************************
//plus operator
NumDays NumDays::operator +(const NumDays &right){
    NumDays temp;
    temp.days=days+right.days;
    return temp;
}
//******************************************************************************
//******************************************************************************
//minus operator
NumDays NumDays::operator -(const NumDays &right){
    NumDays temp;
    temp.days=days-right.days;
    return temp;
}
//******************************************************************************
//******************************************************************************
//minus operator
NumDays& NumDays::operator++(){
    days+=1;
    return *this;
}
//******************************************************************************
//******************************************************************************
NumDays NumDays::operator++(int){
    NumDays temp=*this;
    ++*this;
    return temp;
}
//******************************************************************************
//******************************************************************************
NumDays& NumDays::operator--(){
    days-=1;
    return *this;
}
//******************************************************************************
//******************************************************************************
NumDays NumDays::operator--(int){
    NumDays temp=*this;
    --*this;
    return temp;
}
//problem 5 class functions
void timeOff::getInfo(int skdy, int skTk, int mxVc, int vcTk,int mxUp,int upTk){
    mxSkDys=skdy;
    sckTkn=skTk; 
    mxVactn=mxVc;
    vacnTkn=vcTk;
    mxUnpd=mxUp;
    unpdTkn=upTk;
}
//******************************************************************************
//******************************************************************************
void timeOff::display(){
    cout<<"Max Sick Days:       "<<mxSkDys<<endl;
    cout<<"Sick days Taken:     "<<sckTkn<<endl;
    cout<<"Max Vacation Days:   "<<mxVactn<<endl; 
    cout<<"Vacation days Taken: "<<vacnTkn<<endl;
    cout<<"Max unpaid Vac Days: "<<mxUnpd<<endl;
    cout<<"Unpaid Days Taken:   "<<unpdTkn<<endl;
}