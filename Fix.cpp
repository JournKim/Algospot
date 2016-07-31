#include<iostream>
using namespace std;

int main()
{
	int a;
	int cases,n;
	cin >> cases;
	while (cases--)
	{
		int count = 0;
		cin >> n;
		
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			if (a == i + 1)
				count++;
		}
		cout << count << endl;

		
	}
}