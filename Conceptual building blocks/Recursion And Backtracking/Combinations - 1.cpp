// Question Link:-


// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/combinations-i-official/ojquestion

// Code:-


#include <bits/stdc++.h>
using namespace std;

void combinations(int cb, int tb, int ssf, int ts, string asf){ 
    // cb = current box , tb = total box, 
    //ssf= selection so far , ts = total selections, asf = answer so far
    if(cb>tb){
        if(ssf == ts){
            cout<<asf<<"\n";
        }
        return;
    }
    
    combinations(cb+1, tb, ssf+1, ts, asf+"i");
    combinations(cb+1, tb, ssf, ts, asf+"-");
    
}


int main(){
    int nboxes, ritems;
    cin>>nboxes>>ritems;
    
    combinations(1, nboxes, 0, ritems, "");
    return 0;
}
