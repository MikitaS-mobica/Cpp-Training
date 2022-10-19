#include "Mandlebrot.h"

#include <complex>


int Mandlebrot::getIterations(double x, double y)
{
    std::complex<double> z = 0;
    std::complex<double> c(x, y);
    int iterations;

    for(iterations = 0; iterations < MAX_ITERATIONS; iterations++)
    {
        z = z*z + c;

        if(abs(z) > 2)
            break;
    }

    return iterations;
}
