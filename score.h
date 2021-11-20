#pragma once
#include"AllHeader.h"
#include"Button.h"

class score
{
private:
	Button returnButton;
	Font font;
	Texture scoreBoard;
	Sprite sprite;
	Text name[5];
	Text scores[5];


public:
	inline score()
	{
		returnButton.setup(Vector2f(435, 733), Vector2f(436, 76), nullptr, "", Color(0, 0, 0, 0), Color(0, 0, 0, 50), Color(0, 0, 0, 100));
		returnButton.isActive = true;
		scoreBoard.loadFromFile("score.png");
		sprite.setTexture(scoreBoard);
		font.loadFromFile("CONSOLA.TTF");
		readScore();
		for (size_t i = 0; i < 5; i++)
		{
			name[i].setFont(font);
			name[i].setFillColor(Color::Black);
			name[i].setCharacterSize(26);
			name[i].setPosition(Vector2f(300, 300) + Vector2f(0, 80*i));
			scores[i].setFont(font);
			scores[i].setFillColor(Color::Black);
			scores[i].setCharacterSize(26);
			scores[i].setPosition(Vector2f(600, 300) + Vector2f(0, 80 * i));
			name[i].setString(scoreData[i].name);
			scores[i].setString(to_string(scoreData[i].score));

		}
	}

	inline void update(RenderWindow& window)
	{
		Vector2f mousePos = Vector2f(Mouse::getPosition(window));
		returnButton.update(mousePos, setScene, MenuScene);
	}

	inline void render(RenderWindow& window)
	{
		window.draw(sprite);
		for (size_t i = 0; i < 5; i++)
		{
			window.draw(name[i]);
			window.draw(scores[i]);
		}
		returnButton.render(window);
	}

};