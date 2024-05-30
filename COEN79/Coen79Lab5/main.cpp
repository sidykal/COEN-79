#include <cctype>
#include <iostream>
#include <string>
#include <cstring>
#include <ctype.h>
#include <ios>
#include <iomanip>
#include <fstream>
#include "mystring.h"

using std::cin;
using std::cout;
using std::endl;
using namespace coen79_lab;

std::string boolString(bool str) {
	return (str) ? "true" : "false";
}

int main(){
	string s1;
	string s2("Hello World");
	string s3(s2);
	cout << "s1: " << s1 << endl << "s2: " << s2 << endl << "s3: " << s3 << endl;

	cout << "*** += operator tests ***" << endl;
	cout << "s1 length: " << s1.length() << endl;
	s1 += string("A");
	cout << "s1: " << s1 << endl;
	cout << "s1 length: " << s1.length() << endl;
	s1 +="B";
        cout << "s1: " << s1 << endl;
        cout << "s1 length: " << s1.length() << endl;
	s1 +='C';
        cout << "s1: " << s1 << endl;
        cout << "s1 length: " << s1.length() << endl;

	cout << "*** [] operator test ***" << endl;
	cout << "s1[0]: " << s1[0] << endl;
	cout << "s1[1]: " << s1[1] << endl;
	cout << "s1[2]: " << s1[2] << endl;

	cout << "*** = operator test ***" << endl;
	s2 = string("= Test 1 Success");
	cout << "s2: " << s2 << endl;
	s2 = string("= Test 2 Success");
        cout << "s2: " << s2 << endl;

	cout << "*** logical operator tests ***" << endl;
	string A('A');
	string B('B');
    	cout << "A == A: " << boolString(A == A) << endl;
     	cout << "A == B: " << boolString(A == B) << endl;
     	cout << "A != A: " << boolString(A != A) << endl;
     	cout << "A != B: " << boolString(A != B) << endl;
     	cout << "A > A: " << boolString(A > A) << endl;
     	cout << "A > B: " << boolString(A > B) << endl;
     	cout << "B > A: " << boolString(B > A) << endl;
     	cout << "A >= A: " << boolString(A >= A) << endl;
     	cout << "A >= B: " << boolString(A >= B) << endl;
     	cout << "B >= A: " << boolString(B >= A) << endl;
     	cout << "A < A: " << boolString(A < A) << endl;
     	cout << "A < B: " << boolString(A < B) << endl;
     	cout << "B < A: " << boolString(B < A) << endl;
     	cout << "A <= A: " << boolString(A <= A) << endl;
     	cout << "A <= B: " << boolString(A <= B) << endl;
     	cout << "B <= A: " << boolString(B <= A) << endl;
	
	cout << "*** + operator tests ***" << endl;
	cout << "A + B: " << (A + B) << endl;
    	cout << "A + C: " << (A + "C") << endl;
    	cout << "B + A: " << (B + A) << endl;
	
	s1 = "";
	cout << "*** >> operator test ***" << endl;
	cout << "Please enter a word: ";
	cin >> s1;
	cout << "You entered: " << s1 << endl;

	cout << "*** Single character constructor test ***" << endl;
	string C('C');
	cout << "C: " << C << endl;
	
	cout << "*** insert tests ***" << endl;
	s1 = "ABCD";
	cout << "s1: " << s1 << endl;
	s1.insert("-",0);
	cout << "s1: " << s1 << endl;
	s1.insert("*",3);
	cout << "s1: " << s1 << endl;
	s1.insert(".",s1.length());
	cout << "s1: " << s1 << endl;
	
		
	cout << "*** dlt tests ***" << endl;
	s1 = "1112233445555";
	cout << "s1: " << s1 << endl;
	s1.dlt(0,3);
	cout << "s1: " << s1 << endl;
	s1.dlt(2,2);
	cout << "s1: " << s1 << endl;
	s1.dlt(s1.length()-4,4);
	cout << "s1: " << s1 << endl;
	
	
	cout << "*** replace tests ***" << endl;
	s1 = "abc";
	cout << "s1: " << s1 << endl;
	s1.replace('z',0);
	cout << "s1: " << s1 << endl;
	s1.replace('y',1);
	cout << "s1: " << s1 << endl;
	s1.replace('x',2);
	cout << "s1: " << s1 << endl;
	s1 = "ABCDEFGHIJKLMNOP";
	s2 = "123";
	s1.replace(s2, 0);
	cout << "s1: " << s1 << endl;
	s1.replace(s2, 5);
	cout << "s1: " << s1 << endl;
	s1.replace(s2, s1.length() - s2.length());
	cout << "s1: " << s1 << endl;
	
	cout << "*** count tests ***" << endl;
	s1 = "ABBCCCDDDD";
	cout << "s1: " << s1 << endl;
	cout << "Num A's: " << s1.count('A') << endl;
	cout << "Num B's: " << s1.count('B') << endl;
	cout << "Num C's: " << s1.count('C') << endl;
	cout << "Num D's: " << s1.count('D') << endl;
	cout << "Num E's: " << s1.count('E') << endl;
	
	cout << "*** search tests ***" << endl;
	cout << "s1: " << s1 << endl;
	cout << "First A: " << s1.search('A') << endl;
	cout << "First B: " << s1.search('B') << endl;
	cout << "First C: " << s1.search('C') << endl;
	cout << "First D: " << s1.search('D') << endl;
	cout << "First E: " << s1.search('E') << endl;
	s1 = "ABCDEFGHIJKLMNOP";
	cout << "s1: " << s1 << endl;
	cout << "Location of \"ABC\": " << s1.search("ABC") << endl;
	cout << "Location of \"GHI\": " << s1.search("GHI") << endl;
	cout << "Location of \"NOP\": " << s1.search("NOP") << endl;
	cout << "Location of \"XYZ\": " << s1.search("XYZ") << endl;
}
