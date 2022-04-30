// FCAI – Programming 1 – 2022 - Assignment 4
// Program Name: Text Editor Program
// Last Modification Date: 26/4/2022
// Author1 and ID and Group: Mohamed Hesham Mohamed / 20210543 / group A
// Author2 and ID and Group: Mostafa Aly Hashem / 20210394 / group A
// Author3 and ID and Group: Mostafa Bahy / 20210401 / group A
// Teaching Assistant: Eng. Abdulrahman Abdulmonem
// Purpose: in this file we will collect all the program functions together



// merge_files() is responsible for merging another file content after taking its name as an input from the user in the current file
//(function no. 6)
void merge_files(){

    string fileContent;
    // input a file name and open that file
    cout << "please enter the other file name :- ";
    cin.clear();
    getline(cin, filename);
    fin2.open(filename,ios::in);

    // check if the filename is valid
    if (!fin2) {
        cout << "Invalid File Name";
    }

    // to append what is in the file which we want to merge in the file we want to merge to
    while(getline(fin2, fileContent)) {
        fin <<" " + fileContent ;
    }
}


// words_number() is responsible for counting the words in the opened file (function no. 7)
void words_number(){
    string fileContent;
    int words_counter = 0;

    while (fin >> fileContent){

        words_counter += 1 ;
    }
    cout << "The number of words in this file =  " << words_counter;
}


// characters_number() is responsible for counting the characters in the opened file (function no. 8)
void characters_number(){
    string fileContent;
    int characters_counter = 0;

    while (getline(fin ,fileContent)){

        for (int i = 0;i < fileContent.length();i++){
            characters_counter += 1;\
        }
    }
    cout << "The number of characters (!! without counting the new lines as a character) in this file =  " << characters_counter;
}


// lines_number() is responsible for counting the lines in the opened file (function no. 9)
void lines_number(){
    string fileContent;
    int lines_counter = 0 ;
    while (getline(fin , fileContent)){
        lines_counter += 1;
    }
    cout << "The number of lines in this file =  " << lines_counter;
}


// search_for_word() is responsible for searching for a given word in teh opened file (function no.10)
void search_for_word() {
    string fileContent,a_word;
    int check_test = 0;

    cout << "please enter the word you want to search for in the file:-  ";
    cin >> a_word;

    // convert the given word to lower case
    for_each(a_word.begin(), a_word.end(), [](char & c){c = ::tolower(c);});

    while (fin >> fileContent){

        // convert the file words to lower case
        for_each(fileContent.begin(), fileContent.end(), [](char & c){c = ::tolower(c);});

        // to check if the word in the file and if so it increments the test
        if (a_word == fileContent ){
            check_test +=1;
        }
    }

    // to check if the test got incremented and if so then the  word is in the file ,if not then the word is not in the file
    if (check_test > 0){
        cout << "Word was found in the file :)\n";
    }
    else{
        cout<<"The word was not found in the file :(\n";
    }
}
