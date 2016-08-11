/*
algospot.com ID : PI
Code By JournKim
*/

#include<iostream>
#include<string>
using namespace std;

int difficulty(string str)
{
	int a[5];
	int len = str.length();
	bool chk; // 수들의 차가 일정한지 확인.
	int d=0;
	for (int i = 0; i < len-1; i++)
	{
		a[i] = str.at(i) - str.at(i + 1);
	}
	
	d = a[0];
	chk = true;
	for (int i = 0; i < len - 1; i++)
	{
		if (d != a[i])
		{
			chk = false;
			break;
		}
	}
	if (chk) //수들의 차가 일정
	{
		if (d == 0) // 난이도 1.
		{
			return 1;
		}
		if (d == 1 || d == -1)
		{
			return 2;
		}
		else
		{
			return 5;
		}
	}
	else
	{	
		//두 숫자가 번갈아 나오거나 노규칙.
		for (int i = 1; i < len - 1; i++)
		{
			if (d == -a[i])
			{
				d = a[i];
			}
			else
			{
				chk = true;
				break;
			}
		}
		if (chk)
		{
			return 10;
		}
		else
			return 4;
	}
	
	
}

int calc(int i, int* arr, const string& pi)
{
	int ret;
	int n3, n4, n5;
	n3 = arr[i - 3] + difficulty(pi.substr(i - 3, 3));
	n4 = arr[i - 4] + difficulty(pi.substr(i - 4, 4));
	n5 = arr[i - 5] + difficulty(pi.substr(i - 5, 5));

	ret = n3;
	if (ret > n4)
		ret = n4;
	if (ret > n5)
		ret = n5;
	return ret;
}

void pi()
{
	int* arr;
	string pi;
	cin >> pi;
	arr = new int[pi.length()+2];
	
	arr[3] = difficulty(pi.substr(0, 3));
	arr[4] = difficulty(pi.substr(0, 4));
	arr[5] = difficulty(pi.substr(0, 5));
	arr[6] = arr[3] + difficulty(pi.substr(3, 3));
	arr[7] = arr[3] + difficulty(pi.substr(3, 4));
	int tmp = arr[4] + difficulty(pi.substr(4, 3));
	if (arr[7] > tmp)
		arr[7] = tmp;
	//printf("%d %d %d", arr[3], arr[4], arr[5]);


	for (int i = 8; i <= pi.length(); i++)
	{
		arr[i] = calc(i, arr, pi);
	}
	cout << arr[pi.length()] << endl;
}


int main()
{
	int cases;
	cin >> cases;
	while (cases--)
	{
		pi();
	}
}