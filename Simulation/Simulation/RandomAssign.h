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
    int probability = (rand() % 10) + 1;
    if (probability >= 4)
    {
      return (rand() % 10) + 1;
    }
    if (probability >= 2)
    {
      return (rand() % 5) + 11;
    }
    if (probability == 1)
    {
      return (rand() % 5) + 16;
    }
    return 1;
  }
};