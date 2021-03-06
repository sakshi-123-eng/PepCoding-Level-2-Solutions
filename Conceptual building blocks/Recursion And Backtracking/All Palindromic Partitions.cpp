// Question Link:-


// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/all-palindromic-partitions-official/ojquestion

// Code:-


#include<bits/stdc++.h>
using namespace std;


bool isPalndrome(string str){
    int li=0;
    int ri=str.length()-1;
    while(li<ri){
        char left = str[li];
        char right = str[ri];
        if(left != right){
            return false;
        }
        li++;
        ri--;
    }
    return true;
}

void solution(string str, string asf){
    if(str.length() == 0){
        cout<<asf<<"\n";
        return;
    }
    
    for(int i=0;i<str.length(); i++){
        string prefix = str.substr(0,i+1);
        string ros = str.substr(i+1);
        if(isPalndrome(prefix)){
            solution(ros, asf + "(" + prefix + ") " );
        }
    }
}

int main(){
    string str;
    cin>>str;
    solution(str,"");
    
    
    
    return 0;
}
