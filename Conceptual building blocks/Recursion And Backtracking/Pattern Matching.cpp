// Question Link:-

// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/pattern-matching-official/ojquestion


// Code:-

#include<bits/stdc++.h>
using namespace std;

void solution(string str, string pattern, map<char, string>&mp, string op){
    if(pattern.length() == 0){
        if(str.length() == 0){
            set<char>alreadyPrinted;
            
            for(int i=0;i<op.length();i++){
                char ch = op[i];
                if(alreadyPrinted.find(ch) == alreadyPrinted.end()){
                    cout<<ch<<" -> "<<mp[ch]<<", ";
                    alreadyPrinted.insert(ch);
                }
            }
            cout<<"."<<endl;
        }
        return;
    }
    
    char ch = pattern[0];
    string rop = pattern.substr(1);
    
    
    if(mp.find(ch) != mp.end()){
        string previousMapping = mp[ch];
        
        if(str.length() >= previousMapping.length()){
            string left = str.substr(0, previousMapping.length());
            string right = str.substr(previousMapping.length());
            if(previousMapping.compare(left) == 0){
                solution(right, rop, mp, op);
            }
        }
        
    }else{
        for(int i =0; i<str.length(); i++){
            string left = str.substr(0, i+1);
            string right = str.substr(i+1);
            
            mp.insert({ch,left});
            solution(right, rop, mp, op);
            mp.erase(ch);
        }
    }
}

int main(){
    string str;
    cin>>str;
    string pattern;
    cin>>pattern;
    map<char, string>mp;
    solution(str, pattern, mp, pattern);
 
    return 0;
}
