#include<iostream>
#include<string.h>
using namespace std;
char* a = new char[11];
char* b = new char[11];
char op;
char eq;
char* c = new char[11];
int answer;

int trans(char* a)
{
	int ans;
	if (strcmp(a, "zero") == 0)
	{
		ans = 0;
	}
	else if (strcmp(a, "one") == 0)
	{
		ans = 1;
	}
	else if (strcmp(a, "two") == 0)
	{
		ans = 2;
	}
	else if (strcmp(a, "three") == 0)
	{
		ans = 3;
	}
	else if (strcmp(a, "four") == 0)
	{
		ans = 4;
	}
	else if (strcmp(a, "five") == 0)
	{
		ans = 5;
	}
	else if (strcmp(a, "six") == 0)
	{
		ans = 6;
	}
	else if (strcmp(a, "seven") == 0)
	{
		ans = 7;
	}
	else if (strcmp(a, "eight") == 0)
	{
		ans = 8;
	}
	else if (strcmp(a, "nine") == 0)
	{
		ans = 9;
	}
	else if (strcmp(a, "ten") == 0)
	{
		ans = 10;
	}
	else
	{
		ans = -1;
	}
	return ans;
}

bool transr(int res)
{
	int anum[11][26] = { 0, };
	int aans[26] = { 0, };

	//zero
	anum[0][25] = anum[0][4] = anum[0][17] = anum[0][14] = 1;
	//one
	anum[1][14] = anum[1][13] = anum[1][4] = 1;
	//two
	anum[2][19] = anum[2][22] = anum[2][14] = 1;
	//three
	anum[3][19] = anum[3][7] = anum[3][17] = 1;
	anum[3][4] = 2;
	//four
	anum[4][5] = anum[4][14] = anum[4][20] = anum[4][17] = 1;
	//five
	anum[5][5] = anum[5][8] = anum[5][21] = anum[5][4] = 1;
	//six
	anum[6][18] = anum[6][8] = anum[6][23] = 1;
	//seven
	anum[7][18] = anum[7][21] = anum[7][13] = 1;
	anum[7][4] = 2;
	//eight
	anum[8][4] = anum[8][8] = anum[8][6] = anum[8][7] = anum[8][19] = 1;
	//nine
	anum[9][13] = 2;
	anum[9][8] = anum[9][4] = 1;
	//ten
	anum[10][19] = anum[10][4] = anum[10][13] = 1;
	for (int i = 0; c[i] != '\0'; i++)
	{
		aans[c[i]-'a']++;
	}

	bool chk = true;
	for (int i = 0; i < 26; i++)
	{
		if (anum[res][i] != aans[i])
		{
			chk = false;
			break;
		}
	}
	return chk;
}

int calc(int ia,int ib)
{
	int res;
	switch (op)
	{
	case'+':
		res = ia + ib;
		break;
	case'-':
		res = ia - ib;
		break;
	case'*':
		res = ia * ib;
		break;
	}
	return res;
}

bool check()
{
	int ia, ib;
	bool ic = true;
	int result;
	
	ia = trans(a);
	ib = trans(b);
	result = calc(ia, ib);
	
	if (result < 0 || result>10)
	{
		return false;
	}
	ic = transr(result);
	
	return ic;
}

int main()
{
	

	int cases;
	cin >> cases;
	while (cases--)
	{
		cin >> a >> op >> b >> eq >> c;
		if (check())
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
}