/* 
 * File:   main.cpp
 * Author: Joel Perez
 * Created on February 4, 2019, 12:06 PM
 * Purpose: Connect4 Project 2
 */

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib>  //for exit function
using namespace std;

//Higher Dimension
const int COL=7;
//Function Prototype
void asgnelm(int [][COL], int); //all elements assigned to 0
void prntbrd(int [][COL], int); //output board game
void inpinvl(char&); //reject invalid characters
void PL1upd(char,int[][COL]); //Player1 updates the board
void PL2upd(char,int[][COL]); //Player2 updates the board
int PL1win(int[][COL]); //Player 1 Win Requirement
int PL2win(int[][COL]); //Player 2 Win Requirement
void replay(char); //play again or quit
void average(int [],int); //finds average of turns between four rounds
bool lnrsrch(int[],int); //finds a round with 7 turns and outputs true or false
void slcsort(int[],int); //sorts # of turns within four rounds
void swap(int&, int&); //within slcsort function


//Execution Begins
int main(int argc, char** argv) {
    //Declare Variables
    const int ROW=6; 
 
    const int CONTNUE=42; //amount of spots available
    const int SIZE=4; //holds # of Turns for each round
    int game[ROW][COL],block[SIZE],trns=0,i=0,j=0;
    char slct;
    string p="Player ",o="One",t="Two";
    
    //Assigning 0 to 2D Array's subscripts
    asgnelm(game,ROW); 
    //Create Loop to repeat turns
    for(int x=0;x<CONTNUE;x++){
        prntbrd(game,ROW);      
        //Player 1's turn
        cout<<p+o<<" Go"<<endl;
        cin>>slct;
        inpinvl(slct);
        PL1upd(slct,game);
        trns++;
        prntbrd(game,ROW);
        PL1win(game);
        if(PL1win(game)==CONTNUE){
            cout<<p+o<<" Wins."<<endl;
            cout<<"Number of turns until victory was "<<trns<<endl;
            block[i++]=trns;
            if(i==SIZE){
                if(lnrsrch(block,SIZE)){
                    cout<<"Winning in 7 turns is like your opponent isn't even trying"<<endl;
                }
                cout<<"Amount of turns within rounds ";
                for(int n=0;n<SIZE;n++){
                    cout<<block[n]<<" ";
                }
                cout<<endl;
                slcsort(block,SIZE);
                cout<<"After sorting from least to greatest ";
                for(int sn=0;sn<SIZE;sn++){
                    cout<<block[sn]<<" ";
                } 
                cout<<endl;
                average(block,SIZE);
                i=0;
            }
            replay(slct);
            asgnelm(game,ROW);
            prntbrd(game,ROW);
            trns=0;
        }
        //Player 2's turn
        cout<<p+t<<" Go"<<endl;
        cin>>slct;
        inpinvl(slct);
        PL2upd(slct,game);
        trns++;
        PL2win(game);
        if(PL2win(game)==CONTNUE){
            cout<<p+t<<" Wins"<<endl;
            cout<<"Number of turns until victory was "<<trns<<endl;
            block[j++]=trns;
            if(j==SIZE){
                if(lnrsrch(block,SIZE)){
                    cout<<"Winning in 7 turns is like your opponent isn't even trying"<<endl;
                }
                cout<<"Amount of turns within rounds ";
                for(int n=0;n<SIZE;n++){
                    cout<<block[n]<<" ";
                }
                cout<<endl;
                slcsort(block,SIZE);
                cout<<"After sorting from least to greatest ";
                for(int sn=0;sn<SIZE;sn++){
                    cout<<block[sn]<<" ";
                } 
                cout<<endl;
                average(block,SIZE);
                j=0;
            }
            replay(slct);
            asgnelm(game,ROW);
            trns=0;
        }
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
    cout<<"a"<<setw(2)<<"b"<<setw(2)<<"c"<<setw(2)<<"d"<<setw(2)<<"e"<<setw(2)<<"f"<<setw(2)<<"g"<<endl;
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
                        rep=6;//kills loop once if expression is true
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
                        rep=6;//kills loop once if expression is true
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
    char chc;
    for(n=5;n>=0;--n){ //Horizontal Victories
        if(game[n][i=0]==1&&game[n][++i]==1&&game[n][++i]==1&&game[n][++i]==1||
            game[n][i=1]==1&&game[n][++i]==1&&game[n][++i]==1&&game[n][++i]==1||
            game[n][i=2]==1&&game[n][++i]==1&&game[n][++i]==1&&game[n][++i]==1||
            game[n][i=3]==1&&game[n][++i]==1&&game[n][++i]==1&&game[n][++i]==1){
                return 42;
        }   
    }
    for(i=0;i<7;i++){ //Vertical Victories
        if(game[n=5][i]==1&&game[--n][i]==1&&game[--n][i]==1&&game[--n][i]==1||
           game[n=4][i]==1&&game[--n][i]==1&&game[--n][i]==1&&game[--n][i]==1||
           game[n=3][i]==1&&game[--n][i]==1&&game[--n][i]==1&&game[--n][i]==1){
            
            return 42;
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
            
            return 42;
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
            
            return 42;
        }
    }   
}
int PL2win(int game[][COL]){
    int i,n;
    char chc;
    for(n=5;n>=0;--n){ //Horizontal Victories
        if(game[n][i=0]==2&&game[n][++i]==2&&game[n][++i]==2&&game[n][++i]==2||
            game[n][i=1]==2&&game[n][++i]==2&&game[n][++i]==2&&game[n][++i]==2||
            game[n][i=2]==2&&game[n][++i]==2&&game[n][++i]==2&&game[n][++i]==2||
            game[n][i=3]==2&&game[n][++i]==2&&game[n][++i]==2&&game[n][++i]==2){
                return 42;
        }   
    }
    for(i=0;i<7;i++){ //Vertical Victories
        if(game[n=5][i]==2&&game[--n][i]==2&&game[--n][i]==2&&game[--n][i]==2||
           game[n=4][i]==2&&game[--n][i]==2&&game[--n][i]==2&&game[--n][i]==2||
           game[n=3][i]==2&&game[--n][i]==2&&game[--n][i]==2&&game[--n][i]==2){
            
            return 42;
        }
    }
    for(int rep=0;rep<1;rep++){ //Diagonal Victories 
        if(game[n=3][i=0]==2&&game[--n][++i]==2&&game[--n][++i]==2&&game[--n][++i]==2||
                game[n=4][i=0]==2&&game[--n][++i]==2&&game[--n][++i]==2&&game[--n][++i]==2||
                game[n=3][i=1]==2&&game[--n][++i]==2&&game[--n][++i]==2&&game[--n][++i]==2||
                game[n=5][i=0]==2&&game[--n][++i]==2&&game[--n][++i]==2&&game[--n][++i]==2||
                game[n=4][i=1]==2&&game[--n][++i]==2&&game[--n][++i]==2&&game[--n][++i]==2||
                game[n=3][i=2]==2&&game[--n][++i]==2&&game[--n][++i]==2&&game[--n][++i]==2||
                game[n=5][i=1]==2&&game[--n][++i]==2&&game[--n][++i]==2&&game[--n][++i]==2||
                game[n=4][i=2]==2&&game[--n][++i]==2&&game[--n][++i]==2&&game[--n][++i]==2||
                game[n=3][i=3]==2&&game[--n][++i]==2&&game[--n][++i]==2&&game[--n][++i]==2||
                game[n=5][i=2]==2&&game[--n][++i]==2&&game[--n][++i]==2&&game[--n][++i]==2||
                game[n=4][i=3]==2&&game[--n][++i]==2&&game[--n][++i]==2&&game[--n][++i]==2||
                game[n=5][i=3]==2&&game[--n][++i]==2&&game[--n][++i]==2&&game[--n][++i]==2){
            
            return 42;
        }
    }
    for(int rep=0;rep<1;rep++){ 
        if(game[n=0][i=3]==2&&game[++n][++i]==2&&game[++n][++i]==2&&game[++n][++i]==2||
                game[n=0][i=3]==2&&game[++n][++i]==2&&game[++n][++i]==2&&game[++n][++i]==2||
                game[n=0][i=2]==2&&game[++n][++i]==2&&game[++n][++i]==2&&game[++n][++i]==2||
                game[n=1][i=3]==2&&game[++n][++i]==2&&game[++n][++i]==2&&game[++n][++i]==2||
                game[n=0][i=1]==2&&game[++n][++i]==2&&game[++n][++i]==2&&game[++n][++i]==2||
                game[n=1][i=2]==2&&game[++n][++i]==2&&game[++n][++i]==2&&game[++n][++i]==2||
                game[n=2][i=3]==2&&game[++n][++i]==2&&game[++n][++i]==2&&game[++n][++i]==2||
                game[n=0][i=0]==2&&game[++n][++i]==2&&game[++n][++i]==2&&game[++n][++i]==2||
                game[n=1][i=1]==2&&game[++n][++i]==2&&game[++n][++i]==2&&game[++n][++i]==2||
                game[n=2][i=2]==2&&game[++n][++i]==2&&game[++n][++i]==2&&game[++n][++i]==2||
                game[n=3][i=3]==2&&game[++n][++i]==2&&game[++n][++i]==2&&game[++n][++i]==2||
                game[n=1][i=0]==2&&game[++n][++i]==2&&game[++n][++i]==2&&game[++n][++i]==2||
                game[n=2][i=1]==2&&game[++n][++i]==2&&game[++n][++i]==2&&game[++n][++i]==2||
                game[n=2][i=0]==2&&game[++n][++i]==2&&game[++n][++i]==2&&game[++n][++i]==2){
            
            return 42;
        }
    }   
}
void replay(char slct){
    cout<<"Press 'Y' to play again or any other key to exit"<<endl;
    cin>>slct;
    if(slct=='Y'||slct=='y'){
        return;
    }
    else{
        ofstream myfile;
        myfile.open("note.txt");
        myfile<<"Thanks for playing!";
        myfile.close();
        exit(0);
    }
}
void average(int block[],int size){
    float rslt=1;
    
    for(int i=0;i<size;i++){
        rslt+=block[i];
        
    }
    rslt/=4;
    cout<<"Average of four turns is "<<rslt<<endl;
}
bool lnrsrch(int block[],int size){
    int i=0;
    bool found=false;
    while(i<size && !found){
        if(block[i]==7){
            
            found=true;
        }
        i++;
    }
    return found;
}
void slcsort(int block[],int size){
    int minelem, minval;
    for(int start=0;start<size-1;start++){
        minelem=start;
        minval=block[start];
        for(int i=start+1;i<size;i++){
            if(block[i]<minval){
                minval=block[i];
                minelem=i;
            }
        }
        swap(block[minelem],block[start]);
    }
}
void swap(int& num1,int& num2){
    int hold=num1;
    num1=num2;
    num2=hold;    
}


    
    
   
   

