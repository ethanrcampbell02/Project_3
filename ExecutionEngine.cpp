#include "ExecutionEngine.h"
#include <iostream>

void ExecutionEngine::Run(DatalogProgram* datalogProgram) {
        database = new Database(datalogProgram);
        EvaluateQueries(datalogProgram);
}

void ExecutionEngine::EvaluateQueries(DatalogProgram *datalogProgram) {
    std::vector<Predicate*> queries = datalogProgram->GetQueries();

    // Iterate through every single query so we can evaluate each one
    for (Predicate* query : queries) {

        std::cout << query->ToString() << "? ";
        Relation* queryResult = database->EvaluatePredicate(query);

        if ((queryResult->GetTuples()).size() == 0) {
            std::cout << "No" << std::endl;
        } else {
            std::cout << "Yes(" << (queryResult->GetTuples()).size() << ")" << std::endl;
            queryResult->PrintRelation();
        }
    }
}