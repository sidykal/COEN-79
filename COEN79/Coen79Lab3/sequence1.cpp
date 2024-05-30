// FILE: sequence1.h
// Sequence Class
//
// COEN 79
// --- Sid Kalidindi, CSEN, SCU, 2/01/2024 ---
//
// TYPEDEF and MEMBER CONSTANTS for the sequence class:
// static const size_t CAPACITY = ____
// sequence::CAPACITY is the maximum number of items that a sequence can hold.
//
// typedef ____ value_type
// sequence::value_type is the data type of the items in the sequence. It may beany of
// the C++ built-in types (int, char, etc.), or a class with a default
// constructor, an assignment operator, and a copy constructor.
//
//
// CONSTRUCTOR for the sequence class:
// sequence( )
// Postcondition: The sequence has been initialized as an empty sequence.
//
//
//
// MODIFICATION MEMBER FUNCTIONS for the sequence class:
//
// void start();
// Poscondition: The iterator is reset to position 0;
//
// void end();
// Poscondition: The iterator points to the last item in the sequence;
//
// void last();
// Poscondition: The iterator is reset to CAPACITY - 1, regardless of the numebr of items in the sequence;
//
// void advance();
// Precondtion: isitem() returns true
// Postcondition: The iterator's value is increased by 1, unless it is already at the end of the sequence.
//
// void retreat();
// Postcondition: The iterator's value is reduced by 1, unless it is already at the beginning of the sequence.
//
//
// void insert(const value_type& entry);
// Precondition: size() < CAPACITY
// Postcondition: A new copy of entry has been inserted in the sequence
// before the current item. If there was no current item, the new entry
// has been inserted at the front. In either case, the new item is now the
// current item of the sequence.
//
// void attach(const value_type& entry);
// Precondition: size() < CAPACITY
// Postcondition: A new copy of entry has been inserted in the sequence
// after the current item. If there was no current item, the new entry
// has been attached to the end. In either case, the new item is now the
// current item of the sequence.
//
// void remove_current();
// Precondtion: isitem() returns true
// Postcondition: The current item has been removed from the sequence,
// and the item after this (if there is one) is now the current item.
//
//
// void insert_front(const value_type& entry);
// Precondition: size() < CAPACITY
// Postcondition: A new copy of entry has been inserted in the sequence
// at the front. The new item is now the current item of the sequence.
//
// void attach_back(const value_type& entry);
// Precondition: size() < CAPACITY
// Postcondition: A new copy of entry has been inserted in the sequence
// at the back. The new item is now the current item of the sequence.
//
// void remove_front();
// Precondtion: isitem() returns true
// Postcondition: The item at the front of the sequence has been removed from the sequence,
// and the current item points at the front of the sequence.
//
// void operator +=(const sequence& lhs, const sequence& rhs)
// Postcondition: Adds the items of rhs to the lhs. Also returns a copy of lhs.
//
//
// CONSTANT MEMBER FUNCTIONS for the sequence class:
//
// size_type size() const;
// Postcondition: The return value is the number of items in the ssequence.
//
// bool is_item( ) const
// Postcondition: A true return value indicates that there is a valid
// "current" item that may be retrieved by activating the current
// member function (listed below). A false return value indicates that
// there is no valid current item.
//
// value_type current() const;
// Precondtion: isitem() returns true
// Poscondition: Returns the item in the sequence at the current position of the iterator.
//
// value_type operator[](int index) const
// Precondition: index < used
// Postcondition: The item returned is the item stored at "index"
//
// double mean() const
// Postcondition: The value returned is the mean of the values stored in the sequence.
//
// double standardDeviation() const
// Postcondition: The value returned is the stadard deviation of the values stored in the sequence.
//
//
//
//
// NON-MEMBER functions for the statistician class:
//
// sequence operator +(const sequence& lhs, const sequence& rhs)
// Postcondition: The sequence that is returned contains all the
// numbers of the sequences of lsh and rhs.
//
//
// value_type summation(const sequence &s)
// Postcondition: The value returned is the summation of the values stored in the sequence s.
//
//
// VALUE SEMANTICS for the sequence class:
// Assignments and the copy constructor may be used with sequence objects.
//
//



#include <iostream>
#include <cassert>
#include <cmath>
#include "sequence1.h"

using namespace std;
using namespace coen79_lab3;

namespace coen79_lab3 {
        // TYPEDEF and MEMBER CONSTANTS
	typedef double value_type;
        typedef std::size_t size_type;
	static const size_type CAPACITY = 30;
        sequence :: sequence(){
		used = 0;
		current_index = 0;
		
	}       
                      
	void sequence :: start(){
		current_index = 0;
	}
			
	void sequence :: end(){
		current_index = used;
	}

	void sequence :: last(){
		current_index = CAPACITY-1;
	}

        void sequence :: advance(){
		if(is_item() == true){
			current_index++;
		}
	}

        void sequence :: retreat(){
		if(current_index != 0){
			current_index--;
		}
	}
        
	void sequence :: insert(const value_type& entry){
		assert(size() < CAPACITY);
		if(is_item() == false){
			current_index = 0;
		}
		else{
			for(int i = used; i > current_index; i--){
                                data[i] = data[i-1];
                        }
		}
		data[current_index] = entry;
		used++;
	}
                       
       	void sequence :: insert_front(const value_type& entry){
		assert(size() < CAPACITY);
		if(used > 0){
			for(int i = used; i >= 0; i--){
				data[i] = data[i-1];
			}
		}
		data[0] = entry;
		current_index = 0;
		used++;
	}
        
	void sequence :: attach(const value_type& entry){
		assert(size() < CAPACITY);
		if(is_item() == true){
			for(int i = used; i > current_index+1; i--){
				data[i] = data[i-1];
			}
			current_index++;
			data[current_index] = entry;
		}
		else{
			data[current_index] = entry;
		}
		used++;
	}
	
	void sequence :: attach_back(const value_type& entry){
		assert(size() < CAPACITY);
		current_index = used;
		data[current_index]=entry;
		used++;
	}
        
	void sequence :: remove_current(){
		assert(size() > 0);
		for(int i = current_index; i < used; i++){
			data[i] = data[i+1];
		}
		used--;
	}
        
	void sequence :: remove_front(){
		assert(size() > 0);
		for(int i = 0; i < used; i++){
			data[i] = data[i+1];
		}
		used--;
	}
	
	sequence :: size_type sequence :: size() const{
		return used;
	}


       	bool sequence :: is_item() const{
		return(used > 0 && current_index < used);
	}	
	
	sequence :: value_type sequence :: current() const{
		assert(is_item());
		return data[current_index];
	}
        	
	sequence :: value_type sequence :: operator[](int index) const{
		assert(index < used);
		return data[index];
	}
        
	double sequence :: mean() const{
		double sum,mean;
		int i;
		for(i = 0; i < used; i++){
			sum += data[i];
		}
		return (double)sum/used;
	}
        
	double sequence :: standardDeviation() const{
		double stdev = 0.0;
                int i;
                for(i = 0; i < used; i++){
			if(is_item()==true){
                		stdev +=(double)pow((double)data[i] - mean(),2);
			}
                }
		return sqrt(stdev/used);
	}
        
	sequence operator+=(sequence& lhs, sequence& rhs){
		assert((lhs.size() + rhs.size()) <= sequence::CAPACITY);
		rhs.start();
        	for(int i = 0; i < rhs.size() - 1; i++) {
        		lhs.attach(rhs.current());
            		rhs.advance();
        	}
        	return lhs;
	}

	sequence operator+(const sequence& lhs, const sequence& rhs){
                assert((lhs.size() + rhs.size()) <= sequence::CAPACITY);
                sequence tmp(lhs);
		sequence tmp2(rhs);
		tmp2.start();
		
		for(int i = 0; i < rhs.size(); i++){
			tmp.attach(tmp2.current());
			tmp2.advance();
		}

                return tmp;
        }

       	
	sequence::value_type summation(const sequence &s){
		double sum = 0.0;
		sequence temp(s);
		temp.start();
 		for(int i = 0; i < temp.size(); ++i) {
 	        	sum += temp.current();
			temp.advance();
        	}
        	return sum;
	}
}
