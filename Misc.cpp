#include "stdafx.h"
#include "Misc.h"


sf::Texture Misc::createTexture(const char* texture_path) {
	sf::Texture blank_texture;
	blank_texture.loadFromFile(texture_path);

	return blank_texture;
}

sf::Sprite Misc::createSprite( float size_x, float size_y, sf::Texture &tex) {
	sf::Sprite blank_sprite;
	blank_sprite.setTexture(tex);
	blank_sprite.setScale(size_x, size_y);

	return blank_sprite;

}

sf::Text Misc::createText(const char* text, int character_size, sf::Font &font) {
	sf::Text blank_text;
	blank_text.setFont(font);
	blank_text.setString(text);
	blank_text.setCharacterSize(character_size);


	return blank_text;

}
