// Question Link:-

// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/max-score-official/ojquestion#!

// Code:-


#include<bits/stdc++.h>
using namespace std;

int solution(vector<string>words,vector<int>farr,vector<int>score , int idx ){
    if(idx==words.size()){
        return 0;
    }
     int sno = 0 + solution(words,farr,score,idx+1); // word at idx indexnot included
     
     // word to include
     int sword =0;
     string word = words[idx];
     bool flag=true;
     for(int i=0;i<word.length();i++){
         char ch = word[i];
         
         if(farr[ch-'a']==0){
             flag = false;
         }
         
         farr[ch-'a']--;
         sword+=score[ch-'a'];
     }
     
     int syes=0;
     if(flag){
         syes = sword + solution(words,farr,score,idx+1);
     }
     
     for(int i=0;i<word.length();i++){
         char ch = word[i];
         farr[ch-'a']++;
     }
     
     return max(sno,syes);
}

int main(){
    int n,m;
    cin>>n;
    
    vector<string>words(n);
    for(int i=0;i<n;i++){
        cin>>words[i];
    }
    cin>>m;
    
    vector<char>letters(m);
    for(int i=0;i<m;i++){
        cin>>letters[i];
    }
    
    vector<int>score(26);
    for(int i=0;i<26;i++){
        cin>>score[i];
    }
    
    if (words.size() == 0 || m == 0) {
			cout<<"0"<<"\n";
			return 0;
		}
		vector<int>farr(26,0);
		for (char ch : letters) {
			farr[ch - 'a']++;
		}
		cout<<solution(words, farr, score, 0)<<"\n";
    return 0;
}
