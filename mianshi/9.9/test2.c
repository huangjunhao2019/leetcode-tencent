#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char *s="Intel is a \0 good company.";
    printf("%d\n",strlen(s));
}