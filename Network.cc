
#include "Network.h"

//===================================================//
//                   Constructors                    //
//===================================================//

Network::Network(const string& name): name(name){
    podcasts = new PodArray();
}

Network::~Network(){
    for(int i=0; i<numSubs; i++){
        delete subs[i];
    }
    numSubs = 0;

    delete podcasts;
}

//===================================================//
//                 Member Functions                  //
//===================================================//

// Store podcast we're looking for if we find it in output parameter
// Return true if found, return false otherwise
bool Network::getPodcast(const string& podcastName, Podcast** podcast) const{
    bool result = podcasts->getPodcast(podcastName, podcast);

    return result;
}

// Add a new podcast if there's room left
// Return true if added episode, return false otherwise
bool Network::addPodcast(const string& podcast, const string& host){
    if(podcasts->size() == MAX_PODS){
        return false;
    }

    Podcast* newPodcast = new Podcast(podcast, host);
    podcasts->addPodcast(newPodcast);
    return true;
}

// Remove podcast who's title matches the input parameter
// Return true if podcast got removed, return false otherwise
bool Network::removePodcast(const string& podcastTitle){
    bool removed;
    Podcast* removedPod;

    removed = podcasts->removePodcast(podcastTitle, &removedPod);

    // Deallocate memory if podcast has been found
    if(removed){
        delete removedPod;
        return true;
    }
    return false;
}

// Create and add a new episode into the specified podcast 
// if it exists and there's room in its episode array
// Return true if episode is created and added. Return false otherwise
bool Network::addEpisode(const string& podcast, const string& title, const string& content){
    bool foundPod, addedEp;
    Podcast* pod;
    Episode* newEp;

    foundPod = podcasts->getPodcast(podcast, &pod);

    if(!foundPod){
        return false;
    }

    addedEp = pod->addEpisode(title, content);
    return addedEp;
}

// Add a new subscriber to the network if there's room in its array
// Return true if subscriber was created and added. Return false otherwise
bool Network::addSubscriber(const string& name, const string& creditcard){
    if(numSubs >= MAX_SUBS){
        return false;
    }

    subs[numSubs] = new Subscriber(name, creditcard);
    numSubs++;
    return true;
}

// Print out network with some meta-data
void Network::print() const{
    cout << "Network: " << name << " with " << numSubs << " subscribers and " << podcasts->size() << " podcasts." << endl;
}

// If the subscriber and podcast exist, store the podcast in the output parameter
// Return true if podcast has been assigned to the output parameter and subscriber and podcast exist 
// Return false otherwise and provide error message
bool Network::download(const string& subscriber, const string& podcastTitle, Podcast** podcast) const{
    bool foundSub, foundPodcast;

    foundSub = hasSubscriber(subscriber);
    if(!foundSub){
        cout << "ERROR: Couldn't find specified subscriber." << endl;
        return false;
    }

    foundPodcast = podcasts->getPodcast(podcastTitle, podcast);
    if(!foundPodcast){
        cout << "ERROR: Couldn't find specified podcast." << endl;
        return false;
    }

    return true;
}

// If the subscriber, podcast, and episode number exist, store that episode in the output parameter
// Return true if subscriber, podcast and episode exist and we've stored said episode in the output parameter
// Return false otherwise and provide error message
bool Network::stream(const string& subscriber, const string& podcastTitle, int episode, Episode** ep) const{
    bool foundSub, foundPodcast, foundEp;
    Podcast* pod;

    foundSub = hasSubscriber(subscriber);
    if(!foundSub){
        cout << "ERROR: Couldn't find specified subscriber." << endl;
        return false;
    }

    foundPodcast = podcasts->getPodcast(podcastTitle, &pod);
    if(!foundPodcast){
        cout << "ERROR: Couldn't find specified podcast." << endl;
        return false;
    }

    foundEp = pod->getEpisode(episode, ep);
    if(!foundEp){
        cout << "ERROR: Couldn't find specified episode." << endl;
        return false;
    }

    return true;
}

// Try and find the subscriber that's been specified by the input parameter
// Return true if the subscriber exists. Return false otherwise
bool Network::hasSubscriber(const string& subName) const{
    for(int i=0; i<numSubs; i++){
        if(subs[i]->matches(subName)){
            return true;
        }
    }
    return false;
}