// Winter'24
// Instructor: Diba Mirza
// Student name: Sophia Ismael and Jacob Ismael
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>
#include <sstream>

#include <unordered_map>
using namespace std;

#include "utilities.h"
#include "movies.h"

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
    if (argc < 2){
        cerr << "Not enough arguments provided (need at least 1 argument)." << endl;
        cerr << "Usage: " << argv[ 0 ] << " moviesFilename prefixFilename " << endl;
        exit(1);
    }

    ifstream movieFile (argv[1]);
 
    if (movieFile.fail()){
        cerr << "Could not open file " << argv[1];
        exit(1);
    }
  
    // Create an object of a STL data-structure to store all the moviesw
    set<Movies> movies_set;
    unordered_map<string, double> movies_map;
    set<string> movies_names;
    string line, movieName;
    double movieRating;
    // Read each file and store the name and rating
    while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
            // Use std::string movieName and double movieRating
            // to construct your Movie objects
            // cout << movieName << " has rating " << movieRating << endl;
            // insert elements into your data structure
            Movies temp(movieName, movieRating);
            // cout << movieName << " has rating " << movieRating << endl;
            movies_set.insert(temp);
            movies_names.insert(movieName);
            movies_map.insert({movieName, movieRating});

            
    }

    movieFile.close();

    if (argc == 2){

            
            //print all the movies in ascending alphabetical order of movie names

            for(string mov_name: movies_names){
                cout << mov_name << ", " << movies_map[mov_name] << endl;
            }
            


            // for (Movies const& movie: movies_set){
            //     cout << movie.getName() << ", " << movie.getRating() << endl;
            // }


            return 0;

            


          
    }

    ifstream prefixFile (argv[2]);

    if (prefixFile.fail()) {
        cerr << "Could not open file " << argv[2];
        exit(1);
    }



    vector<string> prefixes;
    vector<Movies> best_ratings;
    bool highest = true;
    unordered_map<string, set<Movies>> prefixes_map;
    while (getline (prefixFile, line)) {
        if (!line.empty()) {
            prefixes.push_back(line);
            prefixes_map.insert({line, set<Movies>()});


            
            //return 0;
        }
    }
    
    for(int i = 0; i < prefixes.size(); i++){
        //go through movies_set and add movie to prefix_map if it has the same prefix
        
        //cout << prefixes.at(i) << endl;

        int pre_len = prefixes.at(i).size();
        string pre = prefixes.at(i);

        
        
        for (Movies const& movie: movies_set){

            //cout << movie.getName().substr(0, pre_len) << endl;


            if(movie.getName().substr(0, pre_len) == pre){
                prefixes_map[pre].insert(movie);
                //cout << movie.getName() << endl;
            }
        }


        if( prefixes_map[pre].empty() ){
            cout << "No movies found with prefix "<<"<replace with prefix>" << endl << endl;
        }else{
            for (Movies const& movie: prefixes_map[pre]){
                
                cout << movie.getName() << ", " << movie.getRating() << endl;

                if(highest){
                    best_ratings.push_back(movie);
                    highest = false;
                }
            }

            cout << endl;
        }

        highest = true;


        
    }

    

    //  For each prefix,
    //  Find all movies that have that prefix and store them in an appropriate data structure
    //  If no movie with that prefix exists print the following message


    

    //  For each prefix,
    //  Print the highest rated movie with that prefix if it exists.

    for(int i = 0; i < prefixes.size(); i++){
        cout << "Best movie with prefix " << prefixes.at(i) << " is: " << best_ratings.at(i).getName() << " with rating " << std::fixed << std::setprecision(1) << best_ratings.at(i).getRating() << endl;

    }

    return 0;
}

/* Add your run time analysis for part 3 of the assignment here as commented block*/

bool parseLine(string &line, string &movieName, double &movieRating) {
    int commaIndex = line.find_last_of(",");
    movieName = line.substr(0, commaIndex);
    movieRating = stod(line.substr(commaIndex+1));
    if (movieName[0] == '\"') {
        movieName = movieName.substr(1, movieName.length() - 2);
    }
    return true;
}