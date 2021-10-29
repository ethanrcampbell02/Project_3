#ifndef PROJECT_3_HEADER_H
#define PROJECT_3_HEADER_H

#include <vector>
#include <string>

class Header {
public:
    Header() {}
    ~Header() {} // TODO: Define destructor for Header

    void AddAttribute(std::string attribute) {
        attributes.push_back(attribute);
    }

    void Replace(std::vector<std::string> attributes) {
        this->attributes = attributes;
    }

    std::string at(int index) {
        return attributes.at(index);
    }

    std::vector<std::string> attributes;
};


#endif //PROJECT_3_HEADER_H
