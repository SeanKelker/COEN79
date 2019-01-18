//
// Created by Sean Kelker on 1/17/19.
//

#include "statistician.h"

using namespace coen79_lab2;

namespace coen79_lab2 {

    statistician::statistician() {
        count = 0;
        total = 0;
    }

    void statistician::next(double r) {
        total += r;

        if(count == 0){
            tiniest = r;
            largest = r;
        }
        else{
            if(r > largest) largest = r;
            if(r < tiniest) tiniest = r;
        }

        count++;
    }

    void statistician::reset() {
        total = 0;
        count = 0;
    }

    double statistician::mean() const {
        return total/count;
    }

    double statistician::minimum() const {
        return tiniest;
    }

    double statistician::maximum() const {
        return largest;
    }



    statistician operator+(const statistician &s1, const statistician &s2) {

        statistician temp;

        temp.count = s1.count + s2.count;
        temp.total = s1.total + s2.total;

        if(s1.largest > s2.largest){
            temp.largest = s1.largest;
        } else {
            temp.largest = s2.largest;
        }

        if(s1.tiniest < s2.tiniest){
            temp.tiniest = s1.tiniest;
        }else{
            temp.tiniest = s2.tiniest;
        }

        return temp;
    }

    statistician operator * (double scale, const statistician& s){
        statistician temp;
        temp.count = s.count;
        temp.total = scale * s.total;

        if(scale > 0) {
            temp.tiniest = scale * s.tiniest;
            temp.largest = scale * s.largest;
        }else{
            temp.tiniest = scale * s.largest;
            temp.largest = scale * s.tiniest;
        }

        return temp;
    }

    bool operator ==(const statistician& s1, const statistician& s2){

        if(s1.length () == 0 && s2.length () == 0){

            return true;

        } else if(s1.length () == s2.length () &&
                  s1.mean () == s2.mean () &&
                  s1.minimum () == s2.minimum () &&
                  s1.maximum () == s2.maximum () &&
                  s1.sum () == s2.sum ()){

            return true;

        }

        return false;


    }

};

