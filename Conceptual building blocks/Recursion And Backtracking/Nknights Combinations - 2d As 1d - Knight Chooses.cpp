// Question Link:-

// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/nknights-combinations-2das1d-knight-chooses-official/ojquestion

// Code:-


#include<bits/stdc++.h>
using namespace std;

bool IsKnightSafe(vector<vector<bool>>&chess, int i, int j){
    if(i-1 >= 0 && j-2 >= 0 && chess[i-1][j-2]){
        return false;
    }
    if(i-2 >= 0 && j-1 >= 0 && chess[i-2][j-1]){
        return false;
    }
    if(i-1 >= 0 && j+2 < chess.size() && chess[i-1][j+2]){
        return false;
    }
    if(i-2 >= 0 && j+1 < chess.size() && chess[i-2][j+1]){
        return false;
    }
    
    return true; 
}

void knightCombination(int kpsf, int tk, vector<vector<bool>>&chess, int lcol){
    if(kpsf == tk){
        for(int row =0; row<chess.size(); row++){
            for(int col =0; col<chess.size(); col++){
                if(chess[row][col] == true){
                    cout<<"k"<<"	";
                }else{
                    cout<<"-"<<"	";
                }
            }
            cout<<"\n";
        }
        cout<<"\n";
        return;
    }
    
    for(int cell =lcol+1; cell < chess.size()*chess.size(); cell++){
        int row = cell / chess.size();
        int col = cell % chess.size();
        
        if(chess[row][col] == false && IsKnightSafe(chess, row, col)){
            chess[row][col] = true;
            knightCombination(kpsf + 1, tk, chess, cell);
            chess[row][col] = false;
        }
    }
}


int main(){
    int n;
    cin>>n;
    
    vector<vector<bool>> chess(n,vector<bool>(n, false));
    knightCombination(0, n, chess, -1);
    
    return 0;
}
