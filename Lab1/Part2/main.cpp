#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    //These are the two strings we will be printing
    string dig = "0123456789";
    string digrev = "9876543210";

    //Printing out the first line
    cout  << dig << endl;

    //this loop will print the next 4 lines
    for(int i=0; i<4;i++){

        //Scaled the string into the desired postion for the middle 4 line
        cout  << setw(2*i+11)<< digrev << setw(22 + (2*i)) << dig << endl;

    }

    //Prints out the last line
    cout << setw(19) << digrev;
    return 0;
}