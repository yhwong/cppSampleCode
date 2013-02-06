// sub.cpp 
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <iostream>

using namespace std;

bool validateInt (const char* value){
	bool valid = true;
	int i;
	int len = strlen(value);
	
	if (isdigit(value[0]) || value[0] == '-' && len > 1){
		for (i =  1; i < len && valid; i++){
			if (value[i] < '0' || value[i] > '9'){
				valid = false;
			}
		}	
	}
	else {
		valid = false;
	}
	return valid;
}

int main(int argc, char* argv[])
{
	int num1;
	int num2;
	bool valid = false;

	if (argc == 3){	
		valid = validateInt(argv[1]) && validateInt(argv[2]);
	}

	if (valid){
		num1 = atoi(argv[1]);
		num2 = atoi(argv[2]);
		cout << "The difference is " << num1 - num2 << endl;
	}
	else {
		cout << "Error: invalid input" << endl;
	}
	return 0;
}
