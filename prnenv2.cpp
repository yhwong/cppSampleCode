//prnenv2.cpp

#include <cstring>
#include <iostream>
using namespace std;
#define MAX 50

int main( int argc, char* argv[], char* env[]){
	char searchStr[MAX + 1];
	char envSubStr[MAX + 1];	
	int key = -1;
	int i;
	int searchStrLen;
	char* envContent = NULL;

	if (argc == 2){	
		//make a copy of first argument passed and append an = sign
		strcpy (searchStr, argv[1]);
		strcat (searchStr, "=");
		
		searchStrLen = strlen (searchStr);
		searchStr [searchStrLen] = '\0';
		//binary search
		for (i = 0; env[i] && key == -1; i++){
			strncpy (envSubStr, env[i],searchStrLen + 1);
			envSubStr[searchStrLen] = '\0';
			if ( strcmp (envSubStr, searchStr) == 0){			
				key = i;			
			}		
		}	
	}
	
	if (key != -1){
		envContent = env[key] + searchStrLen;
		cout << envContent << endl;
	}
	else {
		cout << "Not found" << endl;	
	}	
}
