// Question Link :-

// https://www.pepcoding.com/resources/data-structures-and-algorithms-in-java-levelup/recursion-and-backtracking/nqueens-branch-and-bound-official/ojquestion


// Code:-



#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<bool>>board, int row, bool cols[], bool ndiag[], bool rdiag[], string asf){
    if(row==board.size()){
        cout<<asf<<"."<<"\n";
        return;
    }
    
    for(int col=0;col<board[0].size();col++){
        if(cols[col]==false && ndiag[row+col]==false && rdiag[row-col+board.size()-1]==false){
            board[row][col]=true;
            cols[col]=true;
            ndiag[row+col]=true;
            rdiag[row-col+board.size()-1]=true;
            solve(board,row+1,cols,ndiag,rdiag,asf+to_string(row)+"-"+to_string(col)+", ");
            board[row][col]=false;
            cols[col]=false;
            ndiag[row+col]=false;
            rdiag[row-col+board.size()-1]=false;
        }
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<bool>>board(n,vector<bool>(n,false));
    bool cols[n]={false};
    bool ndiag[2*n-1]={false};
    bool rdiag[2*n-1]={false};
    solve(board,0,cols,ndiag,rdiag,"");
    return 0;
}
