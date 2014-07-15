#include <cstdlib>
#include <iomanip>

#include "common.h"

using namespace std;

Timer::Timer(void)
{
  _start = clock();
}

Timer::~Timer(void)
{
  clock_t end = clock();
  clock_t diff = end - _start;

  cout << std::fixed << ((float)diff) / CLOCKS_PER_SEC << endl;
  cout.flush();
}

void print_rss(void)
{
  stringstream command;
  command << "top -pid " << getpid() << " -stats mem -l1 | tail -1 | tr -d '+-' | tr -d '\n'";
  system(command.str().c_str());

  cout << ",";
  cout.flush();
}

