#include<iostream>
using namespace std;

int main()
{
	int cases;
	cin >> cases;
	int x1, x2, x3, x4, y1, y2, y3, y4;
	int xa, ya, xb, yb;
	while (cases--)
	{
		cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		xa = x2 - x1;
		ya = y2 - y1;
		xb = x3 - x1;
		yb = y3 - y1;
		if (xa*xb + ya*yb == 0) // ����a�� ���� b�� ���հ� 90�� (���� = 0)
		{
			x4 = x3 + xa;
			y4 = y3 + ya;
		}
		else if(xa*(x3-x2) + ya*(y3-y2) == 0)// ����a�� ����p2p3�� ���հ� 90
		{
			x4 = x3 - xa;
			y4 = y3 - ya;
		}
		else
		{
			x4 = x2 - xb;
			y4 = y2 - yb;
		}
		printf("%d %d\n", x4, y4);
	}
}