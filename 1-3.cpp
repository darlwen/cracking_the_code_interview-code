#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int solution(string & str)
{
	int len = str.length();
	int idx1 = 0;
	int idx2 = len-1;
	int idx3 = idx1 + 1;
	while(idx1 < idx2)
	{
		while(idx3 <= idx2)
		{
			if(str[idx1] == str[idx3])
			{
				swap(str[idx3], str[idx2]);
				idx2--;
			} else {
				idx3++;
			}
		}
		idx1++;
		idx3 = idx1 + 1;
	}
	cout << "idx2: " << idx2 << endl;
	return idx2;
}


int main()
{
	string str = "hello world";
    int idx = solution(str);
	cout << str.length() << endl;
	cout << str << endl;
	string sub_str = str.substr(0, idx+1);
	cout << sub_str << endl;

	return 0;
}
