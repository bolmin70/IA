#pragma once
class Init
{
public:

	static sf::Texture background_texture;
	static sf::Sprite background_block;


	static sf::Sprite menu_box[3];
	static sf::Text menu_label[3];

	static sf::Sprite input_box[10];
	static sf::Text input_field[9];


	static sf::Text input_label[7];

	static sf::Sprite sort_box[2];
	static sf::Text sort_label[2];


	static sf::Texture help_panel_texture;
	static sf::Texture help_panel_filled_texture;
	static sf::Texture help_panel_filled_selected_texture;

	static sf::Sprite help_panel;
	static sf::Text help_panel_text;
	static sf::Text help_panel_text2;


	static sf::Sprite grid_panel[20];
	static sf::Text grid_label[20];


	static sf::Texture sort_box_texture;
	static sf::Texture sort_box_texture_filled;
	static sf::Texture sort_box_texture_filled_selected;


	static sf::Texture box_texture;
	static sf::Texture box_texture_filled;
	static sf::Texture box_texture_filled_selected;

	static sf::Texture small_box_texture;
	static sf::Texture small_box_texture_filled;
	static sf::Texture small_box_texture_filled_selected;

	static sf::Texture tiny_box_texture;
	static sf::Texture tiny_box_texture_filled;
	static sf::Texture tiny_box_texture_filled_selected;

	static sf::Text welcome_text;
	static sf::Font main_font;

	static sf::Texture arrow_r_texture;
	static sf::Texture arrow_r_filled_texture;
	static sf::Texture arrow_r_selected_texture;

	static sf::Texture arrow_l_texture;
	static sf::Texture arrow_l_filled_texture;
	static sf::Texture arrow_l_selected_texture;

	static sf::Sprite arrow_r;
	static sf::Sprite arrow_l;


	static sf::Texture arrow_r_long_texture;
	static sf::Texture arrow_r_long_filled_texture;
	static sf::Texture arrow_r_long_selected_texture;

	static sf::Texture arrow_l_long_texture;
	static sf::Texture arrow_l_long_filled_texture;
	static sf::Texture arrow_l_long_selected_texture;

	static sf::Sprite arrow_r_long;
	static sf::Sprite arrow_l_long;
	
	static sf::Text page_text;


	static void initialize();

};

