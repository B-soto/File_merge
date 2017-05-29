//
//  main.cpp
//  hw_2_file_merge
//
//  Created by bryce soto on 2/27/17.
//  Copyright © 2017 Bryce Soto. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
using namespace std;

int main() {
    ifstream inStream1, inStream2;
    ofstream outStream;
    string file1, file2, filey;
    
    //ask user for two files with sorted integers
    cout << "Hello! Please enter the name of the first text file you want to open:";
    cin >> file1;
    cout <<"Please enter the name of the second text file you want to open:";
    cin >>file2;
    
    //try to open both files
    inStream1.open(file1);
    if (inStream1.fail()){
        cout << file1 <<" open failed \n";
        exit (1);
    }
    //try to open file 2
    inStream2.open(file2);
    if (inStream2.fail()){
        cout << file2 <<" open failed \n";
        exit (1);
    }
    outStream.open("filey.txt");
    if (outStream.fail()){
        cout << "File Y error";
    }
    
    
    
    int f1num, f2num;
    inStream1 >> f1num;
    inStream2 >> f2num;
    
    while(true){
        //chek to see if file 1 is empty
        if (inStream1.fail()){
            //fill the output file with the rest of file 2
            while(true){
                outStream << f2num << endl;
                inStream2 >> f2num;
                if (inStream1.fail()){
                    break;
                }
            }
            break;
        }
        //chek to see if file 2 is empty
        if (inStream2.fail()){
            //fill the output file with the rest of file 2
            while(true){
                outStream << f1num << endl;
                inStream1 >> f1num;
                if (inStream1.fail()){
                    break;
                }
            }
            break;
        }
        
        if (f1num > f2num){
            outStream << f2num << endl;
            inStream2 >> f2num;
        }else{
            outStream << f1num << endl;
            inStream1 >> f1num;
        }
        
        
        if (inStream1.fail() && inStream2.fail() ) {
            break;
        }
    }
    cout << "Thanks for you entry, your files have been merged into 'filey.txt' !";
    return 0;
}








