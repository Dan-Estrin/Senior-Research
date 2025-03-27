#ifndef STRUCTURES_H
#define STRUCTURES_H
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

  inline ~Base();

  public:
  //+/- indexing
  iType operator[](int index);
};
template<typename iType>
class Unorganized : public Base<iType>{
  public:
  inline Unorganized(iType* array, unsigned int num);//DONE
};

template<typename iType>
class GroupOrganized : public Base<iType>{
  public:
  inline GroupOrganized(iType* array, unsigned int num, int groups);//DONE
};

template<typename iType>
class FullyOrganized : public Base<iType>{
  public:
  inline FullyOrganized(iType* array, unsigned int num);//DONE
};
#endif