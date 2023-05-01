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
        char c1;
        char c2;

        while (getline(newFile, input))
        {
            cout << input << " -> ";
            switch (input[0])
            {
            case 'I':
                cout << "Insert" << endl;
                break;
            case 'D':
                cout << "Delete" << endl;
                break;
            case 'P':
                cout << "Print" << endl;
                break;
            case 'E':
                cout << "Empty" << endl;
                break;
            default:
                break;
            }
        }


        newFile.close();
    }
}
