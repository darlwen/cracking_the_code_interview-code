#include<iostream>
using namespace std;

void quick_sort(string & str, int l, int r)
{
	if (l >= r)
	{
		return;
	}

	int k = l;
	int q = r;
	int p = l+1;
	while(p < q)
	{
		if(str[k] <= str[p])
		{
			swap(str[p], str[q]);
			--q;
		} else {
			++p;
		}
	}
	if(str[k] <= str[p])
	{
		swap(str[k], str[p-1]);
		quick_sort(str, l, p-2);
		quick_sort(str, p, r);
	} else {
		swap(str[k], str[p]);
		quick_sort(str, l, p-1);
		quick_sort(str, p+1, r);
	}
}




bool is_anagram(string str1, string str2)
{
	int len1 = str1.length();
	int len2 = str2.length();
	if(len1 != len2)
	{
		return false;
	}
	if(len1 == 0 || len2 == 0)
	{
		return false;
	}
	quick_sort(str1, 0, len1-1);
	quick_sort(str2, 0, len2-1);
	if (str1.compare(str2) != 0)
	{
		return false;
	} else {
		return true;
	}
}

int main()
{
	string str = "esescda";
	int len = str.length();
	cout << str << endl;
	cout << "---------------" << endl;
	quick_sort(str, 0, len-1);
	cout << str << endl;
	cout << "~~~~~~~~~~~~~~~~~" << endl;
	string str1 = "hello";
	string str2 = "ollhe";
	if (is_anagram(str1, str2))
	{
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}

