#include <iostream>
#include <string>

using namespace std;


int solution1(string s)
{
	int len = s.length();
	for(int i = 0; i < len; i++)
	{
		for(int j = i+1; j < len; j++)
		{
			if(s[i] == s[j])
			{
				return 1;
			}
		}
	}
	return 0;
}

int solution2(string s)
{
	int* char_set = new int[256];
	int len = s.length();
	for(int i = 0; i < len; i++)
	{
		int val = int(s[i]);
		if(char_set[val]) return 0;
		char_set[val] = 1;
	}
	return 1;
}

int solution3(string s)
{
	int checker = 0;
	int len = s.length();
	for(int i = 0; i < len; ++i)
	{
		int val = int(s[i]);
		if(checker & (1 << val)) return 0;
		checker |= (1 << val);
	}
	return 1;
}

int main()
{
	string s = "hello world";
//	int tag = solution1(s);
	bool idx = solution3(s);
	if(idx)
	{
		cout << "Have unique character." << endl;
	} else {
		cout << "Have replicate character." << endl;
	}

	return 0;
}
