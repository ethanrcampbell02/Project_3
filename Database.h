#ifndef PROJECT_3_DATABASE_H
#define PROJECT_3_DATABASE_H

#include "DatalogProgram.h"
#include "Relation.h"
#include <string>
#include <map>

class Database {
public:
    Database() {}
    Database(DatalogProgram* datalogProgram);
    ~Database() {} // TODO: Define destructor for Database
    Relation* EvaluatePredicate(Predicate* p);
    Relation* CopyRelation(Relation* relationToCopy);

private:
    std::map<std::string, Relation*> relations;
};


#endif //PROJECT_3_DATABASE_H
