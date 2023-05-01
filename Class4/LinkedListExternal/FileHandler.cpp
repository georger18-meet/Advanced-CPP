#include "FileHandler.h"

FileHandler::FileHandler()
{
	GetFile();
	AddToList();
}

void FileHandler::GetFile()
{
    newFile.open("LinkedListCMD.txt");
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
            cout << input << endl;
            switch (input[0])
            {
            case 'I':
                cout << "its an EYE" << endl;
                break;
            case 'D':

                break;
            case 'P':

                break;
            case 'E':

                break;
            default:
                break;
            }
        }


        newFile.close();
    }
}
