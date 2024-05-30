// Siddharth Kalidindi | SCU | CSEN | 2/29/24
#include <iostream>
#include "deque.h"
using namespace coen79_lab8;
using namespace std;

int main() {
    
	int test = 0;
	cout << "Test number: " << ++test << endl;
	cout << "Testing constructor...!" << endl;
	coen79_lab8::deque<int> myDeque1;
	cout << "Done!" << endl << endl;
    
   
	cout << "Test number: " << ++test << endl;
	cout << "Testing push_back() and back()...!" << endl;
	for (int i = 0; i < 100; i++){
       		myDeque1.push_front(i);
        	cout << myDeque1.front() << " ";
    	}
    	cout << endl << "Done!" << endl << endl;
    
    
    	cout << "Test number: " << ++test << endl;
    	cout << "Testing push_front() and front()...!" << endl;
    	for (int i = 0; i < 100; i++){
    	    myDeque1.push_back(i);
    	    cout << myDeque1.back() << " ";
    	}
    	cout << endl << "Done!" << endl;

    
    	cout << "Test number: " << ++test << endl;
    	cout << "Testing iterator...!" << endl;
    	for (deque<int>::iterator it = myDeque1.begin(); it != myDeque1.end(); it++){
        	cout << *it << " ";
    	}
    	cout << endl << "Done!" << endl << endl;

    
    	cout << "Test number: " << ++test << endl;
    	cout << "Testing pop_front()...!" << endl;
    	for (int i = 0; i < 100; i++){
        	myDeque1.pop_front();
    	}	
   	cout << endl << "Front is: " << myDeque1.front();
    	cout << endl << "Back is: " << myDeque1.back();
    	cout << endl << "Done!" << endl << endl;
    
    
    	cout << "Test number: " << ++test << endl;
    	cout << "Testing pop_back()...!" << endl;
    	for (int i = 0; i < 10; i++){
        	myDeque1.pop_back();
    	}
    	cout << endl << "Front is: " << myDeque1.front();
    	cout << endl << "Back is: " << myDeque1.back();
    	cout << endl << "Done!" << endl << endl;

    
    	cout << "Test number: " << ++test << endl;
    	cout << "Testing iterator...!" << endl;
    	for (deque<int>::iterator it = myDeque1.begin(); it != myDeque1.end(); it++){
        	cout << *it << " ";
	}
    	cout << endl << "Done!" << endl << endl;

    
    	cout << "Test number: " << ++test << endl;
    	cout << "Testing assignment operator...!" << endl;
    	coen79_lab8::deque<int> myDeque2;
    	myDeque2.push_front(3);
    	myDeque2.push_front(2);
    	myDeque2.push_front(1);
    	myDeque2.push_back(4);
    	myDeque2.push_back(5);
    	myDeque2.push_back(6);
    	coen79_lab8::deque<int> myDeque3;
    	myDeque3 = myDeque2;
    	for (deque<int>::iterator it = myDeque3.begin(); it != myDeque3.end(); it++){
        	cout << *it << " ";
	}
    	cout << endl << "Done!" << endl << endl;
    
    
    	cout << "Test number: " << ++test << endl;
    	cout << "Testing copy constructor...!" << endl;
    	coen79_lab8::deque<int> myDeque4(myDeque3);
    	for (deque<int>::iterator it = myDeque4.begin(); it != myDeque4.end(); it++){
        	cout << *it << " ";
	}
    	cout << endl << "Done!" << endl << endl;


    	cout << "Test number: " << ++test << endl;
    	cout << "Testing iterator...!" << endl;
    	deque<int>::iterator it_start = myDeque4.begin();
    	deque<int>::iterator it_end = myDeque4.end();
    	deque<int>::iterator it2 = it_start;
    	while(it2 != it_end){
        	*it2 = 950;
        	++it2;
    	}
    	it2 = it_start;
    
    	while(it2 != it_end){
       		cout << *it2 << " ";
        	it2++;
    	}
    	cout << endl << "Done!" << endl;
}
