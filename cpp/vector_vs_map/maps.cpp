#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <functional>
#include <algorithm>

#include <cstdlib>

#include "common.h"

using namespace std;

typedef int DataType;
typedef map<DataType, DataType> Container;

void test(size_t containers_count, size_t items_count);

int main(int argc, char* args[])
{
  if (argc < 3) return -1;

  size_t containers_count = atoi(args[1]);
  size_t items_count = atoi(args[2]);

  cout << args[0] << "," << containers_count << "," << items_count << ",";
  cout.flush();

  {
    Timer timer;
    test(containers_count, items_count);
  }
}

void test(size_t containers_count, size_t items_count)
{
  vector<Container> v;
  v.resize(containers_count);

  for (size_t i = 0; i < containers_count * items_count; i++) {
    size_t num = rand();
    size_t index = num % containers_count;
    Container& iv = v[index];
    iv[num] = num;
  }

  for (size_t i = 0; i < containers_count; i++) {
    Container& iv = v[i];
    Container(iv).swap(iv);
  }

  print_rss();
}

