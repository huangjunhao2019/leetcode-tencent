#include<iostream>
#include<regex>
using namespace std;
int main(){
    regex r("[[:alnum:]]+\\.(cpp|cxx|cc)$",regex::icase);
    smatch results;
    string fileName;
    while(cin>>fileName){
        if(regex_search(fileName,results,r)){
            cout<<results.str()<<endl;
        }
    }
    return 0;
}