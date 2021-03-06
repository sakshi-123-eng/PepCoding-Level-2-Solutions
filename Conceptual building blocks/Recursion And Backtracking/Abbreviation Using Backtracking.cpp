// Question Link:-

// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/abbreviation-suing-backtracking-official/ojquestion


// Code:-



#include<bits/stdc++.h>
using namespace std;

void solution(string str, string asf , int count , int pos){
    if(pos==str.length()){
        if(count==0){
            cout<<asf<<"\n";
        }else{
            cout<<asf+to_string(count)<<"\n";
        }
        return;
    }
    if(count>0){
        solution(str,asf+to_string(count)+str[pos],0,pos+1);
    }else{
        solution(str,asf+str[pos],0,pos+1);
    }
    solution(str,asf,count+1,pos+1);
}

int main(){
    string str;
    cin>>str;
    solution(str,"",0,0);
    return 0;
}
