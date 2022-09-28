#include<bits/stdc++.h>
#include"Validators.h"
#include"Random.h"

using namespace std;

bool solveBoard(vector<vector<int>> &board,vector<int> &order,vector<vector<int>> &vertical,vector<vector<int>> &horizontal,vector<vector<int>> &box,int r,int c){
    if(r==9&&c==10){
        return true;
    }
    if(c==10){
        r++;
        c=1;
    }
    if(board[r][c]){
        return solveBoard(board,order,vertical,horizontal,box,r,c+1);
    }
    for(auto i:order){
        if(isValid(vertical,horizontal,box,r,c,i)){
            board[r][c]=i;
            if(solveBoard(board,order,vertical,horizontal,box,r,c+1)){
                return true;
            }
            vertical[c][i]=0;
            horizontal[r][i]=0;
            box[getBox(r,c)][i]=0;
        }
        board[r][c]=0;
    }
    return false;
}