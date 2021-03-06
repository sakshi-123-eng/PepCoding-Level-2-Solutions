// Question Link:-

// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/k-subsets-with-equal-sum-official/ojquestion


// Code:-


#include <bits/stdc++.h>
using namespace std;

void solve(int level, int n, int k,vector<vector<int>>&ans, vector<int>v, int nos){
    if(level>n){
        if(nos==k){
            vector<int>vt(k);
            string s ="";
            
            for(int i=0;i<k;i++){
                int sum =0;
                s=s+"[";
                for(int j=0;j<ans[i].size();j++){
                    sum = sum + ans[i][j];
                    
                    if(j<ans[i].size()-1){
                        s=s+to_string(ans[i][j])+", ";
                    }else{
                        s= s+to_string(ans[i][j]);
                    }
                }
                vt[i]=sum;
                s=s+"] ";
            }
            
            bool flag = true;
            for(int i=0;i<k-1;i++){
                if(vt[i]!=vt[i+1]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                cout<<s<<"\n";
                return;
            }
            
        }
        return ;
    }
    
    for(int j=0;j<k;j++){
        if(ans[j].size()>0){
            ans[j].push_back(v[level-1]);
            solve(level+1, n, k, ans, v, nos );
            ans[j].pop_back();
        }else{
            ans[j].push_back(v[level-1]);
            solve(level+1, n, k, ans, v, nos+1 );
            ans[j].pop_back();
            break;
        }
    }
    
}


int main(){
	int n;
	int k;
	cin >> n;
	int sum =0;
	vector<int>v(n);
	for (int i = 0; i < n; i++){
	    cin>>v[i];
	    sum=sum+v[i];
	}
	cin>>k;
	
		// if k=1 , then whole array is your answer
	if(k==1){
	    cout<<"[";
	    for (int i = 0; i < n-1; i++){
	        cout<<v[i]<<", ";
	     }
	     cout<<v[n-1]<<"]";
	     cout<<"\n";
	     return 0;
	}
	
	// if there are more subsets than no. of elements in array or sum of all elements of array is not       //divisible by k then "-1" will be printed
	
	if(k>n || sum%k != 0){
	    cout<<"-1"<<"\n";
	    return 0;
	}
	vector<vector<int>>ans(k);
	solve(1, n, k,ans, v , 0);
}
