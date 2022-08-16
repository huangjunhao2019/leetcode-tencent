#include<iostream>
#include<regex>
#include<string>
int main(){
    //std::string pattern("[[:alpha:]]*[^c]ei[[:alpha:]]*");
    std::string pattern("[^c]ei");
    std::regex r(pattern);
    std::smatch results;
    std::cout<<"input a word";
    std::string s;
    while(std::cin>>s){
        if(std::regex_search(s,results,r)){
            std::cout<<s<<": error"<<std::endl;
            std::cout<<results.str()<<std::endl;
        }
        else{
            std::cout<<s<<": correct"<<std::endl;
        }
    }
    return 0;
}