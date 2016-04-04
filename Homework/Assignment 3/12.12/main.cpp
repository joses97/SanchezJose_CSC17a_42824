/* 
 * File:   main.cpp
 * Author: Jose Sanchez
 * Purpose: 
 * Created on 
 */

//System Libraries
#include <iostream> //i/o
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes

//Structures
struct info{
    string name;
    int quarter;
    float sales;
};

//Execution Begins Here
int main(int argc, char** argv) {
    //declare and initialize variables
    info comp;
    char ansr='Y';
    fstream file;
    
    //open the file
    file.open("testFile.dat", ios::out | ios::binary); 
    
    do{
        //enter division name
        cout<<"Enter Division name"<<endl;
        getline(cin, comp.name);
         
        //enter quarter number
        cout<<"Enter Quarter number"<<endl;
        cin>>comp.quarter;
        
        //enter number of sales
        cout<<"Enter Quarterly Sales"<<endl;
        cin>>comp.sales;
        
        //write to file
        file.write(reinterpret_cast<char *>(&comp), sizeof(comp));
        
        //ask user for next entry
        cout<<"Would you like to enter another set of data? Y/N"<<endl;
        cin>>ansr;
        cin.ignore();
        
        
    }while(toupper(ansr=='Y'));
    cout<<comp.name;
    
    file.close();
    
    return 0;
}