//
//  network.hpp
//  framework
//
//  Created by Admin on 2019/12/2.
//  Copyright © 2019 Admin. All rights reserved.
//

#ifndef network_hpp
#define network_hpp

#include <stdio.h>
#include <vector>
#include <cmath>
#include <random>
#include <iostream>

#include "gemm.hpp"

namespace framework {


struct UpdateArgs{
    int batch_size;
    float learning_rate;
    float momentum;
    float decay;
};


struct Layer{
    
    // define the input size / output size / batch size of the layer
    // Layer don't own the input data
    int inputs;
    int outputs;
    int batch_size;
    
    // define the output pointer and delta pointer of the layer
    float *output; //size outputs
    float *delta; //size outputs
    
    // define some flags
    bool is_training;
    bool stopbackward;
    bool is_init = false;
    bool is_final;
    
    explicit Layer(int batch_size, int inputs, int outputs):
                   inputs(inputs),
                   outputs(outputs),
                   batch_size(batch_size) {}
    
  
    virtual ~Layer(){}
    
    // you need first init the layer before you use it.
    virtual void init(){}
    
    // virtual forward of the layer.
    virtual void forward(float * input){}
    
    virtual void backward(float *net_delta, float *net_input){}
    
    // do nothing by default
    virtual void update(UpdateArgs arg){}
    
};


struct Network{
    
    int inputs;
    int outputs;
    
    float * input;
    float * delta;
    
    int batch_size;
    int layers;
    
    std::vector<Layer*> layer;
    
    bool is_training;
    
    void forward_network(float *input);
    
    void backward_network(float *gt_result);
    
    void update_network(UpdateArgs arg);
    
    void train_onestep(float *input, float *gt_result, UpdateArgs arg);
    
    void inference();
    
};


enum ACTIVATION{
    LOGISTIC,
    RELU
};

using idx_t = int64_t;


} // namespace framework

#endif /* network_hpp */
