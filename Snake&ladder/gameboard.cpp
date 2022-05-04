#include<iostream>
#include "dice.cpp"
#include "player.cpp"
#include "jumper.cpp"
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;


class gameboard{
    dice d;
    queue<player> nextTurn;
    vector<jumper> snakes;
    vector<jumper> ladder;
    unordered_map<string, int> playerCurrentPosition;
    int boardSize;

    public:
     gameboard(dice d, queue<player> nextTurn, vector<jumper> snakes, vector<jumper> ladder, unordered_map<string, int> playerCurrentPosition, int boardSize){
         this->d=d;
         this->nextTurn=nextTurn;
         this->snakes=snakes;
         this->ladder=ladder;
         this->playerCurrentPosition=playerCurrentPosition;
         this->boardSize=boardSize;
     }

     void startGame(){
         while(nextTurn.size()>1){
               player p=nextTurn.front();
                nextTurn.pop();
               int currentPos=playerCurrentPosition[p.getPlayerName()];
               int diceVal=d.rollDice();
               int nextCell=currentPos+diceVal;
               if(nextCell==boardSize){
                    cout<<"\n\n"<<"player:"<<p.getPlayerName()<<"won the game\n\n";
                    break;
               }
            
               else if(nextCell>boardSize)
                    nextTurn.push(p);
                
                else{
                    int nextPos[1];
                    vector<bool> b;
                    nextPos[0]=nextCell;
                    for(int i=0;i<ladder.size();i++){
                        if(snakes[i].startpoint==nextCell){
                            nextPos[0]=snakes[i].endpoint;
                            b[0]=true;
                        }
                    }
                    if((nextPos[0]!=nextCell) && b[0]){
                        cout<<p.getPlayerName()<<"got a snake";
                    }

                    for(int i=0;i<ladder.size();i++){
                        if(ladder[i].startpoint==nextCell){
                            nextPos[0]=ladder[i].endpoint;
                        }
                    }

                    if(nextPos[0]!=nextCell){
                        cout<<p.getPlayerName()<<"got a ladder";
                    }

                    if(nextPos[0] == boardSize){
                        cout<<p.getPlayerName()<<"won\n\n";
                        break;
                    }

                    else{
                            playerCurrentPosition[p.getPlayerName()]=nextPos[0];
                            cout<<p.getPlayerName()<<" is at :"<<nextPos[0]<<"\n";
                            nextTurn.push(p);
                    }


                }

            }
        }
};