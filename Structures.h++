#ifndef STRUCTURES_H
#define STRUCTURES_H
template<typename iType, int N>
class Unorganized{
  private:
  //pointer to start of array
  iType* start;
  //pointer to end of  array
  iType* end;
  //pointer to first real element in the array
  iType* eStart;
  //pointer to last real element in the array
  iType* eEnd;
  //# of real elements in array
  int nElem;
  //# of total spaces in array
  int len;
  
  
  public:
  Unorganized(iType (&array)[N]);//DONE
  ~Unorganized();//DONE

  //+/- indexing for elements
  iType operator[](int index);//DONE
};

template<typename iType, int N>
class GroupOrganized{
  private:
  //pointer to start of array
  iType* start;
  //pointer to end of  array
  iType* end;
  //pointer to first real element in the array
  iType* eStart;
  //pointer to last real element in the array
  iType* eEnd;
  //# of real elements in array
  int nElem;
  //# of total spaces in array
  int len;

  int Organize();


  public:
  GroupOrganized(iType (&array)[N]);//DONE
  ~GroupOrganized();//DONE

  //+/- indexing for elements
  iType operator[](int index);//DONE
};

template<typename iType, int N>
class FullyOrganized{
  private:
  //pointer to start of array
  iType* start;
  //pointer to end of  array
  iType* end;
  //pointer to first real element in the array
  iType* eStart;
  //pointer to last real element in the array
  iType* eEnd;
  //# of real elements in array
  int nElem;
  //# of total spaces in array
  int len;

  int Organize();

  
  public:
  FullyOrganized(iType (&array)[N]);//DONE
  ~FullyOrganized();//DONE

  //+/- indexing for elements
  iType operator[](int index);//DONE
};
#endif