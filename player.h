#pragma once
#include"AllHeader.h"

class Player
{
private:
	RectangleShape shape;
	Vector2f direction;
	float speed;

public:
	//constructor
	inline Player()
	{
		shape.setSize(Vector2f(40.f, 40.f));
		shape.setPosition(Vector2f(620.f, 460.f));
		speed = 150;
	}

	inline void update(float deltaTime)
	{
		direction = Vector2f(0.f, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			direction.y -= 1;
		}
		if (Keyboard::isKeyPressed(Keyboard::A))
		{
			direction.x -= 1;
		}
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			direction.y += 1;
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			direction.x += 1;
		}
		shape.move(nomalize(direction) * speed * deltaTime);
		if (shape.getPosition().y < 50)
		{
			shape.setPosition(Vector2f(shape.getPosition().x, 50));
		}
		if (shape.getPosition().y > 870)
		{
			shape.setPosition(Vector2f(shape.getPosition().x, 870));
		}
		if (shape.getPosition().x < 50)
		{
			shape.setPosition(Vector2f(50, shape.getPosition().y));
		}
		if (shape.getPosition().x > 1190)
		{
			shape.setPosition(Vector2f(1190, shape.getPosition().y));
		}
		//warp

		if (shape.getPosition().x == 50 && shape.getPosition().y == 870)
		{
			int warpRan = randint(1, 3);
			if (warpRan == 1)
			{
				shape.setPosition(Vector2f(51, 51));
			}
			else if (warpRan == 2)
			{
				shape.setPosition(Vector2f(1189, 51));
			}
			else if (warpRan == 3)
			{
				shape.setPosition(Vector2f(1189, 869));
			}
		}
		if (shape.getPosition().x == 50 && shape.getPosition().y == 50)
		{
			int warpRan = randint(1, 3);
			if (warpRan == 1)
			{
				shape.setPosition(Vector2f(51, 871));
			}
			else if (warpRan == 2)
			{
				shape.setPosition(Vector2f(1189, 51));
			}
			else if (warpRan == 3)
			{
				shape.setPosition(Vector2f(1189, 869));
			}
		}
		if (shape.getPosition().x == 1190 && shape.getPosition().y == 50)
		{
			int warpRan = randint(1, 3);
			if (warpRan == 1)
			{
				shape.setPosition(Vector2f(51, 51));
			}
			else if (warpRan == 2)
			{
				shape.setPosition(Vector2f(51, 869));
			}
			else if (warpRan == 3)
			{
				shape.setPosition(Vector2f(1189, 869));
			}
		}
		if (shape.getPosition().x == 1190 && shape.getPosition().y == 870)
		{
			int warpRan = randint(1, 3);
			if (warpRan == 1)
			{
				shape.setPosition(Vector2f(51, 51));
			}
			else if (warpRan == 2)
			{
				shape.setPosition(Vector2f(1189, 51));
			}
			else if (warpRan == 3)
			{
				shape.setPosition(Vector2f(51, 869));
			}
		}
	}

	inline void render(RenderWindow& window)
	{
		window.draw(shape);
	}

	inline FloatRect getGlobalBounds()
	{
		return shape.getGlobalBounds();
	}

	inline Vector2f getPosition()
	{
		return shape.getPosition();
	}

	inline Vector2f getSize()
	{
		return shape.getSize();
	}

	inline void setPosition(Vector2f position)
	{
		shape.setPosition(position);
	}
};