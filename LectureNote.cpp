/*
Astring 배열을 main함수에 선언하고 함수에 인자로 넘기면 에러 발생.
전역변수로 하니까 바로 됨. 뭐가문제임?

*/

#include<iostream>
using namespace std;
char Astring[500][3] = { 0, };

void swap(int j)
{
	char a0 = Astring[j][0];
	char a1 = Astring[j][1];
	Astring[j][0] = Astring[j + 1][0];
	Astring[j][1] = Astring[j + 1][1];
	Astring[j + 1][0] = a0;
	Astring[j + 1][1] = a1;
}

void sort(int n)
{
	char a0, a1;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1 ; j++)
		{
			if (Astring[j][0] > Astring[j + 1][0])
			{
				swap(j);
			}
			else if (Astring[j][0] == Astring[j + 1][0] && Astring[j][1] > Astring[j + 1][1])
			{
				swap(j);
			}
		}
	}
}

void print(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s", Astring[i]);
	}
	cout << endl;
}

int main()
{
	int cases;
	
	cin >> cases;
	char c = 1;
	int n;
	getchar();
	while (cases--)
	{
		n = 0;
		while (1)
		{
			Astring[n][0] = getchar();
			if (Astring[n][0] == '\n')
			{
				Astring[n][0] = '\0';
				break;
			}
			Astring[n][1] = getchar();
			Astring[n][2] = '\0';
			n++;
		}
		sort(n);
		
		print(n);

	}

}