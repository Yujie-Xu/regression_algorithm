//
// Created by yujie on 2020-04-16.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <boost/algorithm/string.hpp>
#include "CSV_reader.h"
#include "dataset.h"
#include <iomanip>
#include <blaze/math/DynamicMatrix.h>
#include <blaze/math/Columns.h>

using namespace std;
using blaze::DynamicMatrix;


int main()
{

    // Creating an object of CSVWriter
    CSV_reader reader("/home/yujie/project/regression_algorithm/data/raw/housing.data");


    // Get the data from CSV File
    std::vector<std::vector<std::string> > dataList = reader.getData();


    // set train and test ratio
    float test_ratio = 0.1;

    int test_size = int(test_ratio*dataList.size());
    int train_size = dataList.size() - test_size;

    cout << "train_size is "<< train_size << endl;
    cout << "test_size is "<< test_size << endl;

    cout << dataList.size() <<endl;

    DynamicMatrix<float> A(dataList.size(), 14);

    size_t row = 0;
    size_t col = 0;



//    CRIM: Per capita crime rate by town
//    ZN: Proportion of residential land zoned for lots over 25,000 sq. ft
//    INDUS: Proportion of non-retail business acres per town
//    CHAS: Charles River dummy variable (= 1 if tract bounds river; 0 otherwise)
//    NOX: Nitric oxide concentration (parts per 10 million)
//    RM: Average number of rooms per dwelling
//    AGE: Proportion of owner-occupied units built prior to 1940
//    DIS: Weighted distances to five Boston employment centers
//    RAD: Index of accessibility to radial highways
//    TAX: Full-value property tax rate per $10,000
//    PTRATIO: Pupil-teacher ratio by town
//    B: 1000(Bk — 0.63)², where Bk is the proportion of [people of African American descent] by town
//    LSTAT: Percentage of lower status of the population
//    MEDV: Median value of owner-occupied homes in $1000s

    vector<string> column_names({"crime", "zn",
    "indus", "chas", "nox", "rm", "age", "dis", "rad", "tax",
    "ptratio", "bk", "lstat", "medv"});


//    dataList.insert(dataList.begin(), column_names);

    // Print the content of row by row on screen
    for(std::vector<std::string> vec : dataList)
    {
        //for(std::string data : vec)
        vector<float> vec_tmp;

        col = 0;

        for(auto it=vec.begin(); it<vec.end(); it++)
        {
            string a = *it;
            int b = a.compare("");
            if((*it).compare("")== 0) {
//                vec.erase(it);
            }
            else{
//                std::cout<<*it<<" "<<left<<std::setw(9);
                float ft_num = stof(*it);

                 A(row, col) = ft_num;


                col++;

            }


        }

        row++;


    }

    // fill the data into the the dataset

    DynamicMatrix<float> train_set(train_size, 14);
    DynamicMatrix<float> test_set(test_size, 14);

    size_t train_row = 0;
    size_t train_col = 0;

    size_t test_row = 0;
    size_t test_col = 0;

    // fill in the train set
    for( size_t i=0; i<train_size; ++i) {

        train_col =0;
        for( DynamicMatrix<float,rowMajor>::Iterator it=A.begin(i); it!=A.end(i); ++it ) {

            train_set(train_row, train_col) = *it;
            train_col ++;

        }

        train_row ++;
    }




    // create a final dataset for training and testing

    dataset final_data(train_set, test_set, test_ratio);


    // get the scaler

    for(size_t col_new = 0; col_new < train_set.columns(); col_new++ ){

        auto col_vec = columns(train_set, {col_new});

        float col_mean = mean(col_vec);

        float col_std = stddev(col_vec);

        if(col_new < (train_set.columns()-1)) {
            final_data.set_X_scaler(col_mean, col_std);
        }
        else{
            final_data.set_y_scaler(col_mean, col_std);
        }
    }

    vector<float> X_mean_vec = final_data.get_X_mean();
    vector<float> X_std_vec = final_data.get_X_std();

    vector<float> y_mean_vec = final_data.get_y_mean();
    vector<float> y_std_vec = final_data.get_y_std();


    // fill in the test set

    // fill in the train set
    for( size_t i=0; i<train_size; ++i) {

        train_col =0;
        for( DynamicMatrix<float,rowMajor>::Iterator it=A.begin(i); it!=A.end(i); ++it ) {

            if(it < (A.end(i)-1)){
                train_set(train_row, train_col) =  (train_set(train_row, train_col)-X_mean_vec.at(test_col))/X_std_vec.at(test_col);
                train_col ++;
            }
            else{
                train_set(test_row, test_col) = (train_set(train_row, train_col)-y_mean_vec.at(test_col))/y_std_vec.at(test_col);
            }



        }

        train_row ++;
    }


    for( size_t i=train_size; i<A.rows(); ++i) {

        test_col =0;

        for( DynamicMatrix<float,rowMajor>::Iterator it=A.begin(i); it!=A.end(i); ++it ) {

            if(it < (A.end(i)-1)){
                test_set(test_row, test_col) = (test_set(test_row, test_col)-X_mean_vec.at(test_col))/X_std_vec.at(test_col);
                test_col ++;}
            else{
                test_set(test_row, test_col) = (test_set(test_row, test_col)-y_mean_vec.at(0))/y_std_vec.at(0);
            }


        }

        test_row ++;
    }






    return 0;

}

