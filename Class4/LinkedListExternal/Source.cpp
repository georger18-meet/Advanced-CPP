#include "FileHandler.h"

int main()
{
	cout << "Intro: The Program accepts Files of .txt format, they should be named 'LinkedListInputs.txt'." << endl;
	cout << "A File is Autocreated if there's none, just make sure to fill it out with the proper Input Format." << endl;
	cout << "(As Written in the Comment)\n------------------------------" << endl << endl;

	// You can type with such formats:
	// I1
	// I-1
	// I 1 24 5
	// i1
	// 
	// (I = 'Insert' {Follow up with a Data Number}, D = 'Delete' {Follow up with a Data Number}, P = 'Print', E = 'Empty' )
	// 
	// A Case Example:
	//	P
	//	I2
	//	I1
	//	I5
	//	I3
	//	P
	//	I3
	//	P
	//	D3
	//	I10
	//	P
	//	D3
	//	P
	//	E
	//	P
	//	I10
	//	P

	FileHandler fileHandler;

	return 0;
}
