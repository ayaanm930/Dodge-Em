#ifndef CARS_H
#define CARS_H
//22i-0861
//Ayaan Mughal
// CS-C
#include <SFML/Graphics.hpp>
#include<string.h>
#include <iostream>
#include <time.h>
using namespace sf;



class Car {
public:
	Texture tex;
	Sprite car;
	float speed;
	float x, y;
	float dx = 1;  //initial direction
	float dy = 0;
	string png_path;
	int lives;
	int score = 0;
	int dietime=7;
	bool incspeed =0;
	bool dieded = 0;


	virtual void autoMove() = 0;
	virtual void takeTurns(string, Arena*) = 0;
	virtual int getLayer(Arena*) = 0;
	virtual void collisionCar(Car&) = 0;
	virtual void setPlayLayer(int)=0;
	virtual void textures(string) = 0;
	virtual	bool JustDied(float) = 0;

	Car( float sp, float x, float y, float delx, float dely, int l) : speed(sp), x(x), y(y), dx(delx), dy(dely), lives(l) {
		car.setScale(1, 1.5);
	}

};

class Player : public Car {
public:
	

	Player() : Car(2.5,510,760,-1,0,3)
	{
		 //initial position, (710,730)  ///MEAN DISTANCE=75  ///SIZE= 60x40
		car.setPosition(x, y);
		car.rotate(-90.0f);
	}


	void setPlayLayer(int) override{
		
	}

	void textures(string s) override{
		tex.loadFromFile(s);
		car.setTexture(tex);
	}
	void autoMove() override {
		cout << "ENEMY " << car.getPosition().x << "  " << car.getPosition().y << endl;
		if ((car.getPosition().y > 790) || (car.getPosition().x > 950 && car.getPosition().y > 700 && car.getPosition().x < 1010 && car.getPosition().y < 720) || (car.getPosition().x < 920 && car.getPosition().x > 850 && car.getPosition().y < 640 && car.getPosition().y > 620) || (car.getPosition().x < 820 && car.getPosition().x > 750 && car.getPosition().y < 570 && car.getPosition().y > 550)) {
			dx = -1;
			dy = 0;
			car.setPosition(car.getPosition().x - 60, car.getPosition().y - 20);
			car.rotate(90.0);                                                                                                                                                                                                                                                                                                  ////////////////
		}
		else if ((car.getPosition().x > 1100) || (car.getPosition().x > 1010 && car.getPosition().x < 1030 && car.getPosition().y > 200 && car.getPosition().y < 280) || (car.getPosition().x > 920 && car.getPosition().x < 940 && car.getPosition().y < 340 && car.getPosition().y > 280) || (car.getPosition().x > 820 && car.getPosition().x < 840 && car.getPosition().y < 420 && car.getPosition().y > 360)) {
			dx = 0;
			dy = 1;
			car.setPosition(car.getPosition().x - 20, car.getPosition().y + 60);
			car.rotate(90);
		}
		else if ((car.getPosition().y < 120) || (car.getPosition().x > 155 && car.getPosition().x < 220 && car.getPosition().y < 200 && car.getPosition().y > 180) || (car.getPosition().x > 250 && car.getPosition().x < 320 && car.getPosition().y < 270 && car.getPosition().y > 250) || (car.getPosition().x > 340 && car.getPosition().x < 400 && car.getPosition().y < 355 && car.getPosition().y > 335)) {
			dx = 1;
			dy = 0;
			car.setPosition(car.getPosition().x + 60, car.getPosition().y + 20);
			car.rotate(90);
		}                                                                                                                                                                                                                                                                                             /////////////////////////////////////////////////////
		else if ((car.getPosition().x < 70) || (car.getPosition().x > 145 && car.getPosition().x < 165 && car.getPosition().y > 640 && car.getPosition().y < 700) || (car.getPosition().x < 245 && car.getPosition().x > 220 && car.getPosition().y > 550 && car.getPosition().y < 620) || (car.getPosition().x < 345 && car.getPosition().x > 325 && car.getPosition().y > 510 && car.getPosition().y < 550)) {
			dx = 0;
			dy = -1;
			car.setPosition(car.getPosition().x + 20, car.getPosition().y - 60);
			car.rotate(90);
		}
		float deltax = dx;
		float deltay = dy;
		deltax *= speed;
		deltay *= speed;
		car.move(deltax, deltay);

	}
	





	void takeTurns(string s, Arena* a) override{    
		
		int layers = getLayer(a);
		int changex = car.getPosition().x;
		int changey = car.getPosition().y;

			if ((car.getPosition().y > 390) && (car.getPosition().y < 510))/////setting movement when outside walls /// y = 390 - 510  x = 510 - 710
			{
				if (car.getPosition().x < a[32].sprite.getPosition().x)
				{
					cout << layers << endl;
					if (s == "l" && layers > 1)
					{
						changey = car.getPosition().y;
						changex = car.getPosition().x - 92;

					}
					else if (s == "r" && layers < 4)
					{
						changey = car.getPosition().y;
						changex = car.getPosition().x + 88;
					}
				}
				if (car.getPosition().x > (a[32].sprite.getPosition().x + a[32].sprite.getGlobalBounds().width))
				{
					if (s == "l" && (layers < 4)) {
						changey = car.getPosition().y;
						changex = car.getPosition().x - 92;

					}
					else if (s == "r" && layers > 1) {
						changey = car.getPosition().y;
						changex = car.getPosition().x + 88;
					}
				}
				x = changex;
				y = changey;
				car.setPosition(x, y);
			}
			if ((car.getPosition().x > 510) && (car.getPosition().x < 710)) {
				if (car.getPosition().y < a[34].sprite.getPosition().y) {
					if (s == "u" && layers > 1) {
						changey = car.getPosition().y - 77;
						changex = car.getPosition().x;
					}
					else if (s == "d" && layers < 4) {
						changey = car.getPosition().y + 80;
						changex = car.getPosition().x;
					}
				}
				if (car.getPosition().y > a[34].sprite.getPosition().y + a[34].sprite.getGlobalBounds().height) {
					if (s == "u" && layers < 4) {
						changey = car.getPosition().y - 80;
						changex = car.getPosition().x;
					}
					else if (s == "d" && layers > 1) {
						changey = car.getPosition().y + 77;
						changex = car.getPosition().x;
					}
				}
				x = changex;
				y = changey;
				car.setPosition(x, y);
			}
	}


	int getLayer(Arena* a) override{  ///RETURNING WHICH LATER THE PLAYER IS AT

		int lowy = a[24].sprite.getPosition().y;
		int highy = lowy + a[24].sprite.getGlobalBounds().height + 120 + a[25].sprite.getGlobalBounds().height;
		int lowx = a[26].sprite.getPosition().x;
		int highx = lowx + a[26].sprite.getGlobalBounds().width+ 200 + a[27].sprite.getGlobalBounds().width;
		cout << highx << " " << lowx << endl << highy << " " << lowy << endl;
		if (car.getPosition().x > lowx && car.getPosition().x<highx && car.getPosition().y>lowy && car.getPosition().y < highy) {
			
			return 4;
		}

		lowy = a[16].sprite.getPosition().y;
		highy = lowy + a[16].sprite.getGlobalBounds().height + 120 + a[17].sprite.getGlobalBounds().height;
		lowx = a[18].sprite.getPosition().x;
		highx = lowx + a[18].sprite.getGlobalBounds().width + 200 + a[19].sprite.getGlobalBounds().width;
		if (car.getPosition().x > lowx && car.getPosition().x<highx && car.getPosition().y>lowy && car.getPosition().y < highy) {
			return 3;
		}

		lowy = a[8].sprite.getPosition().y;
		highy = lowy+ a[9].sprite.getGlobalBounds().height+ 120 + a[9].sprite.getGlobalBounds().height;
		lowx = a[10].sprite.getPosition().x;
		highx = lowx + a[11].sprite.getGlobalBounds().width + 200 + a[11].sprite.getGlobalBounds().width;
		if (car.getPosition().x > lowx && car.getPosition().x<highx && car.getPosition().y>lowy && car.getPosition().y<highy) {
			return 2;
		}		
		lowy = a[0].sprite.getPosition().y;
		highy = lowy+ a[0].sprite.getGlobalBounds().height + 120 + a[1].sprite.getGlobalBounds().height;
		lowx = a[2].sprite.getPosition().x+40;
		highx = lowx + a[2].sprite.getGlobalBounds().width + 200 + a[3].sprite.getGlobalBounds().width;
		if (car.getPosition().x > lowx && car.getPosition().x<highx && car.getPosition().y>lowy && car.getPosition().y<highy) {
			return 1;
		}

		return 0;
	}

	void collisionCar(Car& c) override { ///ENEMY COLLISION (LIFE LOST )
		if (!dieded ) {
			if (car.getGlobalBounds().intersects(sf::FloatRect(static_cast<float>(c.car.getPosition().x), static_cast<float>(c.car.getPosition().y), 1, 1))) {
				dx = -1;
				dy = 0;
				car.setPosition(510, 760);
				car.setRotation(-90);
				lives--;
				dieded = 1;
			}
		}

	}
	bool JustDied(float time) override{ ///MAKES THE PLAYER INVINCIBLE FOR A WHILE AFTER DYING
		if (dieded) {
			tex.loadFromFile("img/died.png");
			car.setTexture(tex);
			cout << time << endl;
			if ( time>1 &&(int)time % dietime ==0) {
				tex.loadFromFile("img/player.png");
				car.setTexture(tex);
				dieded = 0;
				return false;
			}
			if (dietime > 10)
				dietime = 7;
			return true;
		}
	}

};


class Enemy : public Car {
public:
	int playerLayer = 0;

	Enemy() : Car( 2.5, 710 ,720,1,0,1)
	{
		//initial position, (510,770)   ///SIZE= 60x40
		car.setPosition(x, y);
		car.rotate(90.0f);
	}

	void setPlayLayer(int a) override {
		playerLayer = a;
	}

	void textures(string s) override {
		tex.loadFromFile(s);
		car.setTexture(tex);
	}
	                                                                   /////////ANTI CLOCKWISE MOVEMENT FOR ENEMY///////////
	void autoMove() override { ///car turns when it runs into corner   
		cout << "PLAYER: " << car.getPosition().x << "  " << car.getPosition().y << endl << endl;
		if ((car.getPosition().x > 1100) || (car.getPosition().x > 1010 && car.getPosition().y < 690 && car.getPosition().x < 1030 && car.getPosition().y > 640) || (car.getPosition().x > 920 && car.getPosition().x < 950 && car.getPosition().y < 615 && car.getPosition().y > 570) || (car.getPosition().x > 830 && car.getPosition().x < 850 && car.getPosition().y < 550 && car.getPosition().y > 490)) {
			dx = 0;
			dy = -1;
			car.setPosition(car.getPosition().x - 60, car.getPosition().y);
			car.rotate(-90.0);
			////////////////
		}
		else if ((car.getPosition().y < 130) || (car.getPosition().x > 940 && car.getPosition().x < 1000 && car.getPosition().y < 200 && car.getPosition().y > 180) || (car.getPosition().x > 850 && car.getPosition().x < 920 && car.getPosition().y < 280 && car.getPosition().y > 260) || (car.getPosition().x > 750 && car.getPosition().x < 820 && car.getPosition().y < 360 && car.getPosition().y > 340)) {
			dx = -1;
			dy = 0;
			car.setPosition(car.getPosition().x, car.getPosition().y + 40);
			car.rotate(-90);
		}
		else if ((car.getPosition().x < 75) || (car.getPosition().x > 155 && car.getPosition().x < 165 && car.getPosition().y < 260 && car.getPosition().y > 200) || (car.getPosition().x > 240 && car.getPosition().x < 260 && car.getPosition().y < 340 && car.getPosition().y > 270) || (car.getPosition().x > 320 && car.getPosition().x < 345 && car.getPosition().y < 410 && car.getPosition().y > 360)) {
			dx = 0;
			dy = 1;
			car.setPosition(car.getPosition().x + 60, car.getPosition().y);
			car.rotate(-90);

		}                                                                                                                                                                                                                                                                                             /////////////////////////////////////////////////////
		else if ((car.getPosition().y > 790) || (car.getPosition().x > 170 && car.getPosition().x < 240 && car.getPosition().y < 720 && car.getPosition().y > 700) || (car.getPosition().x > 260 && car.getPosition().x < 320 && car.getPosition().y < 640 && car.getPosition().y > 620) || (car.getPosition().x > 350 && car.getPosition().x < 410 && car.getPosition().y < 570 && car.getPosition().y > 550)) {
			dx = 1;
			dy = 0;
			car.setPosition(car.getPosition().x, car.getPosition().y - 40);
			car.rotate(-90);
		}
		float deltax = dx;
		float deltay = dy;
		deltax *= speed;
		deltay *= speed;
		car.move(deltax, deltay);

	}

	void takeTurns(string level, Arena* a) override {    ///setting movement when outside walls /// y = 390 - 510  x = 510 - 710
		//level 1, random switch, no top bottom turns not taken
		//active: takes player pos and makes decision to switch accordingly (can only switch once in an opening)
		srand(time(0));
		string s="o";
		bool bop = 0;
		bool active = 0;

		if (level == "1") {
			bop = 0;
			active = 0;
		}
		else if (level == "2" || level == "3" || level == "4" ) {
			bop = 1;
			active = 1;
		}
		int c;

			int layers = getLayer(a);
			int changex = car.getPosition().x;
			int changey = car.getPosition().y;

			int p_layer;
			if ((car.getPosition().y > 390) && (car.getPosition().y < 510))
			{
				c = rand() %3;
				switch (c) {
				case 1: {
					s = "l";
					break;
				}
				  case 2: {
					  s = "r";
					  break;
				}
				}

				if (car.getPosition().x < a[32].sprite.getPosition().x)
				{

					if (active) {
						if (playerLayer > layers) {
							s = "r";
						}
						else if(playerLayer< layers)
							s = "l";

					}

					if (s == "l" && layers > 1)
					{
						changey = car.getPosition().y;
						changex = car.getPosition().x - 84;
					}
					else if (s == "r" && layers < 4)
					{
						changey = car.getPosition().y;
						changex = car.getPosition().x + 85;
					}
				}
				if (car.getPosition().x > (a[32].sprite.getPosition().x + a[32].sprite.getGlobalBounds().width))
				{
					if (active) {
						if (playerLayer > layers) {
							s = "l";
						}
						else if (playerLayer < layers)
							s = "r";

					}
					if (s == "l" && (layers < 4)) {
						changey = car.getPosition().y;
						changex = car.getPosition().x - 84;

					}
					else if (s == "r" && layers > 1) {
						changey = car.getPosition().y;
						changex = car.getPosition().x + 85;
					}
				}
					x = changex;
					y = changey;
					car.setPosition(x, y);

			}
			if ((car.getPosition().x > 510) && (car.getPosition().x < 710) && bop) {
				c = rand() % 3;
				switch (c) {
				case 1: {
					s = "u";
					break;
				}
				case 2: {
					s = "d";
					break;
				}
				}
				if (car.getPosition().y < a[34].sprite.getPosition().y) {
					if (active) {
						if (playerLayer > layers) {
							s = "d";
						}
						else if (playerLayer < layers)
							s = "u";

					}
					if (s == "u" && layers > 1) {
						changey = car.getPosition().y - 78;
						changex = car.getPosition().x;
					}
					else if (s == "d" && layers < 4) {
						changey = car.getPosition().y + 78;
						changex = car.getPosition().x;
					}
				}
				if (car.getPosition().y > a[34].sprite.getPosition().y + a[34].sprite.getGlobalBounds().height) {
					if (active) {
						if (playerLayer > layers) {
							s = "u";
						}
						else if (playerLayer < layers)
							s = "d";

					}
					if (s == "u" && layers < 4) {
						changey = car.getPosition().y - 78;
						changex = car.getPosition().x;
					}
					else if (s == "d" && layers > 1) {
						changey = car.getPosition().y + 78;
						changex = car.getPosition().x;
					}
				}
				x = changex;
				y = changey;
				car.setPosition(x, y);
			}

	}

	int getLayer(Arena* a) override {

		int lowy = a[24].sprite.getPosition().y;
		int highy = lowy + a[24].sprite.getGlobalBounds().height + 120 + a[25].sprite.getGlobalBounds().height;
		int lowx = a[26].sprite.getPosition().x;
		int highx = lowx + a[26].sprite.getGlobalBounds().width + 200 + a[27].sprite.getGlobalBounds().width;
		if (car.getPosition().x > lowx && car.getPosition().x<highx && car.getPosition().y>lowy && car.getPosition().y < highy) {

			return 4;
		}

		lowy = a[16].sprite.getPosition().y;
		highy = lowy + a[16].sprite.getGlobalBounds().height + 120 + a[17].sprite.getGlobalBounds().height;
		lowx = a[18].sprite.getPosition().x;
		highx = lowx + a[18].sprite.getGlobalBounds().width + 200 + a[19].sprite.getGlobalBounds().width;
		if (car.getPosition().x > lowx && car.getPosition().x<highx && car.getPosition().y>lowy && car.getPosition().y < highy) {
			return 3;
		}

		lowy = a[8].sprite.getPosition().y;
		highy = lowy + a[9].sprite.getGlobalBounds().height + 120 + a[9].sprite.getGlobalBounds().height;
		lowx = a[10].sprite.getPosition().x;
		highx = lowx + a[11].sprite.getGlobalBounds().width + 200 + a[11].sprite.getGlobalBounds().width;
		if (car.getPosition().x > lowx && car.getPosition().x<highx && car.getPosition().y>lowy && car.getPosition().y < highy) {
			return 2;
		}
		lowy = a[0].sprite.getPosition().y;
		highy = lowy + a[0].sprite.getGlobalBounds().height + 120 + a[1].sprite.getGlobalBounds().height;
		lowx = a[2].sprite.getPosition().x;
		highx = lowx + a[2].sprite.getGlobalBounds().width + 200 + a[3].sprite.getGlobalBounds().width;
		if (car.getPosition().x > lowx && car.getPosition().x<highx && car.getPosition().y>lowy && car.getPosition().y < highy) {
			return 1;
		}

		cout << highx << " " << lowx << endl << highy << " " << lowy << endl;

		return 0;
	}

	void collisionCar(Car& c) override {  //NOT USED JUST TO PREVENT ERRORS
		if (dx == 0) {
			if (car.getPosition().y == c.car.getPosition().y) {
				dx = 1;
				dy = 0;
				car.setPosition(710, 730);
				car.setRotation(90);

			}

		}

	}

	bool JustDied(float t) override{
		return 0;
	}



};


#endif //CARS_H