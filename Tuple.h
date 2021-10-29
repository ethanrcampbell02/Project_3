#ifndef PROJECT_3_TUPLE_H
#define PROJECT_3_TUPLE_H

#include <string>
#include <vector>

class Tuple {
public:
    Tuple() {}
    ~Tuple() {} // TODO: Define destructor for Tuple

    void AddElement(std::string element) {
        values.push_back(element);
    }

    std::string at(int index) const {
        return values.at(index);
    }

    bool operator< (const Tuple &rhs) const {
        return values < rhs.values;
    }

    std::vector<std::string> values;
};


#endif //PROJECT_3_TUPLE_H
