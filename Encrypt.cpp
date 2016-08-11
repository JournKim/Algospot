#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	char str[101];
	char str1[101];
	int cases, n;
	cin >> cases;
	while (cases--)
	{
		int j=0;
		cin >> str;
		n = strlen(str);
		int mid = (n + 1) / 2;
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				str1[j++] = str[i];
			}
			else
			{
				str1[mid++] = str[i];

			}
		}
		str1[n] = '\0';

		cout << str1 << endl;
	}
}