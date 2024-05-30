// FILE: keyed_bag.h
// CLASS PROVIDED: keyed_bag (part of the namespace coen79_lab4)
//
//
// COEN 79
// --- Sid Kalidindi, COEN, SCU 2/7/24
//
//
// TYPEDEF and MEMBER CONSTANTS for the keyed_bag class:
// typedef ____ value_type
// keyed_bag::value_type is the data type of the items in the keyed_bag. It maybe any of
// the C++ built-in types (int, char, etc.), or a class with a default
// constructor, an assignment operator, and operators to
// test for equality (x == y) and non-equality (x != y).
//
// typedef ____ key_type
// keyed_bag::key_type is the data type of the items used as keys for the items
// in the keyed_bag. It may be any of the C++ built-in types (int, char, etc.),
// or a class with a default constructor, an assignment operator, and
// operators to test for equality (x == y) and non-equality (x != y).
//
// typedef ____ size_type
// keyed_bag::size_type is the data type of any variable that keeps track of how many items
// are in a keyed_bag.
//
// static const size_type CAPACITY = _____
// keyed_bag::CAPACITY is the maximum number of items that a keyed_bag can hold.
//
// CONSTRUCTOR for the keyed_bag class:
// keyed_bag( )
// Postcondition: The keyed_bag has been initialized as an empty keyed_bag.
//
//
// MODIFICATION MEMBER FUNCTIONS for the keyed_bag class:
// void erase();
// Postcondition: This keyed_bag is emptied of all items and keys.
//
// bool erase(const key_type& key);
// Postcondition: If key was in the keyed_bag, then the key and its value have been removed;
// otherwise the keyed_bag is unchanged. A true return value indicates that an
// item was removed; false indicates that nothing was removed.
//
// void insert(const value_type& entry, const key_type& key)
// Precondition: size( ) < CAPACITY, and the keyed_bag does not yet contain
// the given key.
// Postcondition: A new copy of entry has been added to the keyed_bag with
// the corresponding key.
//
// void operator +=(const keyed_bag& addend)
// Precondition: size( ) + addend.size( ) <= CAPACITY.
// The intersection of the keyed_bags' key tables is empty (i.e. the keyed_bags)
// share no keys.
// Postcondition: Each item and its key in addend has been added to this keyed_bag.
//
//
// CONSTANT MEMBER FUNCTIONS for the keyed_bag class:
// bool has_key(const key_type& key) const
// Postcondition: The return value is whether or not the given key is in
// the keyed_bag's list of keys.
//
// value_type get(const key_type& key) const;
// Precondition: has_key returns true for the given key.
// Postcondtion: the data value corresponding to the given key is returned.
//
// size_type size( ) const
// Postcondition: The return value is the total number of items in the keyed_bag.
//
// size_type count(const value_type& target) const
// Postcondition: The return value is number of times target is in the keyed_bag.
//
// bool hasDuplicateKey(const keyed_bag& otherBag) const
// Postcondition: The return value is true if there is at least one key used by both this bag and the "otherBag". In other words, this function checks if there is any shared key by the two bags.
//
// NONMEMBER FUNCTIONS for the keyed_bag class:
// keyed_bag operator +(const keyed_bag& b1, const keyed_bag& b2)
// Precondition: b1.size( ) + b2.size( ) <= keyed_bag::CAPACITY.
// The intersection of the keyed_bags' key tables is empty.
// (i.e. The two keyed_bag's have no keys in common.)
// Postcondition: The keyed_bag returned is the union of b1 and b2.
//
//
// VALUE SEMANTICS for the keyed_bag class:
// Assignments and the copy constructor may be used with keyed_bag objects.


#include <cstdlib>
#include <string>
#include <iostream>
#include <cassert>
#include <cmath>
#include "keyed_bag.h"

using namespace std;
using namespace coen79_lab4;

namespace coen79_lab4
{
	keyed_bag :: keyed_bag(){
		for(int i = 0; i < CAPACITY; i++) {
            		keys[i] = '\0';
            		data[i] = '\0';
        	}
        	used = 0;
	}

        void keyed_bag :: erase(){
		for(int i = 0; i < used; i++) {
            		keys[i] = '\0';
            		data[i] = '\0';
        	}
        	used = 0;
	}

        bool keyed_bag :: erase(const key_type& key){
		assert(used > 0);                         
	     	for(int i = 0; i < used; i++) {
            		if(keys[i] == key) {
                		for(int j = i; j < used-1 ; j++) {
                    			keys[j] = keys[j+1];
                    			data[j] = data[j+1];
                		}
                	used--;
                	return true;
            		}
       		}
        	return false;	
	}
        
	void keyed_bag :: insert(const value_type& entry, const key_type& key){
        	assert((size() < CAPACITY) && (has_key(key) == false));
        	keys[used] = key;
        	data[used] = entry;
        	used++;
	}

        void keyed_bag :: operator+=(const keyed_bag& addend){
		assert(size() + addend.size() <= CAPACITY);
        	for (int i = 0; i < addend.used; ++i){
            		if (!has_key(addend.keys[i])){                         
                		keys[used] = addend.keys[i]; 
                		data[used] = addend.data[i];
                		used++;
            		}
        	}
	}

        bool keyed_bag :: has_key(const key_type& key) const{
        	for (int i = 0; i < used; ++i){
            		if (keys[i] == key){
                		return true; 
            		}
        	}
        	return false; 
	}

	keyed_bag :: value_type keyed_bag :: get(const key_type& key) const{
		assert(has_key(key));
        	for(int i = 0; i < used; i++) {
            		if(keys[i] == key) {
                		return data[i];
            		}
        	}
        	return '\0';		
	}

	keyed_bag :: size_type keyed_bag :: size() const{
		return used;
	}

	keyed_bag :: size_type keyed_bag :: count(const value_type& target) const{
	        size_type count = 0;
        	for(int i = 0; i < used; i++) {
            		if(data[i] == target) {
                		count++;
            		}
        	}
        	return count;
	}

        bool keyed_bag :: hasDuplicateKey(const keyed_bag& otherBag) const{
		for(int i = 0; i < otherBag.used; ++i) {
            		if( has_key(otherBag.keys[i]) ) {
                		return true;
            		}
        	}
        	return false;
	}

	keyed_bag operator +(const keyed_bag& b1, const keyed_bag& b2){
		assert(b1.size() + b2.size() <= keyed_bag::CAPACITY);
        	keyed_bag temp; 
        	temp += b1;
        	temp += b2;

        	return temp;
	}
}

