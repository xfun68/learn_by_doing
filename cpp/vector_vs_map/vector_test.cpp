#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

#include <cstdlib>

#include <unistd.h>

using namespace std;

typedef int DataType;

void myfunction (int i) {  // function:
  std::cout << ' ' << i;
}

int main(int argc, char* args[])
{
  if (argc < 2) return -1;

  cout << args[0] << endl;
  size_t count = atoi(args[1]);

  vector<DataType> v;

  cout << "Populating, count = " << count << endl;

  for (size_t i = 0; i < count; i++) {
    v.push_back(rand());
  }

  cout << "\tv.capacity() is " << v.capacity() << endl;
  cout << "\tv.size() is " << v.size() << endl;

  cout << "Swaping to release extra space..." << endl;

  vector<int>(v).swap(v);

  cout << "\tv.capacity() is " << v.capacity() << endl;

  cout << "Sorting..." << endl;
  sort(v.begin(), v.end(), less<int>());
  cout << "Done" << endl;

  // for_each(v.begin(), v.end(), myfunction);
  // cout << flush;

  sleep(5);
}

