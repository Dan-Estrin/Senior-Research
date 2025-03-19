#include "Structures.h++"
#include <iostream>
//========================================================================================================================================
//Unorganized definitions
//========================================================================================================================================
template<typename iType, int N>
inline Unorganized<iType, N>::Unorganized(iType (&array)[N]){
  //assign # of elements in array
  this->nElem = N;
  //assign total length of array
  this->len = this->nElem + 512;

  //create array & store end
  this->start = new iType[this->len];
  this->end = (this->start + this->len - 1);

  //assign element start/end positions
  this->eStart = this->start + 255;
  this->eEnd = this->end - 257;

  //copy over unsorted
  for(int i = 0; i < this->nElem; i++){
    this->eStart[i] = array[i];
  }
}

template<typename iType, int N>
inline Unorganized<iType, N>::~Unorganized(){
  delete[] this->start;
}

template<typename iType, int N>
inline iType Unorganized<iType, N>::operator[](int index){
  if(index > this->nElem) throw(777);
  if(index >= 0) return this->eStart[index];
  else return *(this->eEnd + index + 1);
}

//========================================================================================================================================
//GroupOrganized definitions
//========================================================================================================================================
template<typename iType, int N>
inline GroupOrganized<iType, N>::GroupOrganized(iType (&array)[N]){
  //assign # of elements in array
  this->nElem = N;
  //assign total length of array
  this->len = this->nElem + 512;

  //create array & store end
  this->start = new iType[this->len];
  this->end = (this->start + this->len - 1);

  //assign element start/end positions
  this->eStart = this->start + 255;
  this->eEnd = this->end - 257;

  //copy over unsorted
  for(int i = 0; i < this->nElem; i++){
    this->eStart[i] = array[i];
  }
}

template<typename iType, int N>
inline GroupOrganized<iType, N>::~GroupOrganized(){
  delete[] this->start;
}

template<typename iType, int N>
inline iType GroupOrganized<iType, N>::operator[](int index){
  if(index > this->nElem) throw(777);
  if(index >= 0) return this->eStart[index];
  else return *(this->eEnd + index + 1);
}

//========================================================================================================================================
//FullyOrganized definitions
//========================================================================================================================================
template<typename iType, int N>
inline FullyOrganized<iType, N>::FullyOrganized(iType (&array)[N]){
  //assign # of elements in array
  this->nElem = N;
  //assign total length of array
  this->len = this->nElem + 512;

  //create array & store end
  this->start = new iType[this->len];
  this->end = (this->start + this->len - 1);

  //assign element start/end positions
  this->eStart = this->start + 255;
  this->eEnd = this->end - 257;

  //copy over unsorted
  for(int i = 0; i < this->nElem; i++){
    this->eStart[i] = array[i];
  }
}

template<typename iType, int N>
inline FullyOrganized<iType, N>::~FullyOrganized(){
  delete[] this->start;
}

template<typename iType, int N>
inline iType FullyOrganized<iType, N>::operator[](int index){
  if(index > this->nElem) throw(777);
  if(index >= 0) return this->eStart[index];
  else return *(this->eEnd + index + 1);
}