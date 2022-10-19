#include "FractalImage.h"

#include<cmath>
#include <iostream>
#include "Mandlebrot.h"
#include <memory>
#include <vector>


// The best image scope
//static const double _xMin = -2;
//static const double _xMax = 2;
//static const double _yMin = -1.2;
//static const double _yMax = 2.8;
static const double _xMin = -1.5;
static const double _xMax = 0.5;
static const double _yMin = -1;
static const double _yMax = 1;


void FractalImage::createImage(int width, int height, std::string name)
{
    // I just don't want to create such an object on a stack
    std::unique_ptr<Bitmap::BitmapImage> testImg(new Bitmap::BitmapImage(width, height));

    calculateImage(*testImg.get());

    if(testImg.get()->write(name) == false)
        std::cout << "Image creation failed!";

    return;
}


void FractalImage::calculateImage(Bitmap::BitmapImage &image)
{
    Bitmap::ImagePoint coords(0, 0);
    std::vector<std::vector<Bitmap::ImagePoint>> histogram(Mandlebrot::MAX_ITERATIONS);
    double xStep = (_xMax - _xMin) / image.width();
    double yStep = (_yMax - _yMin) / image.height();
    int iterations;

    auto incrementX = [&](){ coords.setX(coords.x() + 1); };
    auto incrementY = [&](){ coords.setY(coords.y() + 1); };

    for(double x = _xMin; x < _xMax; x += xStep, incrementX())
    {
        coords.setY(0);
        for(double y = _yMin; y < _yMax; y += yStep, incrementY())
        {
            iterations = Mandlebrot::getIterations(x, y);
            if(iterations == Mandlebrot::MAX_ITERATIONS)
                continue;
            histogram[iterations].push_back(coords);
        }
    }


    int totalHistogramSize{0};

    for(auto &iteration: histogram)
        totalHistogramSize += iteration.size();

    double brightness{0};
    
    for(auto &iteration: histogram)
    {
        brightness += (double)iteration.size() / totalHistogramSize;
        uint8_t brightnessFixed = pow(256, brightness);

        for(auto &point: iteration)
            image.setPixel(point, Bitmap::ImageRGBColor(0, brightnessFixed, 0));
    }

    return;
}

