#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int getRow(string input)
{
    unsigned int front=0, rear=127;
    unsigned int nRows=rear;
    for(unsigned int i=0; i<input.length(); i++) {
        if(input[i] == 'F') {
            rear-=(nRows>>1)+1;
        }
        if(input[i] == 'B') {
            front+=(nRows>>1)+1;
        }
        nRows=rear-front;
    }
    return front;
}

int getColumn(string input)
{
    unsigned int left=0, right=7;
    unsigned int nCols=right;
    for(unsigned int i=0; i<input.length(); i++) {
        if(input[i] == 'L') {
            right-=(nCols>>1)+1;
        }
        if(input[i] == 'R') {
            left+=(nCols>>1)+1;
        }
        nCols=right-left;
    }
    return left;
}
int main()
{
    ifstream in("input.txt");
    string line;
    int maxSeatID=0;
    while(getline(in, line)) {
        int len =line.length();
        int row=getRow(line.substr(0, len-3));
        int column =getColumn(line.substr(0+len-3, 3));
        int seat=row*8 + column;
        if(maxSeatID<seat) {
            maxSeatID =seat;
        }
    }
    cout<<maxSeatID<<endl;
    return 0;
}
