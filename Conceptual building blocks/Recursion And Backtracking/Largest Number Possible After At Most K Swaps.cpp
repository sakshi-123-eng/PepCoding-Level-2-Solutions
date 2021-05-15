// Question Link:-

// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/largest-number-at-most-k-swaps-official/ojquestion

// Code:-

#include <bits/stdc++.h>
using namespace std;
static int maxi = INT_MIN;
void findmax(string str, int k)
{   
     int z = stoi(str);
		
		if (z > maxi)
		{
			maxi = stoi(str);
		}
	if (k == 0)
	{
		
		return;
	}
	for (int i = 0; i < str.length()-1; i++)
	{
		for (int j = i+1; j < str.length(); j++)
		{
			if (str[i] <str[j])
			{
				char swap = str[i];
				str[i] = str[j];
				str[j] = swap;
				findmax(str, k - 1);
				swap = str[i];
				str[i] = str[j];
				str[j] = swap;
			}
		}
	}
}
int main()
{
	string str;
	cin >> str;
	int k;
	cin >> k;
	findmax(str, k);
	cout << maxi;
}
