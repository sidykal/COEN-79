// FILE: mystring.h
// CLASS PROVIDED: string
//
//  COEN 79
//  --- Siddharth Kalidindi, SCU, CSEN, 2/15/24 ---
//
//
//
// CONSTRUCTOR for the string class:
//   string(const char str[ ] = "") -- default argument is the empty string.
//     Precondition: str is an ordinary null-terminated string.
//     Postcondition: The string contains the sequence of chars from str.
//
//   string(char c)
//     Postcondition: The string contains c and then the null character.
//
//   string(const string& source) -- Copy Constructor.
//     Postcondition: The string becomes a copy of the source string.
//
// MODIFICATION MEMBER FUNCTIONS for the string class:
//   void operator +=(const string& addend)
//     Postcondition: addend has been catenated to the end of the string.
//
//   void operator +=(const char addend[ ])
//     Precondition: addend is an ordinary null-terminated string.
//     Postcondition: addend has been catenated to the end of the string.
//
//   void operator +=(char addend)
//     Postcondition: The single character addend has been catenated to the
//     end of the string.
//
//   void reserve(size_t n)
//     Postcondition: All functions will now work efficiently (without
//     allocating new memory) until n characters are in the string.
//
//   void insert(const string& source, unsigned int position)
//     Precondtion: position <= length()
//     Postcondition: The source string is inserted into this string before
//     the character at the given index.
//
//   void dlt(unsigned int position, unsigned int num)
//     Precondition: (position + num) <= length( ).
//     Postcondition: num characters are deleted from the sequence, starting
//     at index position.
//
//   void replace(char c, unsigned int position)
//     Precondition: position < length()
//     Postcondtion: the character at the given position in the string is
//     replaced with c.
//
//   void replace(const string& source, unsigned int position)
//     Precondition: (position + source.length()) <= length()
//     Postcondtion: the characters in this string starting at position are
//     replaced with those in the source srting.
//
// CONSTANT MEMBER FUNCTIONS for the string class:
//   size_t length( ) const
//     Postcondition: The return value is the number of characters in the
//     string.
//
//   char operator [ ](size_t position) const
//     Precondition: position < length( ).
//     Postcondition: The value returned is the character at the specified
//     position of the string. A string's positions start from 0 at the start
//     of the sequence and go up to length( )-1 at the right end.
//
//   int search(char c) const
//     Postcondition: The location of the first occurence of the character c
//     within this string is returned. If the string does not contain c, -1 is
//     is returned.
//
//   int search(const string& substring) const
//     Postcondition: Returns the index of the start of the first instance of
//     the given substring inside of this string. If the substring is not found,
//     this function returns -1.
//
//   unsigned int cout(char c) const
//     Postcondition: The count of the occurence of the character c within this
//     string is returned.
//
// NON-MEMBER FUNCTIONS for the string class:
//   string operator +(const string& s1, const string& s2)
//     Postcondition: The string returned is the catenation of s1 and s2.
//
//   istream& operator >>(istream& ins, string& target)
//     Postcondition: A string has been read from the istream ins, and the
//     istream ins is then returned by the function. The reading operation
//     skips white space (i.e., blanks, newlines, tabs) at the start of ins.
//     Then the string is read up to the next white space or the end of the
//     file. The white space character that terminates the string has not
//     been read.
//
//   ostream& operator <<(ostream& outs, const string& source)
//     Postcondition: The sequence of characters in source has been written
//     to outs. The return value is the ostream outs.
//
//  VALUE SEMANTICS for the string class:
//    Assignments and the copy constructor may be used with string objects.
//
//  TOTAL ORDER SEMANTICS for the string class:
//    The six comparison operators (==, !=, >=, <=, >, and <) are implemented
//    for the string class, forming a total order semantics, using the usual
//    lexicographic order on strings.
//
// DYNAMIC MEMORY usage by the string class:
//   If there is insufficient dynamic memory then the following functions call
//   new_handler: The constructors, resize, operator +=, operator +, and the
//   assignment operator.


#include <cstdlib>  // Provides size_t
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>
#include <cmath>
#include <climits>
#include <stdio.h>
#include "mystring.h"

using std::cin;
using std::cout;
using std::endl;
using std::copy;
using namespace coen79_lab;
//using namespace std;

namespace coen79_lab
{
	string :: string(const char str[ ]){
		allocated = 0;
		characters = NULL;
		current_length = strlen(str);
        	reserve(current_length + 1);
		characters[0] = '\0';
	        strncpy(characters, str, allocated);
	}

        string :: string(char c){
		characters = NULL;
		allocated = 0;
		current_length = 1;
	        reserve(2);
        	characters[0] = c;
		characters[1] = '\0';
	}

        string :: string(const string& source){
		characters = NULL;
		allocated = 0;
       		current_length = source.length();
       		reserve(current_length + 1);
	        strncpy(characters, source.characters, allocated);
	}

        string :: ~string( ){
		delete [] characters;
		characters = NULL;
		current_length = 0;
		allocated = 0;
	}

        void string :: operator +=(const string& addend){
		reserve(current_length + addend.length() + 1);
		strncat(characters,addend.characters,allocated-current_length);
		current_length+=addend.length();
	}
	
        void string :: operator +=(const char addend[ ]){
		reserve(current_length + strlen(addend) + 1);
		strncat(characters,addend,strlen(addend));
		current_length+=strlen(addend);
	}

        void string :: operator +=(char addend){
		reserve(current_length + 2);
		characters[current_length] = addend;
		current_length++;
		characters[current_length] = '\0';
	}

        void string :: reserve(size_t n){
		if(n==allocated){
			return;
		}
		else if(n < current_length+1){
			n = current_length +1;
		}
		else{
			char* newChars = new char[n];
			if(characters != NULL){
				strncpy(newChars, characters, n);
				delete [] characters;
			}
			allocated = n;
			characters = newChars;
			return;
		}
	}

        string& string :: operator =(const string& source){
		if(this == &source) {
            		return *this;
        	}
        	current_length = source.current_length;
        	reserve(source.allocated);
        	strncpy(characters,source.characters, source.current_length+1);
        	return *this;
	}

        void string :: insert(const string& source, unsigned int position){
		assert(position <=length());
		int newLen =  source.current_length + current_length;
		reserve(newLen);
		for(int i = length(); i!= 0 && i >= position; i--){
			characters[i] = characters[i-1];
		}
		for(int j = 0; j < source.length(); j++){
			characters[j+position] = source.characters[j];
		}
		current_length = newLen;
	}

        void string :: dlt(unsigned int position, unsigned int num){
		assert(position + num <= current_length);
        	int i,j;
        	j = num + position;
        	for(i = position; i <= length()-num; i++) {
            		characters[i] = characters[i+num];
        	}
        	current_length = current_length - num;
	}

        void string :: replace(char c, unsigned int position){
		assert(position <= current_length);
        	characters[position] = c;
	}
        
	void string :: replace(const string& source, unsigned int position){
		assert((position + source.current_length) <= length());
        	for(int i = 0; i < source.current_length; i++){
            		characters[position + i] = source[i];
        	} 
	}

        char string :: operator [ ](size_t position) const{
		return characters[position];
	}

        int string :: search(char c) const{
        	for(int i = 0; i < length(); i++){
            		if (characters[i] == c){
                		return i;
			}
        	}
        	return -1;  				
	}
	
        int string :: search(const string& substring) const{
        	char* temp = strstr(characters, substring.characters);
        	if(temp != NULL) {                                    
            		return temp[0] - characters[0];               
        	}
		return -1;
	}

        unsigned int string :: count(char c) const{
		int i = 0;
		int count = 0;
        	while (i < current_length) {
            		if (characters[i] == c) {
                		count++;
            		}
            		i++;
        	}
        	return count;
	}
	
        std::ostream& operator <<(std::ostream& outs, const string& source){
		outs << source.characters;
		return outs;
	}

        bool operator ==(const string& s1, const string& s2){
		return (strcmp(s1.characters, s2.characters) == 0);
	}
	
        bool operator !=(const string& s1, const string& s2){
		return (strcmp(s1.characters, s2.characters) != 0);
	}

        bool operator > (const string& s1, const string& s2){
		return (strcmp(s1.characters, s2.characters) > 0);
	}
	
        bool operator < (const string& s1, const string& s2){
		return (strcmp(s1.characters, s2.characters) < 0);		
	}
	
        bool operator >=(const string& s1, const string& s2){
		return ((s1 > s2) || (s1 == s2));
	}

        bool operator <=(const string& s1, const string& s2){
		return ((s1 < s2) || (s1 == s2));
	}

    	string operator +(const string& s1, const string& s2){
		string temp(s1);
                temp += s2;
                return temp;
	}
	
    	string operator +(const string& s1, const char addend[ ]){
		string temp(s1);
        	temp += addend;
		return temp;
	}
	
    	std::istream& operator >> (std::istream& ins, string& target){
		char temp;
		while (ins && isspace(ins.peek())){
            		ins.ignore();
        	}
        	while (!ins.eof() && !isspace(ins.peek())){
            		ins >> temp;
            		target += temp;
        	}
        	cout << target << endl;
        	return ins;
    	}			
}
