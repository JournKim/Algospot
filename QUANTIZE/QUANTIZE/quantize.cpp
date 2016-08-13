/*
algospot.com ID : QUANTIZE

*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define INF 987654321;

int sqareError(const vector<int>& seq, int start, int k)
{
	if (k == 1)
	{
		return 0;
	}
	int sum = 0;
	double avg;
	for (int i = 0; i < k; ++i)
	{
		sum += seq[start + i];
	}
	
	avg = sum / (double)k;
	if ((int)(avg * 10) % 10 >= 5)
	{
		avg = ceil(avg);
	}
	else
		avg = floor(avg);
	sum = 0;
	for (int i = 0; i < k; i++)
	{
		sum += (int)pow(avg - seq[start + i], 2);
	}
	cout << "sqareError " << start << "~" << start + k << " : "  << sum << endl;
	return sum;
}

int calc(const vector<int>& seq, vector<vector<int>>& sqErr, int n, int S)
{
	if (sqErr[S][n] >= 0)
		return sqErr[S][n];
	int min = INF;
	int tmp;
	for (int i = 1; i < S; i++)
	{
		//tmp = sqErr[S-1][n-i] + sqareError(seq, n - i, i); 
		tmp = calc(seq,sqErr,n-i,S-1) + sqareError(seq, n - i, i);
		if (min > tmp)
			min = tmp;
	}

	printf("S = %d, n = %d\n", S, n);
	for (int i = 0; i<S;i++)
	{
		cout << sqErr[i][n-1] << " ";
	}
	cout << endl;

	return min;
}

void quantize()
{
	vector<vector<int>> sqErr(10, vector<int>(101,-1));

	int n, s;
	cin >> n >> s;
	vector<int> seq(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}
	//오름차순 정렬
	sort(begin(seq), end(seq));

	for (int i = 0; i < s; i++)
	{
		sqErr[i][i] = 0;
	}
	cout << calc(seq, sqErr, n, s) << endl;
}


int main()
{
	int c;
	cin >> c;
	while (c--)
	{
		quantize();
	}
}