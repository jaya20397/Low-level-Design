#include<iostream>
#include<vector>
#include<queue>
#include "gameboard.cpp"
#include<unordered_map>
using namespace std; 

int main(){
    dice d;
    player p1("p1", 1);
    player p2("p2", 2);
    queue<player> players;
    players.push(p1);
    players.push(p2);
    jumper snake1(10, 2);
    jumper snake2(15,5);
    jumper ladder1(6,18);
    jumper ladder2(9,21);
    vector<jumper> snakes;
    snakes.push_back(snake1);
    snakes.push_back(snake2);
    vector<jumper> ladders;
    ladders.push_back(ladder1);
    ladders.push_back(ladder2);
    unordered_map<string, int> playerCurrentPosition;
    playerCurrentPosition["p1"]=1;
    playerCurrentPosition["p2"]=1;
    gameboard gb(d,players,snakes,ladders,playerCurrentPosition,40);
    gb.startGame();
}