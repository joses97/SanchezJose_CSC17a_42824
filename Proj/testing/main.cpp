/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Jose
 *
 * Created on May 27, 2016, 1:25 AM
 */

#include <cstdlib>
#include <iostream>
#include "board.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    board test;
    test.display(0);
    test.createships(0, 1, 1, 2, 2);
    test.location(0);
    test.display(0);

    
    return 0;
}

