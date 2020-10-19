#pragma once
class Player
{
private:
	sf::Sprite sprite;
	sf::Texture textureSheet;
	bool moving{};
	sf::Clock animationTimer;

	//Animation
	sf::IntRect currentFrame;

	//Movement

	//Core Ex:HP

	void initVariables();
	void initTexture();
	void initSprite();
	void initAnimation();
	
public:
	Player();

	//Funtions
	void updateMovement();
	void updateAnimation();
	void update();
	void render(sf::RenderTarget& target);
};

