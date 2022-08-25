//
//  NeuralNetwork.hpp
//  Perceptron
//
//  Created by Guillaume Sylvain on 2022-05-26.
//

#ifndef NeuralNetwork_hpp
#define NeuralNetwork_hpp

//#include <ofMain.h>
#include "Matrix.h"

//--------------------------------------------------------------
static float sigmoid(float x){
    return 1. / (1. + exp(-x));
}

// derived sigmoid
static float dSigmoid(float y){
    //return sigmoid(x) * (1 - sigmoid(x));
    return y * (1.-y);
}
//--------------------------------------------------------------

class NeuralNetwork{
public:
    
    int input_nodes_, hidden_nodes_, output_nodes_;
    Matrix *weights_ih, *weights_ho, *bias_h, *bias_o;
    float learningRate_;
    
    NeuralNetwork(int input_nodes, int hidden_nodes, int output_nodes){
        input_nodes_ = input_nodes;
        hidden_nodes_ = hidden_nodes;
        output_nodes_ = output_nodes;
        
        weights_ih = new Matrix(hidden_nodes_, input_nodes_);
        weights_ho = new Matrix(output_nodes_, hidden_nodes_);
        
        bias_h = new Matrix(hidden_nodes_, 1);
        bias_o = new Matrix(output_nodes_, 1);
        
        learningRate_ = 0.1;
    }
    
    std::vector<float> feedforward(std::vector<float> input_vec){
        
        // Generating the Hidden Output
        Matrix * inputs = Matrix::fromVector(input_vec);
        Matrix * hidden = Matrix::multiply(weights_ih, inputs);
        hidden->add(bias_h);
        // activation function
        hidden->map(sigmoid);
    
        
        // Generate output's output
        Matrix * output = Matrix::multiply(weights_ho, hidden);
        output->add(bias_o);
        output->map(sigmoid); 
        
        return output->toVector();
    }
    
    void train(std::vector<float> input_vec, std::vector<float> targets_vec){
        
//       ### REDONDANCE ###
        // Generating the Hidden Output
        Matrix * inputs = Matrix::fromVector(input_vec);
        Matrix * hidden = Matrix::multiply(weights_ih, inputs);
        hidden->add(bias_h);
        // activation function
        hidden->map(sigmoid);
        
        // Generate output's output
        Matrix * outputs = Matrix::multiply(weights_ho, hidden);
        outputs->add(bias_o);
        outputs->map(sigmoid);
        
        //std::vector< float > outputs_vec = feedforward(input_vec);
        
        // convert vectors to Matrix
        Matrix *targets;
        targets = Matrix::fromVector(targets_vec);
        
        //Matrix *outputs;
        //outputs = Matrix::fromVector(outputs_vec);
        
        // calculate error
        // ERROR = TARGETS - OUTPUTS
        Matrix *output_errors;
        output_errors = Matrix::subtract(targets, outputs);
        
        //Calculate gradient
        Matrix * gradients = Matrix::map(outputs, dSigmoid);
        gradients->multiply(output_errors);
        gradients->multiply(learningRate_);
       
        
        // Calculate deltas
        Matrix * hidden_T = Matrix::transpose(hidden);
        Matrix * weight_ho_deltas = Matrix::multiply(gradients, hidden_T);
        
        // Adjust the weights by deltas
        weights_ho->add(weight_ho_deltas);
        // Adjust the bias by its  deltas
        bias_o->add(gradients);
        
        // calcule the hidden layer error
        Matrix *who_t = Matrix::transpose(weights_ho);  // Wheigts Hidden Output Transpose
        //who_t->print();
        Matrix *hidden_errors = Matrix::multiply(who_t, output_errors);
        
        // calculate hidden gradient
        Matrix * hidden_gradient = Matrix::map(hidden, dSigmoid);
        hidden_gradient->multiply(hidden_errors);
        hidden_gradient->multiply(learningRate_);
        
        // Calculate input->hidden deltas
        Matrix * inputs_T = Matrix::transpose(inputs);
        Matrix * weight_ih_deltas = Matrix::multiply(hidden_gradient, inputs_T);
        
        weights_ih->add(weight_ih_deltas);
        // Adjust the bias by its  deltas
        bias_h->add(hidden_gradient);
        
        //outputs->print();
        //targets->print();
        //output_error->print();
    }
};

#endif /* NeuralNetwork_hpp */
