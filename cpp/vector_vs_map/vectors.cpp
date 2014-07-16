#include <iostream>
#include <sstream>
#include <vector>
#include <functional>
#include <algorithm>

#include <cstdlib>

#include "common.h"

using namespace std;

typedef int DataType;

void test(size_t vectors_count, size_t items_count);

int main(int argc, char* args[])
{
  if (argc < 3) return -1;

  size_t vectors_count = atoi(args[1]);
  size_t items_count = atoi(args[2]);

  cout << args[0] << "," << vectors_count << "," << items_count << ",";
  cout.flush();

  {
    Timer timer;
    test(vectors_count, items_count);
  }
}

void test(size_t vectors_count, size_t items_count)
{
  vector<vector<DataType> > v;
  v.resize(vectors_count);

  for (size_t i = 0; i < vectors_count * items_count; i++) {
    size_t num = rand();
    size_t index = num % vectors_count;
    vector<DataType>& iv = v[index];

    size_t value = num % items_count;
    vector<DataType>::iterator iter = lower_bound(iv.begin(), iv.end(), value, less<int>());
    if (iter == iv.end() || (*iter) != value) {
      iv.push_back(value);
      sort(iv.begin(), iv.end(), less<int>());
    }
  }

  for (size_t i = 0; i < vectors_count; i++) {
    vector<DataType>& iv = v[i];
    vector<int>(iv).swap(iv);
  }

  print_rss();
}

