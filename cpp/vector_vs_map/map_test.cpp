#include <iostream>
#include <map>
#include <cstdlib>

#include <unistd.h>

using namespace std;

typedef int DataType;

int main(int argc, char* args[])
{
  if (argc < 2) return -1;

  cout << args[0] << endl;
  size_t count = atoi(args[1]);

  map<int, DataType> m;

  cout << "Populating, count = " << count << endl;

  for (size_t i = 0; i < count; i++) {
    m.insert(make_pair(i, rand()));
  }

  cout << "\tm.size() is " << m.size() << endl;

  cout << "Swaping to release extra space..." << endl;

  map<int, DataType>(m).swap(m);

  cout << "\tm.size() is " << m.size() << endl;

  cout << "Done" << endl;

  sleep(30);
}

