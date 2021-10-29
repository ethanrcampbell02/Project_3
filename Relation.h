#ifndef PROJECT_3_RELATION_H
#define PROJECT_3_RELATION_H

#include "Tuple.h"
#include "Header.h"
#include <set>

class Relation {
public:
    Relation() {}
    Relation(Header* header) {
        this->header = header;
    }
    ~Relation() {}

    void AddTuple(Tuple tuple) {
        tuples.insert(tuple);
    }
    std::set<Tuple> GetTuples() {
        return tuples;
    }
    Header* GetHeader() {
        return header;
    }
    void SetHeader(Header* newHeader) {
        this->header = newHeader;
    }
    void Select(int index, std::string value);
    void Select(int index1, int index2);
    void Project(std::vector<int> indices, Relation* peeking);
    void Rename(std::vector<std::string> newHeader);
    void PrintRelation();

private:
    Header* header;
    std::set<Tuple> tuples;
};

#endif //PROJECT_3_RELATION_H
