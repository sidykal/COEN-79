#include <iostream>
#include <string>
#include <ctype.h>
#include <ios>
#include <iomanip>
#include <fstream>
#include "sequence1.h"

using namespace std;
using namespace coen79_lab3;

void printSequence(sequence &seq){
	int i = 0;
	seq.start();
	for(i = 0; i < seq.size();i++){
		if(seq.is_item() == true){
			std :: cout << seq.current() << " ";
		}
		seq.advance();
	}
	//seq.start();
}

void printStats(sequence &seq){
	seq.start();
	std :: cout << "-----------------------------" << endl; 
	std :: cout << "Mean: " << seq.mean() << endl; 
	std :: cout << "StdDev: " << seq.standardDeviation() << endl;
	std :: cout << "Sum: " << summation(seq) << endl;
	std :: cout << "Contents: ";
	printSequence(seq);
	std :: cout << endl << "-----------------------------" << endl;
}

int main(){
	sequence tester1;
	tester1.insert(1);
	tester1.insert(2);
	tester1.insert(3);
	printStats(tester1);	

	sequence tester2;
	tester2.insert(2);
	tester2.insert(3);
	tester2.insert(4);
	printStats(tester2);
	
	sequence tester3 = tester1+tester2;
	printStats(tester3);
	
	tester3.advance();
	printStats(tester3);
	tester3.advance();
	printStats(tester3);
	tester3.remove_front();
	printStats(tester3);
	tester3.advance();
	printStats(tester3);
	tester3.remove_front();
	printStats(tester3);
	tester3.advance();
	printStats(tester3);
	tester3.remove_current();
	printStats(tester3);
	tester3.attach_back(14);
	printStats(tester3);
}	
