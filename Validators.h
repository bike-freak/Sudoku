#include<bits/stdc++.h>

using namespace std;

void assignValidators(vector<vector<int>> &vertical,vector<vector<int>> &horizontal,vector<vector<int>> &box){
    vertical.clear();
    horizontal.clear();
    box.clear();
    vector<int> temp;
    temp.clear();
    for(int i=0;i<10;i++){
        temp.push_back(0);
    }
    for(int i=0;i<10;i++){
        vertical.push_back(temp);
        horizontal.push_back(temp);
        box.push_back(temp);
    }
}

int getBox(int r,int c){
    r-=1;c-=1;
    return r/3*3+c/3+1;
}

bool isValid(vector<vector<int>> &vertical,vector<vector<int>> &horizontal,vector<vector<int>> &box,int r,int c,int e){
    int x=getBox(r,c);
    if(!(vertical[c][e]) && !(horizontal[r][e]) && !(box[x][e])){
        vertical[c][e]=1;
        horizontal[r][e]=1;
        box[x][e]=1;
        return true;
    }
    return false;
}

void unmarkValidators(vector<vector<int>> &vertical,vector<vector<int>> &horizontal,vector<vector<int>> &box,int r,int c,int e){
    vertical[c][e]=0;
    horizontal[r][e]=0;
    box[getBox(r,c)][e]=0;
}

void initializeFixedPositions(vector<vector<int>> &board,set<pair<int,int>> &fixedPosition){
    for(int i=1;i<10;i++){
        for(int j=1;j<10;j++){
            if(board[i][j]!=0){
                fixedPosition.insert({i,j});
            }
        }
    }
}