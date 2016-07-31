#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char uri[100];
	char ori[100];
	int cases;
	cin >> cases;
	while (cases--)
	{
		int len, idx;
		char c;
		cin >> uri;
		len = strlen(uri);
		idx = 0;//ori ÀÇ idx
		for (int i = 0; i < len; i++)
		{
			if (uri[i] == '%')
			{
				switch (uri[i + 2])
				{
				case '0':
					c = ' ';
					break;
				case '1':
					c = '!';
					break;
				case '4':
					c = '$';
					break;
				case '5':
					c = '%';
					break;
				case '8':
					c = '(';
					break;
				case '9':
					c = ')';
					break;
				case 'a':
					c = '*';
					break;

				}
				i += 2;
				ori[idx] = c;
			}
			else
			{
				ori[idx] = uri[i];
			}
			idx++;
		}
		ori[idx] = '\0';

		cout << ori << endl;
	}
}