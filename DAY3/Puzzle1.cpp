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
    int result = g.getTreesCount(3,1);
    cout<<result<<endl;
    return 0;
}