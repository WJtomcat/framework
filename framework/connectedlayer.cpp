//
//  connectedlayer.cpp
//  framework
//
//  Created by Admin on 2019/12/3.
//  Copyright © 2019 Admin. All rights reserved.
//

#include "connectedlayer.hpp"



namespace framework {


void ConnectedLayer::init()
{
    int weights = inputs * outputs;
    weight = new float[weights];
    output = new float[batch_size * outputs];
    
    std::default_random_engine generator;
    std::uniform_real_distribution<float> distribution(-1.0, 1.0);
    for (int i = 0; i < weights; i++)
    {
        weight[i] = distribution(generator);
    }
    
    if(is_biases)
    {
        biases = new float[outputs];
    }
    
    if(is_training)
    {
        weight_update = new float[weights];
        delta = new float[outputs * batch_size];
        if(is_biases)
        {
            bias_update = new float[outputs];
        }
    }
}


void ConnectedLayer::forward(float * input)
{
    fill_cpu(outputs*batch_size, 0, output, 1);
    int m = batch_size;
    int k = inputs;
    int n = outputs;
    float *a = input;
    float *b = weight;
    float *c = output;
    gemm(0, 1, m, n, k, 1, a, k, b, k, 1, c, n);
}


void ConnectedLayer::backward(float *net_delta, float *net_input)
{
    int m = outputs;
    int k = batch_size;
    int n = inputs;
    float *a = delta;
    float *b = net_input;
    float *c = weight_update;
    gemm(1, 0, m, n, k, 1, a, m, b, n, 1, c, n);
    
    m = batch_size;
    k = outputs;
    n = inputs;
    a = delta;
    b = weight;
    c = net_delta;
    gemm(0, 0, m, n, k, 1, a, k, b, n, 1, c, n);
}


void ConnectedLayer::update(UpdateArgs arg)
{
    float learning_rate = arg.learning_rate;
    float momentum = arg.momentum;
    float decay = arg.decay;
    int batch_size = arg.batch_size;
    axpy_cpu(inputs*outputs, -decay*batch_size, weight, 1, weight_update, 1);
    axpy_cpu(inputs*outputs, learning_rate/batch_size, weight_update, 1, weight, 1);
    scal_cpu(inputs*outputs, momentum, weight_update, 1);
}



} // namespace framework
