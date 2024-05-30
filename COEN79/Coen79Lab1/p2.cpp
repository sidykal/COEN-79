#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int i,j;
	char a[] = "0123456789";
	char b[] = "9876543210";
	for(int i = 0; i < 5; i++){
		cout << setw(12 +  2*i) << a << setw(20 + 2*i) << b << endl;
	}
}
