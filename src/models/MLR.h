//
// Created by yujie on 2020-04-27.
//

#ifndef DATA_MLR_H
#define DATA_MLR_H

#include <blaze/math/DynamicVector.h>
#include <random>

using namespace blaze;


class MLR {

    int dim;

    DynamicVector<float,rowVector> W;

    float b;

public:

    MLR(int dim_init): dim(dim_init){

        std::random_device rd;
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<> dis(0.0, 1.0);


        for(int i=0; i< dim_init; i++){

            W[i] = dis(gen);
        }

        b = dis(gen);


    };




};


#endif //DATA_MLR_H
