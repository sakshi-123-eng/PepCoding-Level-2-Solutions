// Question Link :-

// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/k-partitions-official/ojquestion


// Code:-


#include <bits/stdc++.h>
using namespace std;
static int p=1;
void solve(int level, int n, int k, string store[], int subset_so_far)
{
	if (level > n)
	{
	    

		if(subset_so_far==k){
		    cout<<p<<'.'<<" ";
		    p++;
		for (int i = 0; i < k; i++)
		{
			cout << "[";
			for(int j=0;j<store[i].length();j++){
			    cout<<store[i][j];
			    if(j<store[i].length()-1){
			        cout<<','<<" ";
			        
			    }
			}
		   	cout<<"]"<<" ";
		}
		cout<<endl;
		}
		return;
	}
	for (int i = 0; i < k; i++)
	{
		if (store[i] != "")
		{
			char x = '0' + level;
			store[i].push_back(x);
			
			solve(level + 1, n, k, store, subset_so_far);
			store[i].erase(store[i].size() - 1);
		}
		else
		{
			char x = '0' + level;
			store[i].push_back(x);
		
			solve(level + 1, n, k, store, subset_so_far + 1);
			store[i].erase(store[i].size() - 1);
			break;
		}
	}
}
int main()
{
	int n;
	int k;
	cin >> n >> k;
	string store[k];
	for (int i = 0; i < k; i++)
	{
		store[i] = "";
	}
	solve(1, n, k, store, 0);
}
