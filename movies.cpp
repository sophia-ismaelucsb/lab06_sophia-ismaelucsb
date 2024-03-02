#include "movies.h"
using namespace std;

bool Movies::operator<(const Movies &m1) const{
    if(this->rating == m1.getRating()){
        return this->name > m1.getName();
    }

    return this->rating > m1.rating;
    

    

};




/*
ostream& operator<<(ostream& os, Movies& movie){
    os << movie.name <<  ", " << endl;
    return os;
};

*/