#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

int readFromFile(string filename, vector<int>&data)
{
    try{
        ifstream in(filename.c_str());
        string line;
        while(getline(in, line)){
            istringstream is(line);
            int num;
            is>>num;
            data.push_back(num);
        }
        sort(data.begin(), data.end());
        in.close();
        return 0;
    } catch(ifstream::failure e) {
            cout<<"Error in opening/reading/closing the file"<<endl;
            return -1;
    }
}
void getProduct(vector<int>&data){
    for(unsigned int i=0;i<data.size(); i++) {
        for(unsigned int j=i+1; j<data.size(); j++) {
            for(unsigned int k=j+1; k<data.size(); k++) {
                int sum = data[i]+data[j]+data[k];
                if(sum ==2020) {
                    int result = data[i]*data[j]*data[k];
                    cout<<result<<endl;
                    break;
                }
            }
        }
    }
}
int main(){
    vector<int>data;
    readFromFile("input.txt", data);
    getProduct(data);
    return 0;
}