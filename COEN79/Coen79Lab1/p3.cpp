#include <cstdlib>
#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;



int main(int argc, const char * argv[]){
	/*
        int i = 0;
        int count;
        int numchars = 0;
        char s[1000];
        char temp;
        char filename[50];
        cout << "Filename: ";
        cin >> filename;
	file.open
        ifstream myfile;
        while (!myfile.eof()){
                myfile.get(s[i]);
                i++;
                numchars;
                if(iswalnum(s[i])){
                        count++;
                }
                else{
                        if(count >= 10){

                                cout << s << endl;
                        }
                        count = 0;
                        s[0] = '\0';

                }
        }
	*/
	
	if(argc != 2){
		cout << "error 1";
		return 1;
	}

        int i = 0;
        int count;
        int numchars = 0;
        char s[1000];
	string temp;
        string word = "";
        
	string filename(argv[1]);
	ifstream myfile;
	myfile.open(filename);

	if(myfile.is_open()){
	}
	else{
		cout << "error 2";
		return 1;
	}

	while(myfile >> temp){
		word = "";
		for(int i = 0; i < temp.length(); i++){
			if(iswalnum(temp[i])){
				word += toupper(temp[i]);
			}
		}
		if(word.length() >= 10){
			cout << word << endl;
		}
	}
}	
