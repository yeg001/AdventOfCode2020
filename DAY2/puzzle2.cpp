#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <iterator>

using namespace std;
void parseLine(string str, vector<bool>&data)
{
    //format first position - second position character: password string
    size_t found=str.find('-');
    if(found == string::npos) {return;}
    
    unsigned int position[2];
    position[0]=atoi(str.substr(0, found).c_str());
    
    size_t pos = str.find(':');
    if(pos == string::npos) {return;}
    
    position[1] =atoi(str.substr(found+1, pos-3).c_str());
    string sstr = str.substr(pos+1, str.length()-1);
    char c = str[pos-1];

    if( (c == sstr[position[0]] && c!=sstr[position[1]] ) || \
        (c != sstr[position[0]] && c==sstr[position[1]]) ) {
        data.push_back(true);
    }else {
        data.push_back(false);
    }
    
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
        cout<<"count="<<count<<endl;
        
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