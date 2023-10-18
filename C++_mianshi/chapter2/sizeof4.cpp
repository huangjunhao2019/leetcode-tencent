  #include <iostream>
  #include <cstring>

  using namespace std;

  struct flexarray {
      int val;
      int array[];  /* Flexible array member; must be last element of struct */
  };

  int main()
  {
      printf("%ld\n", sizeof(struct flexarray)); // 4
  }
