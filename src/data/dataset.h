//
// Created by yujie on 2020-04-20.
//

#ifndef DATA_DATASET_H
#define DATA_DATASET_H
#include <blaze/math/DynamicMatrix.h>
#include <vector>

#include <utility>

using namespace blaze;

class dataset {

    DynamicMatrix<float> train_set;
    DynamicMatrix<float> test_set;
    float test_ratio;
    std::vector<float> X_scalers_avg;
    std::vector<float> X_scalers_std;
    std::vector<float> y_scalers_avg;
    std::vector<float> y_scalers_std;


public:
    dataset (DynamicMatrix<float> train_set_init, DynamicMatrix<float> test_set_init, float test_ratio_init):
    train_set(std::move(train_set_init)), test_set(std::move(test_set_init)), test_ratio(test_ratio_init){
    }

    void set_train_set(DynamicMatrix<float>);

    void set_test_set(DynamicMatrix<float>);

    DynamicMatrix<float> get_train();

    DynamicMatrix<float> get_test();

    void set_X_scaler(float x_scaler_avg, float x_scaler_std);

    void set_y_scaler(float y_scaler_avg, float y_scaler_std);

    std::vector<float> get_X_mean();

    std::vector<float> get_X_std();

    std::vector<float> get_y_mean();

    std::vector<float> get_y_std();







};


#endif //DATA_DATASET_H
