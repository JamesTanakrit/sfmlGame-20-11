#pragma once
#include"AllHeader.h"
#include"Button.h"

class Menu
{
private:
	Button startButton;
	Button scoreButton;
	Button quitButton;
	Texture menu;
	Sprite sprite;

public:
	inline Menu()
	{
		startButton.setup(Vector2f(466, 430), Vector2f(356, 96), nullptr, "", Color(0, 0, 0, 0), Color(0, 0, 0, 50), Color(0, 0, 0, 100));
		scoreButton.setup(Vector2f(466, 591), Vector2f(356, 96), nullptr, "", Color(0, 0, 0, 0), Color(0, 0, 0, 50), Color(0, 0, 0, 100));
		quitButton.setup(Vector2f(466, 753), Vector2f(356, 96), nullptr, "", Color(0, 0, 0, 0), Color(0, 0, 0, 50), Color(0, 0, 0, 100));
		startButton.isActive = true;
		scoreButton.isActive = true;
		quitButton.isActive = true;
		menu.loadFromFile("menu.png");
		sprite.setTexture(menu);
	}

	inline void update(RenderWindow& window)
	{
		Vector2f mousePos = Vector2f(Mouse::getPosition(window));
		startButton.update(mousePos, setScene, GameScene);
		scoreButton.update(mousePos, setScene, ScoreScene);
		quitButton.update<RenderWindow>(mousePos, &window, &RenderWindow::close);
	}

	inline void render(RenderWindow& window)
	{
		window.draw(sprite);
		startButton.render(window);
		scoreButton.render(window);
		quitButton.render(window);
	}

};

