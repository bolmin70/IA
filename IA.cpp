#include "stdafx.h"
#include "Data.h"
#include "Sorting.h"
#include "Initialize.h"
#include "Menu.h"

using namespace std;


int grid_selected;


int main()
{
	
	srand(time(NULL));




	sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "IA"); 
	window.setFramerateLimit(60); 
	//sf::Image image;
	//image.loadFromFile("Graphic/icon.png");
	//window.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());

	

	
	sf::Clock fadeclock;
	

	//music
	sf::Music mmusic1;
	mmusic1.openFromFile("Music/crimson.flac");
	mmusic1.setVolume(80);

	//misc
	sf::RectangleShape fade;
	fade.setPosition(sf::Vector2f(0, 0));
	fade.setFillColor(sf::Color(0, 0, 0, 0));
	fade.setSize(sf::Vector2f(1920, 1080));


	sf::SoundBuffer popupb;
	popupb.loadFromFile("Music/pop_up.ogg");
	sf::Sound popup;
	popup.setBuffer(popupb);
	popup.setVolume(50);

	Init::initialize();


	std::string playerInput[9];

	int input_selected = -1;

	bool sortingOrder = 0;

	bool sortingType = 0;

	int page = -1;

	int page_display = 1;

	Data::Load();

 menu:for (;; ) {
		window.clear();
		Init::background_block.setPosition(30, 30);
		window.draw(Init::background_block);
		
		
		Init::welcome_text.setPosition(500, 350);
		 window.draw(Init::welcome_text);
		 

		 for (int i = 0; i < 3; i++) {
			 Init::menu_box[i].setPosition(1230, 100 + 320 * i);
			 window.draw(Init::menu_box[i]);

			 Init::menu_label[i].setPosition(1300, 140 + 320 * i);
			 window.draw(Init::menu_label[i]);
			
		 }

		
		
		sf::Event menu;
		while (window.pollEvent(menu)) {

			if (menu.type == sf::Event::Closed) {
				return 0;
				window.close();
				
			}

			for (int i = 0; i < 3; i++) {
				if (Init::menu_box[i].getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {

					if (menu.type == sf::Event::MouseButtonPressed && menu.key.code == sf::Mouse::Left) {
						Init::menu_box[i].setTexture(Init::box_texture_filled_selected);
					}
					else {
						Init::menu_box[i].setTexture(Init::box_texture_filled);
					}
					if (menu.type == sf::Event::MouseButtonReleased && menu.key.code == sf::Mouse::Left) {
						Init::menu_box[i].setTexture(Init::box_texture);
						switch (i) {
						case 0:
							goto input;
							break;
						case 1:
							//randomInputs(30);
							goto database;					
							break;
						case 2:
							Data::Save();

							return 0;						
							window.close();
							break;
						}
					}
				}
				else {
					Init::menu_box[i].setTexture(Init::box_texture);
				}
			}
		
			
		}

		window.display();

		
	}

database:for (;; ) {
		window.clear();
		
		Init::background_block.setPosition(30, 30);
		window.draw(Init::background_block);
		
		Init::help_panel.setPosition(1215, 30);
		window.draw(Init::help_panel);
		
		Init::help_panel_text.setPosition(1300, 30);
		window.draw(Init::help_panel_text);

		Init::menu_box[0].setPosition(1230, 740);
		window.draw(Init::menu_box[0]);
		Init::menu_label[2].setPosition(1300, 140 + 320 * 2);
		window.draw(Init::menu_label[2]);





		int x = 0;
		int y = 0;

		

		for (int i = 1; i < 21; i++) {

			if (i > 0) {
				x = i;
				y = 1;
			}
			if (i > 5) {
				x = i - 5;
				y = 2;
			}
			if (i > 10) {
				x = i - 10;
				y = 3;
			}
			if (i > 15) {
				x = i - 15;
				y = 4;
			}
			if (i > 20) {
				x = i - 20;
				y = 5;
			}

			Init::grid_panel[i - 1].setPosition(200 * x - 70, 200 * y - 50);
			window.draw(Init::grid_panel[i - 1]);
			
			stringstream Date;
			
			if (Data::trainingData.day[i + page] < 10) {
				Date << "0" <<Data::trainingData.day[i + page] << ".";
			}
			else {
				Date << Data::trainingData.day[i + page] << ".";
			}

			if (Data::trainingData.month[i + page] < 10) {
				Date << "0" <<Data::trainingData.month[i + page] << ".";
			}
			else {
				Date << Data::trainingData.month[i + page] << ".";
			}

			if (Data::trainingData.year[i + page] < 10) {
				Date << "0" <<Data::trainingData.year[i + page];
			}
			else {
				Date << Data::trainingData.year[i + page];
			}

			Init::grid_label[i - 1].setString(Date.str().c_str());
			Init::grid_label[i - 1].setPosition(200 * x - 28, 200 * y + 10);
			window.draw(Init::grid_label[i - 1]);


		}

		for (int i = 0; i < 2; i++) {
			Init::sort_box[i].setPosition(400 + 270 * i, 70);
			window.draw(Init::sort_box[i]);

			Init::sort_label[i].setPosition(420 + 270 * i, 75);
			window.draw(Init::sort_label[i]);

		}

		Init::arrow_l.setRotation(90);
		Init::arrow_l.setPosition(250, 10);
		window.draw(Init::arrow_l);

		Init::arrow_r.setRotation(90);
		Init::arrow_r.setPosition(370, 10);
		window.draw(Init::arrow_r);

		if (page_display != 1) {
			Init::arrow_l_long.setRotation(0);
			Init::arrow_l_long.setPosition(400, 905);
			window.draw(Init::arrow_l_long);
		}

		if (page_display != 18) {
			Init::arrow_r_long.setRotation(180);
			Init::arrow_r_long.setPosition(900, 1023);
			window.draw(Init::arrow_r_long);
		}


		
		stringstream helpStream;
		helpStream << "\nTime: " << Data::trainingData.hours[grid_selected + 1 + page] << "H " << Data::trainingData.minutes[grid_selected + 1 + page] << "min \nDistance: " << Data::trainingData.distance[grid_selected + 1 + page]
			<< "km \nDate: " << Data::trainingData.day[grid_selected + 1 + page] << "." << Data::trainingData.month[grid_selected + 1 + page] << "." << Data::trainingData.year[grid_selected + 1 + page] << "\nAvg Speed: "
			<< Data::trainingData.speed[grid_selected + 1 + page] << "km/h" << "\nAvg Power: " << Data::trainingData.power[grid_selected + 1 + page] << "W";


		Init::help_panel_text.setString(helpStream.str().c_str());
			
		if (page_display == 1) {
			page = -1;
		}
		else {
			page = 20 * (page_display - 1);
		}
		stringstream pageStream;
		pageStream << page_display;
		Init::page_text.setString(pageStream.str().c_str());

		Init::page_text.setPosition(635, 905);
		window.draw(Init::page_text);

		sf::Event menu;
		while (window.pollEvent(menu)) {

			if (menu.type == sf::Event::Closed) {
				return 0;
				window.close();

			}

		

			for (int i = 0; i < 20; i++) {
				if (Init::grid_panel[i].getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
					Init::grid_panel[i].setTexture(Init::help_panel_filled_texture);
					if (menu.type == sf::Event::MouseButtonReleased && menu.key.code == sf::Mouse::Left) {
						//grid_panel[i].setTexture(help_panel_filled_selected_texture);
						grid_selected = i;
					}
				}
				else {
					Init::grid_panel[i].setTexture(Init::help_panel_texture);

				}
			}


			if (MenuEvent::clickEventHandler(window, menu, Init::menu_box[0], Init::box_texture, Init::box_texture_filled_selected, Init::box_texture_filled)) {
				goto menu;
			}

			if (MenuEvent::clickEventHandler(window, menu, Init::sort_box[0], Init::sort_box_texture, Init::sort_box_texture_filled_selected, Init::sort_box_texture_filled, !sortingOrder)) {
				Sorting::bubbleSortUpDate(Sorting::cellCheck());
				sortingOrder = 0;
			}

			if (MenuEvent::clickEventHandler(window, menu, Init::sort_box[1], Init::sort_box_texture, Init::sort_box_texture_filled_selected, Init::sort_box_texture_filled, sortingOrder)) {
				Sorting::bubbleSortUpPower(Sorting::cellCheck());
				sortingOrder = 1;
			}

			if (MenuEvent::clickEventHandler(window, menu, Init::arrow_l, Init::arrow_l_texture, Init::arrow_l_selected_texture, Init::arrow_l_filled_texture, !sortingType)) {
				if (sortingOrder) {
					Sorting::bubbleSortUpPower(Sorting::cellCheck());
				}
				else {
					Sorting::bubbleSortUpDate(Sorting::cellCheck());
				}
				sortingType = 0;
			}

			if (MenuEvent::clickEventHandler(window, menu, Init::arrow_r, Init::arrow_r_texture, Init::arrow_r_selected_texture, Init::arrow_r_filled_texture, sortingType)) {
				if (sortingOrder) {
					Sorting::bubbleSortDownPower(Sorting::cellCheck());
				}
				else {
					Sorting::bubbleSortDownDate(Sorting::cellCheck());
				}
				sortingType = 1;
			}

			if (MenuEvent::clickEventHandler(window, menu, Init::arrow_r_long, Init::arrow_l_long_texture, Init::arrow_l_long_selected_texture, Init::arrow_l_long_filled_texture, sortingType)) {
				if (page_display < 18) {
					page_display++;
				}
				
			}
			if (MenuEvent::clickEventHandler(window, menu, Init::arrow_l_long, Init::arrow_l_long_texture, Init::arrow_l_long_selected_texture, Init::arrow_l_long_filled_texture, sortingType)) {
				if (page > 1) {
					page_display--;
				}
			}

		}


		Init::grid_panel[grid_selected].setTexture(Init::help_panel_filled_selected_texture);


		window.display();
	}
	
input:for (;; ) {
	window.clear();

	Init::background_block.setPosition(30, 30);
	window.draw(Init::background_block);


	for (int i = 0; i < 9; i++) {

		if (i < 4) {
			Init::input_box[i].setPosition(370, 360 + 160 * i);
			Init::input_box[i].setScale(2.4f, 2.4f);
			window.draw(Init::input_box[i]);

			Init::input_field[i].setPosition(390, 360 + 160 * i);
			window.draw(Init::input_field[i]);

		}

		if (i >= 4 && i < 6) {
			Init::input_box[i].setPosition(372 + 235 * (i - 4), 220);
			Init::input_box[i].setScale(2.3f, 2.1f);
			window.draw(Init::input_box[i]);

			Init::input_field[i].setPosition(450 + 235 * (i - 4), 215);
			window.draw(Init::input_field[i]);

		}

		if (i >= 6 && i < 9) {
			Init::input_box[i].setPosition(372 + 157 * (i - 6), 80);
			Init::input_box[i].setScale(2.3f, 2.1f);
			window.draw(Init::input_box[i]);

			Init::input_field[i].setPosition(415 + 158 * (i - 6), 75);
			window.draw(Init::input_field[i]);

		}

		if (i < 6) {
			Init::input_label[i].setPosition(80, 50 + 160 * i);
			window.draw(Init::input_label[i]);
		}
	}

	


	Init::help_panel.setPosition(1215, 30);
	window.draw(Init::help_panel);

	Init::menu_box[0].setPosition(1230, 740);
	window.draw(Init::menu_box[0]);
	Init::menu_label[2].setPosition(1300, 140 + 320 * 2);
	window.draw(Init::menu_label[2]);

	Init::help_panel_text2.setPosition(1300, 30);
	window.draw(Init::help_panel_text2);

	Init::input_box[9].setPosition(930, (360 + 160 * 3) + 10);
	Init::input_box[9].setScale(2.3f, 2.1f);
	window.draw(Init::input_box[9]);
	
	Init::input_label[6].setPosition(950, (360 + 160 * 3) + 20);
	window.draw(Init::input_label[6]);


	sf::Event menu;
	while (window.pollEvent(menu)) {

		if (menu.type == sf::Event::Closed) {
			return 0;
			window.close();

		}

		if (input_selected != -1) {

			if (menu.type == sf::Event::TextEntered)
			{
				if (menu.text.unicode == '\b') {
					if (playerInput[input_selected].size() > 0) {
						playerInput[input_selected].erase(playerInput[input_selected].size() - 1, 1);
						Init::input_field[input_selected].setString(playerInput[input_selected]);
					}
				}
				else {
					int letter_limit = 4;
					if (input_selected < 4) {
						letter_limit = 4;
					}
					if (input_selected >= 4) {
						letter_limit = 1;
					}


					if (playerInput[input_selected].size() <= letter_limit) {
						playerInput[input_selected] += menu.text.unicode;
						Init::input_field[input_selected].setString(playerInput[input_selected]);
					}
				}
			}
		}
		if (menu.type == sf::Event::MouseButtonReleased && menu.key.code == sf::Mouse::Left) {
			input_selected = -1;
		}
		for (int i = 0; i < 4; i++) {
			if (Init::input_box[i].getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
				Init::input_box[i].setTexture(Init::box_texture_filled);
				if (menu.type == sf::Event::MouseButtonReleased && menu.key.code == sf::Mouse::Left) {
					//grid_panel[i].setTexture(help_panel_filled_selected_texture);
					input_selected = i;
				}
			}
			else {
				Init::input_box[i].setTexture(Init::box_texture);
				
			}
		}
		for (int i = 4; i < 6; i++) {
			if (Init::input_box[i].getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
				Init::input_box[i].setTexture(Init::small_box_texture_filled);
				if (menu.type == sf::Event::MouseButtonReleased && menu.key.code == sf::Mouse::Left) {

					input_selected = i;
				}
			}
			else {
				Init::input_box[i].setTexture(Init::small_box_texture);

			}
		}
		for (int i = 6; i < 9; i++) {
			if (Init::input_box[i].getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {
				Init::input_box[i].setTexture(Init::tiny_box_texture_filled);
				if (menu.type == sf::Event::MouseButtonReleased && menu.key.code == sf::Mouse::Left) {

					input_selected = i;
				}
			}
			else {
				Init::input_box[i].setTexture(Init::tiny_box_texture);

			}
		}




		if (Init::menu_box[0].getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {

			if (menu.type == sf::Event::MouseButtonPressed && menu.key.code == sf::Mouse::Left) {
				Init::menu_box[0].setTexture(Init::box_texture_filled_selected);
			}
			else {
				Init::menu_box[0].setTexture(Init::box_texture_filled);
			}
			if (menu.type == sf::Event::MouseButtonReleased && menu.key.code == sf::Mouse::Left) {
				Init::menu_box[0].setTexture(Init::box_texture);

				goto menu;



			}
			
		}
		else {
			Init::menu_box[0].setTexture(Init::box_texture);
		}

		if (Init::input_box[9].getGlobalBounds().contains(window.mapPixelToCoords(sf::Mouse::getPosition(window)))) {

			if (menu.type == sf::Event::MouseButtonPressed && menu.key.code == sf::Mouse::Left) {
				Init::input_box[9].setTexture(Init::small_box_texture_filled_selected);
			}
			else {
				Init::input_box[9].setTexture(Init::small_box_texture_filled);
			}
			if (menu.type == sf::Event::MouseButtonReleased && menu.key.code == sf::Mouse::Left) {
				Init::input_box[9].setTexture(Init::small_box_texture);


				for (int i = 0; i < 365; i++) {
					if (!Data::trainingData.distance[i]) {

						stringstream submitStream;

						submitStream << playerInput[0];
						submitStream >> Data::trainingData.distance[i];
						submitStream.clear();

						submitStream << playerInput[1];
						submitStream >> Data::trainingData.speed[i];
						submitStream.clear();

						submitStream << playerInput[2];
						submitStream >> Data::trainingData.power[i];
						submitStream.clear();

						submitStream << playerInput[3];
						submitStream >> Data::trainingData.intensity[i];
						submitStream.clear();


						submitStream << playerInput[4];
						submitStream >> Data::trainingData.hours[i];
						submitStream.clear();

						submitStream << playerInput[5];
						submitStream >>Data::trainingData.minutes[i];
						submitStream.clear();


						submitStream << playerInput[6];
						submitStream >> Data::trainingData.day[i];
						submitStream.clear();

						submitStream << playerInput[7];
						submitStream >> Data::trainingData.month[i];
						submitStream.clear();

						submitStream << playerInput[8];
						submitStream >> Data::trainingData.year[i];
						submitStream.clear();





						break;
					}
				}


				for (int i = 0; i < 9; i++) {
					playerInput[i] = "";
					Init::input_field[i].setString(playerInput[i]);
				}

				goto menu;



			}

		}
		else {
			Init::input_box[9].setTexture(Init::small_box_texture);
		}


	}

	if (input_selected < 4) {
		Init::input_box[input_selected].setTexture(Init::box_texture_filled_selected);
	}

	if (input_selected >= 4 && input_selected < 6) {
		Init::input_box[input_selected].setTexture(Init::small_box_texture_filled_selected);
	}
	if (input_selected >= 6 && input_selected < 9) {
		Init::input_box[input_selected].setTexture(Init::tiny_box_texture_filled_selected);
	}

	window.display();

}


}

