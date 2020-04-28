//
// Created by yujie on 2020-04-20.
//

#include "dataset.h"

#include <utility>

void dataset::set_train_set(DynamicMatrix<float> new_train_set){

    train_set = std::move(new_train_set);

}

void dataset::set_test_set(DynamicMatrix<float> new_test_set){

    test_set = std::move(new_test_set);

}

DynamicMatrix<float> dataset::get_train() {
    return train_set;
}

DynamicMatrix<float> dataset::get_test() {
    return test_set;
}

void dataset::set_X_scaler(float x_scaler_avg, float x_scaler_std) {
    X_scalers_avg.push_back(x_scaler_avg);
    X_scalers_std.push_back(x_scaler_std);
}

void dataset::set_y_scaler(float y_scaler_avg, float y_scaler_std) {
    y_scalers_avg.push_back(y_scaler_avg);
    y_scalers_std.push_back(y_scaler_std);

}

std::vector<float> dataset::get_X_mean(){
    return X_scalers_avg;

};

std::vector<float> dataset::get_X_std(){
    return X_scalers_std;

};

std::vector<float> dataset::get_y_mean(){
    return y_scalers_avg;

};

std::vector<float> dataset::get_y_std(){
    return y_scalers_std;

};
