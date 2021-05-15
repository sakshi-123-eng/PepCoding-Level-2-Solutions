// Question Link:-

// https://github.com/sakshi-123-eng/PepCoding-Level-2-Solutions/new/main/Conceptual%20building%20blocks/Recursion%20And%20Backtracking

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
    
   coinChange(i+1, coins, amtsf+coins[i], tamt, asf+to_string(coins[i])+"-") ;
   coinChange(i+1, coins, amtsf+0, tamt, asf) ;
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
