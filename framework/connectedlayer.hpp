//
//  connectedlayer.hpp
//  framework
//
//  Created by Admin on 2019/12/3.
//  Copyright © 2019 Admin. All rights reserved.
//

#ifndef connectedlayer_hpp
#define connectedlayer_hpp

#include <stdio.h>

#include "network.hpp"


namespace framework {


struct ConnectedLayer: Layer {

    bool is_biases = false;
    
    Network *net;
    ACTIVATION activation;
    
    float * weight = nullptr;
    float * biases = nullptr;
    float * weight_update = nullptr;
    float * bias_update = nullptr;
    
    ConnectedLayer(int batch_size,
                   int inputs,
                   int outputs,
                   ACTIVATION activation):
                   Layer(batch_size, inputs, outputs),
                   activation(activation) {}
    
    void init() override;
    void forward(float * input) override;
    void backward(float *net_delta, float *net_input) override;
    void update(UpdateArgs arg) override;
    
    ~ConnectedLayer()
    {}
    
};



} // namespace framework

#endif /* connectedlayer_hpp */
