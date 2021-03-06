#include<bits/stdc++.h>

bool isValid(vector<string> &board, string &s, int row, int col, int n){
    if(s[col]=='Q') return false; // for current row

    int j=col, k=1;
    for(int i=row-1; i>=0; i--){
        if(j+k<n && board[i][j+k]=='Q') // upper right diagonal
            return false;
        if(j-k>=0 && board[i][j-k]=='Q') // upper left diagonal
            return false;
        k++;
    }
    return true;
}

void backtracker(vector<vector<string>> &soln, vector<string> &board, int row, int n, string &s){
    if(row==n){
        soln.push_back(board);
        return;
    }
    for(int col=0; col<n; col++){
        if(isValid(board, s, row, col, n)){
            board[row][col] = 'Q'; s[col] = 'Q';
            backtracker(soln, board, row+1, n, s);
            board[row][col] = '.'; s[col] = '.';
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    vector<vector<string>> soln;
    vector<string> board(A, string(A,'.'));
    string s(A, '.');
    backtracker(soln, board, 0, A, s);
    return soln;
}
