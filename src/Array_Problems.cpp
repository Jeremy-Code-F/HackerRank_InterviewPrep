#include "Array_Problems.h"
#include <iostream>
using namespace std;

Array_Problems::Array_Problems()
{
    //ctor
}

Array_Problems::~Array_Problems()
{
    //dtor
}

// https://www.hackerrank.com/challenges/2d-array/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=arrays
Array_Problems::Hourglass_Problem(vector<vector<int> > arr){
    int maxSum = -9999;

    for(int i=0; i < arr.size(); i++){
        vector<int> innerVector = arr[i];
        for(int j=0; j<innerVector.size(); j++){
            if(j + 3 > innerVector.size() || i + 3 > arr.size()){
                //Do nothing since this couldn't possibly be a valid hourglass
            }else{
                //Find the rest of the hourglass values based on the current J value
                int currentSum = innerVector[j] + innerVector[j+1] + innerVector[j+2] + arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
                if(currentSum > maxSum || maxSum == -9999){
                    maxSum = currentSum;
                }
            }

        }
    }

    cout << "Max sum was: " << maxSum << endl;
    return maxSum;
}
