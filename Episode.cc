
#include "Episode.h"

//===================================================//
//                   Constructors                    //
//===================================================//

Episode::Episode(){
    this->podcast = "N/A";
    this->number = -1;
    this->name = "N/A";
    this->content = "N/A";
}

Episode::Episode(const string& podcast, int number, const string& name, const string& content): podcast(podcast), number(number), name(name), content(content){}

//===================================================//
//                     Functions                     //
//===================================================//

// Print out an episode with some meta-data
void Episode::print() const{
    cout << "Podcast: " << podcast << " - Episode " << number << ": " << name <<endl;
}

// "Play" the episode by printing out some data and its content to the console
void Episode::play() const{
    cout << endl;
    cout << "Now playing, " << endl;
    cout << "Podcast: " << podcast << " --- " << name << ": Ep #" << number <<endl;
    cout << "Content: " << content << endl;
    cout << endl;
}