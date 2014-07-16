#include <iostream>
#include <sstream>
#include <map>
#include <functional>
#include <algorithm>

#include <cstdlib>

#include "common.h"

using namespace std;

typedef int DataType;

void test(size_t count, size_t keys_count);

int main(int argc, char* args[])
{
  if (argc < 2) return -1;

  size_t count = atoi(args[1]) / 10 * 10;
  size_t keys_count = count;

  if (argc >= 3) {
    keys_count = atoi(args[2]);
  }

  cout << args[0] << "," << count << ",";
  cout.flush();

  {
    Timer timer;
    test(count, keys_count);
  }
}

void test(size_t count, size_t keys_count)
{
  map<int, DataType> m;

  for (size_t i = 0; i < count; i++) {
    size_t value = rand();
    int key = value % keys_count;
    m[key] = value;
  }

  map<int, DataType>(m).swap(m);

  print_rss();
}

