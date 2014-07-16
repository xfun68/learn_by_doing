#ifndef _COMMON_H
#define _COMMON_H

#include <iostream>
#include <sstream>

#include <unistd.h>


class Timer
{
  public:
    Timer(void);
    ~Timer(void);

  private:
    clock_t _start;
};

void print_rss(void);

#endif // _COMMON_H

