#ifndef FOOD_H
#define FOOD_H
//22i-0861
//Ayaan Mughal
// CS-C
#include <SFML/Graphics.hpp>
#include<string.h>
#include <iostream>

using namespace sf;

class Food {
public:
	Texture tex;
	Sprite food;
	int points;
	bool active;

	Food(int p, bool a): points(p),active(a){
		food.setPosition(-50, -50);
	}

	virtual void placement(int, int) = 0;  //just for placement
	virtual void checkPlayer(Car&) = 0;   ///collision checks with player & changes score
	virtual bool checkActive() = 0;
};

class RedRectangle : public Food {
public:
	RedRectangle() : Food(10,1) {
		tex.loadFromFile("img/coins.png");
		food.setTexture(tex);
		food.setScale(0.75, 0.5);
	}

	void placement(int x, int y) override { 
		if (active)
		food.setPosition(x, y);
	}

	void checkPlayer(Car&c) override  {
		if (food.getGlobalBounds().intersects(c.car.getGlobalBounds())){
		c.score += points;
			active = 0;
			food.setPosition(-50, -50);
		}

	}

	bool checkActive() override {
		return active;
	}

};

class GreenCircle : public Food {
public:
	GreenCircle() : Food(20, 1) {
		tex.loadFromFile("img/circle.png");
		food.setTexture(tex);
		food.setScale(0.75, 0.75);
	}

	void placement(int x, int y) override {
		if (active)
		food.setPosition(x, y);
	}

	void checkPlayer(Car& c) override {
		if (food.getGlobalBounds().intersects(c.car.getGlobalBounds())) {
			c.score += points;
			active = 0;
			food.setPosition(-50, -50);
			c.lives++;
		}

	}
	bool checkActive() override {
		return active;
	}


};



class WhiteTriangle : public Food {
public:
	WhiteTriangle() : Food(10, 1) {
		tex.loadFromFile("img/triangle.png");
		food.setTexture(tex);
		food.setScale(0.75, 0.75);

	}

	void placement(int x, int y) override {
		if (active)
		food.setPosition(x, y);
	}

	void checkPlayer(Car& c) override {
		if (food.getGlobalBounds().intersects(c.car.getGlobalBounds())) {
			c.score += points;
			active = 0;
			food.setPosition(-50, -50);
			c.dieded= 1;
			c.dietime = 11;
		}

	}
	bool checkActive() override {
		return active;
	}

};


class OrangeHexagon : public Food {
public:
	OrangeHexagon() : Food(10, 1) {
		tex.loadFromFile("img/hexagon.png");
		food.setTexture(tex);
		food.setScale(0.75, 0.75);
	}

	void placement(int x, int y) override {
		if (active)
		food.setPosition(x, y);
	}

	void checkPlayer(Car& c) override {
		if (food.getGlobalBounds().intersects(c.car.getGlobalBounds())) {
			c.score += points;
			active = 0;
			food.setPosition(-50, -50);
			c.incspeed = 1;
			c.speed *= 1.5;
		}

	}
	bool checkActive() override {
		return active;
	}

};

#endif //FOOD_H