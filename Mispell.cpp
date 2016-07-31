#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int cases, n_th;
	char str[100];
	cin >> cases;
	for (int i = 0; i < cases; i++)
	{
		cin >> n_th >> str;
		int n = strlen(str);
		for (int j = n_th; j <= n; j++)
		{
			str[j - 1] = str[j];
		}
		printf("%d %s\n", i+1, str);
	}
}
