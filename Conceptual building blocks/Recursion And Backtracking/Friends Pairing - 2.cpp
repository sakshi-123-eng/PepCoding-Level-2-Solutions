// Question Link:-

// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/friends-pairing-2-official/ojquestion


// Code:-


#include<bits/stdc++.h>
using namespace std;
static int c = 1;

void solution(int i , int n , bool used[], string asf){
    if(i>n){
        cout<<c<<"."<<asf<<"\n";
        c++;
        return;
    }
    if(used[i]==true){
        solution(i+1, n, used, asf);
    }
    else{
        used[i]=true;
        solution(i+1, n, used, asf+"("+to_string(i)+") ");
        for(int j= i+1;j<=n;j++){
            if(used[j]==false){
                used[j]=true;
                solution(i+1, n, used, asf+"("+to_string(i)+","+to_string(j)+") ");
                used[j]=false;
            }
        }
        used[i]=false;
    }
}

int main(){
    int n ;
    cin>>n;
    bool used[n+1]={false};
    solution(1, n, used, "");
    
    return 0;
}
