#include<iostream>
#include<bits/stdc++.h>
using namespace std;



// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    map<int, int> charFreqMap;
    map<int, int> freqMap;
    vector<int> appendedResults;
    
    vector<int> endResult;

    vector<vector<int>>::iterator row;
    vector<int>::iterator col;

    for (row = queries.begin(); row != queries.end(); row++) {
        for (col = row->begin(); col != row->end(); col++) {
            if(*col == 1){
                col++;
                cout << "Increasing freq for : " << *col;
                appendedResults.insert(appendedResults.end(), *col);


                charFreqMap[*col]++;
                cout << "New freq: " << charFreqMap[*col] << endl;
                freqMap[charFreqMap[*col]]++;
            }else if(*col == 2){
                col++;
                cout << "Attempting to delete " << *col << endl;

                if(charFreqMap[*col] >= 1){
                    //Loop through appendedResults and delete the first *col we find
                    appendedResults.erase(std::remove(appendedResults.begin(), appendedResults.end(), 8), appendedResults.end());
                    charFreqMap[*col]--;
                    freqMap[charFreqMap[*col]]++;
                }
                

            }else if(*col == 3){
                col++;
                cout << "Checking if a freq of " << *col << " exists " << endl;
                if(charFreqMap.size() < 1){ 
                    endResult.insert(endResult.end(), 0);
                }else{
                    bool foundFreq = false;
                    for(auto& thing:charFreqMap){
                        if(thing.second == *col){
                            endResult.insert(endResult.end(), 1);
                            foundFreq = true;
                            break;
                        }
                    }
                    if(foundFreq == false){
                        endResult.insert(endResult.end(), 0);
                    }
                }
            }else{
                cout << "ERROR" << endl;
            }
        }
    }

    for(auto& result:endResult){
        cout << result << " ";
    }

    return endResult;
}

int main(){
    vector<vector<int>> table;
    vector<int> firstRow;
    firstRow.push_back(1);
    firstRow.push_back(3);
    vector<int> secondRow;
    secondRow.push_back(2);
    secondRow.push_back(3);
    vector<int> thirdRow;
    thirdRow.push_back(3);
    thirdRow.push_back(2);
    vector<int> fourthRow;
    fourthRow.push_back(1);
    fourthRow.push_back(4);
    // vector<int> fifthRow;
    // fifthRow.push_back(1);
    // fifthRow.push_back(10);
    // vector<int> sixthRow;
    // sixthRow.push_back(1);
    // sixthRow.push_back(6);
    // vector<int> seventhRow;
    // seventhRow.push_back(2);
    // seventhRow.push_back(5);
    // vector<int> eighthRow;
    // eighthRow.push_back(3);
    // eighthRow.push_back(2);
    table.push_back(firstRow);
    table.push_back(secondRow);
    table.push_back(thirdRow);
    table.push_back(fourthRow);
    // table.push_back(fifthRow);
    // table.push_back(sixthRow);
    // table.push_back(seventhRow);
    // table.push_back(eighthRow);


    vector<int> results = freqQuery(table);
}