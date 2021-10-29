#include "Database.h"
#include <iostream>

Database::Database(DatalogProgram* datalogProgram) {

    // Creating a relation for each scheme and adding it to the relations map
    std::vector<Predicate*> schemes = datalogProgram->GetSchemes();
    for (Predicate* scheme : schemes) {
        Header* header = new Header();

        for (unsigned int i = 0; i < scheme->NumParameters(); i++) {
            Parameter* currParameter = scheme->GetParameter(i);
            header->AddAttribute(currParameter->ToString());
        }

        Relation* relation = new Relation(header);
        relations[scheme->GetId()]  =  relation;
    }

    // Creating a tuple for each fact and adding it to the corresponding relation in the relations map
    std::vector<Predicate*> facts = datalogProgram->GetFacts();
    for (Predicate* fact : facts) {
        Tuple tuple;

        for (unsigned int i = 0; i < fact->NumParameters(); i++) {
            Parameter* currParameter = fact->GetParameter(i);
            tuple.AddElement(currParameter->ToString());
        }

        Relation* relation = relations[fact->GetId()];
        relation->AddTuple(tuple);
    }
}

Relation* Database::EvaluatePredicate(Predicate* p) {

    // Get the relation with the same name as the query then make a copy of it
    Relation* matchingRelation = relations[p->GetId()];
    Relation* relationCopy = CopyRelation(matchingRelation);
    // Select for each constant in the query
    for (unsigned int i = 0; i < p->NumParameters(); i++) {
        Parameter* currParameter = p->GetParameter(i);
        if (currParameter->IsConstant()) {
            relationCopy->Select(i, currParameter->ToString());
        }
    }

    // We will store the positions of all variables in the query
    std::vector<int> varPositions;

    // Select for each pair of matching variables in the query
    for (unsigned int i = 0; i < p->NumParameters(); i++) {

        Parameter* currParameter1 = p->GetParameter(i);
        if (!(currParameter1->IsConstant())) {

            // Keeping track of the indices with variables so we can have easy access to them later
            varPositions.push_back(i);

            // Checking to see if the variable matches with any others in the query+
            for (unsigned int j = i+1; j < p->NumParameters(); j++) {
                Parameter* currParameter2 = p->GetParameter(j);
                if (currParameter1->ToString() == currParameter2->ToString()) {
                    relationCopy->Select(i, j);
                }
            }

        }
    }

    // Project using the positions of the variables in the query
    relationCopy->Project(varPositions, matchingRelation);

    // Rename to match the names of the variables in the query
    std::vector<std::string> newHeader;
    for (int index : varPositions) {
        Parameter* currParameter = p->GetParameter(index);
        newHeader.push_back(currParameter->ToString());
    }
    relationCopy->Rename(newHeader);

    return relationCopy;
}

// Because I made my relation operators modify the relation instead of returning a new relation, I needed to make a copy
// of the relations to edit. Made this function since I might need this in future projects
Relation* Database::CopyRelation(Relation *relationToCopy) {
    Relation* relationCopy = new Relation();
    *relationCopy = *relationToCopy;
    Header* ogHeader = relationToCopy->GetHeader();
    Header* headerCopy = new Header();
    *headerCopy = *ogHeader;
    relationCopy->SetHeader(headerCopy);

    return relationCopy;
}