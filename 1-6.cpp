#include <iostream>

using namespace std;
const int len = 4;

void rotation(int matrix[][len])
{
	int iter = len/2;
	for(int loop = 0; loop < iter; ++loop)
	{
		for(int j = loop; j < len-loop-1; ++j)
		{
			int k = 1;
			int x = loop;
			int y = j;
			int tmp = matrix[x][y];
			while(k < 4/(loop+1))
			{
				cout << "x: " << x << "  y: " << y << endl;
				matrix[x][y] = matrix[y][len-x-1];
				int tmp_x = x;
				x = y;
				y = len-tmp_x-1;
				++k;
			}
			matrix[x][y] = tmp;
		}
	}
}

int main()
{
	int matrix[][len] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

	for(int i = 0; i < len; ++i)
	{
		for(int j = 0; j < len; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << "~~~~~~~~~~~~~~~~~~~~" << endl;
	rotation(matrix);
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	for(int i = 0; i < len; ++i)
	{
		for(int j = 0; j < len; ++j)
		{
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
