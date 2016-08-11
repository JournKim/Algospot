#include<iostream>
#include<vector>
using namespace std;



int isFriends(const vector < vector<int>>& v, bool* taken) {
	int next = -1;
	for (int i = 0; i < v.size(); i++)
	{
		if (!taken[i]) {
			next = i;
			break;
		}
	}
	if (next == -1) // ¸ðµÎ Â¦Áö¾îÁü.
		return 1;
	int ret = 0;
	for (int pWith = next + 1; pWith < v.size(); ++pWith)
	{
		if (!taken[pWith] && v[next][pWith] == 1)
		{
			taken[next] = taken[pWith] = true;
			ret += isFriends(v, taken);
			taken[next] = taken[pWith] = false;
		}
	}

	return ret;
	
	
}

void friends()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<vector<int>> fr;
	fr.assign(n, vector<int>(n, 0));
	int a, b;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		fr[a][b] = 1;
		fr[b][a] = 1;
	}
	bool taken[10] = { 0, };
	int ret = 0;
	printf("%d\n",isFriends(fr, taken));
}

int main()
{
	int cases;
	scanf("%d", &cases);

	while (cases--)
	{
		friends();
	}
}
	