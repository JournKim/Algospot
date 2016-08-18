#include<iostream>
#include<vector>
using namespace std;

/*
L : coverType[0]
¤¡ : coverType[1]
¤¤ : coverType[2]
¡¹ : coverType[3]
*/
const int coverType[4][3][2] = {
	{ { 0,0 },{ 1,0 },{ 0,1 } },
	{ { 0,0 },{ 0,1 },{ 1,1 } },
	{ { 0,0 },{ 1,0 },{ 1,1 } },
	{ { 0,0 },{ 1,0 },{ 1,-1 } }
};

void boardcover()
{
	int board[21][21] = { 0, };
	int h, w, count = 0;
	cin >> h >> w;
	vector<vector<char>> v(h, vector<char>(w));
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++) {
			scanf("%c", &v[i][j]);
			if (v[i][j] == '.') ++count;

		}
	}
	if (count % 3 != 0) {
		printf("0\n");
		return;
	}




}
int main()
{
	int cases;
	cin >> cases;
	while (cases--)
	{
		boardcover();
	}
}