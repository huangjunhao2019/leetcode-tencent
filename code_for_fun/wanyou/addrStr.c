#include<stdio.h>
int main(){
    char *a[]={"work","at","alibaba"};
    char **pa=a;
    //pa++;
    printf("%d\n",a);
    printf("%d\n",pa);
    printf("%s\n",*pa);
    return 0;
}