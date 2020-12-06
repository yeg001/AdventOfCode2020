#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main(){
    ifstream input;
    int num[200], a, b;
    input.open("input.txt");
    for(int i = 0; i < 200; i++){
        input >> num[i];
    } 
    sort(num, num+200);
    for(int i = 0, j = 199; i < j;){
        int sum = num[i] + num[j];
        if(sum == 2020){
            a = num[i];
            b = num[j];;
            break;
        }
        else if(sum > 2020)
            j--;
        else
            i++;
    }
    cout << a * b << "\n";
    input.close();   
    return 0;
}