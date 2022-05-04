#include<iostream>
using namespace std;

class dice{
    public:
        int rollDice(){
            return ((rand() % 6) + 1);
        }
};