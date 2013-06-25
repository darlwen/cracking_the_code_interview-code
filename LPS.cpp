/**
 * This file includes four methods to find the longest palindrome substring of a string.
 **/

#include <iostream>
#include <string>
using namespace std;


/**
 * 1. dynamic programming:
 * dp[][] store matching info, s is the string to be delt with
 * if s[i] == s[j] :
 *   dp[i][j] = dp[i+1][j-1]
 * else:
 *   dp[i][j] = false
 * base condition:
 * dp[i][i] = true;
 * time: 0(n^2); space: 0(n^2)
 **/


string LPS_dp(string s) {
	int len = s.length();

	bool** dp = new bool* [len];
	for(int i = 0; i < len; i++)
		dp[i] = new bool[len];
	for(int i = 0; i < len; i++)
		for(int j = 0; j < len; j++)
			dp[i][j] = false;

	int maxLen = 0;
	int longestBegin = 0;

	for(int i = 0; i < len; i++)
	{
		dp[i][i] = true;
	}

	for(int i = 0; i < len-1; i++)
	{
		if(s[i] == s[i+1])
		{
			dp[i][i+1] = true;
			longestBegin = i;
			maxLen = 2;
		}
		else
			dp[i][i+1] = false;
	}

	for(int n = 3; n <= len; n++)
	{
		for(int i = 0; i < len-n+1; i++)
		{
			int j = i+n-1;
			if(s[i] == s[j] && dp[i+1][j-1])
			{
				dp[i][j] = true;
				longestBegin = i;
				maxLen = n;
			}
		}
	}

	return s.substr(longestBegin, maxLen);
}

/**
 * time: O(n^2), space: O(1)
 * it starts at a point i, and then expends to the two sides(<--, -->)
 * since the length of string can be odd or even, so the expendation can be <--i--> or <--i, i+1-->
 **/

string expandPosition(string s, int l, int r)
{
	int len = s.length();
	while(l >= 0 && r < len && s[l] == s[r])
	{
		l--;
		r++;
	}
	return s.substr(l+1, r-l-1);
}

string expand(string s)
{
	int len = s.length();
	string longest = s.substr(0,1);

	// <----i---->
	for(int i = 0; i < len; i++)
	{
		string str = expandPosition(s, i, i);
		if(longest.length() < str.length())
			longest = str;
	}

	// <---i, i+1--->
	for(int i = 0; i < len-1; i++)
	{
		string str = expandPosition(s, i, i+1);
		if(longest.length() < str.length())
			longest = str;
	}

	return longest;
}

/**
 * use longest common substring to get longest palindrome substring
 * given string s, reverse it to get s'
 * assume that the length of s' is len, based on postfix, split it to len substring
 * match each substring to s, and find the longest prefix
 **/
void preprocess(int *p, string s)
{ 
	int m = s.length();
	int k = -1;
	p[0] = -1;
	for(int i = 1; i < m; i++)
	{
		while(k > -1 && s[k+1] != s[i])
			k = p[k];
		if(s[k+1] == s[i])
			k = k+1;
		p[i] = k;
	}
}

string reverse(const string s)
{
	string str;
	int len = s.length();
	for(int i = 0; i < len; i++)
	{
		str = s[i] + str;
	}
	return str;
}

string prefixStr(string s, string subStr)
{
	int n = s.length();
	int m = subStr.length();
	int *p = new int[m];
	preprocess(p, subStr);
	int ll = 0;
	int k = -1;
	for(int i = 0; i < n; i++)
	{
		while(k > -1 && subStr[k+1]!=s[i])
			k = p[k];
		if(subStr[k+1] == s[i])
		{
			k = k+1;
		}
		if(ll < k)
		{
			ll = k;
		}
		if(k == m)
			k = p[k];
	}
	delete [] p;
	return subStr.substr(0,ll+1);
}


string LPS_kmp(string s)
{
	int n = s.length();
	int startId = 0;
	int maxLen = 0;
	string longestStr = s.substr(0,1);
	
	string rs = reverse(s);
	for(int i = 0; i < n; i++)
	{
		if(longestStr.length() > n-i)
			break;
		string subStr = rs.substr(i, n-i);
		string preStr = prefixStr(s, subStr);
		if(longestStr.length() < preStr.length())
			longestStr = preStr;
	}
	return longestStr;
}

/**
 * Manacher's algorithm
 * time:O(n),space:O(n)
 * I think its idea is a little similar to kmp
 **/

string translateStr(string s)
{
	string str = "^#";
	int len = s.length();
	for(int i = 0; i < len; i++)
	{
		str = str + s[i] + '#';
	}
	str = str + '$';
	return str;
}

string Manacher(string s)
{
	string str = translateStr(s);
	int len = str.length();
	int* p = new int[len];
	int c = 0;
	int r = 0;
	int i_missor;

	for(int i = 1; i < len-1; i++)
	{
		i_missor = 2*c - c;

		p[i] = r > i ? min(r-i, p[i_missor]) : 0;

		while(str[i+p[i]+1] == str[i-1-p[i]])
			p[i]++;

		if(i+p[i] > r)
		{
			c = i;
			r = i+p[i];
		}
	}

	int maxLen = 0;
	int maxIdx = 0;
	for(int i = 1; i < len-1; i++)
	{
		if(p[i] > maxLen)
		{
			maxLen = p[i];
			maxIdx = i;
		}
	}

	delete [] p;
	return s.substr((maxIdx-1-maxLen)/2, maxLen);
}

int main()
{
	string s = "ababababca";
	cout << LPS_dp(s) << endl;
	cout << expand(s) << endl;
	cout << LPS_kmp(s) << endl;
	cout << Manacher(s) << endl;
}


