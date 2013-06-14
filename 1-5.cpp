#include <iostream>
using namespace std;

void replace(string & str, string in_str)
{
	int len1 = str.length();
	int len2 = in_str.length();
	int num = 0;
	for(int i = 0; i < len1; ++i)
	{
		if(str[i] == ' ')
		{
			++num;
		}
	}
	int len = len1 + num * (len2 - 1);
	str.resize(len);
	int p = len-1;
	int q = len1-1;
	while(p >= 0 && q >= 0)
	{
		if(str[q] == ' ')
		{
			for(int i = len2-1; i >= 0; --i)
			{
				str[p] = in_str[i];
			}
			p = p-3;
			--q;
		} else {
			str[p] = str[q];
			--p;
			--q;
		}
	}
}

int main()
{
	string str = " abc def g";
	string in_str = "%20";
	replace(str, in_str);
	cout << str << endl;
	cout << in_str << endl;

	return 0;
}




