#pragma once

#include <cstdlib>
#include <ctime>

class RandomAssign
{
public:

  RandomAssign() {
    srand((unsigned int)std::time(0));
  }

  RandomAssign(int seed)
  {
    srand(seed);
  }

  int next_int(int n)
  {
    return int(next_double() * n);
  }

  double next_double()
  {
    return double(rand()) / RAND_MAX;
  }

  int rand_priority()
  {
    return (rand() % 20) + 1;
  }
};