#include <iostream>
#include <iomanip>
using namespace std;
#define N 1000

class Turn {
public:
	int n = 2;
	int i = 1;
	int j = 1;
	int num = 1;
	int array[N][N] = {};
	int print_array(int n);
	int left_turn(int x, int y, int xx, int yy);
} ;

int Turn::print_array(int n) {
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			array[i][j] = num++;
			cout << setw(4) << array[i][j];
		}
		cout << '\n';
	}

	return 0;
}

int Turn::left_turn(int x, int y, int xx, int yy) {
	// left
	for (i = x+1; i <= xx; i++)
	{
		array[i - 1][y] = array[i][y];
	}

	// bottom
	for (i = y; i <= yy; i++)
	{
		array[xx][i] = array[xx][i + 1];
	}
	
	// right
	for (i = xx; i >= x; i--)
	{
		array[i][yy] = array[i - 1][yy];
	}

	// up
	for (i = yy; i >= y; i--)
	{
		array[x][i] = array[x][i - 1];
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << setw(4) << array[i][j];
		}
		cout << '\n';
	}

	return 0;
}

/*
int Turn::right_turn(int x, int y, int xx, int yy) {

	for (i = x; i <= xx; i++)
	{
		array[i][y] = array[i + 1][y];
	}

	for (i = y; i <= yy; i++)
	{
		array[xx][yy] = array[xx][yy + 1];
	}

	for (i = xx; i >= x; i--)
	{
		array[i][yy] = array[i - 1][yy];
	}

	for (i = yy; i >= y; i--)
	{
		array[x][i] = array[x][i - 1];
	}

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			cout << setw(4) << array[i][j];
		}
		cout << '\n';
	}

	return 0;
}
*/

int main(void)
{
	Turn a;
	int x = 1;
	int y = 1;

	cout << "n을 입력하시오(n X n) ";
	cin >> a.n;
	int xx = a.n;
	int yy = a.n;

	a.print_array(a.n);
	cout << '\n';
	cout << "왼쪽으로 회전\n";
	a.left_turn(x, y, xx, yy);
	// cout << "오른쪽으로 회전\n";
	// a.right_turn(x, y, xx, yy);

	return 0;
}