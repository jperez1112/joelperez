/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Joel Perez
 * Created on February 4, 2019, 12:06 PM
 * Purpose: Connect4 Project 2
 */

#include <iostream>
#include <string>
using namespace std;

//Higher Dimension
const int COL=7;
//Function Prototype
void asgnelm(int [][COL], int); //all spaces assigned to 0
void prntbrd(int [][COL], int); //output board game
void inpinvl(char&); //reject invalid characters
void PL1upd(char,int[][COL]); //Player1 updates the board
void PL2upd(char,int[][COL]); //Player2 updates the board
int PL1win(int[][COL]); //Player 1 Wins Requirement



int main(int argc, char** argv) {
    //Declare Variables
    const int ROW=6; 
    const int CONTNUE=8;
    int game[ROW][COL],x=8;
    char slct;
    string p="Player ",o="One",t="Two";
    
    //Assigning 0 to subscripts
    asgnelm(game,ROW); 
    //Create Loop to repeat turns
    while(x==CONTNUE){
        prntbrd(game,ROW);      
        //Player 1's turn
        cout<<p+o<<" Go"<<endl;
        cin>>slct;
        inpinvl(slct);
        PL1upd(slct,game);
        PL1win(game);
        prntbrd(game,ROW);
        //Player 2's turn
        cout<<p+t<<" Go"<<endl;
        cin>>slct;
        inpinvl(slct);
        PL2upd(slct,game);
    }
    
    
    return 0;
}


void asgnelm(int game[][COL],int row){
    for(int i=0;i<row;i++){
        for(int j=0;j<COL;j++){
            game[i][j]=0;   
        }
    }
}
void prntbrd(int game[][COL],int row){
    for(int i=0;i<row;i++){
        for(int j=0;j<COL;j++){
            cout<<game[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"a "<<"b "<<"c "<<"d "<<"e "<<"f "<<"g"<<endl;
}
void inpinvl(char& slct){
    while((slct>31&&slct<65)||(slct>71&&slct<97)||(slct>103&&slct<127)){
        cout<<"Invalid Location Pick Again"<<endl;
        cin>>slct;
    }
}
void PL1upd(char slct,int game[][COL]){
    int r,rep;
    switch(slct){
        case 'A':
        case 'a':for(r=5,rep=0;r>=rep;--r){
                    if(game[r][0]==0){
                        game[r][0]=1;
                        rep=6;//kills loop once if is true
                    }      
                }
        break;
        case 'B':
        case 'b':for(r=5,rep=0;r>=rep;--r){
                    if(game[r][1]==0){
                        game[r][1]=1;
                        rep=6;
                    }
                }
        break;
        case 'C':
        case 'c':for(r=5,rep=0;r>=rep;--r){
                    if(game[r][2]==0){
                        game[r][2]=1;
                        rep=6;
                    }
                }
        break;
        case 'D':
        case 'd':for(r=5,rep=0;r>=rep;--r){
                    if(game[r][3]==0){
                        game[r][3]=1;
                        rep=6;
                    }
                }
        break;
        case 'E':
        case 'e':for(r=5,rep=0;r>=rep;--r){
                    if(game[r][4]==0){
                        game[r][4]=1;
                        rep=6;
                    }
                }
        break;
        case 'F':
        case 'f':for(r=5,rep=0;r>=rep;--r){
                    if(game[r][5]==0){
                        game[r][5]=1;
                        rep=6;
                    }
                }
        break;
        case 'G':
        case 'g':for(r=5,rep=0;r>=rep;--r){
                    if(game[r][6]==0){
                        game[r][6]=1;
                        rep=6;
                    }
                }
        break;
    }
}
void PL2upd(char slct,int game[][COL]){
    int r,rep;
    switch(slct){
        case 'A':
        case 'a':for(r=5,rep=0;r>=rep;--r){
                    if(game[r][0]==0){
                        game[r][0]=2;
                        rep=6;//kills loop once if is true
                    }      
                }
        break;
        case 'B':
        case 'b':for(r=5,rep=0;r>=rep;--r){
                    if(game[r][1]==0){
                        game[r][1]=2;
                        rep=6;
                    }
                }
        break;
        case 'C':
        case 'c':for(r=5,rep=0;r>=rep;--r){
                    if(game[r][2]==0){
                        game[r][2]=2;
                        rep=6;
                    }
                }
        break;
        case 'D':
        case 'd':for(r=5,rep=0;r>=rep;--r){
                    if(game[r][3]==0){
                        game[r][3]=2;
                        rep=6;
                    }
                }
        break;
        case 'E':
        case 'e':for(r=5,rep=0;r>=rep;--r){
                    if(game[r][4]==0){
                        game[r][4]=2;
                        rep=6;
                    }
                }
        break;
        case 'F':
        case 'f':for(r=5,rep=0;r>=rep;--r){
                    if(game[r][5]==0){
                        game[r][5]=2;
                        rep=6;
                    }
                }
        break;
        case 'G':
        case 'g':for(r=5,rep=0;r>=rep;--r){
                    if(game[r][6]==0){
                        game[r][6]=2;
                        rep=6;
                    }
                }
        break;
    }
}
int PL1win(int game[][COL]){
    int i,n;
    for(n=5;n>=0;--n){ //Horizontal Victories
        if(game[n][i=0]==1&&game[n][++i]==1&&game[n][++i]==1&&game[n][++i]==1||
            game[n][i=1]==1&&game[n][++i]==1&&game[n][++i]==1&&game[n][++i]==1||
            game[n][i=2]==1&&game[n][++i]==1&&game[n][++i]==1&&game[n][++i]==1||
            game[n][i=3]==1&&game[n][++i]==1&&game[n][++i]==1&&game[n][++i]==1){
                cout<<"Player One Wins"<<endl;
        }   
    }
    for(i=0;i<7;i++){ //Vertical Victories
        if(game[n=5][i]==1&&game[--n][i]==1&&game[--n][i]==1&&game[--n][i]==1||
           game[n=4][i]==1&&game[--n][i]==1&&game[--n][i]==1&&game[--n][i]==1||
           game[n=3][i]==1&&game[--n][i]==1&&game[--n][i]==1&&game[--n][i]==1){
            cout<<"Player One Wins"<<endl;
        }
    }
    for(int rep=0;rep<1;rep++){ //Diagonal Victories 
        if(game[n=3][i=0]==1&&game[--n][++i]==1&&game[--n][++i]==1&&game[--n][++i]==1||
                game[n=4][i=0]==1&&game[--n][++i]==1&&game[--n][++i]==1&&game[--n][++i]==1||
                game[n=3][i=1]==1&&game[--n][++i]==1&&game[--n][++i]==1&&game[--n][++i]==1||
                game[n=5][i=0]==1&&game[--n][++i]==1&&game[--n][++i]==1&&game[--n][++i]==1||
                game[n=4][i=1]==1&&game[--n][++i]==1&&game[--n][++i]==1&&game[--n][++i]==1||
                game[n=3][i=2]==1&&game[--n][++i]==1&&game[--n][++i]==1&&game[--n][++i]==1||
                game[n=5][i=1]==1&&game[--n][++i]==1&&game[--n][++i]==1&&game[--n][++i]==1||
                game[n=4][i=2]==1&&game[--n][++i]==1&&game[--n][++i]==1&&game[--n][++i]==1||
                game[n=3][i=3]==1&&game[--n][++i]==1&&game[--n][++i]==1&&game[--n][++i]==1||
                game[n=5][i=2]==1&&game[--n][++i]==1&&game[--n][++i]==1&&game[--n][++i]==1||
                game[n=4][i=3]==1&&game[--n][++i]==1&&game[--n][++i]==1&&game[--n][++i]==1||
                game[n=5][i=3]==1&&game[--n][++i]==1&&game[--n][++i]==1&&game[--n][++i]==1){
            cout<<"Player One Wins"<<endl;
        }
    }
    for(int rep=0;rep<1;rep++){ 
        if(game[n=0][i=3]==1&&game[++n][++i]==1&&game[++n][++i]==1&&game[++n][++i]==1||
                game[n=0][i=3]==1&&game[++n][++i]==1&&game[++n][++i]==1&&game[++n][++i]==1||
                game[n=0][i=2]==1&&game[++n][++i]==1&&game[++n][++i]==1&&game[++n][++i]==1||
                game[n=1][i=3]==1&&game[++n][++i]==1&&game[++n][++i]==1&&game[++n][++i]==1||
                game[n=0][i=1]==1&&game[++n][++i]==1&&game[++n][++i]==1&&game[++n][++i]==1||
                game[n=1][i=2]==1&&game[++n][++i]==1&&game[++n][++i]==1&&game[++n][++i]==1||
                game[n=2][i=3]==1&&game[++n][++i]==1&&game[++n][++i]==1&&game[++n][++i]==1||
                game[n=0][i=0]==1&&game[++n][++i]==1&&game[++n][++i]==1&&game[++n][++i]==1||
                game[n=1][i=1]==1&&game[++n][++i]==1&&game[++n][++i]==1&&game[++n][++i]==1||
                game[n=2][i=2]==1&&game[++n][++i]==1&&game[++n][++i]==1&&game[++n][++i]==1||
                game[n=3][i=3]==1&&game[++n][++i]==1&&game[++n][++i]==1&&game[++n][++i]==1||
                game[n=1][i=0]==1&&game[++n][++i]==1&&game[++n][++i]==1&&game[++n][++i]==1||
                game[n=2][i=1]==1&&game[++n][++i]==1&&game[++n][++i]==1&&game[++n][++i]==1||
                game[n=2][i=0]==1&&game[++n][++i]==1&&game[++n][++i]==1&&game[++n][++i]==1){
            cout<<"Player One Wins"<<endl;
        }
    }

           
        
   
      
}
    
   

