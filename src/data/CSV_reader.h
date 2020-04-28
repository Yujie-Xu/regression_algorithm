//
// Created by yujie on 2020-04-19.
//


#ifndef DATA_CSV_READER_H
#define DATA_CSV_READER_H

#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

using namespace std;

class CSV_reader {

    string fileName;
    string delimeter;

public:
    explicit CSV_reader(string filename, string delm = " ") :
    fileName(filename), delimeter(delm)
    { }

    // Function to fetch data from a CSV File
    vector<vector<string> > getData();

};




#endif //DATA_CSV_READER_H
