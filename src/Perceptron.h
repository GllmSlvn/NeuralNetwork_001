//
//  Perceptron.h
//  Perceptron
//
//  Created by Guillaume Sylvain on 2022-05-20.
//

#ifndef Perceptron_h
#define Perceptron_h

class Perceptron{
public:
    
    std::vector<float> weights;
    
    Perceptron(){
        for(int i = 0; i < 2; i++){
            weights.push_back(ofRandom(-1,1));
        }
    }
    
    int sign(float n){
        if(n >= 0) {
            return 1;
        } else {
            return -1;
        }
    }
    
     
    int guest(std::vector<float> inputs){
        
        float sum = 0;
        for(int i=0; i < weights.size(); i++){
            sum += inputs[i] * weights[i];
        }
        return sign(sum);
    }
};

#endif /* Perceptron_h */
