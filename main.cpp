#include<iostream>
#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;



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
    vector<vector<int>> table;
    vector<int> firstRow;
    firstRow.push_back(1);
    firstRow.push_back(5);
    vector<int> secondRow;
    secondRow.push_back(1);
    secondRow.push_back(6);
    vector<int> thirdRow;
    thirdRow.push_back(3);
    thirdRow.push_back(2);
    vector<int> fourthRow;
    fourthRow.push_back(1);
    fourthRow.push_back(10);
    vector<int> fifthRow;
    fifthRow.push_back(1);
    fifthRow.push_back(10);
    vector<int> sixthRow;
    sixthRow.push_back(1);
    sixthRow.push_back(6);
    vector<int> seventhRow;
    seventhRow.push_back(2);
    seventhRow.push_back(5);
    vector<int> eighthRow;
    eighthRow.push_back(3);
    eighthRow.push_back(2);
    vector<int> ninthRow;
    ninthRow.push_back(2);
    ninthRow.push_back(10);
    vector<int> tenthRow;
    tenthRow.push_back(2);
    tenthRow.push_back(6);
    vector<int> eleventhRow;
    eleventhRow.push_back(3);
    eleventhRow.push_back(2);
    table.push_back(firstRow);
    table.push_back(secondRow);
    table.push_back(thirdRow);
    table.push_back(fourthRow);
    table.push_back(fifthRow);
    table.push_back(sixthRow);
    table.push_back(seventhRow);
    table.push_back(eighthRow);
    table.push_back(ninthRow);
    table.push_back(tenthRow);
    table.push_back(eleventhRow);


    vector<int> results = freqQuery(table);
}