#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>

#include "OtherMethods.h"

using namespace std;

int main()
{
	int c;
	FILE* fp;
	char str[10000];
	fopen_s(&fp, "item.txt", "r");
	int counter = 0;

	OtherMethods om;

	om.SetKeyword(0, "type");
	om.SetKeyword(1, "number");
	om.SetType(0, 'i');
	om.SetType(1, 'd');


	if (fp)
	{
		// Saving the Data into a Char
		while ((c = getc(fp)) != EOF)
		{
			str[counter++] = c;
			str[counter] = 0;
			//printf("%s==>%d", str, counter);
		}
		printf(str);
		cout << endl << "----------------------------------------" << endl;


		int i = 0;
		int level = 0;
		int array = 0;

		int keyCounter1 = 0;
		int keyCounter2 = 0;
		string tempWord;
		bool lookingForKeyVal = false;

		printf("\n\n");
		while (i < counter)
		{
			// Going through Levels in Depth
			switch (str[i])
			{
			case '{':
				printf("enter level %d\n", ++level);
				lookingForKeyVal = false;
				break;
			case '}':
				printf("exit level %d\n", level--);
				lookingForKeyVal = false;
				om.AddToData("\n");
				break;
			case '[':
				printf("enter array %d\n", ++array);
				lookingForKeyVal = false;
				break;
			case ']':
				printf("exit array %d\n", array--);
				lookingForKeyVal = false;
				break;
			case ',':
				lookingForKeyVal = false;
				break;
			default:
				break;
			}


			// Checking for Matching Keywords
			if (str[i] == om.GetKeyword(0)[keyCounter1])
			{
				tempWord += str[i];
				//cout << "Found " << tempWord << endl;
				keyCounter1++;

				if (tempWord == om.GetKeyword(0))
				{
					lookingForKeyVal = true;
					cout << "Found Keyword Match!: " << om.GetKeyword(0) << endl;
				}
			}
			else if (str[i] == om.GetKeyword(1)[keyCounter2])
			{
				tempWord += str[i];
				//cout << "Found " << tempWord << endl;
				keyCounter2++;

				if (tempWord == om.GetKeyword(1))
				{
					lookingForKeyVal = true;
					cout << "Found Keyword Match!: " << om.GetKeyword(1) << endl;
				}
			}
			else
			{
				tempWord = "";
				keyCounter1 = 0;
				keyCounter2 = 0;
			}

			// Checking for Key Values
			if (lookingForKeyVal)
			{
				if (isdigit(str[i]))
				{
					om.AddToData(str[i]);
				}

				for (int t = 0; t < om.GetTypesLength(); t++)
				{
					if (str[i] == om.GetType(t))
					{
						lookingForKeyVal = false;
						om.AddToData(str[i]);
						cout << "Found Type Match!: " << om.GetType(t) << endl;
					}
				}
			}

			i++;
		}

		cout << endl << "Data Outcome:\n" << om.GetData() << endl;

		fclose(fp);
	}

	return 0;
}