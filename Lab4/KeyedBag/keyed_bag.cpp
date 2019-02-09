//
// Created by Sean Kelker on 2/1/19.
//


#include "keyed_bag.h"

namespace coen79_lab4
{

    keyed_bag::keyed_bag(){

        data = new value_type[CAPACITY];
        keys = new key_type[CAPACITY];
        used = 0;

    }

    keyed_bag::keyed_bag(const keyed_bag &b) {

        std::copy (b.data,b.data+b.used,data);
        std::copy (b.keys,b.keys+b.used,keys);
        used = b.used;

    }

    void keyed_bag::erase(){
        used = 0;
    }

    void keyed_bag::insert(const value_type& entry, const key_type& key){

        if(!has_key (key)){
            keys[used] = key;
            data[used] = entry;
            used++;
        }



    }

    bool keyed_bag::erase(const keyed_bag::key_type &key) {

        size_type i;
        for(i=0;i<used;i++){
            if(keys[i] == key){
                used--;
                keys[i] = keys[used];
                data[i] = data[used];
                return true;
            }
        }

        return false;

    }

    bool keyed_bag::has_key(const key_type& key) const{

        size_type i;
        for(i=0;i<used;i++){
            if(keys[i] == key){
                return true;
            }
        }

        return false;

    }

    keyed_bag::value_type keyed_bag::get(const keyed_bag::key_type &key) const {

        assert(has_key(key));

        size_type i;
        for(i=0;i<used;i++){
            if(keys[i] == key){
                return data[i];
            }
        }

        return NULL;


    }

    keyed_bag::size_type keyed_bag::size() const {
        return used;
    }

    keyed_bag::size_type keyed_bag::count(const keyed_bag::value_type &target) const {
        size_type i;
        size_type n = 0;
        for(i=0;i<used;i++){
            if(data[i] == target){

                n++;
            }
        }

        return n;

    }

    bool keyed_bag::hasDuplicateKey(const keyed_bag &otherBag) const {
        size_type i;
        for(i=0;i<used;i++){
            if(otherBag.has_key (keys[i])){
                return true;
            }

        }

        return false;
    }

    void keyed_bag::operator=(const keyed_bag &b) {

        std::copy (b.data,b.data+b.used,data);
        std::copy (b.keys,b.keys+b.used,keys);
        used = b.used;

    }

    void keyed_bag::operator+=(const keyed_bag &addend) {


        std::copy (addend.data, addend.data + addend.used, data + used);
        std::copy (addend.keys, addend.keys + addend.used, keys + used);

        used += addend.used;
    }

    keyed_bag operator +(const keyed_bag& b1, const keyed_bag& b2){

        keyed_bag new_bag;
        new_bag += b1;
        new_bag += b2;
        return new_bag;

    }


}
