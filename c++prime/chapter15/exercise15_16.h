#ifndef EXERCISE15_16
#define EXERCISE15_16
#include"exercise15_15_Disc.h"
class Limit_quote:public Disc_quote{
public:
    Limit_quote()=default;
    Limit_quote(const std::string &b,double p,std::size_t max,double disc):
        Disc_quote(b,p,max,disc){}
    double net_price(std::size_t n) const override{
        return n*price*(n<quantity?1-discount:1);
    }
};
#endif