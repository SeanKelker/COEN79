#include <iostream>

using namespace std;

int main() {

    string s;
    cout << "Please type something:" << endl;
    //Get a line from user input
    getline( std::cin, s );
    int alpha = 0;
    int non = 0;

    //Loop through all the letters in the string
    for(int i = 0;i < s.size ();i++){
        //if its an alphanumeric we add it to out alpha count
        if (isalnum(s[i])){
            alpha++;
        }
        //we check if its not a space and add that to out non count
        else if(s[i] != ' '){
            non++;
        }

    }
    //Print out of the desired format
    cout << "\"" << s << "” has " << alpha << " alphanumeric characters and " << non << " non-alphanumeric characters.";
    return 0;
}