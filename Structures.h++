#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <iostream>
template<typename iType>
struct Base{
  protected:
  //pointer to start of array
  iType* start;
  //pointer to end of  array
  iType* end;
  //pointer to first real element in the array
  iType* eStart;
  //pointer to last real element in the array
  iType* eEnd;
  //number of real elements in array
  int nElem;
  //number of total spaces in array
  int len;

  ~Base();

  public:
  //+/- indexing
  iType operator[](int index);
};
template<typename iType, int N>
class Unorganized : public Base<iType>{
  public:
  Unorganized(iType (&array)[N]);//DONE
};

template<typename iType, int N>
class GroupOrganized : public Base<iType>{
  public:
  GroupOrganized(iType (&array)[N], int groups);//TODO: IMPLEMENT ORGANIZATIONS
};

template<typename iType, int N>
class FullyOrganized : public Base<iType>{
  public:
  FullyOrganized(iType (&array)[N]);//TODO: IMPLEMENT ORGANIZATIONS
};
#endif