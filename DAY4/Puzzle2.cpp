#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <stdexcept>
#include <regex>

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
            passportFields[str.substr(start, COL_INDEX)] = \
                    str.substr(start+COL_INDEX+1, (end-(start+COL_INDEX+1)));
            start = end+1;
            end = str.find(delim, start);
        }

        passports.push_back(passportFields);
        passportFields.clear();
    }

    inline int convertToInt(string s)
    {
        int num=0;
        stringstream sstr(s);
        sstr>>num;
        return num;
    }

    bool checkConstraints(unordered_map<string, string>& in)
    {
        int ibyr, iiyr,ieyr;
        int numFields=in.size();

        if( numFields<7|| (numFields==7 && in.find("cid") != in.end())) {
            return false;
        }

        ibyr=convertToInt(in["byr"]);
        if ( (ibyr<1920 || ibyr>2002)) {
            return false;
        }

        iiyr=convertToInt(in["iyr"]);
        if( (iiyr< 2010 || iiyr > 2020)) {
            return false;
        }

        ieyr=convertToInt(in["eyr"]);
        if( ieyr<2020 || ieyr >2030) {
            return false;
        }

        if (in["pid"].length()!=9) {
            return false;
        }

        string shcl=in["hcl"];
        regex pattern("^#[0-9a-f]*?$");
        if( shcl.length()!=7 || !(regex_match(shcl.begin(), shcl.end(), pattern))) {
            return false;
        }

        string secl=in["ecl"];
        const string ecl[]= {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"};
        if( find(ecl, ecl+7, secl) == ecl+7 ) {
            return false;
        }

        string shgt=in["hgt"];
        int ihgt = convertToInt(shgt.substr(0, shgt.length()-2));
        string units = shgt.substr(shgt.length()-2, 2);

        if(units.compare("cm") == 0 && ( ihgt < 150 || ihgt > 193)) {
            return false;
        }

        if(units.compare("in")==0 && ( ihgt < 59 || ihgt >76))  {
            return false;
        }

        return true;
    }

    int getValidPassportsCount()
    {
        int cnt=0;
        for(unsigned int i=0; i<=passports.size(); i++) {
            if(true == checkConstraints(passports[i]) ) {
                cnt++;
            }
        }
        return cnt;
    }
};

int readFromFile(string filename, passport& data)
{
    try {
        ifstream in(filename.c_str());
        string line, str;
        while(getline(in, line)) {
            if(!line.empty()) {
                str+=line+" ";
            } else {
                data.parseLine(str);
                str.clear();
            }
        }
        in.close();
    } catch(ifstream::failure& e) {
        cout<<"Error in opening/reading/closing the file"<<endl;
        return -1;
    }
    return 0;
}

int main()
{
    passport data;
    readFromFile("input.txt", data);
    cout<<data.getValidPassportsCount()<<endl;
    return 0;
}
