
#include "Client.h"

//===================================================//
//                   Constructors                    //
//===================================================//

Client::Client(const string& name): name(name){
    podcastArray = new PodArray();
}

Client::~Client(){
    delete podcastArray;
}

//===================================================//
//                 Member Functions                  //
//===================================================//

// Print out client with some meta-data
void Client::print(){
    cout << "Client " << name << " with " << podcastArray->size() << " podcasts." << endl;
}

// Attempt to download the given podcast by trying to find it in the
// the network.
// If the podcast is found and there's room in the array, add it to
// the podcast array
// If the podcast is not found or there's no room in the podcast array,
// then print out an error message
void Client::download(Network* network, const string& podcast){

    // Makes sure there's room to add a new podcast
    if(podcastArray->isFull()){
        cout << "Podcast array is full. Cannot add a new podcast." << endl;
        return;
    }

    Podcast* tempPodcast;
    bool foundPodcast = network->download(name, podcast, &tempPodcast);

    if(foundPodcast){
        podcastArray->addPodcast(new Podcast(*tempPodcast));
    }
}

// Attempt to stream(play) the episode in the given podcast in the given network.
// If the episode was found, then play it
// If the episode was not found, output an error message indicating why 
void Client::stream(Network* network, const string& podcast, int episode){
    Episode* ep;
    bool foundEpisode = network->stream(name, podcast, episode, &ep);

    if(foundEpisode){
        ep->play();
    }
}

// Attempt to find the episode at the specified index at the given podcast.
// If the podcast or episode could not be found, output and error.
// If the episode was found, play it
void Client::playLocal(const string& podcast, int episode){
    Podcast* pod;
    Episode* ep;
    bool foundPodcast, foundEpisode;

    foundPodcast = podcastArray->getPodcast(podcast, &pod);
    if(!foundPodcast){
        cout << "ERROR: Couldn't find specified podcast." << endl;
        return;
    }

    foundEpisode = pod->getEpisode(episode, &ep);
    if(!foundEpisode){
        cout << "ERROR: Couldn't find specified episode." << endl;
        return;
    }

    ep->play();
}