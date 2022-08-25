//
//  NeuralNetwork.cpp
//  Perceptron
//
//  Created by Guillaume Sylvain on 2022-05-26.
//

#include "NeuralNetwork.hpp"


//--------------------------------------------------------------
//NeuralNetwork::NeuralNetwork(int input_nodes, int hidden_nodes, int output_nodes){
//    input_nodes_ = input_nodes;
//    hidden_nodes_ = hidden_nodes;
//    output_nodes_ = output_nodes;
//    
//    weights_ih = new Matrix(hidden_nodes_, input_nodes_);
//    weights_ho = new Matrix(output_nodes_, hidden_nodes_);
//    
//    bias_h = new Matrix(hidden_nodes_, 1);
//    bias_o = new Matrix(output_nodes_, 1);
//}

//--------------------------------------------------------------
//std::vector<float> NeuralNetwork::feedforward(std::vector<float> input_vec){
//    
//    // Generating the Hidden Output
//    Matrix * inputs = Matrix::fromVector(input_vec);
//    Matrix * hidden = Matrix::multiply(weights_ih, inputs);
//    hidden->add(bias_h);
//    // activation function
//    //        hidden->map(gs_sigmoid);
//    //hidden->map();
//    
//    // Generate output's output
//    Matrix * output = Matrix::multiply(weights_ho, hidden);
//    //        output->map(gs_sigmoid);
//    //output->map();
//    
//    return output->toVector();
//}

//--------------------------------------------------------------
//void NeuralNetwork::train(std::vector< float > inputs, std::vector< float > targets_vec){
//
//    std::vector< float > outputs_vec = feedforward(inputs);
//
//    // convert vectors to Matrix
//    Matrix *outputs;
//    outputs = Matrix::fromVector(outputs_vec);
//
//    Matrix *targets;
//    targets = Matrix::fromVector(targets_vec);
//
//    // calculate error
//    // ERROR = TARGETS - OUTPUTS
//
//    Matrix *output_error;
//    output_error = Matrix::subtract(targets, outputs);
//
//    // calcule the hidden layer error
//    // Wheigts Hidden Output Transpose
//    Matrix *who_t = Matrix::transpose(weights_ho);
//    Matrix *hidden_errors = Matrix::multiply(who_t, output_error);
//
//
//    outputs->print();
//    targets->print();
//    output_error->print();
//
//}







