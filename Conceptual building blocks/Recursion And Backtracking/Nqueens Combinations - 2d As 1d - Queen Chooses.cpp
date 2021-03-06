// Question Link:-

// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/nqueens-combinations-2das1d-queen-chooses-official/ojquestion

// Code:-


#include<bits/stdc++.h>
using namespace std;

bool IsQueenSafe(vector<vector<bool>>&chess, int row, int col){
    for(int i=row, j=col; i>=0; i--){
        if(chess[i][j]){
            return false;
        }
    }
    
    for(int i=row, j=col; j>=0; j--){
        if(chess[i][j]){
            return false;
        }
    }
    
    for(int i=row, j=col; i>=0 && j>=0; i--, j--){
        if(chess[i][j]){
            return false;
        }
    }
    
    
    for(int i=row, j=col; i>=0 && j<chess.size(); i--, j++){
        if(chess[i][j]){
            return false;
        }
    }
    
    return true;
    
    
}

void queensCombination2(int qpsf, int tq, vector<vector<bool>>&chess, int lcol){
    if(qpsf == tq){
        for(int row =0; row<chess.size(); row++){
            for(int col =0; col<chess.size(); col++){
                if(chess[row][col] == true){
                    cout<<"q"<<"	";
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
        
        if(chess[row][col] == false && IsQueenSafe(chess, row, col)){
            chess[row][col] = true;
            queensCombination2(qpsf + 1, tq, chess, cell);
            chess[row][col] = false;
        }
    }
}


int main(){
    int n;
    cin>>n;
    
    vector<vector<bool>> chess(n,vector<bool>(n, false));
    queensCombination2(0, n, chess, -1);
    
    return 0;
}
