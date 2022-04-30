#ifndef EPISODE_H
#define EPISODE_H

#include <iostream>
#include <string>

using namespace std;

class Episode{

    public:
        //* Constructors
        Episode();
        Episode(const string& podcast, int number, const string& name, const string& content);

        //* Functions
        void print() const;
        void play() const;

    private:
        //* Member Variables
        string name;
        string content;
        string podcast;
        int number;

};

#endif