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

/*
 * cdf of the uniform distribution
 *
 * Keith O'Hara
 * 01/03/2016
 *
 * This version:
 * 06/14/2017
 */

//
// single input

inline
double
punif_int(double x, double* a_inp, double* b_inp, bool log_form)
{
    double a = (a_inp) ? *a_inp : 0;
    double b = (b_inp) ? *b_inp : 1;
    //
    if (x <= a) {
        return 0;
    }

    if (x >= b) {
        return 1;
    }
    //
    double ret = (x-a) / (b-a);

    if (log_form) {
        ret = std::log(ret);
    }
    //
    return ret;
}

inline
double
punif(double x)
{
    return punif_int(x,NULL,NULL,false);
}

inline
double
punif(double x, bool log_form)
{
    return punif_int(x,NULL,NULL,log_form);
}

inline
double
punif(double x, double a, double b)
{
    return punif_int(x,&a,&b,false);
}

inline
double
punif(double x, double a, double b, bool log_form)
{
    return punif_int(x,&a,&b,log_form);
}

//
// vector input

inline
arma::vec
punif_int(const arma::vec& x, double* a_inp, double* b_inp, bool log_form)
{
    double a = (a_inp) ? *a_inp : 0;
    double b = (b_inp) ? *b_inp : 1;
    //
    arma::vec ret = (x-a) / (b-a);

    ret.elem(arma::find( ret < 0 )).zeros();
    ret.elem(arma::find( ret > 1 )).ones();

    if (log_form) {
        ret = arma::log(ret);
    }
    //
    return ret;
}

inline
arma::vec
punif(const arma::vec& x)
{
    return punif_int(x,NULL,NULL,false);
}

inline
arma::vec
punif(const arma::vec& x, bool log_form)
{
    return punif_int(x,NULL,NULL,log_form);
}

inline
arma::vec
punif(const arma::vec& x, double a, double b)
{
    return punif_int(x,&a,&b,false);
}

inline
arma::vec
punif(const arma::vec& x, double a, double b, bool log_form)
{
    return punif_int(x,&a,&b,log_form);
}