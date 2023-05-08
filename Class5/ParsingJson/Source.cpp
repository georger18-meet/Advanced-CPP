#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int c;
	FILE* fp;
	char str[10000];
	fopen_s(&fp, "item.txt", "r");
	int counter = 0;
	if (fp)
	{
		while ((c = getc(fp)) != EOF)
		{
			str[counter++] = c;
			str[counter] = 0;
			printf("%s==>%d", str, counter);
		}
		
		int i = 0;
		int level = 0;
		int array = 0;

		printf("\n\n");
		while (i < counter)
		{
			switch (str[i])
			{
			case '{':
				printf("enter level %d\n", ++level);
				break;			
			case '}':
				printf("exit level %d\n", level--);
				break;
			case '[':
				printf("enter array %d\n", ++array);
				break;
			case ']':
				printf("exit array %d\n", array--);
				break;
			default:
				break;
			}
			i++;
		}

		fclose(fp);
	}
	return 0;
}