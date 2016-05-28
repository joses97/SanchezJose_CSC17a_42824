/* 
 * File:   board.h
 * Author: Jose
 *
 * Created on May 27, 2016, 12:58 AM
 */

#include "shipps.h"
#include <iostream>
using namespace std;


#ifndef BOARD_H
#define	BOARD_H
const int SIZE=10;
const int NUMSHIP=5;

class board{
    private:
        static int count;
        char array[SIZE][SIZE];
        warShip ships[NUMSHIP];
    public:
        board(){
            for(int i=0; i<SIZE; i++){
                for(int j=0; j<SIZE; j++){
                    array[i][j]='-';
                }
            }
            count++;
        }    
        
        operator int(){
            return count;
        }
        
        void operator = (const board &right){
            for(int i=0; i<SIZE; i++){
                for(int j=0; j<SIZE; j++){
                    array[i][j]=right.array[i][j];
                }
            }
        }
        
        void createships(int i, int a, int b, int c, int d){
            ships[i].battleshipC(a, b, c, d);
        }
        
        
        void location(int i){
            array[ships[i].getypos()-1][ships[i].getxpos()-1]='X';
            array[ships[i].getfypos()-1][ships[i].getfxpos()-1]='X';
        }
        
        
        
        void display(){
            cout<<"    1   2   3   4   5   6   7   8   9   10"<<endl;
            for(int i=0; i<SIZE; i++){
                cout<<i+1;
                for(int j=0; j<SIZE; j++){
                    cout<<" | "<<array[i][j];
                }  
                cout<<endl;
            }               
        }
        
        
        
        void fillrest(int n){
            for(int i=ships[n].getxpos(); i<ships[n].getfxpos(); i++){
                array[ships[n].getypos()-1][i]='X';
            }
            for(int i=ships[n].getypos(); i<ships[n].getfypos(); i++){
                array[i][ships[n].getxpos()-1]='X';
            }           
        }

};

int board::count=0;

#endif	/* BOARD_H */


