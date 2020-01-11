#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

long countTriplets(vector<long> arr, long r){
    map<int, vector<int>> positionMap;


    int positionTracker = 0;
    for(int number : arr){
        vector<int> positions = positionMap[number];
        positions.insert(positions.end(), positionTracker);
        positionMap[number] = positions;

        positionTracker++;
    }

     for(auto& position:positionMap){
         cout << "Positions for: " << position.first << endl;
         for(int thing: position.second){
            cout << thing << " ";
         }
         cout << endl;
     }

     int currentPosTracker = 0;
     int numOfProgressions = 0;
     for(int number : arr){
        int tempNumOfProgressions = 0;
        if(positionMap[number * r].size() > 0){
            cout << "Next geometric progress exists for : " << number << " " << positionMap[number * r].size() << " times."<< endl;
            tempNumOfProgressions += positionMap[number * r].size();
            if(positionMap[number * r * r].size() > 0){
                cout << "Next geometric progress exists for : " << number * r  << " " << positionMap[number * r * r].size() << " times."<< endl;
                tempNumOfProgressions *= positionMap[number * r * r].size();
                numOfProgressions += tempNumOfProgressions;
            }
        }
        currentPosTracker++;
     }
     cout << "Number of progressions: " << numOfProgressions << endl;

    return numOfProgressions;
}

int findNumThatWork(int currentPos, vector<int> matchingVector){
    int numberThatWork = 0;
    for(int number: matchingVector){
        if(number > currentPos){
            numberThatWork++;
        }
    }

    return numberThatWork;
}

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {

    auto start = high_resolution_clock::now();

    map<int, int> charFreqMap;
    map<int, int> freqMap;
    //vector<int> appendedResults;

    vector<int> endResult;

    vector<vector<int>>::iterator row;
    vector<int>::iterator col;

    for (row = queries.begin(); row != queries.end(); row++) {
        for (col = row->begin(); col != row->end(); col++) {
            if(*col == 1){
                col++;
                //cout << "Inserting: " << *col << endl;
                //appendedResults.insert(appendedResults.end(), *col);
                int currFreq = charFreqMap[*col];
                if(currFreq > 0){
                    freqMap[currFreq]--;
                }

                charFreqMap[*col]++;
                //cout << *col << " Has occurred: " << charFreqMap[*col] << " times now." << endl;


                freqMap[currFreq+1]++;
                //cout << "Increased the number of times the frequency: " << charFreqMap[*col] << " has occurred to: " << freqMap[charFreqMap[*col]] << endl;
            }else if(*col == 2){
                col++;
                //cout << "Attempting to delete " << *col << endl;

                if(charFreqMap[*col] >= 1){
                    //Loop through appendedResults and delete the first *col we find
                    //appendedResults.erase(std::remove(appendedResults.begin(), appendedResults.end(), *col), appendedResults.end());
                    //cout << "Decreasing the number of times the frequency " << freqMap[charFreqMap[*col]] << " exists to ";
                    int currFreq = charFreqMap[*col];
                    freqMap[currFreq]--;
                    //cout <<  freqMap[charFreqMap[*col]] << endl;
                    charFreqMap[*col]--;
                    if(currFreq - 1 != 0){
                        freqMap[currFreq-1]++;
                    }

                }


            }else if(*col == 3){
                col++;
                //cout << "Checking if a freq of " << *col << " exists " << endl;
                if(freqMap[*col] > 0){
                    //cout << "Freq existed writing a 1" << endl;
                    endResult.insert(endResult.end(), 1);
                }else{
                    //cout << "Freq didn't exist writing 0. freq was: " << freqMap[*col] << endl;
                    endResult.insert(endResult.end(), 0);
                }
            }else{
                //cout << "ERROR" << endl;
            }
        }
    }

    // for(auto& result:endResult){
    //     cout << result << " ";
    // }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);
    cout << duration.count() << endl;

    return endResult;
}

int main(){

    //vector<int> results = freqQuery(table);

    vector<long int> geomProgresInput;
    geomProgresInput.push_back(1);
    geomProgresInput.push_back(1);
    geomProgresInput.push_back(1);
    geomProgresInput.push_back(1);


    countTriplets(geomProgresInput, 1);
}
