
#include "PodArray.h"

//===================================================//
//                   Constructors                    //
//===================================================//

PodArray::PodArray(){
	numPods = 0;
	podcasts = new Podcast*[MAX_PODS];
}

PodArray::PodArray(PodArray& pa){
	podcasts = new Podcast*[MAX_PODS];
	for (int i =0 ; i < pa.numPods; ++i){
		podcasts[i] = new Podcast(*pa.podcasts[i]);
	}
	numPods = pa.numPods;

}

PodArray::~PodArray(){
	for(int i=0; i<numPods; i++){
		delete podcasts[i];
	}
	numPods = 0;

	delete[] podcasts;
}

//===================================================//
//                 Member Functions                  //
//===================================================//

// Adds a new podcast to the array of podcasts
// Returns true if podcast was added
// Return false otherwise
bool PodArray::addPodcast(Podcast* p){
	if (numPods >= MAX_PODS) return false;
	for (int i = numPods; i > 0; --i){
		if (p->lessThan(*podcasts[i-1])){
			podcasts[i] = podcasts[i-1];
		}else{
			podcasts[i] = p;
			++numPods;
			return true;
		}
	}
	podcasts[0] = p;
	++numPods;
	return true;
}

// Removes the specified podcast and stores it in the output parameter
// Return true if podcast was removed
// Return false otherwise
bool PodArray::removePodcast(const string& title, Podcast** pod){
	bool foundPod = false;

	// Loop through all podcasts to find the one with the matching title
	for(int i=0; i<numPods; i++){
		// "Fill" in the hole left by the removed podcast by
		// moving back all podcasts, after the removed one, in the 
		// array by 1
		if(foundPod){
			podcasts[i] = podcasts[i+1];
		}
		else{
			// If current podcast title is the same as the one
			// we're looking for, then we've found the podcast
			// we want to remove
			if(podcasts[i]->getTitle() == title){
				*pod = podcasts[i];
				podcasts[i] = podcasts[i+1];
				foundPod = true;
			}
		}
	}

	// Make the position after the last podcast
	// null in order to remove duplicates
	if(foundPod){
		podcasts[numPods-1] = NULL;
		numPods--;
	}

	return foundPod;
}

// Find and store the specified podcast in the output parameter
// Return true if podcast was found
// Return false otherwise
bool PodArray::getPodcast(const string& title, Podcast** pod){
	for(int i=0; i<numPods; i++){
		if(podcasts[i]->getTitle() == title){
			*pod = podcasts[i];
			return true;
		}
	}
	return false;
}

// Return true if the podcast array is full
// Return false otherwise
bool PodArray::isFull(){
	return numPods >= MAX_PODS;
}

// Returns the number of podcasts stored in the array
int PodArray::size(){
	return numPods;
}

// Prints out all podcasts in the array
void PodArray::print(){
	for (int i = 0; i < numPods; ++i){
		podcasts[i]->print();
	}
}
