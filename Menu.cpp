#include "stdafx.h"
#include "Menu.h"

Menu_States Menu_Global::state;

void Menu_Boarding::Menu_Page() {

}


bool MenuEvent::clickEventHandler(sf::RenderWindow& window, sf::Event& menu, sf::Sprite& sprite, sf::Texture& defaultTexture, sf::Texture& selectedTexture, sf::Texture& filledTexture) {
	if (sprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {

		if (menu.type == sf::Event::MouseButtonPressed && menu.key.code == sf::Mouse::Left) {
			sprite.setTexture(selectedTexture);
		}
		else {
			sprite.setTexture(filledTexture);
		}
		if (menu.type == sf::Event::MouseButtonReleased && menu.key.code == sf::Mouse::Left) {
			sprite.setTexture(filledTexture);

			return true;
		}
	}
	else {
		sprite.setTexture(defaultTexture);

	}
	return false;

}

bool MenuEvent::clickEventHandler(sf::RenderWindow& window, sf::Event menu, sf::Sprite& sprite, sf::Texture& defaultTexture, sf::Texture& selectedTexture, sf::Texture& filledTexture, int condition) {
	if (sprite.getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {

		if (menu.type == sf::Event::MouseButtonPressed && menu.key.code == sf::Mouse::Left) {
			sprite.setTexture(selectedTexture);
		}
		else {
			sprite.setTexture(filledTexture);
		}
		if (menu.type == sf::Event::MouseButtonReleased && menu.key.code == sf::Mouse::Left) {
			sprite.setTexture(filledTexture);

			return true;
		}
	}
	else {

		if (condition) {
			sprite.setTexture(selectedTexture);
		}
		else {
			sprite.setTexture(defaultTexture);
		}


	}
	return false;
}


