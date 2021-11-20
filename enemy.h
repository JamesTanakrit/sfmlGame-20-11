#pragma once
#include"AllHeader.h"
#include"player.h"

class Enemy
{
private:
	CircleShape shape;
	Vector2f direction;
	float speed;
	bool aggro;

	Player* player;

public:
	//constructor
	inline Enemy(float size, Vector2f position, float spd)
	{
		shape.setRadius(size);
		shape.setPosition(position);
		shape.setFillColor(Color::Color(randint(0, 255), randint(0, 255), randint(0, 255),255));
		shape.setOutlineThickness(2.5f);
		shape.setOutlineColor(Color::Black);
		speed = spd;
		aggro = false;
		player = nullptr;
	}

	inline void update(float deltaTime)
	{
		if (player != nullptr)
		{
			direction = nomalize(player->getPosition() - shape.getPosition());
			shape.move(direction * speed * deltaTime);
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

	inline void	collision(Player* player)
	{
		if (shape.getGlobalBounds().intersects(player->getGlobalBounds()))
		{
			this->player = player;
			setAggressive(true);
		}
	}

	inline void setPlayer(Player* player)
	{
		this->player = player;
	}

	inline void setAggressive(bool aggress)
	{
		aggro = aggress;
		if (aggro)
		{
			shape.setFillColor(Color::Red);
		}
		else
		{
			shape.setFillColor(Color::Green);
		}
	}

	inline Vector2f getPosition()
	{
		return shape.getPosition();
	}
};

