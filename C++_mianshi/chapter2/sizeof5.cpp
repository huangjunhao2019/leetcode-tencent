#include <iostream>
using namespace std;
int main(int argc, char * argv[])
{
    int x = 4;
    sizeof(x++);
    printf("%d\n", x);
    return 0;
}
