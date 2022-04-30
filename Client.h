#ifndef CLIENT_H
#define CLIENT_H

#include "PodArray.h"
#include "Network.h"
#include <string>
#include <iostream>

class Client{

    public:
        //* Constructors
        Client(const string& name);
        ~Client();

        //* Member functions
        void print();
        void download(Network* network, const string& podcast);
        void stream(Network* network, const string& podcast, int episode);
        void playLocal(const string& podcast, int episode);

    private:
        //* Member variables
        string name;
        PodArray* podcastArray;
};

#endif