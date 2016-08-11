#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void quantize()
{
	int n, s;
	cin >> n >> s;
	vector<int> seq(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &seq[i]);
	}
	sort(begin(seq), end(seq));
	for (int i = 0; i < n; i++)
	{
		printf("%d ", seq[i]);
	}
	cout << endl;
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