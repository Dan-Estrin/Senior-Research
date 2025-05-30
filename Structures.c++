#include "Structures.h++"
//=================================================================
//misc definitions
//=================================================================

template<typename iType>
inline int partition(iType* array, int low, int high) {
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
inline void Base<iType>::init(iType* array, unsigned int num){
  //assign # of elements in array
  this->nElem = num;
  //assign total length of array
  this->len = this->nElem + 512;

  //create array & store end
  this->start = new iType[this->len];
  this->end = (this->start + this->len - 1);

  //assign element start/end positions
  this->eStart = this->start + 255;
  this->eEnd = this->end - 257;

  //copy over unsorted
  for(int i = 0; i < num; i++){
    this->eStart[i] = array[i];
  }
}

template<typename iType>
inline Base<iType>::~Base(){
  delete[] this->start;
}

template<typename iType>
inline iType Base<iType>::operator[](int index){
  if(index > this->nElem) throw(1);
  if(index >= 0) return this->eStart[index];
  else return *(this->eEnd + index + 1);
}

template<typename iType>
inline void Base<iType>::AddFront(iType elem){
  this->eStart = this->eStart - 1;
  *this->eStart = elem;
}

template<typename iType>
inline void Base<iType>::AddBack(iType elem){
  this->eEnd = this->eEnd + 1;
  *this->eEnd = elem;
}

template<typename iType>
inline void Base<iType>::PopBack(){
  *this->eEnd = 0;
  this->eEnd = this->eEnd - 1;
}

template<typename iType>
inline void Base<iType>::PopFront(){
  *this->eStart = 0;
  this->eStart = this->eStart + 1;
}

template<typename iType>
inline void Base<iType>::ChangeAt(int index, iType replacement){
  if(index < 0) *(this->eEnd + index) = replacement;
  else *(this->eStart + index) = replacement;
}

//=================================================================
//Unorganized definitions
//=================================================================

template<typename iType>
inline Unorganized<iType>::Unorganized(iType* array, unsigned int num){
  Base<iType>::init(array, num);
}

//=================================================================
//GroupOrganized definitions
//=================================================================

template<typename iType>
inline GroupOrganized<iType>::GroupOrganized(iType* array, unsigned int num, unsigned int groups){
  Base<iType>::init(array, num);
  this->groups = groups;
  //# of elements inside each group
  int interval = this->nElem/groups;
  //1 or less results in no actual sorting
  if(interval > 1){
    //sort up to number of groups
    for(int i = 0; i < groups; i++){
      quicksort(this->eStart + (i * interval), 0, interval - 1);
    }
    //if any remaining elements are unsorted finish them
    if((float)this->nElem/groups > interval){
      quicksort(this->eStart + (interval * groups), 0, (this->nElem % groups) - 1);
    }
  }
}

template<typename iType>
inline void GroupOrganized<iType>::NewGroups(int groups){
  this->groups = groups;
  int interval = this->nElem/groups;
  //1 or less results in no actual sorting
  if(interval > 1){
    for(int i = 0; i < groups; i++){
      quicksort(this->eStart + (i * interval), 0, interval - 1);
    }
    if((float)this->nElem/groups > interval){
      quicksort(this->eStart + (interval * groups), 0, (this->nElem % interval) - 1);
    }
  }
}

template<typename iType>
inline void GroupOrganized<iType>::Reorganize(int group){
  int interval = this->nElem/this->groups;
  if(interval > 1){
    quicksort(this->eStart + (group * interval), 0, interval - 1);
  }
}

//=================================================================
//FullyOrganized definitions
//=================================================================

template<typename iType>
inline FullyOrganized<iType>::FullyOrganized(iType* array, unsigned int num){
  Base<iType>::init(array, num);
  quicksort(this->eStart, 0, this->nElem - 1);
}