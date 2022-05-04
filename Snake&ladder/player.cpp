#include<iostream>
using namespace std;

class player{
   
    string playername;
    int id;

     public:
        player(string pname, int id){
            this->playername=pname;
            this->id=id;
        }

        string getPlayerName(){
            return playername;
        }
};