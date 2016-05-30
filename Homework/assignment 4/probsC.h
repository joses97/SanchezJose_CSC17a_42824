/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   prob1.h
 * Author: Jose
 *
 * Created on May 2, 2016, 10:45 PM
 */
#include <string>
using namespace std;

const int SIZE=19;
const int SIZE2=8;
const int SIZE3=12;

#ifndef PROB1_H
#define PROB1_H
//problem 1 class
class date{
    private:
        int day; //day
        int month; //month
        int year; //year
    public:
        date(int, int, int); //date constructor
        void getConv(); //covert
};
//problem 2 class
class info1{
    private:
        string name; //name 
        int idNum; //id number
        string depart; //department
        string pos; //position
    public:
        info(); //defaulted constructor 
        void setInfo(int num, string name, string depart, string pos); //set info
        void dispInfo(); //displays info
    
};  
//problem 3 class
class car{
    private:
        int yrModel; //year of the car
        string make; //make of the car
        int speed;  //current speed of the car
    public:
        car(int, string);  //constructor accepts for year and make
        void accl(); //accelerates 
        void brake(); //slows down
};
//problem 4 class
class info2{
    //problem 4
    private:
        string name; //name 
        string address; //address
        int age;  //age
        string phone; //phone number
    public:
        info2(); //defaulted constructor 
        void setInfo(int, string, string, string); //set info
        int getAge();
        string getName();
        string getAdd();
        string getPhne();
};
//problem 5 class
class RetailItem{
    private:
        string descr; //description
        int unitsOH;  //units on hand
        float price;  //retail price
    public:
        RetailItem(string, int, float); //constructor
        string getDesc(); //get description
        int getUnit();    //get unit
        float getPrce();   //get price
    };
//class for problem 6
class Invtry{
    private:
        int itmNum;
        int quant;
        float cost;
        float totCost;
    public:
        Invtry(int, int, float);
        void setItNum(int num ){itmNum=num;}
        void setQuant(int num ){quant=num;}
        void setCost(float num ){cost=num;}
        void setTCost();
        int getNum(){return itmNum;}
        int getQuant(){return quant;}
        float getCost(){return cost;}
        float getTCost(){return totCost;}

};

//problem 1 chapter 14 class
//******************************************************************************
//******************************************************************************
class numbers{
    private:
        int number; //number
        static string less20[SIZE];  //array from one to nineteen
        static string above20[SIZE2]; //array from twenty to ninety
        static string hundrd; //holds "hundred"
        static string thousnd;  //holds "thousand"
    public:
        numbers(int num){number=num;}
        void print();
};

#endif /* PROB1_H */

//problem 2 chapter 14 class
//******************************************************************************
//******************************************************************************
class dOfYear{
    private:
        int day;
        static string month[SIZE3];
    public:
        dOfYear(int num){day=num;}
        print();
        
};
//problem 3 chapter 14 class
//******************************************************************************
//******************************************************************************
class dOfYear2{
    private:
        string month;
        int day;
    public:
        dOfYear2(string m , int n);
        void display();
        dOfYear2& operator++();
        dOfYear2 operator++(int);
        dOfYear2& operator--();
        dOfYear2 operator--(int);
};
//problem 4 chapter 14 class
//******************************************************************************
//******************************************************************************
class NumDays{
    private:
        int hours;
        float days;
    public:
        NumDays(){hours=0, days=0;}
        void setHour(int h){hours=h;}
        void conv();
        float getDays(){return days;}
        NumDays operator+(const NumDays &r);
        NumDays operator-(const NumDays &r);
        NumDays& operator++();
        NumDays operator++(int);
        NumDays& operator--();
        NumDays operator--(int);
        
};
//problem 5 chapter 14 class
//******************************************************************************
//******************************************************************************
class timeOff{
    private:
        string name;
        int mxSkDys;
        int sckTkn; 
        int mxVactn;
        int vacnTkn;
        int mxUnpd;
        int unpdTkn;
    public:
        timeOff(string m){name=m;}
        void getInfo(int, int, int , int, int, int);
        void display();
};

