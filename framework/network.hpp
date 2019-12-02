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

struct Layer;

struct Network{
    
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
    
    void inference(){}
    
};


struct Image{
    int w;
    int h;
    int c;
    float *data;
};


struct node{
    void *val;
    struct node *next;
    struct node *prev;
};


struct List{
    int size;
    node *front;
    node *end;
};





struct Layer{
    
    int batch_size;
    float *output;
    float *delta;
    bool stopbackward;
    
    bool is_init = false;
  
    virtual ~Layer(){};
        
    virtual void forward(float * input){}
    
    virtual void backward(float *net_delta, float *net_input){}
    
    virtual void update(UpdateArgs arg){}
    
};

enum ACTIVATION{
    LOGISTIC,
    RELU
};

struct ConnectedLayer: Layer {
    
    int inputs;
    int outputs;
    
    bool is_biases = false;
    bool is_training = false;
    
    Network *net;
    
    ACTIVATION activation;
    
    float * weight = nullptr;
    float * biases = nullptr;
    float * delta = nullptr;
    float * weight_update = nullptr;
    float * bias_update = nullptr;
    float * output = nullptr;
    
    ConnectedLayer(int batch_size,
                   int inputs,
                   int outputs,
                   ACTIVATION activation):
    inputs(inputs), outputs(outputs), activation(activation) {
        this->batch_size = batch_size;
    }
    
    void init();
    
    void forward(float * input) override;
    
    void backward(float *net_delta, float *net_input) override;
    
    void update(UpdateArgs arg) override;
    
    ~ConnectedLayer()
    {}
    
};




} // namespace framework

#endif /* network_hpp */
