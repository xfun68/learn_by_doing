#include <iostream>
#include <sstream>
#include <vector>
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
  vector<DataType> v;
  v.reserve(count);

  for (size_t i = 0; i < count; i++) {
    v.push_back(rand());
    sort(v.begin(), v.end(), less<int>());
  }

  vector<int>(v).swap(v);

  print_rss();
}

