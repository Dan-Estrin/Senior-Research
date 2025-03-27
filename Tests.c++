#include <iostream>
#include <random>
#include <chrono>
#include "Structures.c++"

template<typename T>
inline void GenTest(unsigned int elem, T comparison){
  int* k = new int[elem];

  for(int i = 0; i < elem; i++){
    k[i] = rand();
  }

  const std::chrono::_V2::steady_clock::time_point un_start = std::chrono::steady_clock::now();
  Unorganized<T> un = Unorganized<T>(k, elem);
  const std::chrono::_V2::steady_clock::time_point un_end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> un_init{un_end - un_start};

  const std::chrono::_V2::steady_clock::time_point gr_start = std::chrono::steady_clock::now();
  GroupOrganized<T> gr = GroupOrganized<T>(k, elem, 200);
  const std::chrono::_V2::steady_clock::time_point gr_end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> gr_init{gr_end - gr_start};

  const std::chrono::_V2::steady_clock::time_point fu_start = std::chrono::steady_clock::now();
  FullyOrganized<T> fu = FullyOrganized<T>(k, elem);
  const std::chrono::_V2::steady_clock::time_point fu_end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> fu_init{fu_end - fu_start};

  std::cout << "unorganized initialization: " << un_init.count() << " seconds" << std::endl;
  std::cout << "group organized initialization: " << gr_init.count() << " seconds" << std::endl;
  std::cout << "fully organized initialization: " << fu_init.count() << " seconds" << std::endl;

  std::cout << "===========================================" << std::endl;
  int a = 0;
  const std::chrono::_V2::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  for(T i = 0; i < elem; i++){
    if(un[i] < comparison) a++;
  }
  const std::chrono::_V2::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  const std::chrono::duration<double> un_branch{t2 - t1};

  int b = 0;
  const std::chrono::_V2::steady_clock::time_point t3 = std::chrono::steady_clock::now();
  for(T i = 0; i < elem; i++){
    if(gr[i] < comparison) b++;
  }
  const std::chrono::_V2::steady_clock::time_point t4 = std::chrono::steady_clock::now();
  const std::chrono::duration<double> gr_branch{t4 - t3};

  int c = 0;
  const std::chrono::_V2::steady_clock::time_point t5 = std::chrono::steady_clock::now();
  for(T i = 0; i < elem; i++){
    if(fu[i] < comparison) c++;
  }
  const std::chrono::_V2::steady_clock::time_point t6 = std::chrono::steady_clock::now();
  const std::chrono::duration<double> fu_branch{t6 - t5};

  std::cout << "unorganized grabtime: " << un_branch.count() << std::endl;
  std::cout << "group organized grabtime: " << gr_branch.count() << std::endl;
  std::cout << "fully organized grabtime: " << fu_branch.count() << std::endl;

  std::cout << "===========================================" << std::endl;

  std::cout << "unorganized fulltime: " << (un_branch.count() + un_init.count()) << std::endl;
  std::cout << "group organized fulltime: " << (gr_branch.count() + gr_init.count()) << std::endl;
  std::cout << "fully organized fulltime: " << (fu_branch.count() + fu_init.count()) << std::endl;
}