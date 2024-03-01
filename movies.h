#ifndef MOVIES_H
#define MOVIES_H


using namespace std;
#include <string>
#include <iostream>

class Movies{
    public:
        Movies(string _name = "UNTITLED", double _rating = 0.0) : name(_name), rating(_rating){}

        bool operator<(const Movies &m1) const;
        bool operator>(const Movies &m1) const;
        //friend ostream& operator<<(ostream& os, Movies& movie);
        
        string getName() const{return name;}
        double getRating() const{return rating;}



    private:
        string name;
        double rating;




};

#endif