#ifndef PODCAST_H
#define PODCAST_H

#include <iostream>
#include <string>
#include "Episode.h"

class Podcast{

    public:
        //* Constructors
        Podcast(const string& title, const string& host);
        Podcast(Podcast&);
        ~Podcast();

        //* Getters
        const string& getTitle() const;
        const string& getHost() const;
        int getNumEpisodes() const;
        
        //* Member functions
        void print() const;
        bool addEpisode(const string& title, const string& content);
        bool getEpisode(int index, Episode** ep) const;
        bool lessThan(Podcast&) const;

    private:
        //* Member variables
        string title;
        string host;
        Episode** episodeArr;
        int numEps;
};

#endif