#ifndef __MENUSTATE_H__
#define __MENUSTATE_H__

#include "State.h"
#include "../GameObjects/TileMap.h"
#include "../GameObjects/Button.h"

class MenuState : public State {
private:
    TileMap menuBg;
    //int arrSize;
    //int activeIndex;
    //Button buttonArr[2];
    Button playButton;
    Button exitButton;
    sf::Text introText;
    sf::Text highScoreHeader;
    sf::Text highScore;
public:
    MenuState(sf::Font&, ScoreBoard*);
    virtual int update(sf::Keyboard::Key&, ScoreBoard*);
    virtual void drawState(sf::RenderWindow&);
};

#endif