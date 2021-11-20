#pragma once
#include"AllHeader.h"
#define BulletSpeed 0
#define SlowEnemy 1
#define DoubleScore 2

class Item
{
private:
	RectangleShape shape;
	float lifeTime;
	
public:
	int tag;
	bool died;

	inline Item(Vector2f position, Vector2f size, int tag, Texture* texture = nullptr)
	{
		shape.setPosition(position);
		shape.setSize(size);
		shape.setTexture(texture);
		lifeTime = 5;
		died = false;
		this->tag = tag;
		if (tag == BulletSpeed)
		{
			shape.setFillColor(Color::Red);
			shape.setOutlineThickness(2.5f);
			shape.setOutlineColor(Color::Black);
		}
		else if (tag == SlowEnemy)
		{
			shape.setFillColor(Color::Cyan);
			shape.setOutlineThickness(2.5f);
			shape.setOutlineColor(Color::Black);
		}
		else if (tag == DoubleScore)
		{
			shape.setFillColor(Color::Yellow);
			shape.setOutlineThickness(2.5f);
			shape.setOutlineColor(Color::Black);
		}
	}
	
	inline bool isPickedUp(FloatRect bound)
	{
		return shape.getGlobalBounds().intersects(bound);
	}

	inline void render(RenderWindow& window)
	{
		window.draw(shape);
	}

	inline void update(float deltaTime)
	{
		lifeTime -= deltaTime;
		if (lifeTime < 0)
		{
			died = true;
		}
	}
};

