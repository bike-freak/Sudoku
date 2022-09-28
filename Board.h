#include<bits/stdc++.h>
#include"Solver.h"

using namespace std;

void assignBoard(vector<vector<int>> &board){
    board.clear();
    vector<int> temp;
    for(int i=0;i<10;i++){
        temp.push_back(0);
    }
    for(int i=0;i<10;i++){
        board.push_back(temp);
    }
}

void displayBoard(vector<vector<int>> &board){
    cout<<"    1 2 3   4 5 6   7 8 9\n";
    cout<<"  -------------------------\n";
    for(int i=1;i<10;i++){
        cout<<i<<" | ";
        for(int j=1;j<10;j++){
            if(board[i][j]!=0){
                cout<<board[i][j];
            }else{
                cout<<".";
            }
            cout<<" ";
            if(j%3==0){
                cout<<"| ";
            }
        }
        cout<<"\n";
        if(i%3==0){
            cout<<"  -------------------------\n";
        }
    }
}

void generateFixedPositions(vector<vector<int>> &board,vector<vector<int>> &vertical,vector<vector<int>> &horizontal,vector<vector<int>> &box,int level){
    int x,r,c,e;
    srand(time(0));
    if(level==1){
        x=40;
    }else if(level==2){
        x=50;
    }else{
        x=60;
    }
    while(x){
        r=rand()%9+1;
        c=rand()%9+1;
        e=board[r][c];
        if(e){
            board[r][c]=0;
            unmarkValidators(vertical,horizontal,box,r,c,e);
            x--;
        }
    }
}

bool generateBoard(vector<vector<int>> &board,vector<vector<int>> &vertical,vector<vector<int>> &horizontal,vector<vector<int>> &box){
    vector<int> order;
    randomOrder(order);
    int i=10;
    srand(time(0));
    while(i){
        int r=rand()%9+1;
        int c=rand()%9+1;
        int x=rand()%9+1;
        if(isValid(vertical,horizontal,box,r,c,x)){
            board[r][c]=x;
            i-=1;
        }
    }
    if(solveBoard(board,order,vertical,horizontal,box,1,1)){
        return true;
    }
    return false;
}

bool isFull(vector<vector<int>> &board){
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            if(board[i][j]==0){
                return false;
            }
        }
    }
    return true;
}

void copySolution(vector<vector<int>> &board,vector<vector<int>> &solutionBoard){
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            solutionBoard[i][j]=board[i][j];
        }
    }
}