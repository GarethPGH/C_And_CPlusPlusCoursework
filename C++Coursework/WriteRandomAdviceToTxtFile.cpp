/*
Name: Gareth Warren
Date: 10/23/2121
Class: CIT-245 Z01
IDE: Visual Studio Community 2022 Preview 

Program that creates file called advice.txt, and allows a user to read or write contents to it
*/

#pragma warning(disable: 4996)
#include <string>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>

using namespace std;

//Helper function WriteMore determines whether user input is Yes or Y to reduce repetitive code
bool WriteMore(bool writeMore){
    string selection = "";
    int length = 0;
    char amIYes[4] = "nop";
    char upperCase[4] = "   ";
    writeMore = false;
        
    cout << "Do you want to write more advice? Yes or No: ";
    getline(cin, selection);

    if (strlen(selection.c_str()) > 3 || strlen(selection.c_str()) == 0){
        return writeMore;
    }
    else {
        strncpy(amIYes, selection.c_str(), 3);
        for (int index = 0; index < 3; index++) {
            upperCase[index] = toupper(amIYes[index]);
        }
        upperCase[3] = '\0';
        if (strcmp(upperCase, "YES") == 0 || strcmp(upperCase, "Y") == 0) {
            writeMore = true;
        }
    }
    return writeMore;
}

//Input to the screen a file contents
void ReadFile(string filename) {
    ifstream stream(filename.c_str());
    char c = ' ';
    string str;
    char fileSentence[100]={};

    if (!stream.fail()) {
        if (stream.eof() || !stream >> c) {
            cout << "File Created, but Empty" << endl;
        }
        else {
            while (!stream.eof()) {
                getline(stream, str);
                cout << str << endl;
            }
        }
        stream.close();
    }
    else {
        stream.close(); // close the input file stream
        fstream inOutStream(filename.c_str(), ios::in | ios::trunc); // create new file
        if (inOutStream.fail()) {
            cout << "Error Reading File: Exiting Program..." << endl;
            exit(1);
        }else if (inOutStream.eof() || !inOutStream >> c) {
            cout << "File Created, but Empty" << endl;
        }
        else {
            while (!inOutStream.eof()) {
                getline(inOutStream, str);
                cout << str << endl;
            }
        }
        inOutStream.close();
    }
}

//Ouput to a File, Create one if none exists
void WriteFile(string filename){
    ofstream stream(filename.c_str(), ios::app);
    string str = "";
    bool bValue = true;
    bool writeMore = true;

    if (!stream.fail()){ 
        while(writeMore && !stream.eof()){     
            str = cin.get();
            for (char c: str) {
                if (c == '\n') {
                    stream.put('\n');
                    writeMore = WriteMore(bValue);
                }
                else {
                    stream.put(c);
                }
            }
        }
        stream.close();
    }else{ 
        stream.close(); // close the input file stream
        fstream inOutStream(filename,  ios::app | ios::out | ios::trunc); // create new file
        if (inOutStream.fail()) {
            cout << "Error Writing to File: Exiting Program..." << endl;
            exit(1);
        }
        else {
            while (writeMore || !inOutStream.eof()) {
                str = cin.get();
                for (char c : str) {
                    if (c == '\n') {
                        inOutStream.put('\n');
                        writeMore = WriteMore(bValue);
                    }
                    else {
                        inOutStream.put(c);
                    }
                }
            }
        }
        inOutStream.close();
    } 
}

int main(){
    string placeholder = "";
    char selection = 'n';
    bool goAgain = true;

    cout << "Do you want to read some advice, or write some advice to a file? 1-Read Advice, 2-Write Advice, Anything else to exit: ";
    do {
        cin >> placeholder;
        cin.get();

        if (strlen(placeholder.c_str()) > 1) {
            cout << "Exiting Program..." << endl;
            goAgain = false;
        }
        else {
            selection = placeholder.c_str()[0];
            if (isdigit(selection) != 0) {
                if (selection == '1') {
                    cout << "Read advice.txt" << endl;
                    ReadFile("advice.txt");
                    cout << "\nDo you want to read some advice, or write some advice to a file? 1-Read Advice, 2-Write Advice, Anything else to end: ";
                }
                else if (selection == '2') {
                    cout << "Write some Advice." << endl;
                    WriteFile("advice.txt");
                    cout << "\nDo you want to read some advice, or write some advice to a file? 1-Read Advice, 2-Write Advice, Anything else to end: ";
                }
            }
            else{
                cout << "Exiting Program..." << endl;
                exit(1);
            }
        }
    } while (goAgain);

    system("pause");
    return 0;
}