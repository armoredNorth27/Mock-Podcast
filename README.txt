Content:
	-Makefile
	-defs.h
		Contains a few constants that determine things
		like max array size
	-Subscriber.h
		Simulates a subscriber by having a name and
		credit card along with a few functions to print
		them out or check if their name matches another
		name
	-Subscriber.cc
		Implements the functions in Subscriber.h
	-Episode.h
		Simulates what a podcast episode would look like 
		by having a name, episode number, content, and
		which podcast this episode belongs to. Has functions
		to play the episode or to print out some of its 
		basic data
	-Episode.cc
		Implements the functions of Episode.h
	-Podcast.h
		Simulates a podcast by having a title, a host,
		a tracker for the total number of episodes and
		an array that holds all episodes of the podcast.
		Allows for functionality such as adding or getting
		an episode. You can compare 2 podcasts to see which
		one's name comes first, and you print out some of
		its data.
	-Podcast.cc
		Implements the functions of Podcast.h
	-PodArray.h
		An Podcast Array Interface that allows us to make
		an array of podcasts with a bunch of useful functions.
		Functions include adding, removing, or getting podcasts,
		finding the size of the array, etc.
	-PodArray.cc
		Implements the functions of PodArray.h 
	-Network.h 
		Simulates having a collection of podcasts and subscribers
		while allowing some basic functionality such as adding and
		removing podcasts, adding subscribers and adding episodes.
		You can also try to download or stream podcasts and episodes
		respectively.
	-Network.cc
		Implements the functions of Network.h
	-Client.h
		Simulates a client who can try to download podcasts or play
		episodes that are found in a network. They will be able to
		do this only if the client's name matches one of the names
		of the subscribers in the Network.
	-Client.cc
		Implements the functions of Client.h
	-TestView.h
		Contains the function are used to display some options for
		testing the classes defined above
	-TestView.cc
		Implements the functions of TestView.h
	-TestControl.h
		Contains functions that perform tests using the classes
		defined above.
	-TestControl.cc
		Implements the functions of TestControl.h
	-main.cc
		The main class that uses the TestView and TestControl classes
		in order to test the implemented classes
