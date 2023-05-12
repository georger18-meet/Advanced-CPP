#include "OtherMethods.h"

void OtherMethods::SetKeyword(int wordInd, string text)
{
	if (wordInd >= 0)
	{
		keywords[wordInd] = text;
	}
}

string OtherMethods::GetKeyword(int wordInd)
{
	if (wordInd >= 0)
	{
		return keywords[wordInd];
	}
}

void OtherMethods::SetType(int typeInd, char text)
{
	if (typeInd >= 0)
	{
		types[typeInd] = text;
	}
}

char OtherMethods::GetType(int typeInd)
{
	if (typeInd >= 0)
	{
		return types[typeInd];
	}
}

int OtherMethods::GetTypesLength()
{
	int len = *(&types + 1) - types;

	return len;
}

void OtherMethods::AddToData(string data)
{
	dataOutcome += data;
}

void OtherMethods::AddToData(char data)
{
	dataOutcome += data;
}

string OtherMethods::GetData()
{
	return dataOutcome;
}
