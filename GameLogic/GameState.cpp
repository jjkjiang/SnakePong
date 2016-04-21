#include "GameState.h"

GameState::GameState() {
    if (!gameMap.load(gameResPath, sf::Vector2u(pixelSizeX, pixelSizeY), level, xPixels, yPixels))
        throw std::runtime_error("Failed to load the tilemap probably because file was not found.");
    //snake = Snake();
}

void GameState::update(const sf::Keyboard::Key& press) {
    if (press == sf::Keyboard::LShift) {
        updateTime = 0.2;
    } else {
        updateTime = 1;
    }

    if (gameClock.getElapsedTime().asSeconds() >= updateTime) {
        int result = player1.updateSnake(press, player1Fruit.getPos());
        if (result == 1) {
            player1Fruit.resetFruit();
        }
        gameClock.restart();
    }
}

void GameState::drawState(sf::RenderWindow& window) {
    sf::RectangleShape square(sf::Vector2f(pixelSizeX,pixelSizeY));
    square.setPosition(borderLeft, borderTop);
    square.setFillColor(sf::Color::Green);

    window.clear();
    window.draw(gameMap);
    window.draw(square);
    player1Fruit.drawFruit(window);
    player1.displaySnake(window);
    window.display();
}
