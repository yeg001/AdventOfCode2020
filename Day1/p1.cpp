#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

void getProduct(int* data){
    for(unsigned int i=0;i<200; i++) {
        for(unsigned int j=i+1; j<200; j++) {
            int sum = data[i]+data[j];
            if(sum ==2020){
                int result = data[i]*data[j];
                cout<<result<<endl;
                break;
            }
        }
    }
}
int main(){
    int num[200];
    ifstream in;
    in.open("input.txt");
    for(int i=0; i<200;i++) {
        in>>num[i];
    }
    sort(num, num+200);
    in.close();
    getProduct(num);
    return 0;
}