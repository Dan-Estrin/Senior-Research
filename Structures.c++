#include "Structures.h++"
#include <iostream>

//=================================================================
//misc definitions
//=================================================================

template<typename iType>
int partition(iType* array, int low, int high) {
  int i = low - 1;
  for (int j = low; j <= high - 1; j++) {
    if (array[j] < array[high]) {
      i++;
      iType temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  } 
  iType temp = array[i + 1];
  array[i + 1] = array[high];
  array[high] = temp;
  return i + 1;
}

template<typename iType>
void quicksort(iType* array, int low, int high) {
  if (low < high) {
    int pi = partition(array, low, high);
    quicksort(array, low, pi - 1);
    quicksort(array, pi + 1, high);
  }
}

//=================================================================
//Base definitions
//=================================================================

template<typename iType>
inline Base<iType>::~Base(){
  delete[] this->start;
}

template<typename iType>
inline iType Base<iType>::operator[](int index){
  if(index > this->nElem) throw(777);
  if(index >= 0) return this->eStart[index];
  else return *(this->eEnd + index + 1);
}

//=================================================================
//Unorganized definitions
//=================================================================

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
  for(int i = 0; i < N; i++){
    this->eStart[i] = array[i];
  }
}

//=================================================================
//GroupOrganized definitions
//=================================================================

template<typename iType, int N>
inline GroupOrganized<iType, N>::GroupOrganized(iType (&array)[N], int groups){
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
  for(int i = 0; i < N; i++){
    this->eStart[i] = array[i];
  }

  //sorting each part of the array by sections determined by group #
  //leftover elements at the end are not sorted
  int interval = (this->nElem/groups);
  for(int i = 0; i < groups; i++){
    quicksort((this->eStart + (i * interval)), 0, interval - 1);
  }
}

//=================================================================
//FullyOrganized definitions
//=================================================================

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
  for(int i = 0; i < N; i++){
    this->eStart[i] = array[i];
  }

  quicksort(this->eStart, 0, this->nElem - 1);
}