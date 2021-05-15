// Question Link:-

// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/coin-change-combinations-2-official/ojquestion

// Code:-


#include<bits/stdc++.h>
using namespace std;

void coinChange(int i, vector<int>&coins, int amtsf, int tamt, string asf){
    // amtsf = amount_so_far, tamt = total_amount_so_far
    if(i == coins.size()){
        if(amtsf == tamt){
            cout<<asf<<"."<<"\n";
        }
        return;
    }
    for(int j= tamt/coins[i]; j>=1; j--){
        string part = "";
        for(int k=0;k<j;k++){
            part += to_string(coins[i]) + "-";
        }
        coinChange(i+1, coins, amtsf+coins[i]*j, tamt, asf+part);
    }
    coinChange(i+1, coins, amtsf, tamt, asf);
}

int main(){
    int n, amt;
    cin>>n;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    
    cin>>amt;
    
    coinChange(0, coins, 0, amt, "");
    
    return 0;
}
