//
//  softmax_layer.hpp
//  framework
//
//  Created by Admin on 2019/12/2.
//  Copyright © 2019 Admin. All rights reserved.
//

#ifndef softmax_layer_hpp
#define softmax_layer_hpp

#include <stdio.h>

#include "network.hpp"
#include "gemm.hpp"


namespace framework {


struct SoftmaxLayer: Layer
{
    SoftmaxLayer(int batch_size,
                 int inputs,
                 int outputs):
    Layer(batch_size, inputs, outputs) {}
    
    float temp = 1;
    
    float *loss = nullptr;
    float *truth = nullptr;
    float *cost = nullptr;
    
    void init() override;
    
    void forward(float * input) override;
    void backward(float *net_delta, float *net_input) override;
    
    // do nothing when update
    void update(UpdateArgs arg) override {}
    
    ~SoftmaxLayer();
};






} // namespace framework

#endif /* softmax_layer_hpp */
