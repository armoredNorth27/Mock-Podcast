#include "Subscriber.h"

//===================================================//
//                   Constructors                    //
//===================================================//

Subscriber::Subscriber(const string& name, const string& creditcard): name(name), creditcard(creditcard){}

//===================================================//
//                 Member Functions                  //
//===================================================//

// Print out subscriber with some meta-data
void Subscriber::print() const{
    cout << "Subscriber " << name << " with credit card number " << creditcard << endl;
}

// Return true if the name of the calling subscriber matches 
//             the name of the input parameter
// Return false otherwise
bool Subscriber::matches(const string& name) const{
    return (this->name.compare(name) == 0);
}