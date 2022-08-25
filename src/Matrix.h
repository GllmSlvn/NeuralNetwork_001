//
//  Matrix.h
//  Perceptron
//
//  Created by Guillaume Sylvain on 2022-05-24.
//

#ifndef Matrix_h
#define Matrix_h

class Matrix{
public:
    
    int rows_, cols_;
    std::vector<std::vector<float>> data_;
    
    Matrix(int rows, int cols){
        rows_ = rows;
        cols_ = cols;
        
        // initialise avec une valeur aléatoire
        for(int i=0; i<rows_; i++) {
            std::vector<float> v;
            data_.push_back(v);
            for(int j=0; j<cols_; j++){
                data_[i].push_back(ofRandom(-1.,1.));
            }
        }
    }
    
    void add(float n){
        for(int i=0; i<rows_; i++) {
            for(int j=0; j<cols_; j++){
                data_[i][j] += n;
            }
        }
    }
    
    void add(Matrix *m){
        for(int i=0; i<rows_; i++) {
            for(int j=0; j<cols_; j++){
                data_[i][j] += m->data_[i][j];
            }
        }
    }
    
    void multiply(float n){
        for(int i=0; i<rows_; i++) {
            for(int j=0; j<cols_; j++){
                data_[i][j] *= n;
            }
        }
    }
    
    std::vector< float > toVector(){
        std::vector< float > vec;
        
        for(int i=0; i<rows_; i++) {
            for(int j=0; j<cols_; j++){
                vec.push_back(data_[i][j]);
            }
        }
        return vec;
    }
    
    // STATIC FUNCTION's
    static Matrix * fromVector(std::vector< float > vec){
        Matrix * m = new Matrix(vec.size(), 1);
        for(int i=0; i<vec.size(); i++){
            m->data_[i][0] = vec[i];
        }
        return m;
    }
    
    static Matrix * subtract(Matrix *a, Matrix *b){
         
        Matrix *result = new Matrix(a->rows_, a->cols_);
        for(int i=0; i<result->rows_; i++) {
            for(int j=0; j<result->cols_; j++){
                result->data_[i][j] = a->data_[i][j] - b->data_[i][j];
            }
        }
        return result;
    }
    
    // Matrix product
    void multiply(Matrix *m){
        for(int i=0; i < rows_; i++) {
            for(int j=0; j < cols_; j++){
                data_[i][j] *= m->data_[i][j];
            }
        }
        
    }
    
    
    static Matrix * multiply(Matrix *a, Matrix *b){
    
        if(a->cols_ != b->rows_){
            ofLogNotice("Columns of A must match rows of B") << a->cols_ << " - " << b->rows_;
        }
        else {
            
            Matrix *result = new Matrix(a->rows_, b->cols_);
            
            for(int i=0; i < result->rows_; i++) {
                for(int j=0; j < result->cols_; j++){
                    // dot product of values in col
                    float sum = 0;
                    for(int k=0; k < a->cols_; k++){
                        sum += a->data_[i][k] * b->data_[k][j];
                    }
                    //matrix_[i][j] *= m->matrix_[i][j];
                    result->data_[i][j] = sum;
                }
            }
            return result;
        }
    }
    
    static Matrix * transpose(Matrix * m){
        
        Matrix * result = new Matrix(m->cols_, m->rows_);
        
        for(int i=0; i < m->rows_; i++) {
            for(int j=0; j < m->cols_; j++){
                result->data_[j][i] = m->data_[i][j];
            }
        }
        return result;
    }
    
    void map( float (*func)(float) ){
        for(int i=0; i < rows_; i++) {
            for(int j=0; j < cols_; j++){
                float val = data_[i][j];
                data_[i][j] = func( val );
            }
        }
    }
    
    static Matrix * map(Matrix * matrix, float (*func)(float)){
        Matrix * result = new Matrix(matrix->rows_, matrix->cols_);
        for(int i=0; i < matrix->rows_; i++) {
            for(int j=0; j < matrix->cols_; j++){
                float val = matrix->data_[i][j];
                result->data_[i][j] = func( val );
            }
        }
        return result;
    }
    
    void print(){
        for(int i=0; i < rows_; i++) {
            for(int j=0; j < cols_; j++){
                cout << data_[i][j] << " ";
            }
            cout << endl;
        }
        cout << "FIN" << endl;
    }
};

#endif /* Matrix_h */
