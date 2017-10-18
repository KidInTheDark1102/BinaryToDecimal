// BinaryToDecimal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "StackADT.h"
#include "arrayStackType.h"
#include "string"
#include "BinaryToDecimal.h"

using namespace std;


int main()
{
	arrayStackType<int> stack;
	string binaryNumber;
	int decimalNumber = 0;
	int count = 0;
	//Enter binary number as a string
	cout << "Enter the binary number:";
	cin >> binaryNumber;

	//call method to convert the string of binary number to ints and push into stack
	extractStringToStack(binaryNumber, stack);

	//use stack to calculate to decimal number
	while (!stack.isEmptyStack()) {
		decimalNumber += stack.top()*pow(2, count++);
		stack.pop();
	}

	cout << "Decimal Number: " <<decimalNumber<< endl;
	system("PAUSE");


}


//recursive function to convert string to ints to the stack
void extractStringToStack(string binaryNumer, arrayStackType<int>& stack) {
	//base case: stop when there is no more character insde the string
	if (binaryNumer.length() == 0)
		return;

	stack.push(binaryNumer.at(0)-48);
	extractStringToStack(binaryNumer.substr(1), stack);
}

