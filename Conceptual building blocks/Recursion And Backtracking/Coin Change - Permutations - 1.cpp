// Question Link:-

// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/coin-change-permutations-1-official/ojquestion


// Code:-


#include<bits/stdc++.h>
using namespace std;

void coinChange(int i, vector<int>&coins, int amtsf, int tamt, string asf,vector<string>&fgh){
    // amtsf = amount_so_far, tamt = total_amount_so_far
    if(i == coins.size()){
        if(amtsf == tamt){
            for(int j=0;j<fgh.size();j++){
                if(asf.compare(fgh[j]) == 0){
                    return;
                }
            }
            fgh.push_back(asf);
            cout<<asf<<"."<<"\n";
        }
        return;
    }
    
    for(int k=0;k<coins.size();k++){
        if(coins[k]!=0){
            int cpp = coins[k];
            coins[k]=0;
            coinChange(i+1, coins, amtsf+cpp, tamt, asf+to_string(cpp)+"-", fgh);
            coins[k]=cpp;
        }
    }
        
            coinChange(i+1, coins, amtsf+0, tamt, asf, fgh) ;
   
    
}

int main(){
    int n, amt;
    cin>>n;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    
    cin>>amt;
    
    vector<string>fgh;
    coinChange(0, coins, 0, amt, "", fgh);
    
    return 0;
}
