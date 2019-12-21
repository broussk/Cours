#ifndef EX1_H
#define EX1_H

struct ensemble{
  double x,y;
  int a,b;

  inline ensemble(){x=1.1;y=2.2;a=3;b=4;};
  inline ensemble(double x1, double y1){x=x1;y=y1;a=1,b=2;};
  inline ensemble(double x1, double y1, int a1, int b1){x=x1;y=y1;a=a1;b=b1;};
};

struct alternance{
  double x;
  int a;
  double y;
  int b;

  inline alternance(){x=1.1;y=2.2;a=3;b=4;};
  inline alternance(double x1, double y1){x=x1;y=y1;a=2;b=3;};
  inline alternance(double x1, double y1, int a1, int b1){x=x1;y=y1;a=a1;b=b1;};
};
#endif
