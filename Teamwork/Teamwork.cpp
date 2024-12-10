#include <iostream>

using std::cout; // cout will be the same as std::cout
using std::endl; // endl will be the same as std::endl
using std::cin; // cin will be the same as std::cin

const unsigned int maxChars = 20; //constant to define the max size of the password

extern "C" bool IsValidAssembly(int a, int b, int c);

void CheckPass() 
{
	char password[maxChars] = "43WscadOB";

	// Create the strings 
	char input1[maxChars];
	char input2[maxChars];

	// Initialize the first to the input of the user 
	cout << "Input the password: "; cin >> input1;

	// Check if the input is equal to the password
	int result;
	result = strcmp(password, input1);

	if (result == 0)
		cout << "Valid access" << endl;
	else
	{
		cout << "Stop there!" << endl;
		exit(0);
	}

	// Initialize the second to the input of the user 
	cout << "Give me another string: "; cin >> input2;

	// Check its length is at least 7 
	if (strlen(input2) < 7 && !(input2[0] == input1[6]))
	{
		cout << "Access denied";
		exit(0);
	}
}

void CheckAcessBits()
{
	//First part 
	unsigned int input1;
	unsigned int input2;

	cout << "Input1 the first integer password: ";
	cin >> input1;

	cout << "Input2 the second integer password: ";
	cin >> input2;

	int bit10 = (input1 & 0x00000400) >> 10;
	int bit11 = (input2 & 0x00000800) >> 11;

	if (bit10 != bit11) 
	{
		cout << "You're not allowed here" << endl;
		exit(0);
	}

	//Second part 
	int the20most = input1 & 0xfffff000;
	int the12least = input2 & 0x00000fff;
	int the20mostAnd12least = the20most | the12least;

	if (the20mostAnd12least < 17149) 
	{
		cout << "Intruder detected" << endl;
		exit(0);
	}

	//Third part
	int between2and4 = (input2 & 0x0000001C) >> 2;

	if (between2and4 != 2) {
		cout << "Bad luck" << endl;
		exit(0);
	}
}

void AsmAccess()
{
	int input1;
	int input2;
	int input3;

	cout << "Input1 a 32-bit integer: "; cin >> input1;
	
	cout << "Input2 a 32-bit integer: "; cin >> input2;

	cout << "Input3 a 32-bit integer: "; cin >> input3;

	int result = IsValidAssembly(input1, input2, input3);

	if (result == 0) {
		cout << "Bad luck" << endl;
		exit(-1);
	}
}

void CheckInlineAssemblyAccess()
{
	unsigned int integer;
	cout << "Give me a 32-bit integer: "; cin >> integer; cout << endl;

	int integerSuperior = (integer & 0xFFFF0000) >> 16;
	int integerInferior = integer & 0x0000FFFF;
	int solution = 0;

	__asm {
		xor ecx, ecx
		mov eax, integerSuperior;	 eax = integerSuperior
		mov ebx, integerInferior;	 bx = integerInferior
		cmp eax, ebx;				 we compae if they are equal
		jne consequent;				 different
		jmp end;					 if they are equal finish
		consequent :
		inc ecx;					 we increment the value by one in case they are different
			mov solution, ecx;	     store that value on solution
		end :
	}

	if (solution > 0)
	{
		cout << "Something went wrong";
		exit(0);
	}

}

void exit()
{
	cout << "Something went wrong";
	exit(-1);
}

int main()
{
	CheckPass();
	CheckAcessBits();
	AsmAccess();
	CheckInlineAssemblyAccess();
	cout << "Correct" << endl;
	return 0;
}

