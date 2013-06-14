#include <iostream>

using namespace std;

void reverse(char* str, int l, int r)
{
	for(int i = l, j = r; i < j; i++, j--)
	{
		char tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
	}
}


void solution1(char* s1)
{
	int len = 0;
	while(s1[len] != '\0')
	{
		len++;
	}
	reverse(s1, 0, len-1);
	int i = 0;
	int j = 0;
	while( j < len)
	{
		j++;
		if(s1[j] == ' ' || s1[j] == '\0')
		{
			reverse(s1, i, j-1);
			i = j+1;
		}
	}
}

int main()
{
	char s1[11] = "char hello";
	cout << s1 << endl;
	cout << "--------------------" << endl;
	solution1(s1);
	cout << s1 << endl;

	return 0;
}


