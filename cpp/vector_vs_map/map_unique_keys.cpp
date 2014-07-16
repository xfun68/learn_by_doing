#include <iostream>
#include <sstream>
#include <map>
#include <functional>
#include <algorithm>

#include <cstdlib>

#include "common.h"

using namespace std;

typedef int DataType;

void test(size_t count);

int main(int argc, char* args[])
{
  if (argc < 2) return -1;

  size_t count = atoi(args[1]) / 10 * 10;

  cout << args[0] << "," << count << ",";
  cout.flush();

  {
    Timer timer;
    test(count);
  }
}

void test(size_t count)
{
  map<int, DataType> m;

  for (size_t i = 0; i < count; i++) {
    int num = rand();
    m.insert(make_pair(num, num));
  }

  map<int, DataType>(m).swap(m);

  print_rss();
}

