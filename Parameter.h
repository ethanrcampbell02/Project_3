#ifndef INTERPRETER_PARAMETER_H
#define INTERPRETER_PARAMETER_H

#include <string>

class Parameter {
private:
    std::string p;
public:
    Parameter() {}
    Parameter(std::string p) {
        this->p = p;
    }
    ~Parameter() {}

    std::string ToString();
    bool IsConstant();
};


#endif //INTERPRETER_PARAMETER_H
