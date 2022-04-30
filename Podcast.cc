#include "Podcast.h"
#include "defs.h"

//===================================================//
//                   Constructors                    //
//===================================================//

Podcast::Podcast(const string& title, const string& host): title(title), host(host){
    numEps = 0;
    episodeArr = new Episode*[MAX_EPS];
}

Podcast::Podcast(Podcast& podcast): title(podcast.title), host(podcast.host), numEps(podcast.numEps){
    Episode* currEpisode;
    this->episodeArr = new Episode*[MAX_EPS];

    // Performs a deep copy of all episodes in the array
    for(int i=0; i<MAX_EPS; i++){
        currEpisode = podcast.episodeArr[i];

        if(currEpisode != NULL){
            this->episodeArr[i] = new Episode(*currEpisode);
        }
    }
}

Podcast::~Podcast(){
    for(int i=0; i<numEps; i++){
        delete episodeArr[i];
    }
    numEps = 0;

    delete[] episodeArr;
}

//===================================================//
//                      Getters                      //
//===================================================//

const string& Podcast::getTitle() const{ return title; }

const string& Podcast::getHost() const{ return host; }

int Podcast::getNumEpisodes() const{ return numEps; }

//===================================================//
//                  Member Functions                 //
//===================================================//

// Print out podcast with some meta-data
void Podcast::print() const{
    cout << "Podcast: " << title << " with host " << host << ". Total number of episodes = " << numEps << endl;
}

// If there's room in the episode array, add a new episode using input parameters
// Return true if episode was created and added. Return false otherwise
bool Podcast::addEpisode(const string& title, const string& content){
    if(numEps == MAX_EPS){
        return false;
    }

    episodeArr[numEps] = new Episode(this->title, numEps, title, content);
    numEps++;
    return true;
}

// Store the episode located at the index in the output parameter
// Return true if the index is within range of all episodes
// Return false if index is out of range of the array or greater
//              than the number of episodes present in the array
bool Podcast::getEpisode(int index, Episode** ep) const{
    if(index < 0 || index >= numEps){
        return false;
    }

    *ep = episodeArr[index];
    return true;
}

// Return true if the title of the podcast calling the function
// comes before the input parameter's title alphabetically
bool Podcast::lessThan(Podcast& podcast) const{
    return this->title < podcast.title;
}