#pragma once
#include"AllHeader.h"

class Bullet
{
private:
	RectangleShape shape;
	Vector2f direction;
	float speed;

public:
	inline Bullet(Vector2f position, Vector2f direction, float speed)
	{
		shape.setSize(Vector2f(5.f, 5.f));
		shape.setPosition(position);
		shape.setFillColor(Color::Yellow);
		this->speed = speed;
		this->direction = direction;
	}

	inline void update(float deltaTime)
	{
		shape.move(nomalize(direction) * speed * deltaTime);
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
};

