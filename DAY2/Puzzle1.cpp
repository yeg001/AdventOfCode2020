#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <iterator>

using namespace std;

void parseLine(string str, vector<bool>&data)
{
    //format low_range -high_range character: password string
    size_t found=str.find('-');
    if(found == string::npos) {return;}
    
    int range[2], count=0;
    range[0]=atoi(str.substr(0, found).c_str());
    
    size_t position = str.find(':');
    if(position == string::npos) {return;}
    
    range[1] =atoi(str.substr(found+1, position-3).c_str());
    string sstr = str.substr(position+1, str.length()-1);
    char c = str[position-1];
    
    for(string::iterator it=sstr.begin(); it != sstr.end(); it++) {
        if(c==*it){++count;}
    }
    
    if (count>=range[0] && count<=range[1]) {
        data.push_back(true);
    }else { data.push_back(false);}
}
int readFromFile(string filename)
{
    vector<bool>results;
    
    try{
        ifstream in(filename.c_str());
        string line;
        while(getline(in, line)){
            parseLine(line, results);
        }
        in.close();
        int count=0;
        for(unsigned int i=0; i<results.size(); i++){
            if(results[i]==true){++count;}
        }
        cout<<count<<endl;
        return 0;
    } catch(ifstream::failure e) {
            cout<<"Error in opening/reading/closing the file"<<endl;
            return -1;
    }
}

int main()
{
    readFromFile("input.txt");
    return 0;
}