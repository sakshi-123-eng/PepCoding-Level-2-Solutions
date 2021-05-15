// Question Link:-


// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/combinations-2-official/ojquestion

// Code:-


#include <bits/stdc++.h>
using namespace std;

void combination2(vector<bool>&boxes, int current_item, int total_item, int last_level_box_visited){
    
    if(current_item > total_item){
        for(int i=0;i<boxes.size();i++){
            if(boxes[i]){
                cout<<"i";
            }else{
                cout<<"-";
            }
        }
        cout<<endl;
        return;
    }
    
    for(int b = last_level_box_visited + 1; b<boxes.size();b++){
        //if(boxes[b]==false){
            boxes[b]=true;
            combination2(boxes, current_item + 1, total_item, b);
            boxes[b]=false;
        //}
    }
}

int main(){
    int nboxes, ritems;
    cin>>nboxes;
    cin>>ritems;
    
    vector<bool>boxes(nboxes, false);
    combination2(boxes, 1, ritems, -1);
    
    return 0;
}
