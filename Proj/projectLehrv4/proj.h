/* 
 * File:   proj.h
 * Author: Jose
 *
 * Created on May 3, 2016, 9:42 PM
 */
const int SIZE=10;
#include <string>
using namespace std;

#ifndef PROJ_H
#define PROJ_H

struct players{
    string name; //name of player
    char board[SIZE][SIZE]; //board of player
};


#endif /* PROJ_H */

