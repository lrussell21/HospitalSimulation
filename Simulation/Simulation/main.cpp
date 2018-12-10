#include <iostream>
#include <string>
#include "Simulator.h"
#include "RandomAssign.h"

int main() {
  int docs, nurses, runtime, patRate, minTime, maxTime;
  std::string askOutput;
  bool output = false;

  std::cout << "Please enter the amount of patients per hour[patients/hour]: ";
  std::cin >> patRate;
  std::cout << "Please enter the amount of doctors: ";
  std::cin >> docs;
  std::cout << "Please enter the amount of nurses: ";
  std::cin >> nurses;
  std::cout << "Please enter the min treatment time [mins]: ";
  std::cin >> minTime;
  std::cout << "Please enter the max treatment time [mins]: ";
  std::cin >> maxTime;
  std::cout << "Please enter the total simulation time [hours]: ";
  std::cin >> runtime;
  runtime *= 60;

  std::cout << "Text Output?[Y]: ";
  std::cin >> askOutput;
  if (askOutput == "Y" || askOutput == "y")
  {
    output = true;
  }

  Simulator sim(docs, nurses, runtime, patRate, minTime, maxTime, output);
  sim.run();
  return 0;
}