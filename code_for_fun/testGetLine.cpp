#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main(){
    string test="a&b";
    string temp;
    stringstream ss(test);
    int countNull=0;
    while(getline(ss,temp,'&')){
        if(temp==""){
            countNull++;
        }
        cout<<temp<<endl;
    }
    cout<<"countNull="<<countNull<<endl;
    return 0;
}