#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, const char * argv[]) {

    //This opens up the file
    ifstream file;
    string filename(argv[1]);
    file.open(filename);

    //Parse the file unitl we see EOF
    while(file && file.peek () != EOF){

        //This grabs the next work from the text file
        string currentWord;
        file >> currentWord;

        //This is where we save the letters to our final word
        string wordBuffer = "";

        for(int i=0; i<currentWord.length();i++){

            //if its a letter we capitalize it and add back to the buffer
            if(isalpha(currentWord[i])){
                wordBuffer += toupper(currentWord[i]);
            }
        }

        //checks to make sure the letters are <10 and then prints
        if(wordBuffer.length () >= 10){
            cout << wordBuffer  << endl;
        }

    }

    return 0;
}