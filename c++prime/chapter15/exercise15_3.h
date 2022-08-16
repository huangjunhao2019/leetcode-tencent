#ifndef EXERCISE15_3
#define EXERCISE15_3
#include<string>
#include<iostream>
class Quote{
public:
    Quote()=default;
    Quote(const std::string &b,double p):bookNo(b),price(p){}
    std::string isbn() const{
        return bookNo;
    }
    virtual double net_price(std::size_t n) const{
        return n*price;
    }
    void debug() const;
    virtual ~Quote()=default;
private:
    std::string bookNo;
protected:
    double price=0.0;
};
void Quote::debug() const{
    std::cout<<"data members of this class:\n"<<"bookNo="<<this->bookNo<<" "<<"price="<<\
    this->price<<" ";
}
#endif