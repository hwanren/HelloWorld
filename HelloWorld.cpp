#include <iostream>

using namespace std;

class A {
public:
  A() { i = 0; f = 0.0; }
  ~A() {}

private:
  int i;
  float f;
};


int main(int argc, char **argv)
{
  A a;

  cout << "Hello World C++" << endl;

  return 0;
}
