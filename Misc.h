#pragma once
#include "stdafx.h"

class Misc
{
public:
	static sf::Texture createTexture(const char* texture_path);
	static sf::Sprite createSprite(float size_x, float size_y, sf::Texture &tex);
	
	static sf::Text createText(const char* text, int character_size, sf::Font &font);
	

};

