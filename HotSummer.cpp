#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int W;
		cin >> W;
		int A[9], tot = 0;
		for (int i = 0; i < 9; i++)
		{
			cin >> A[i];
		}
		for (int i = 0; i < 9; i++)
		{
			tot = tot + A[i];
		}
		
		if (W >= tot)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}