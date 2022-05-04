#include<iostream>
#include<unordered_map>
using namespace std;

class jumper{
    
    int startpoint;
    int endpoint;
    public:
        jumper(int start, int end){
            this->startpoint=start;
            this->endpoint=end;
        }
};