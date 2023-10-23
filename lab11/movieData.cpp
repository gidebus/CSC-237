#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct MovieData {
  string title;
  string director;
  int yearReleased;
  double runningTime;
};

void displayMovie(MovieData *moviePtr);
void populateMovieDataArray(MovieData *arrayPtr, int arraySize);
void displayMovieDataArray(MovieData *arrayPtr, int arraySize);
MovieData* findLongestMovie(MovieData *arrayPtr, int arraySize);

int main() {
  int ARRAY_SIZE;
  MovieData* longestMovie;

  cout << "Enter desired array size: ";
  cin >> ARRAY_SIZE;

  MovieData* arrayOfMovies = new MovieData[ARRAY_SIZE];
  populateMovieDataArray(arrayOfMovies, ARRAY_SIZE);
  displayMovieDataArray(arrayOfMovies, ARRAY_SIZE);
  longestMovie = findLongestMovie(arrayOfMovies, ARRAY_SIZE);

  cout << "Longest Movie in list: \n" << endl;
  displayMovie(longestMovie);
  
  cout << "\nLongest Movie is: " << longestMovie->runningTime << " minutes long" << endl;
  
  cout << "DELETING array at arrayPtr = " << arrayOfMovies << endl;
  delete[] arrayOfMovies;
  
  cout << "Exit the program.";
  
  return 0;
}

void populateMovieDataArray(MovieData *arrayPtr, int arraySize) {
  cout << "arrayPtr = " << arrayPtr << endl;

  for(int i = 0; i < arraySize; i++) {
    cin.ignore();
    cout << "Enter Title " << i << ": ";
    getline(cin, arrayPtr[i].title);

    cout << "Enter Director " << i << ": ";
    cin.ignore();
    getline(cin, arrayPtr[i].director);

    cout << "Enter Year Released " << i << ": ";
    cin >> arrayPtr[i].yearReleased;

    cout << "Enter running time (minutes) " << i << ": ";
    cin >> arrayPtr[i].runningTime;

    cout << endl;
  }
}

void displayMovieDataArray(MovieData* arrayPtr, int arraySize) {
  for(int i = 0; i < arraySize; i++) {
    cout << &arrayPtr[i] << ": arrayPtr[" << i << "] =" << endl;
    displayMovie(&arrayPtr[i]);
    cout << endl;
  }
}

MovieData* findLongestMovie(MovieData* arrayPtr, int arraySize) {
  int longestMovieIndex = 0;
  for(int i = 1; i < arraySize; i++) {
    if(arrayPtr[i].runningTime > arrayPtr[longestMovieIndex].runningTime) {
      longestMovieIndex = i;
    }    
  }
  return &arrayPtr[longestMovieIndex];
};

void displayMovie(MovieData* moviePtr) {
  cout << setw(9) << "" << "Title : " << moviePtr->title << endl;
  cout << setw(9) << "" << "Director : " << moviePtr->director << endl;
  cout << setw(9) << "" << "Released : " << moviePtr->yearReleased << endl;
  cout << setw(9) << "" << "Running Time : " << moviePtr->runningTime << " minutes long" << endl;
};
