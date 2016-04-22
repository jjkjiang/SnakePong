#ifndef __STATE_H__
#define __STATE_H__

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>

// abstract base class
class State
{
public:
  virtual void update(const sf::Keyboard::Key&) = 0;
  virtual void drawState(sf::RenderWindow&) = 0;
};

#endif