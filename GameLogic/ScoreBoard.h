#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MAXSCORES = 5;
struct Score
{
  string name;
  int score;
  Score(string name,int score)
  {
    this->name = name;
    this->score = score;
  }
};

class ScoreBoard
{
private:
  string saveFile;
  //greatest score will be first in vector
  vector<Score> scores;
  vector<Score> read();
    int lastScore;
public:
    void setLastScore(const int&);
    int getLastScore();
    int getHighScoreInt();
  ScoreBoard(const string& filePath);
  void write(string name, int score);
  string getHighScore();

};

#endif
