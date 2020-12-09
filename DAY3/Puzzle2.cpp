#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class grid {
public:
    vector<string> data;
    
    int isTree(unsigned int rightCoordinate, unsigned int downCoordinate){
        unsigned int x=rightCoordinate%31;
        return (data[downCoordinate][x] == '#');
    }
    
    int getTreesCount(int right , int left){
        unsigned int rightCoordinate=0;
        unsigned int downCoordinate =0;
        int treeCount=0;
        
        while (downCoordinate < data.size() ) {
            if(isTree(rightCoordinate, downCoordinate)) {
                treeCount +=1;
            }
            rightCoordinate+=right;
            downCoordinate+=left;
        }
        
        return treeCount;
    }
};
int readFromFile(string filename, vector<string>& data)
{
    
    try{
        ifstream in(filename.c_str());
        string line;
        while(getline(in, line)){
            data.push_back(line);
        }
        in.close();
        return 0;
    } catch(ifstream::failure e) {
            cout<<"Error in opening/reading/closing the file"<<endl;
            return -1;
    }
}

int main()
{
    grid g;
    readFromFile("input.txt", g.data);
    int result = 0;
    long unsigned int product =1;
    // Puzzle 2 : to check for slopes -Right 1, down 1.-Right 3, down 1. 
    //Right 5, down 1.Right 7, down 1.Right 1, down 2.
    result = g.getTreesCount(1,1);
    cout<<"Number of trees - slope (1,1)" <<result<<endl;
    product*=result;
    result= g.getTreesCount(3,1);
    cout<<"Number of trees - slope (3,1)" <<result<<endl;
    product*=result;
    result = g.getTreesCount(5,1);
    cout<<"Number of trees - slope (5,1)" <<result<<endl;
    product*=result;
    result = g.getTreesCount(7,1);
    cout<<"Number of trees - slope (7,1)" <<result<<endl;
    product*=result;
    result = g.getTreesCount(1,2);
    cout<<"Number of trees - slope (1,2)" <<result<<endl;
    product*=result;
    
    cout<<product<<endl;
    return 0;
}
