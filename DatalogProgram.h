#ifndef INTERPRETER_DATALOGPROGRAM_H
#define INTERPRETER_DATALOGPROGRAM_H

#include "Predicate.h"
#include "Rule.h"
#include <vector>
#include <string>
#include <set>

class DatalogProgram {
private:
    std::vector<Predicate*> schemes;
    std::vector<Predicate*> facts;
    std::vector<Rule*> rules;
    std::vector<Predicate*> queries;
    std::set<std::string> domain;
public:
    DatalogProgram() {}
    ~DatalogProgram();
    void AddScheme(Predicate* scheme);
    void AddFact(Predicate* fact);
    void AddRule(Rule* rule);
    void AddQuery(Predicate*);

    std::vector<Predicate*> GetSchemes() {
        return schemes;
    }
    std::vector<Predicate*> GetFacts() {
        return facts;
    }
    std::vector<Rule*> GetRules() {
        return rules;
    }
    std::vector<Predicate*> GetQueries() {
        return queries;
    }

    std::string ToString();
};


#endif //INTERPRETER_DATALOGPROGRAM_H
