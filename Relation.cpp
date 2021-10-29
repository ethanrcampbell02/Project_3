#include "Relation.h"
#include <iostream>

void Relation::Select(int index, std::string value) {
    // Iterate through each tuple and delete it if it doesn't match the value
    auto currTuple = tuples.begin();
    while (currTuple != tuples.end()) {
        if ((*currTuple).at(index) != value) {
            currTuple = tuples.erase(currTuple);
        } else {
            currTuple++;
        }
    }
}

void Relation::Select(int index1, int index2) {
    // Iterate through each tuple and delete it if the values at each index aren't equal
    auto currTuple = tuples.begin();
    while (currTuple != tuples.end()) {
        if ((*currTuple).at(index1) != (*currTuple).at(index2)) {
            currTuple = tuples.erase(currTuple);
        } else {
            currTuple++;
        }
    }
}

void Relation::Project(std::vector<int> indices, Relation* peeking) {
    // Making a new header to replace the current one with
    std::vector<std::string> newHeader;
    for (int currIndex : indices) {
        newHeader.push_back(header->at(currIndex));
    }
    header->Replace(newHeader);     // TODO: FIX THE PROBLEM THAT MAYBE EXISTS HERE??????

    // Replacing all the tuples
    std::set<Tuple> newTuples;
    for (Tuple currTuple : tuples) {
        Tuple newTuple;
        for(int currIndex : indices) {
            newTuple.AddElement(currTuple.at(currIndex));
        }
        newTuples.insert(newTuple);
    }
    tuples = newTuples;
}

void Relation::Rename(std::vector<std::string> newHeader) {
    std::vector<int> notDupes;          // Indices of attributes that are not duplicates
    std::set<std::string> headerSet;    // Set that will contain all attributes in newHeader

    unsigned int i = 0;
    while (i < newHeader.size()) {
        headerSet.insert(newHeader.at(i));
        if (i > headerSet.size()-1) {
           newHeader.erase(newHeader.begin()+i);
           continue;
        }
        notDupes.push_back(i);
        i++;
    }

    this->Project(notDupes, this);
    header->Replace(newHeader);
}

void Relation::PrintRelation() {
    for (Tuple tuple : tuples) {
        std::cout << "  ";
        for (unsigned int i = 0; i < tuple.values.size(); i++) {
            if (i != tuple.values.size()-1) {
                std::cout << header->at(i) << "=" << tuple.at(i) << ", ";
                continue;
            } else {
                std::cout << header->at(i) << "=" << tuple.at(i) << std::endl;
            }
        }
    }
}