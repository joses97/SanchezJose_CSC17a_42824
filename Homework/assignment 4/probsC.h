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


#ifndef PROB1_H
#define PROB1_H
//problem 1 class
class date{
private:
    int day;
    int month;
    int year;
public:
    date(int, int, int);
    void getConv();
};
//problem 2 class
class info1{
private:
    string name;
    int idNum;
    string depart;
    string pos;
public:
    info();
    void receiveInfo();
    void dispInfo();
    
};  
//problem 3 class
class car{
private:
    int yrModel;
    string make;
    int speed;
public:
    car(int, string);
    void accl();
    void brake();
};
//problem 4 class
class info2{
private:
    string name;
    string address;
    int age;
    string phone;
public:
    void reciInfo();
    void displInfo();
};
//problem 5 class
class RetailItem{
private:
    string descr; //description
    int unitsOH;  //units on hand
    float price;  //retail price
public:
    RetailItem(string, int, float);
    string getDesc();
    int getUnit();
    float getPrce();
};
//class for problem 6
class Invtry{
private:
    int itmNum;
    int quant;
    float cost;
    float totCost;
public:
    Invtry();
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

#endif /* PROB1_H */

