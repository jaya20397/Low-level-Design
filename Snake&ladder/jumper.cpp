#include<iostream>
#include<unordered_map>
using namespace std;

class jumper{
    public:
    int startpoint;
    int endpoint;
    
        jumper(int start, int end){
            this->startpoint=start;
            this->endpoint=end;
        }
};