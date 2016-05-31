/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   assgnt5.h
 * Author: Jose
 *
 * Created on May 30, 2016, 4:55 PM
 */
#include <string>
using namespace std;

#ifndef ASSGNT5_H
#define ASSGNT5_H

//******************************************************************************
//******************************************************************************
//******************************************************************************
//chapter 15 problem 1
class employee{
    protected:
        string name;
        int number;
        string date;
    public:
        employee(){number=0;}
        employee(string n, int num, string day){name=n, number=num, date=day;}
        string getName(){return name;}
        string getDate(){return date;}
        int    getNum(){return number;}
};

class pWorker: public employee{
    private:
        float hrPay;
        int shift;
    public:
        pWorker(string nam, int num, string day, int shft, float pay):
        employee(nam, num, day){
            shift=shft;
            hrPay=pay;
        }
        float getPay(){return hrPay;}
        int getShft(){return shift;}
};
//******************************************************************************
//******************************************************************************
//************************* chapter 15 problem 2
class shiftS: public employee{
    private:
        float salary;
        float bonus;
    public:
        shiftS(float s, float b, string n, int num, string day ):employee(n,num,day)
        {salary=s, bonus=b, name=n, number=num, date=day;}
        float getSal(){return salary;}
        float getBs(){return bonus;}  
};
//******************************************************************************
//******************************************************************************
//******************************************************************************
//chapter 15 problem 6
class GradedActivity
{
    protected:
        char letter; // To hold the letter grade
        double score; // To hold the numeric score
    public:
        // Default constructor
        GradedActivity()
            { letter = ' '; score = 0.0; }
        // Accessor functions
        double getScore() const { return score; }
        char getLetterGrade() const { return letter; }
};

class Essay: public GradedActivity{
    private:
        int grmr;
        int spllg;
        int length;
        int content;
    public:
        Essay(int g, int s, int l, int c){grmr=g, spllg=s, length=l, content=c;}
        void calcGr();     
};
//******************************************************************************
//******************************************************************************
//******************************************************************************
//chapter 15 problem 4
// Specification file for the Time class
class Time{
    protected:
        int hour;
        int min;
        int sec;
    public:
        // Default constructor
        Time() { hour = 0; min = 0; sec = 0; }
        // Constructor
        // Accessor functions
        int getHour() const { return hour; }
        int getMin() const { return min; }
        int getSec() const { return sec; }
};

class milTime: public Time{
    protected:
        int milHours;
        int milSec;
    public:
        milTime(){;}
        milTime(int h, int s){milHours=h, milSec=s;}
        void setTime();
};
//******************************************************************************
//******************************************************************************
//******************************************************************************
//chapter 15 problem 5
class TimeClock: public milTime{
    private:
        int time1;
        int time2;
        int netTime;
    public:
        TimeClock(int a, int b){
            time1=a, time2=b;
        };
        void findDif();
        int getTime(){return netTime;}
};

#endif /* ASSGNT5_H */


