#include<iostream>
#include<bits/stdc++.h>
using namespace std;



// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    map<int, int> freqMap;
    map<int, int> posMap;
    vector<int> holder;

    int resultPosCounter = 0;
    vector<int> endResult;

    vector<vector<int>>::iterator row;
    vector<int>::iterator col;

    for(row = queries.begin(); row != queries.end(); row++){

        int thingCounter = 1;

        for(col = row->begin(); col != row->end(); col++){
            cout << *col << endl;
            if(thingCounter == 1){
                if(*col == 1){
                    col++;
                    freqMap[*col]++;
                    holder.insert(holder.end(), *col);
                    posMap[*col] = holder.size() - 1;
                    cout << "Inserting thing: " << *col << "Freq map: " << freqMap[*col] <<  endl;
                }else if(*col == 2){
                    col++;
                    cout << "Trying to delete " << *col << endl;
                    if(posMap[*col] != 0){
                        cout << "Deleting at position: " << posMap[*col] << " value: " << *col << " " <<endl;
                        //cout << "Deleting first occurance of: " << *col << " at " << posMap[*col];
                        holder.erase(holder.begin() + posMap[*col]);

                    }else{
                        cout << "Nothing found to delete" << endl;
                    }
                    

                }else if(*col == 3){
                    col++;
                    cout << "Freq map size: " << freqMap.size() << endl;

                    if(freqMap.size() < 1){
                        cout << "freq map's size is less than 1 so inserting 0" << endl;
                        endResult.insert(endResult.end(), 0);
                    }else{
                        bool foundTwoFreq = false;
                        
                        //cout << "Checking for any frequency of : " << *col << endl;
                        for(auto it = freqMap.begin(); it != freqMap.end(); ++it){
                            if(it->second >= *col){
                                cout << "Found matching freq, writing a 1" << endl;
                                endResult.insert(endResult.end(), 1);
                                foundTwoFreq = true;
                                break;
                            }
                        }
                        if(!foundTwoFreq){
                            cout << "Couldn't find a matching freq" << endl;
                            endResult.insert(endResult.end(), 0);
                        }

                    }

                }else{
                    col++;
                }
            }else{
                cout << "Operating on thing: " << *col << " ";
            }
        }
        cout << endl;
    }
    for(auto it = endResult.begin(); it != endResult.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    for(auto it = posMap.begin(); it != posMap.end(); ++it){
        cout << "Value " << it->first << " " <<  "Position " << it->second << " ";
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