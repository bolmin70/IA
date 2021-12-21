#pragma once

enum class Menu_States {
	Boarding,
	Database,
	NewInput,
	Exit
};

class Menu_Global {
public:
	virtual void Menu_Page() = 0;
	static Menu_States state;


};

class MenuEvent {
public:
	static bool MenuEvent::clickEventHandler(sf::RenderWindow& window, sf::Event& menu, sf::Sprite& sprite, sf::Texture& defaultTexture, sf::Texture& selectedTexture, sf::Texture& filledTexture);
	static bool MenuEvent::clickEventHandler(sf::RenderWindow& window, sf::Event menu, sf::Sprite& sprite, sf::Texture& defaultTexture, sf::Texture& selectedTexture, sf::Texture& filledTexture, int condition);

};


class Menu_Boarding : Menu_Global {

public:
	virtual void Menu_Page();

};

class Menu_Database : Menu_Global {

public:
	virtual void Menu_Page();

};

class Menu_Input : Menu_Global {

public:
	virtual void Menu_Page();

};