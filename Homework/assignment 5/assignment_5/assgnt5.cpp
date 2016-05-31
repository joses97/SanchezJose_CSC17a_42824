/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "assgnt5.h"
#include <string>
#include <iostream>
using namespace std;
//******************************************************************************
//******************************************************************************
//******************************************************************************
//Chapter 15 Problem 6 class functions
void Essay::calcGr(){
    int num=grmr+spllg+length+content;
    score=num;
    char letterGrade; // To hold the letter grade
    if (score > 89)
    letterGrade = 'A';
    else if (score > 79)
    letterGrade = 'B';
    else if (score > 69)
    letterGrade = 'C';
    else if (score > 59)
    letterGrade = 'D';
    else
    letterGrade = 'F';
    letter=letterGrade;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
//Chapter 15 Problem 4 class functions
void milTime::setTime(){
    int num=milHours;
    int num2=num;
    
    num=num%100;
    num2=(milHours-num)/100;
    
    hour=num2;
    min=num;
    sec=milSec;
}
//******************************************************************************
//******************************************************************************
//******************************************************************************
//Chapter 15 Problem 5 class functions
void TimeClock::findDif(){
    netTime=time1-time2;
}