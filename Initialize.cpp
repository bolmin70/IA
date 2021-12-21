#include "stdafx.h"
#include "Initialize.h"
#include "Data.h"

using namespace std;

sf::Texture Init::background_texture;
sf::Sprite Init::background_block;


sf::Sprite Init::menu_box[3];
sf::Text Init::menu_label[3];

sf::Sprite Init::input_box[10];
sf::Text Init::input_field[9];


sf::Text Init::input_label[7];

sf::Sprite Init::sort_box[2];
sf::Text Init::sort_label[2];


sf::Texture Init::help_panel_texture;
sf::Texture Init::help_panel_filled_texture;
sf::Texture Init::help_panel_filled_selected_texture;

sf::Sprite Init::help_panel;
sf::Text Init::help_panel_text;
sf::Text Init::help_panel_text2;


sf::Sprite Init::grid_panel[20];
sf::Text Init::grid_label[20];


sf::Texture Init::sort_box_texture;
sf::Texture Init::sort_box_texture_filled;
sf::Texture Init::sort_box_texture_filled_selected;


sf::Texture Init::box_texture;
sf::Texture Init::box_texture_filled;
sf::Texture Init::box_texture_filled_selected;

sf::Texture Init::small_box_texture;
sf::Texture Init::small_box_texture_filled;
sf::Texture Init::small_box_texture_filled_selected;

sf::Texture Init::tiny_box_texture;
sf::Texture Init::tiny_box_texture_filled;
sf::Texture Init::tiny_box_texture_filled_selected;

sf::Text Init::welcome_text;
sf::Font Init::main_font;

sf::Texture Init::arrow_r_texture;
sf::Texture Init::arrow_r_filled_texture;
sf::Texture Init::arrow_r_selected_texture;

sf::Texture Init::arrow_l_texture;
sf::Texture Init::arrow_l_filled_texture;
sf::Texture Init::arrow_l_selected_texture;

sf::Sprite Init::arrow_r;
sf::Sprite Init::arrow_l;


sf::Texture Init::arrow_l_long_texture;
sf::Texture Init::arrow_l_long_filled_texture;
sf::Texture Init::arrow_l_long_selected_texture;

sf::Sprite Init::arrow_r_long;
sf::Sprite Init::arrow_l_long;


sf::Text Init::page_text;


void Init::initialize() {

	main_font.loadFromFile("Graphic/Silver.ttf");



	welcome_text = Misc::createText("Welcome", 200, main_font);


	background_texture = Misc::createTexture("Graphic/main_back.png");
	background_block = Misc::createSprite(4.0f, 5.0f, background_texture);

	sort_box_texture = Misc::createTexture("Graphic/box_alt.png");
	sort_box_texture_filled = Misc::createTexture("Graphic/box_alt_filled.png");
	sort_box_texture_filled_selected = Misc::createTexture("Graphic/box_alt_selected.png");


	box_texture = Misc::createTexture("Graphic/block.png");
	box_texture_filled = Misc::createTexture("Graphic/block_filled.png");
	box_texture_filled_selected = Misc::createTexture("Graphic/block_selected.png");

	small_box_texture = Misc::createTexture("Graphic/small_block.png");
	small_box_texture_filled = Misc::createTexture("Graphic/small_block_filled.png");
	small_box_texture_filled_selected = Misc::createTexture("Graphic/small_block_selected.png");

	tiny_box_texture = Misc::createTexture("Graphic/tiny_block.png");
	tiny_box_texture_filled = Misc::createTexture("Graphic/tiny_block_filled.png");
	tiny_box_texture_filled_selected = Misc::createTexture("Graphic/tiny_block_selected.png");



	for (int i = 0; i < 2; i++) {
		sort_box[i] = Misc::createSprite(2.0f, 2.0f, sort_box_texture);
	}
	for (int i = 0; i < 3; i++) {
		menu_box[i] = Misc::createSprite(3.4f, 3.4f, box_texture);
	}

	for (int i = 0; i < 9; i++) {
		input_field[i] = Misc::createText("", 100, main_font);
	}
	for (int i = 0; i < 4; i++) {
		input_box[i] = Misc::createSprite(2.4f, 2.4f, box_texture);

	}

	for (int i = 4; i < 6; i++) {
		input_box[i] = Misc::createSprite(2.3f, 2.1f, small_box_texture);

	}

	for (int i = 6; i < 9; i++) {
		input_box[i] = Misc::createSprite(2.3f, 2.1f, tiny_box_texture);
	}

	input_box[9] = Misc::createSprite(2.3f, 2.1f, small_box_texture);



	help_panel_filled_texture = Misc::createTexture("Graphic/help_panel_filled.png");
	help_panel_filled_selected_texture = Misc::createTexture("Graphic/help_panel_filled_selected.png");
	help_panel_texture = Misc::createTexture("Graphic/help_panel.png");

	help_panel = Misc::createSprite(3.4f, 4.0f, help_panel_texture);

	help_panel_text = Misc::createText("", 80, main_font);
	help_panel_text2 = Misc::createText("\nProvide the details of\nthe training session", 80, main_font);



	for (int i = 0; i < 20; i++) {
		grid_panel[i] = Misc::createSprite(1.0f, 1.0f, help_panel_texture);
		stringstream Date;

		if (Data::trainingData.day[i] < 10) {
			Date << "0" << Data::trainingData.day[i] << ".";
		}
		else {
			Date << Data::trainingData.day[i] << ".";
		}

		if (Data::trainingData.month[i] < 10) {
			Date << "0" << Data::trainingData.month[i] << ".";
		}
		else {
			Date << Data::trainingData.month[i] << ".";
		}

		if (Data::trainingData.year[i] < 10) {
			Date << "0" << Data::trainingData.year[i];
		}
		else {
			Date << Data::trainingData.year[i];
		}

		grid_label[i] = Misc::createText(Date.str().c_str(), 50, main_font);
	}


	arrow_r_texture = Misc::createTexture("Graphic/arrow_r.png");
	arrow_r_filled_texture = Misc::createTexture("Graphic/arrow_r_filled.png");
	arrow_r_selected_texture = Misc::createTexture("Graphic/arrow_r_selected.png");

	arrow_r = Misc::createSprite(3.4f, 3.4f, arrow_r_texture);

	arrow_l_texture = Misc::createTexture("Graphic/arrow_l.png");
	arrow_l_filled_texture = Misc::createTexture("Graphic/arrow_l_filled.png");
	arrow_l_selected_texture = Misc::createTexture("Graphic/arrow_l_selected.png");


	arrow_l = Misc::createSprite(3.4f, 3.4f, arrow_l_texture);

	arrow_l_long_texture = Misc::createTexture("Graphic/arrow_l_long.png");
	arrow_l_long_filled_texture = Misc::createTexture("Graphic/arrow_l_long_filled.png");
	arrow_l_long_selected_texture = Misc::createTexture("Graphic/arrow_l_long_selected.png");


	arrow_r_long = Misc::createSprite(3.4f, 2.8f, arrow_l_long_texture);


	arrow_l_long = Misc::createSprite(3.4f, 2.8f, arrow_l_long_texture);






	input_label[0] = Misc::createText("Date", 100, main_font);
	input_label[1] = Misc::createText("Time", 100, main_font);
	input_label[2] = Misc::createText("Distance", 100, main_font);
	input_label[3] = Misc::createText("Avg Speed", 100, main_font);
	input_label[4] = Misc::createText("Avg Power", 100, main_font);
	input_label[5] = Misc::createText("Intensity", 100, main_font);

	input_label[6] = Misc::createText("Proceed", 80, main_font);


	menu_label[0] = Misc::createText("New Session", 100, main_font);
	menu_label[1] = Misc::createText("Session Database", 100, main_font);
	menu_label[2] = Misc::createText("Exit", 100, main_font);

	sort_label[0] = Misc::createText("By Date", 50, main_font);
	sort_label[1] = Misc::createText("By Performance", 50, main_font);




	page_text = Misc::createText("", 80, main_font);


}
