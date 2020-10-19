#include "stdafx.h"
#include "Game.h"

void Game::initWindow()
{
	this->window.create(sf::VideoMode(1080,720),"The Warden",sf::Style::Close|sf::Style::Titlebar);
	this->window.setFramerateLimit(200);
}

void Game::initPlayer()
{
	this->player = new Player();
}

Game::Game()
{
	this->initWindow();
	this->initPlayer();
}


void Game::updatePlayer()
{
	this->player->update();
}

void Game::update()
{

	//Polling Window Event
	while (this->window.pollEvent(this->evnt))
	{
		if (this->evnt.type == sf::Event::Closed)
		{
			this->window.close();
		}
		else if (this->evnt.type == sf::Event::KeyPressed && this->evnt.key.code==sf::Keyboard::Escape)
		{
			this->window.close();
		}
		this->updatePlayer();
	}

	
}

void Game::renderPlayer()
{
	this->player->render(this->window);
}

void Game::render()
{
	this->window.clear();

	//Render Game
	this->renderPlayer();
	this->window.display();

}

const sf::RenderWindow & Game::getwindow() const
{
	return this->window;
}
