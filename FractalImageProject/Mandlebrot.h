#ifndef MANDLEBROT_H
#define MANDLEBROT_H


class Mandlebrot
{
public:
    static const int MAX_ITERATIONS = 512;

    static int getIterations(double x, double y);
};

#endif
