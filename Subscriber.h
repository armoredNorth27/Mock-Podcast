#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <iostream>
#include <string>

using namespace std;

class Subscriber{

    public:
        //* Constructors
        Subscriber(const string& name, const string& creditcard);

        //* Member functions
        void print() const;
        bool matches(const string& name) const;

    private:
        //* Member Variables
        string name;
        string creditcard;
};

#endif