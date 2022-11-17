#include<iostream>
#include<fstream>
using namespace std;

int main(){
    string path="./testFile";
    fstream fs(path);
    string temp;
    while(getline(fs,temp)){
        cout<<temp<<endl;
    }
    return 0;
}