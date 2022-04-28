// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: Text Editor Program
// Last Modification Date: 26/4/2022
// Author1 and ID and Group: Mohamed Hesham Mohamed / 20210543 / group A
// Author2 and ID and Group: Mostafa Aly Hashem / 20210394 / group A
// Author3 and ID and Group: Mostafa Bahy / 20210401 / group A
// Teaching Assistant: Eng. Abdulrahman Abdulmonem
// Purpose:..........

#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <cctype>
using namespace std;
string filename,filename2;
fstream fin,fin2;
void open_toread_file(),closefile();

// open_toread_file() is a function responsible for entering a file name and opening for reading it to work on through the program ,
// checks if it exists or not and if not it creates a new one with the given name and opens it for writing
void open_toread_file() {

    // input a file name and open that file
    cout << "please enter the file name :- ";
    getline(cin, filename);
    fin.open(filename);
    if (fin) {
        cout << "\nThis File Already exists\n\n";
    }

    // check if the file is or existed not and if not asks to creat a new one or not
    while (!fin) {
        int choice;
        cout << "Could not the open file --> " + filename << endl;
        cout << "if you want to creat a new file please enter 1 if not enter 0 :- ";
        cin >> choice;

        // to check the user input for the choice (defensive)
        while (true) {
            if (choice == 1 || choice == 0) {
                break;
            }
            else {
                cin.clear();
                cout << "\nif you want to creat a new file please enter 1 if not enter 0 :- ";
                cin >> choice;
            }
        }

        if (choice == 1) {

            // creating a new file here
            ofstream fin (filename,ios::out|ios::app);

            cout << "This is a new file. I created it for you\n";
            break;
        }
        else
            break;
    }

}

// closefile() is a function responsible for closing the file after using it
void closefile(){
    fin.close();
}







int main() {

    open_toread_file();

//     here you can write any lines of to make ane changes to the file ex:
//     print the file content
    string fileContent;
    while (fin >> fileContent){
        cout << fileContent;
    }

    closefile();

    return 0;
     }
