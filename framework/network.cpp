//
//  network.cpp
//  framework
//
//  Created by Admin on 2019/12/2.
//  Copyright © 2019 Admin. All rights reserved.
//

#include "network.hpp"

namespace framework{


void Network::forward_network(float *input)
{
    Layer * curr_layer;
    for(int i=0; i < layer.size(); i++)
    {
        curr_layer = layer[i];
        if(curr_layer->delta)
        {
            fill_cpu(curr_layer->outputs * curr_layer->batch_size, 0, curr_layer->delta, 1);
        }
        curr_layer->forward(input);
        input = curr_layer->output;
    }
}


void Network::backward_network(float *gt_result)
{
    Layer * curr_layer;
    Layer * prev_layer;
    for(unsigned long i=layer.size()-1; i >= 0; i--)
    {
        curr_layer = layer[i];
        if(curr_layer->stopbackward)
        {
            break;
        }
        if(i == 0)
        {
            
        }
        else if(curr_layer->is_final)
        {
            
        }
        else
        {
            prev_layer = layer[i-1];
            float *net_input = prev_layer->output;
            float *net_delta = prev_layer->delta;
            curr_layer->backward(net_delta, net_input);
        }
        
    }
}


void Network::update_network(UpdateArgs arg)
{
    Layer * curr_layer;
    for(int i = 0; i < layer.size(); i++)
    {
        curr_layer = layer[i];
        
    }
}


void Network::train_onestep(float *input, float *gt_result, UpdateArgs arg)
{
    forward_network(input);
    backward_network(gt_result);
    update_network(arg);
}


} //namespace framework
