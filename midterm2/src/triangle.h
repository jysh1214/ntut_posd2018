#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle
{
public:
  Triangle(int a, int b, int c);
  virtual ~Triangle(){}

private:
  int _a;
  int _b;
  int _c;
};
#endif
