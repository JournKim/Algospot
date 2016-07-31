/*
strcpy, strncpy 사용시 에러 발생. 왜그런지 모르겠음.

*/


#include<iostream>
#include<string.h>
using namespace std;

void cpy(char* dest, char* from)
{
	int n = strlen(from);
	for (int i = 0; i <= n; i++)
	{
		dest[i] = from[i];
	}
}

int main()
{
	char kg[] = "kg";
	char lb[] = "lb";
	char l[] = "l";
	char g[] = "g";

	double f;
	char c[10];
	int cases;
	cin >> cases;
	//cout.precision(4);

	for(int i=0; i<cases;i++)
	{
		cin >> f >> c;
		/*
		1 kg -> 2.2046 lb
		1 lb -> 0.4536 kg
		1 l -> 0.2642 g
		1 g -> 3.7854 l
		*/
		if (strcmp(c, kg) == 0)
		{
			f *= 2.2046;
			cpy(c, lb);
		}
		else if(strcmp(c, lb) == 0)
		{
			f *= 0.4536;
			cpy(c, kg);
		}
		else if (strcmp(c, l) == 0)
		{
			f *= 0.2642;
			cpy(c, g);
		}
		else if(strcmp(c, g) == 0)
		{
			f *= 3.7854;
			cpy(c, l);
		}

		printf("%d %.4f %s\n", i + 1, f, c);
	}
}