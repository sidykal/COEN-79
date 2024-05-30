#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int main(){
	char s[100];
	int i,alpha,non,counter;

	cin.get( s, 100);
	counter=strlen(s);
	for(i = 0; i < counter; i++){
		if(s[i] == ' '|| s[i] == '\0'){
		}
		else if(iswalnum(s[i]) != 0){
			alpha++;
		}
		else{
			non++;
		}
	}

	cout << "Alphanumeric : " << alpha << endl;
	cout << "Non-Alphanumeric : " << non << endl;
}
