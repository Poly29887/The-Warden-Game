
#include"Player.h"
class Game
{
private:
	sf::RenderWindow window;
	sf::Event evnt;
    
	Player* player;

	void initWindow();
	void initPlayer();

public:
	Game();
	
	//Funtions
	void updatePlayer();
	void update();
	void renderPlayer();
	void render();
	const sf::RenderWindow& getwindow() const;
};

