#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileHandler
{

public:
	FileHandler();
	void GetFile();
	void AddToList();

private:
	fstream newFile;

	string NumTranslate(string input) const;
};
