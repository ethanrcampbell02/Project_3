#include "Parameter.h"

std::string Parameter::ToString() {
    return p;
}

bool Parameter::IsConstant() {
    if (p[0] == p[p.length()-1] && p[0] == '\'') {
        return true;
    } else {
        return false;
    }
}