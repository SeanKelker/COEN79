/*
	File:
		mystring.cpp

	Author:
		Sean Kelker

	Purpose:
		Implementation of a super sick string to Coen 79 Lab
	Invariants:

        The string is stored in char array that dynamically allocated and null terminate. The amount of data that is allocated for the
        array is modified by the reserve function which is called by every function that make additive changes to the array.

        Allocated is the current amount of data where current_length is the amount of char stored in the array

        the value of charecters[current_length+1] should always be the null terminater '\0'

*/

#include "mystring.h"
#include <iostream>
#include <string.h>

using namespace std;

namespace coen79_lab5 {

    string::string(const char *str) {

        current_length = strlen (str);
        assert (str[current_length] == '\0');

        characters = new char[current_length + 1];
        for (int i = 0; i <= current_length; i++) {
            characters[i] = str[i];
        }

        allocated = current_length + 1;

    }

    string::string(char c) {

        current_length = 1;

        characters = new char[current_length + 1];
        characters[0] = c;
        characters[1] = '\0';

        allocated = current_length + 1;

    }

    string::string(const string &source) {

        current_length = source.current_length;

        characters = new char[source.allocated];
        for (int i = 0; i <= current_length; i++) {
            characters[i] = source.characters[i];
        }

        allocated = source.allocated;

    }

    string::~string() {

        delete[] characters;

    }

    void string::operator+=(const string &addend) {

        if (allocated < current_length + addend.current_length) {
            reserve (current_length + addend.current_length + 1);
        }

        for (int i = 0; i < addend.current_length + 1; i++) {
            characters[current_length + i] = addend.characters[i];
        }

        current_length = current_length + addend.current_length;
        characters[current_length + 1] = '\0';

    }

    void string::operator+=(const char *addend) {

        *this += string (addend);

    }

    void string::operator+=(char addend) {

        *this += string (addend);

    }

    void string::reserve(size_t n) {

        char *tmp = new char[n];
        copy (characters, characters + n, tmp);
        delete[] characters;
        characters = tmp;
        allocated = n;

    }

    string &string::operator=(const string &source) {

        current_length = source.length ();
        reserve (source.allocated);
        copy (source.characters, source.characters + source.current_length + 1, characters);
        return *this;

    }

    void string::insert(const string &source, unsigned int position) {\
        assert(position <= length ());

        string front, back;

        for (int i = 0; i < current_length; i++) {
            if (i < position) {
                front += string (characters[i]);
            } else {
                back += string (characters[i]);
            }
        }

        *this = front + source + back;

    }

    void string::dlt(unsigned int position, unsigned int num) {

        assert ((position + num) <= length ());

        string front;
        for (int i = 0; i < current_length; i++) {
            if (i < position || i >= position + num) {
                front += string (characters[i]);
            }
        }

        *this = front;

    }

    void string::replace(char c, unsigned int position) {
        assert (position < length ());
        characters[position] = c;
    }

    void string::replace(const string &source, unsigned int position) {
        assert(position + source.length () <= length ());

        for (int i = 0; i < source.length (); i++) {
            replace (source[i], i + position);
        }

    }

    char string::operator[](size_t position) const {

        assert (position < length ());
        return characters[position];

    }

    int string::search(char c) const {
        for (int i = 0; i < current_length; i++) {
            if (characters[i] == c) {
                return i;
            }
        }
        return -1;
    }

    int string::search(const string &substring) const {

        for (size_t i = 0; i < current_length; i++) {
            if (*(characters + i) == substring[0]) {
                bool flag = 1;
                for (size_t j = 0; j < substring.length (); j++) {
                    if (*(characters + i + j) != substring[j]) flag = 0;
                };
                if (flag) return i;
            };
        };
        return -1;

    }

    unsigned int string::count(char c) const {
        size_t count = 0;
        for (int i = 0; i < current_length; i++) {
            if (characters[i] == c) {
                count++;
            }
        }
        return count;
    }

    std::ostream &operator<<(std::ostream &outs, const string &source) {

        outs << source.characters;
        return outs;

    }

    bool operator==(const string &s1, const string &s2) {

        if (strncmp (s1.characters, s2.characters, 30) == 0) {
            return true;
        } else {
            return false;
        }

    }

    bool operator!=(const string &s1, const string &s2) {
        return !(s1 == s2);
    }

    bool operator>(const string &s1, const string &s2) {
        if (strncmp (s1.characters, s2.characters, 30) > 0) {
            return true;
        } else {
            return false;
        }
    }

    bool operator<(const string &s1, const string &s2) {
        return !(s1 >= s2);
    }

    bool operator>=(const string &s1, const string &s2) {
        if (strncmp (s1.characters, s2.characters, 30) >= 0) {
            return true;
        } else {
            return false;
        }
    }

    bool operator<=(const string &s1, const string &s2) {
        return !(s1 > s2);
    }

    string operator+(const string &s1, const string &s2) {

        string new_string = string (s1);
        new_string += s2;
        return new_string;

    }

    string coen79_lab5::operator+(const string &s1, const char *addend) {

        string new_string = string (s1);
        new_string += string (addend);
        return new_string;

    }

    istream &operator>>(istream &ins, string &target) {

        char *tmp = new char[1000];
        cin >> tmp;
        target = string (tmp);

        return ins;

    }

}