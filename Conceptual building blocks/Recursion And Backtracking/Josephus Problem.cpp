// Question Link:-

// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/josephus-problem-official/ojquestion#!


// Code:-


#include<bits/stdc++.h>
using namespace std;

// 0 to n-1
int solution(int n , int k){
    if(n==1){
        return 0;
    }
    int x = solution(n-1,k);
    int y = (x+k)%n;
    return y;
}

int main(){
    int n,k;
    cin>>n>>k;
   cout<<solution(n,k)<<"\n";
    return 0;
}
