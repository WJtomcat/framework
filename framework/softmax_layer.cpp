//
//  softmax_layer.cpp
//  framework
//
//  Created by Admin on 2019/12/2.
//  Copyright © 2019 Admin. All rights reserved.
//

#include "softmax_layer.hpp"

namespace framework {


void SoftmaxLayer::init()
{
    output = new float[outputs * batch_size];
    if (is_training)
    {
        delta = new float[outputs * batch_size];
        loss = new float[outputs * batch_size];
        cost = new float;
    }
}


void SoftmaxLayer::forward(float * input)
{
    if (not is_training)
    {
        softmax_cpu(input, inputs, batch_size, temp, output);
    }
    else
    {
        softmax_x_ent_cpu(inputs*batch_size, output, truth, delta, loss);
    }
}


void SoftmaxLayer::backward(float *net_delta, float *net_input)
{
    axpy_cpu(inputs*batch_size, 1, delta, 1, net_delta, 1);
}


SoftmaxLayer::~SoftmaxLayer()
{
    delete cost;
    delete []loss;
    delete []truth;
    delete []output;
}


} // namespace framework
