#include<iostream>
using namespace std;

unsigned int reverse(unsigned int input)
{
	unsigned int a, b, c, d;
	a = input % 0x100;
	input = input >> 8;
	b = input % 0x100;
	input = input >> 8;
	c = input % 0x100;
	input = input >> 8;
	d = a;
	d <<= 8;
	d += b;
	d <<= 8;
	d += c;
	d <<= 8;
	d += input;
	return d;

}

int main()
{
	int cases;
	unsigned int input;
	cin >> cases;
	while (cases--)
	{
		cin >> input;
		cout << reverse(input) << endl;
	}
}