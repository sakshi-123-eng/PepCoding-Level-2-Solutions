// Question Link:-

// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/nqueens-permutations-2das1d-official-queen-chooses/ojquestion


// Code:-


#include<bits/stdc++.h>
using namespace std;

bool IsQueenSafe(vector<vector<int>>&chess, int row, int col){
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
    
    
    for(int i=row, j=col; i< chess.size(); i++){
        if(chess[i][j]){
            return false;
        }
    }
    
    for(int i=row, j=col; j< chess.size();  j++){
        if(chess[i][j]){
            return false;
        }
    }
    
    for(int i=row, j=col; i < chess.size() && j < chess.size(); i++, j++){
        if(chess[i][j]){
            return false;
        }
    }
    
    
    for(int i=row, j=col; i < chess.size() && j >=0; i++, j--){
        if(chess[i][j]){
            return false;
        }
    }
    
    
    
    
    return true;
    
    
}

void queensPermutation(int qpsf, int tq, vector<vector<int>>&chess){
    if(qpsf == tq){
        for(int row =0; row<chess.size(); row++){
            for(int col =0; col<chess.size(); col++){
                if(chess[row][col] == 0){
                    cout<<"-"<<"	";
                }else{
                    cout<<"q"<<chess[row][col]<<"	";
                }
            }
            cout<<"\n";
        }
        cout<<"\n";
        return;
    }
    
    for(int cell = 0; cell < chess.size()*chess.size(); cell++){
        int row = cell / chess.size();
        int col = cell % chess.size();
        
        if(chess[row][col] == 0 && IsQueenSafe(chess, row, col)){
            chess[row][col] = qpsf + 1;
            queensPermutation(qpsf + 1, tq, chess);
            chess[row][col] = 0;
        }
    }
}


int main(){
    int n;
    cin>>n;
    
    vector<vector<int>> chess(n,vector<int>(n, 0));
    queensPermutation(0, n, chess);
 
    return 0;
}
