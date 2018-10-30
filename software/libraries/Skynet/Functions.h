//
// Created by trystanmay on 10/30/18.
//

#ifndef SKYNET_FUNCTIONS_H
#define SKYNET_FUNCTIONS_H

#include "Layer.h"

double relu (const double &input, const bool &derivative);
double relu (const double &input);

double sigmoid (const double &input, const bool &derivative);
double sigmoid (const double &input);

double softmax (const double &input, const double &sum, const bool &derivative);
double softmax (const double &input, const double &sum);

#endif //SKYNET_FUNCTIONS_H
