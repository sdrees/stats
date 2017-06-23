/*################################################################################
  ##
  ##   Copyright (C) 2011-2017 Keith O'Hara
  ##
  ##   This file is part of the StatsLib C++ library.
  ##
  ##   StatsLib is free software: you can redistribute it and/or modify
  ##   it under the terms of the GNU General Public License as published by
  ##   the Free Software Foundation, either version 2 of the License, or
  ##   (at your option) any later version.
  ##
  ##   StatsLib is distributed in the hope that it will be useful,
  ##   but WITHOUT ANY WARRANTY; without even the implied warranty of
  ##   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  ##   GNU General Public License for more details.
  ##
  ################################################################################*/

// g++-mp-5 -O2 -Wall -std=c++11 -I./../../ -I/opt/local/include incomplete_gamma_test.cpp -o incomplete_gamma.test -framework Accelerate

#include <math.h>
#include "armadillo"
#include "stats.hpp"

int main()
{
    double ret_val;
    double x = 2;
    double shape = 2;
    double scale = 2;
    stats::incomplete_gamma(shape,x/scale,ret_val);

    std::cout << "incomplete_gamma: " << ret_val << std::endl;

    return 0;
}