#ifndef PROJECT_3_EXECUTIONENGINE_H
#define PROJECT_3_EXECUTIONENGINE_H

#include "Database.h"
#include "DatalogProgram.h"

class ExecutionEngine {
public:
    ExecutionEngine() {}
    ~ExecutionEngine() {} // TODO: Define destructor for Execution Engine
    void Run(DatalogProgram* datalogProgram);
    void EvaluateQueries(DatalogProgram* datalogProgram);
private:
    Database* database;
};


#endif //PROJECT_3_EXECUTIONENGINE_H
