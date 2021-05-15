// Question Link:-

// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/lexicographical-numbers-official/ojquestion

// Code:-

#include<bits/stdc++.h>
using namespace std;

void dfs(int i , int n){
    if(i>n){
        return;
    }
    cout<<i<<endl;
    for(int j=0;j<10;j++){
        dfs(10*i+j,n);
    }
}

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=9;i++){
        dfs(i,n);
    }
    return 0;
}
