#include<bits/stdc++.h>
#include<windows.h>
#include"Board.h"

using namespace std;

int playGame(vector<vector<int>> &board,vector<vector<int>> &vertical ,vector<vector<int>> &horizontal,vector<vector<int>> &box,set<pair<int,int>> &fixedPositions){
    int r,c,e;

    while(!(isFull(board))){
        getValue:
        system("CLS");
        cout<<"0 for row and column to display solution\n";
        cout<<"-1 for row and column to resign\n";
        cout<<"Enter number as -1 to remove the element.\n";

        displayBoard(board);
        
        cout<<"Enter row number:(0 for solution, -1 to resign) \n";
        cin>>r;
        cout<<"Enter column number:(0 for solution, -1 to resign) \n";
        cin>>c;
        
        if(r==c&&(r==-1||r==0)){
            return r;
        }else if(r<-1||r>9||c<-1||c>9){
            cout<<"Enter a valid row and column number.\n";
            Sleep(5000);
            system("CLS");
            goto getValue;
        }
        cout<<"Enter number to insert in "<<r<<","<<c<<":(-1 to remove at the position) ";
        cin>>e;
        if((e<1||e>9)&&e!=-1){
            cout<<"Enter a valid number to insert.\n";
            Sleep(5000);
            system("CLS");
            goto getValue;
        }
        if(board[r][c]==0){
            if(isValid(vertical,horizontal,box,r,c,e)){
                board[r][c]=e;
            }else{
                cout<<"This number can not be entered here.";
                Sleep(7500);
                goto getValue;
            }

        }else if(e==-1){
            if(board[r][c]!=0){
                if(fixedPositions.find({r,c})==fixedPositions.end()){
                    unmarkValidators(vertical,horizontal,box,r,c,board[r][c]);
                    board[r][c]=0;
                }else{
                    cout<<"This location is fixed. You can not change this position.";
                    Sleep(7500);
                    goto getValue;
                }
            }else{
                cout<<"There is no value present to remove it.";
                Sleep(7500);
                goto getValue;
            }
            
        }else if(board[r][c]!=0){
            if(fixedPositions.find({r,c})==fixedPositions.end()){
                char y;
                cout<<"Are you sure you want to replace:(Y/N) ";
                cin>>y;
                if(y=='Y'||y=='y'){
                    if(isValid(vertical,horizontal,box,r,c,e)){
                        unmarkValidators(vertical,horizontal,box,r,c,board[r][c]);
                        board[r][c]=e;
                    }else{
                        cout<<"Number "<<e<<" is not placeable here.\n";
                        Sleep(7500);
                        goto getValue;
                    }
                }
            }else{
                cout<<"This location is fixed. You can not change this position.";
                Sleep(7500);
                goto getValue;
            }
        }
    }
    return 1;
}