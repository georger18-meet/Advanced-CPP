#include "FileHandler.h"

FileHandler::FileHandler()
{
	GetFile();
	AddToList();
}

void FileHandler::GetFile()
{
	fstream MyFile("LinkedListInputs.txt");

	newFile.open("LinkedListInputs.txt");
}

void FileHandler::AddToList()
{
	if (newFile.is_open())
	{
		string input;

		while (getline(newFile, input))
		{
			cout << input << " -> " << NumTranslate(input);
			switch (toupper(input[0]))
			{
			case 'I':
				cout << " Insert" << endl;
				nh.InsertNode(stoi(NumTranslate(input)));
				nh.SortList();
				break;
			case 'D':
				cout << " Delete" << endl;
				nh.DeleteNode(stoi(NumTranslate(input)));
				break;
			case 'P':
				cout << " Print" << endl;
				nh.DisplayList();
				break;
			case 'E':
				cout << " Empty" << endl;
				nh.EmptyList();
				break;
			//case 'S':
			//	cout << " Sort" << endl;
			//	nh.SortList();
			//	break;
			default:
				cout << " Invalid Input!" << endl;
				break;
			}
		}


		newFile.close();
	}
}

string FileHandler::NumTranslate(string input) const
{
	string tempNum;
	for (int i = 0; i < input.length(); i++)
	{

		if (isdigit(input[i]))
		{
			tempNum += int(input[i]);
		}
	}
	return tempNum;
}
