#ifndef NETWORK_H
#define NETWORK_H

#include "defs.h"
#include "PodArray.h"
#include "Subscriber.h"
#include <iostream>
#include <string>

class Network{

    public:
        //* Constructors
        Network(const string&);
        ~Network();

        //* Member functions
        // Get elements from collections
        bool getPodcast(const string& podcastTitle, Podcast** podcast) const;
        
        // Add and remove
        bool removePodcast(const string& podcastTitle);
        bool addPodcast(const string& podcastTitle, const string& host);
        bool addEpisode(const string& podcast, const string& title, const string& content);
        bool addSubscriber(const string& name, const string& creditcard);
        
        // Client services
        void print() const;
        bool download(const string& subscriber, const string& podcastTitle, Podcast** podcast) const;
        bool stream(const string& subscriber, const string& podcastTitle, int episode, Episode** ep) const;
        bool hasSubscriber(const string& subName) const;

    private:
        //* Member variables
        string name;
        PodArray* podcasts;
        Subscriber* subs[MAX_SUBS];
        int numSubs;
};

#endif