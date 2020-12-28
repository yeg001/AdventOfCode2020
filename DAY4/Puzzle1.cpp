#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

class passport 
{
public:
  unordered_map<string,string>passportFields;
  vector<unordered_map<string, string>> passports;
public:
  void parseLine(string str)
  {
      if(str.length()<=0) return;
      
      string delim=" ";
      auto start=0;
      auto end = str.find(delim);
      const int COL_INDEX=3;
      
      while(end !=string::npos) {
          passportFields[str.substr(start, COL_INDEX)] = str.substr(start+COL_INDEX+1, (end-(start+COL_INDEX+1)));
          start = end+1;
          end = str.find(delim, start);
      }
      
      passports.push_back(passportFields);
      passportFields.clear();
  }
  int getValidPassportsCount()
  {
      int cnt=0;
      for(unsigned int i=0; i<passports.size();i++) {
          int numFields=passports[i].size();
          if( numFields<7|| (numFields==7 && passports[i].find("cid") != passports[i].end())) { continue;}
          else {cnt++;}
      }
    return cnt;
  }
};

int readFromFile(string filename)
{
    passport p;
    try{
        ifstream in(filename.c_str());
        string line, data;
        while(getline(in, line)){
            if(!line.empty()){
                data+=line+" ";
            }
            else{
              p.parseLine(data);
              data.clear();
            }
        }
        in.close();
        cout<<p.getValidPassportsCount()<<endl;
    } catch(ifstream::failure e) {
            cout<<"Error in opening/reading/closing the file"<<endl;
            return -1;
    }
    return 0;
}

int main()
{
    readFromFile("input.txt");
    return 0;
}