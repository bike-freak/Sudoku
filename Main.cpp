#include<bits/stdc++.h>
#include<windows.h>
#include"Play.h"

using namespace std;

int main(){
    vector<vector<int>> board,solutionBoard;
    vector<vector<int>> vertical,horizontal,box;
    set<pair<int,int>> fixedPositions;
    int level,option;

    menuLabel:
    cout<<"Enter:\n1.Play\n2.Exit\n";
    cin>>option;

    switch (option){
    case 1:
        generateLabel:
        assignBoard(board);
        assignValidators(vertical,horizontal,box);
        while(!(generateBoard(board,vertical,horizontal,box))){
            goto generateLabel;
        }

        levelLabel:
        system("CLS");
        cout<<"1.Easy\n2.Medium\n3.Hard\n";
        cin>>level;

        if(level>0&&level<4){
            assignBoard(solutionBoard);
            copySolution(board,solutionBoard);
            generateFixedPositions(board,vertical,horizontal,box,level);
        }
        else{
            cout<<"Enter a valid option.";
            Sleep(5000);
            goto levelLabel;
        }

        break;

    case 2:
        exit(0);

    default:
        cout<<"Enter a valid option.";
        Sleep(5000);
        system("CLS");
        goto menuLabel;
        break;
    }

    initializeFixedPositions(board,fixedPositions);
    int result=playGame(board,vertical,horizontal,box,fixedPositions);

    if(result==1){
        cout<<"You solved it! Congragulations!\n";
    }else if(result==0){
        cout<<"Well tried. Here is the solution.\n";
        displayBoard(solutionBoard);
    }else{
        cout<<"Better luck next time.\n";
        cout<<"Do you want to see the solution?(Y/N)\n";
        char yn;
        cin>>yn;
        if(yn=='Y'||yn=='y'){
            displayBoard(solutionBoard);
        }
    }
    
    Sleep(5000);
    cout<<"Press any key to continue";
    char a;
    a=getchar();
    a=getchar();
    Sleep(5000);
    goto menuLabel;
    return 0;
}