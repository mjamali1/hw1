#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{

  ULListStr dat;

  dat.push_back("1");
  dat.push_front("2");

  std::cout << dat.get(0) << " " << dat.get(1) << std::endl;


}
