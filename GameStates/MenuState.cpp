#include "MenuState.h"
#include "../Definitions/ResolutionVariables.h"
#include "../Definitions/TileMapArr.h"

MenuState::MenuState(sf::Font& mainFont, ScoreBoard* scoreBoard) {
    if (!menuBg.load(menuResPath, sf::Vector2u(pixelSizeX, pixelSizeY), level, xPixels, yPixels))
        throw std::runtime_error("Failed to load the tilemap probably because file was not found.");

    sf::Vector2f playButtonLocation(screenResWidth / 2 - buttonSizeX / 2, screenResHeight / 2 - buttonSizeY / 2);
    sf::Vector2f exitButtonLocation(playButtonLocation);
    exitButtonLocation.y += buttonSizeY * 2;
    playButton = Button("PLAY", playButtonLocation, mainFont);
    exitButton = Button("EXIT", exitButtonLocation, mainFont);
    playButton.activate();

    introText.setString("SNAKE!");
    introText.setColor(sf::Color(84, 191, 88));
    introText.setPosition(screenResWidth / 2 - buttonSizeX + pixelSizeX, screenResHeight / 2 - 3 * buttonSizeY);
    introText.setCharacterSize(210);
    introText.setFont(mainFont);

    highScore.setString(scoreBoard->getHighScore());
    highScore.setCharacterSize(pixelSizeX * 3);
    highScore.setPosition(pixelSizeX * 2, screenResHeight / 2 + pixelSizeY * 3);
    highScore.setFont(mainFont);

    highScoreHeader.setString("Highscore");
    highScoreHeader.setCharacterSize(pixelSizeX * 3);
    highScoreHeader.setPosition(0, screenResHeight / 2);
    highScoreHeader.setFont(mainFont);
    //buttonArr[0] = playButton;
    //buttonArr[1] = exitButton;
    //arrSize = 2;
    //activeIndex = 0;
    //snakeLogo;
}

int MenuState::update(sf::Keyboard::Key& press, ScoreBoard* scoreBoard) {
    highScore.setString(scoreBoard->getHighScore());

    if (press == sf::Keyboard::Down) {
        if (playButton.isActive()) {
            playButton.deactivate();
            exitButton.activate();
        } else if (exitButton.isActive()) {
            exitButton.deactivate();
            playButton.activate();
        }
        press = sf::Keyboard::Left;
    }
    if (press == sf::Keyboard::Up) {
        if (playButton.isActive()) {
            playButton.deactivate();
            exitButton.activate();
        } else if (exitButton.isActive()) {
            exitButton.deactivate();
            playButton.activate();
        }
        press = sf::Keyboard::Left;
    }
    if (press == sf::Keyboard::Return) {
        press = sf::Keyboard::Unknown;
        if (playButton.isActive()) return 1;
        if (exitButton.isActive()) return -1;
    }
    return 0;
}

void MenuState::drawState(sf::RenderWindow& window) {
    window.clear();
    window.draw(menuBg);
    window.draw(highScoreHeader);
    window.draw(highScore);
    playButton.drawButton(window);
    exitButton.drawButton(window);
    window.draw(introText);
    window.display();
}