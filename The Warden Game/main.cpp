#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Player.h"


static const float VIEW_HEIGHT = 1000.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 720), "The Warden",sf::Style::Close|sf::Style::Titlebar | sf::Style::Resize);
    sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
    sf::Sprite background;

    /*sf::Music music;
        if (!music.openFromFile("D:\Programming Project\The Warden Game\The Warden Game\sound"))
        {
            std::cout << "Load music failed" << std::endl;
    }*/
    
    //sf::RectangleShape block(sf::Vector2f(100.0f, 200.0f));
    //block.setFillColor(sf::Color::Blue);

    /*sf::Sprite player;
    player.setScale(3.0f, 3.0f);
    player.setPosition(100.f,400.f);*/

    sf::Texture playerTexture,backgroundTexture;
    playerTexture.loadFromFile("character_1/hero_spritesheet.png");
    backgroundTexture.loadFromFile("background/bg4.png");
    background.setTexture(backgroundTexture);
    //background.setScale(1.5f, 1.5f);
    //player.setTexture(playerTexture);
    
   /* if (!playerTexture.loadFromFile("character_1/hero_spritesheet.png"))
    {
        std::cout << "Load player failed" << std::endl;
    }*/
    

    Player player(&playerTexture,sf::Vector2u(10,10),0.1f,150.0f);


    /*sf::Vector2u spriteSize = playerTexture.getSize() ;
    spriteSize.x /= 10;
    spriteSize.y /= 10;

    player.setTextureRect(sf::IntRect(spriteSize.x * 3, spriteSize.y * 4, spriteSize.x, spriteSize.y));*/
    

    float deltaTime = 0.0f;
    sf::Clock clock;

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();

        sf::Event evnt;
        while (window.pollEvent(evnt))
        {
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            /*case sf::Event::Resized:
                ResizeView(window, view);
                break;*/
            }
        }
       

        player.update(deltaTime);

        //platform1.GetCollider().CheckCollision(player.GetCollider(), 0.0f);
       // platform2.GetCollider().CheckCollision(player.GetCollider(), 1.0f);

       view.setCenter(player.GetPosition());

        window.clear();
        //music.play();
        window.draw(background);
        window.setView(view);
        player.draw(window);
        //platform1.draw(window);
        //platform2.draw(window);

        window.display();



    }
}