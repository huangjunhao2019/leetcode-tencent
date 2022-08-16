#include<iostream>
#include<regex>
#include<string>
using namespace std;
int main(){
    string pattern("[^c]ei");
    pattern="[[:alpha:]]*"+pattern+"[[:alpha:]]*";
    regex r(pattern);
    smatch results;
    string testStr="receipt freind theif receive";
    if(regex_search(testStr,results,r)){
        cout<<results.str()<<endl;
    }
    return 0;
}