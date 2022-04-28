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
using namespace std;
string filname;
fstream fin;
void openfile(),closefile();

// openfile() is a function responsible for entering a file name and opening it to work on through the program
void openfile() {

    // input a file name and open that file
    cout << "please enter the file name :- ";
    getline(cin, filname);
    fin.open(filname);
    if (fin) {
        cout << "This File Already exists\n";
    }

    // check if the file is or existed not and if not asks to creat a new one or not
    while (!fin) {
        int choice;
        cout << "Could not the open file --> " + filname << endl;
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
            ofstream fin (filname);
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


    openfile();

    // here you can write any lines of to make ane changes to the file ex:
    // print the file content
    string fileContent;
    while (fin >> fileContent){
        cout << fileContent;
    }

    closefile();

    return 0;
     }
