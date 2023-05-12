#pragma once
#include <string>
using namespace std;

class OtherMethods {
public:

	void SetKeyword(int wordInd, string text);
	string GetKeyword(int wordInd);	

	void SetType(int typeInd, char text);
	char GetType(int typeInd);
	int GetTypesLength();

	void AddToData(string data);
	void AddToData(char data);
	string GetData();

private:
	
	string keywords[2];
	char types[2];

	string dataOutcome;
};