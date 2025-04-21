#include <iostream>
#include <random>
#include <chrono>
#include <fstream>
#include "Structures.c++"

template<typename T>
inline void ltTest(unsigned int elem, int group){
  int* k = new int[elem];

  for(int i = 0; i < elem; i++){
    k[i] = rand();
  }

  const std::chrono::_V2::steady_clock::time_point un_start = std::chrono::steady_clock::now();
  Unorganized<T> un = Unorganized<T>(k, elem);
  const std::chrono::_V2::steady_clock::time_point un_end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> un_init{un_end - un_start};

  const std::chrono::_V2::steady_clock::time_point gr_start = std::chrono::steady_clock::now();
  GroupOrganized<T> gr = GroupOrganized<T>(k, elem, group);
  const std::chrono::_V2::steady_clock::time_point gr_end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> gr_init{gr_end - gr_start};

  const std::chrono::_V2::steady_clock::time_point fu_start = std::chrono::steady_clock::now();
  FullyOrganized<T> fu = FullyOrganized<T>(k, elem);
  const std::chrono::_V2::steady_clock::time_point fu_end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> fu_init{fu_end - fu_start};

  std::cout << "Lesser than comparison testing" << std::endl << std::endl;
  std::cout << "unorganized initialization: " << un_init.count() << " seconds" << std::endl;
  std::cout << "group organized initialization: " << gr_init.count() << " seconds" << std::endl;
  std::cout << "fully organized initialization: " << fu_init.count() << " seconds" << std::endl;

  std::cout << "===========================================" << std::endl;
  int a = 0;
  const std::chrono::_V2::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  for(int j = 0; j < RAND_MAX; j++){
    for(T i = 0; i < elem; i++){
      if(un[i] < j) a++;
    }
  }
  const std::chrono::_V2::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  const std::chrono::duration<double> un_branch{t2 - t1};

  int b = 0;
  const std::chrono::_V2::steady_clock::time_point t3 = std::chrono::steady_clock::now();
  for(int j = 0; j < RAND_MAX; j++){
    for(T i = 0; i < elem; i++){
      if(gr[i] < j) b++;
    }
  }
  const std::chrono::_V2::steady_clock::time_point t4 = std::chrono::steady_clock::now();
  const std::chrono::duration<double> gr_branch{t4 - t3};

  int c = 0;
  const std::chrono::_V2::steady_clock::time_point t5 = std::chrono::steady_clock::now();
  for(int j = 0; j < RAND_MAX; j++){
    for(T i = 0; i < elem; i++){
      if(fu[i] < j) c++;
    }
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

template<typename T>
inline void eqTest(unsigned int elem, int group){
  int* k = new int[elem];

  for(int i = 0; i < elem; i++){
    k[i] = rand();
  }

  const std::chrono::_V2::steady_clock::time_point un_start = std::chrono::steady_clock::now();
  Unorganized<T> un = Unorganized<T>(k, elem);
  const std::chrono::_V2::steady_clock::time_point un_end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> un_init{un_end - un_start};

  const std::chrono::_V2::steady_clock::time_point gr_start = std::chrono::steady_clock::now();
  GroupOrganized<T> gr = GroupOrganized<T>(k, elem, group);
  const std::chrono::_V2::steady_clock::time_point gr_end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> gr_init{gr_end - gr_start};

  const std::chrono::_V2::steady_clock::time_point fu_start = std::chrono::steady_clock::now();
  FullyOrganized<T> fu = FullyOrganized<T>(k, elem);
  const std::chrono::_V2::steady_clock::time_point fu_end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> fu_init{fu_end - fu_start};

  std::cout << "Equal to comparison testing" << std::endl << std::endl;
  std::cout << "unorganized initialization: " << un_init.count() << " seconds" << std::endl;
  std::cout << "group organized initialization: " << gr_init.count() << " seconds" << std::endl;
  std::cout << "fully organized initialization: " << fu_init.count() << " seconds" << std::endl;

  std::cout << "===========================================" << std::endl;
  int a = 0;
  const std::chrono::_V2::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  for(int j = 0; j < RAND_MAX; j++){
    for(T i = 0; i < elem; i++){
      if(un[i] == j) a++;
    }
  }
  const std::chrono::_V2::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  const std::chrono::duration<double> un_branch{t2 - t1};

  int b = 0;
  const std::chrono::_V2::steady_clock::time_point t3 = std::chrono::steady_clock::now();
  for(int j = 0; j < RAND_MAX; j++){
    for(T i = 0; i < elem; i++){
      if(gr[i] == j) b++;
    }
  }
  const std::chrono::_V2::steady_clock::time_point t4 = std::chrono::steady_clock::now();
  const std::chrono::duration<double> gr_branch{t4 - t3};

  int c = 0;
  const std::chrono::_V2::steady_clock::time_point t5 = std::chrono::steady_clock::now();
  for(int j = 0; j < RAND_MAX; j++){
    for(T i = 0; i < elem; i++){
      if(fu[i] == j) c++;
    }
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

template<typename T>
inline void gtTest(unsigned int elem, int group){
  int* k = new int[elem];

  for(int i = 0; i < elem; i++){
    k[i] = rand();
  }

  const std::chrono::_V2::steady_clock::time_point un_start = std::chrono::steady_clock::now();
  Unorganized<T> un = Unorganized<T>(k, elem);
  const std::chrono::_V2::steady_clock::time_point un_end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> un_init{un_end - un_start};

  const std::chrono::_V2::steady_clock::time_point gr_start = std::chrono::steady_clock::now();
  GroupOrganized<T> gr = GroupOrganized<T>(k, elem, group);
  const std::chrono::_V2::steady_clock::time_point gr_end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> gr_init{gr_end - gr_start};

  const std::chrono::_V2::steady_clock::time_point fu_start = std::chrono::steady_clock::now();
  FullyOrganized<T> fu = FullyOrganized<T>(k, elem);
  const std::chrono::_V2::steady_clock::time_point fu_end = std::chrono::steady_clock::now();
  const std::chrono::duration<double> fu_init{fu_end - fu_start};

  std::cout << "Greater than comparison testing" << std::endl << std::endl;
  std::cout << "unorganized initialization: " << un_init.count() << " seconds" << std::endl;
  std::cout << "group organized initialization: " << gr_init.count() << " seconds" << std::endl;
  std::cout << "fully organized initialization: " << fu_init.count() << " seconds" << std::endl;

  std::cout << "===========================================" << std::endl;
  int a = 0;
  const std::chrono::_V2::steady_clock::time_point t1 = std::chrono::steady_clock::now();
  for(int j = 0; j < RAND_MAX; j++){
    for(T i = 0; i < elem; i++){
      if(un[i] > j) a++;
    }
  }
  const std::chrono::_V2::steady_clock::time_point t2 = std::chrono::steady_clock::now();
  const std::chrono::duration<double> un_branch{t2 - t1};

  int b = 0;
  const std::chrono::_V2::steady_clock::time_point t3 = std::chrono::steady_clock::now();
  for(int j = 0; j < RAND_MAX; j++){
    for(T i = 0; i < elem; i++){
      if(gr[i] > j) b++;
    }
  }
  const std::chrono::_V2::steady_clock::time_point t4 = std::chrono::steady_clock::now();
  const std::chrono::duration<double> gr_branch{t4 - t3};

  int c = 0;
  const std::chrono::_V2::steady_clock::time_point t5 = std::chrono::steady_clock::now();
  for(int j = 0; j < RAND_MAX; j++){
    for(T i = 0; i < elem; i++){
      if(fu[i] > j) c++;
    }
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

template<typename T>
inline void GroupAsymtote(unsigned int elem){
  int* k = new int[elem];
  for(int i = 0; i < elem; i++){
    k[i] = rand();
  }

  unsigned int b = 0;
  std::ofstream myfile;
  myfile.open ("z.txt");
  for(int i = 1; i < elem/2; i++){
    const std::chrono::_V2::steady_clock::time_point gr_start = std::chrono::steady_clock::now();
    GroupOrganized<T> gr = GroupOrganized<T>(k, elem, i);
    const std::chrono::_V2::steady_clock::time_point gr_end = std::chrono::steady_clock::now();
    const std::chrono::duration<double> gr_init{gr_end - gr_start};

    const std::chrono::_V2::steady_clock::time_point t3 = std::chrono::steady_clock::now();
    for(int j = 0; j < RAND_MAX; j++){
      for(T i = 0; i < elem; i++){
        if(gr[i] < j) b++;
      }
    }
    const std::chrono::_V2::steady_clock::time_point t4 = std::chrono::steady_clock::now();
    const std::chrono::duration<double> gr_branch{t4 - t3};
    myfile << (gr_branch.count() + gr_init.count()) << '\n';
    b = 0;
    break;
  }
  myfile.close();
}

template<typename T>
inline void comp(){
  std::ofstream un_init;
  std::ofstream un_comp;
  std::ofstream un_ttl;
  std::ofstream fu_init;
  std::ofstream fu_comp;
  std::ofstream fu_ttl;
  un_init.open("un_init.txt");
  un_comp.open("un_comp.txt");
  un_ttl.open("un_ttl.txt");
  fu_init.open("fu_init.txt");
  fu_comp.open("fu_comp.txt");
  fu_ttl.open("fu_ttl.txt");

  for(int j = 16; j < 33; j++){
    unsigned long long elem = 1<<j;
    int* k = new int[elem];

    for(int i = 0; i < elem; i++){
      k[i] = rand();
    }

    const std::chrono::_V2::steady_clock::time_point un_start = std::chrono::steady_clock::now();
    Unorganized<T> un = Unorganized<T>(k, elem);
    const std::chrono::_V2::steady_clock::time_point un_end = std::chrono::steady_clock::now();
    const std::chrono::duration<double> un_in{un_end - un_start};
    un_init << un_in.count() << '\n';

    const std::chrono::_V2::steady_clock::time_point fu_start = std::chrono::steady_clock::now();
    FullyOrganized<T> fu = FullyOrganized<T>(k, elem);
    const std::chrono::_V2::steady_clock::time_point fu_end = std::chrono::steady_clock::now();
    const std::chrono::duration<double> fu_in{fu_end - fu_start};
    fu_init << fu_in.count() << '\n';

    int a = 0;
    const std::chrono::_V2::steady_clock::time_point t1 = std::chrono::steady_clock::now();
    for(int j = 0; j < RAND_MAX; j++){
      for(T i = 0; i < elem; i++){
        if(un[i] < j) a++;
      }
    }
    const std::chrono::_V2::steady_clock::time_point t2 = std::chrono::steady_clock::now();
    const std::chrono::duration<double> un_branch{t2 - t1};
    un_comp << un_branch.count() << '\n';

    int c = 0;
    const std::chrono::_V2::steady_clock::time_point t5 = std::chrono::steady_clock::now();
    for(int j = 0; j < RAND_MAX; j++){
      for(T i = 0; i < elem; i++){
        if(fu[i] < j) c++;
      }
    }
    const std::chrono::_V2::steady_clock::time_point t6 = std::chrono::steady_clock::now();
    const std::chrono::duration<double> fu_branch{t6 - t5};
    fu_comp << fu_branch.count() << '\n';
    
    un_ttl << (un_in.count() + un_branch.count()) << '\n';
    fu_ttl << (fu_in.count() + fu_branch.count()) << '\n';
  }

  
  un_init.close();
  un_comp.close();
  un_ttl.close();
  fu_init.close();
  fu_comp.close();
  fu_ttl.close();
}