#include "stdafx.h"
#include "Player.h"

void Player::initVariables()
{
	this->moving = false;
}

void Player::initTexture()
{
	
	if (!this->textureSheet.loadFromFile("character/SC01-idle_right.png"))
	{
		std::cout << "ERROR::PLAYER::could not load the player sheet!" << "\n";
	}
}

void Player::initSprite()
{
	this->sprite.setTexture(this->textureSheet);
	this->currentFrame=sf::IntRect(0,0,567,556);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.setScale(0.3f, 0.3f);
}

void Player::initAnimation()
{
	this->animationTimer.restart();
}

Player::Player()
{
	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimation();
}


void Player::updateMovement()
{
	this->moving = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) //Left
	{
		this->sprite.move(-1.f, 0.f);
		this->moving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) //Right
	{
		this->sprite.move(1.f, 0.f);
		this->moving = true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) //Top
	{
		this->sprite.move(0.f, -1.f);
		this->moving = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) //Down
	{
		this->sprite.move(0.f, 1.f);
		this->moving = true;
	}
}

void Player::updateAnimation()
{
	if (this->animationTimer.getElapsedTime().asSeconds() >= 0.5f)
	{


		if (this->moving == false) //IDLE Animation
		{
			this->currentFrame.left += 567.f;
			if (this->currentFrame.left >= 5103.f)
			{
				this->currentFrame.left = 0;
			}
		}
	   this->animationTimer.restart();
	   this->sprite.setTextureRect(this->currentFrame);
	}
}

void Player::update()
{
	this->updateMovement();
	this->updateAnimation();
}

void Player::render(sf::RenderTarget & target)
{
	target.draw(this->sprite);
}
