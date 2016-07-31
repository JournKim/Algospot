#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
bool bitmask[1000000] = { 0 };
using namespace std;

////// 70, 836, 4030, 5830, 7192, 7912, 9272, 10430, 10570, 10792, 10990, 11410, 11690, 12110, 12530, 12670, 13370, 13510, 13790, 13930, 14770, 15610, 15890, 16030, 16310, 16730, 16870, 17272, 17570, 17990, 18410, 18830, 18970, 19390, 19670

bool isWierd(int num)
{
	//vector<int> divisors;
	int divisors[100000];
	int idx = 0;

	for (int i = 1; i*i <= num; i++)
	{
		if (num%i == 0)
		{
			divisors[idx++] = i;
			if (num / i != i)
			{
				divisors[idx++] = num / i;
			}
		}
	}
	sort(begin(divisors), &divisors[idx]);
	
	//if sum of divisors not greater than num, not wierd.
	if (accumulate(begin(divisors), &divisors[idx - 1], 0) <= num)
		return false;

	bitmask[0] = true;
	for (int i = 0; i < idx - 1; i++)
	{
		for (int j = num - divisors[i]; j >= 0; j--)
		{
			if (bitmask[j])
			{
				if (j + bitmask[i] <= num)
				{
					bitmask[j + divisors[i]] = true;
					if (j + divisors[i] == num)
						return false;
				}
			}
		}
	}

	
	//cout << divisors[idx - 1] << endl;
	return true;
}
/*
bool weird(int n)
{
	vector divisors;
	divisors.push_back(1);
	for (int i = 2; i*i <= n; ++i)
	{
		if (n % i == 0)
		{
			divisors.push_back(i);
			if (n / i != i)
				divisors.push_back(n / i);
		}
	}
	if (accumulate(divisors.begin(), divisors.end(), 0) <= n) return false;
	memset(bitmask, 0, sizeof(bitmask);
	bitmask[0] = true;
	for (int i = 0; i < divisors.size(); ++i)
	{
		for (int j = n - divisors[i]; j >= 0; --j) if (bitmask[j])
			if (j + divisors[i] <= n)
			{
				bitmask[j + divisors[i]] = true;
				if (j + divisors[i] == n)
					return false;
			}
	}
	return true;
}
*/
int main()
{
	int cases;
	cin >> cases;
	while (cases--)
	{
		int num;
		cin >> num;
		if (isWierd(num))
		{
			cout << "wierd" << endl;
		}
		else
		{
			cout << "not wierd" << endl;
		}
	}
}