#ifndef GAME_H
#define GAME_H
//22i-0861
//Ayaan Mughal
// CS-C
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
using namespace std;
#include "arena.h"
#include "cars.h"
#include "food.h"


const char title[] = "OOP-Project, Spring-2023";
using namespace sf;


class Game
{
public:
    string path = "img/player.png";
    string en_path = "img/enemy.png";
    Sprite background; //Game background sprite
    Texture bg_texture;
    Car* p; //player 
    Car* en[2];
    Food** food;
    string level ="3";
    bool keyflag = 0;
    // add other game attributes
    Arena* arena; //arena blocks
    bool flag = 0;
    bool died;
    bool foodset = 0;
    bool reset;
    int score;

    Game()
    {
        arena = new Arena[40];

        p = new Player;

        en[0] = new Enemy;
        en[1] = new Enemy;
        
        p->textures(path);
        en[0]->textures(en_path);

        en[1]->textures(en_path);

        en[1]->car.setPosition(510, 650);

    //\
    //     bg_texture.loadFromFile("img/background.jpg");
        background.setTexture(bg_texture);
        background.setScale(2, 1.5);
     //   initializeSmallBoxes();

    }


    void start_game(bool& w, bool& res)
    {
        Font font;
        font.loadFromFile("content.ttf");////SETTING TEXT FOR TOP OF MAZE
        Text lifetxt, scortxt, lvltxt;
        lifetxt.setFont(font);
        lifetxt.setCharacterSize(80);
        lifetxt.setFillColor(Color::Blue);
        lifetxt.setPosition(50, 10);

        scortxt.setFont(font);
        scortxt.setCharacterSize(80);
        scortxt.setFillColor(Color::Yellow);
        scortxt.setPosition(510, 10);

        lvltxt.setFont(font);
        lvltxt.setCharacterSize(80);
        lvltxt.setFillColor(Color::Green);
        lvltxt.setPosition(950, 10);
        srand(time(0));
        RenderWindow window(VideoMode(1200, 900), title);
        Clock clock;
        food = new Food*[65];

        for (int i = 0; i < 65; i++)   ///avoid exception
            food[i] = new RedRectangle;


        bool playerturn = 1;
        float timer = 0;
        float timeDelay = 1;
        float deadTime = 0;
        float deadDelay = 3;
        while (window.isOpen())
        {
            if (!foodset) {
                if (level == "1") {   //ALL RED RECTANGLES
                    for (int i = 0; i < 65; i++)
                        delete food[i];
                    for (int i = 0; i < 65; i++)
                        food[i] = new RedRectangle;
                }
                else if (level == "2") { //2 GREEN CIRCLES ADDED
                    for (int i = 0; i < 65; i++)
                        delete food[i];
                    int gc = rand() % 65;
                    int gc2 = gc;
                    while (gc2 == gc)
                        gc2 = rand() % 65;
                    for (int i = 0; i < 65; i++) {
                        if (i == gc || i == gc2)
                            food[i] = new GreenCircle;
                        else
                            food[i] = new RedRectangle;
                    }
                }
                else if (level == "3") { //2 CIRCLES, 3 HEXAGONS
                    for (int i = 0; i < 65; i++)
                        delete food[i];
                    int gc = rand() % 65;
                    int gc2 = gc;
                    while (gc2 == gc)
                        gc2 = rand() % 65;
                    int oh = gc2;
                    while (oh == gc || oh == gc2)
                        oh = rand() % 65;
                    int oh2 = oh;
                    while (oh2 == gc || oh2 == gc2 || oh2 == oh)
                        oh2 = rand() % 65;
                    int oh3 = oh2;
                    while (oh3 == gc || oh3 == gc2 || oh3 == oh || oh3 == oh2)
                        oh3 = rand() % 65;

                    for (int i = 0; i < 65; i++) {
                        if (i == gc || i == gc2)
                            food[i] = new GreenCircle;
                        else if (i == oh || i == oh2 || i == oh3)
                            food[i] = new OrangeHexagon;
                        else
                            food[i] = new RedRectangle;
                    }
                }
                else if (level == "4") { //2 CIRCLES, 3 HEXAGONS AND 2 WHITE TRIANGLES
                    for (int i = 0; i < 65; i++)
                        delete food[i];
                    int gc = rand() % 65;
                    int gc2 = gc;
                    while (gc2 == gc)
                        gc2 = rand() % 65;
                    int oh = gc2;
                    while (oh == gc || oh == gc2)
                        oh = rand() % 65;
                    int oh2 = oh;
                    while (oh2 == gc || oh2 == gc2 || oh2 == oh)
                        oh2 = rand() % 65;
                    int oh3 = oh2;
                    while (oh3 == gc || oh3 == gc2 || oh3 == oh || oh3 == oh2)
                        oh3 = rand() % 65;
                    int wt = oh3;
                    while (wt == gc || wt == gc2 || wt == oh || wt == oh2 || wt == oh3)
                        wt = rand() % 65;
                    int wt2 = wt;
                    while (wt2 == gc || wt2 == gc2 || wt2 == oh || wt2 == oh2 || wt2 == oh3 || wt2 == wt)
                        wt2 = rand() % 65;


                    for (int i = 0; i < 65; i++) {
                        if (i == gc || i == gc2)
                            food[i] = new GreenCircle;
                        else if (i == oh || i == oh2 || i == oh3)
                            food[i] = new OrangeHexagon;
                        else if (i == wt || i == wt2)
                            food[i] = new WhiteTriangle;
                        else
                            food[i] = new RedRectangle;
                    }
                }
                foodset = 1;
            }




            float time = clock.getElapsedTime().asSeconds();
            clock.restart();
            timer += time;
            //cout<<time<<endl; 
            Event e;
            while (window.pollEvent(e))
            {
                if (e.type == Event::Closed || w==1 || p->lives==0) // If cross/close is clicked/pressed
                    if (w = 1) {
                            window.close(); //close the game
                            
                    }
            }

            if (Keyboard::isKeyPressed(Keyboard::Left) && !keyflag) {//If left key is pressed
                p->takeTurns("l",arena);    // Player will move to left
                keyflag = 1;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Right) && !keyflag) { // If right key is pressed
                p->takeTurns("r", arena);  //player will move to right
                keyflag = 1;
            }
            else if (Keyboard::isKeyPressed(Keyboard::Up) && !keyflag) { //If up key is pressed
                p->takeTurns("u", arena);    //playet will move upwards
                keyflag = 1;
            }

            else if (Keyboard::isKeyPressed(Keyboard::Down) && !keyflag) { // If down key is pressed
                p->takeTurns("d", arena);  //player will move downwards
                keyflag = 1;
            }
  
            window.clear(Color::Black); //clears the screen
            ////////////////////////////////////////////////
            /////  Call your functions here            ////
            arena->createArena(window,arena);

            int x = 410;
            int diff = 120; //////////PLACING THE FOOD  
            for (int i = 0; i < 32; i+=8) {
                food[0+i]->placement(x, 750);
                food[1+i]->placement(x, 660);
                food[2+i]->placement(x, 590);
                food[3+i]->placement(x, 520);
                food[4+i]->placement(x, 370);
                food[5+i]->placement(x, 300);
                food[6+i]->placement(x, 220);
                food[7+i]->placement(x, 140);
                x -= diff;
                diff -= 10;
            }
             x = 730;
             diff = 130;
            for (int i = 32; i < 64; i += 8) {
                food[0 + i]->placement(x, 750);
                food[1 + i]->placement(x, 660);
                food[2 + i]->placement(x, 590);
                food[3 + i]->placement(x, 520);
                food[4 + i]->placement(x, 370);
                food[5 + i]->placement(x, 300);
                food[6 + i]->placement(x, 220);
                food[7 + i]->placement(x, 140);
                x += diff;
                diff -= 17;
            }









            

            if (level == "3") {
                en[0]->speed = 3; /////level setting
            }

            if (timer >= timeDelay)   /////////movement of opponent (for both if level 4
            {
                // Process enemy turn
                if (level == "4") {
                    en[0]->speed = 4;
                    en[1]->speed = 4;
                    en[1]->setPlayLayer(p->getLayer(arena));
                    en[1]->takeTurns(level, arena);
                }


                en[0]->setPlayLayer(p->getLayer(arena));
                en[0]->takeTurns(level, arena);
                playerturn = 1;
                timer = 0;
            }
             
            deadTime += time;

            if (!p->JustDied(deadTime)) {
                deadTime = 0;
            }

            if ((!(Keyboard::isKeyPressed(Keyboard::Down)) && !(Keyboard::isKeyPressed(Keyboard::Up)) && !(Keyboard::isKeyPressed(Keyboard::Left)) && !(Keyboard::isKeyPressed(Keyboard::Right))) && keyflag) {
                keyflag = 0; //make the movement instantaneous
            }   ///otherwise player go ZOOOM

            if (p->lives <= 0)
                window.close();
            if (p->incspeed) {
                if ((int)timer % 11 == 0) {
                    p->incspeed = 0;
                    p->speed /= 1.5;
                }
            }


            string helth="";
            for (int i = p->lives; i > 0; i--) {
                helth += "0 ";
            }

            string lvl = "LVL: ";
            lvl += (string)level;
            string scor = to_string(p->score);
            lifetxt.setString(helth);
            scortxt.setString(scor);
            lvltxt.setString(lvl);
            p->autoMove();
            en[0]->autoMove();
            if (level == "4") {
                en[1]->autoMove();
                window.draw(en[1]->car);
            }
            p->collisionCar(*en[0]);
            bool nextlvl = 0;
            for (int i = 0; i < 64; i++) {
                if (food[i]->checkActive()) {
                    nextlvl = 0;
                    break;
                }
                nextlvl = 1;
               
            }
            if (nextlvl) {
                if (level == "1") {
                    level = "2";
                    w = 0;
                }
                else if (level == "2") {
                    level = "3";
                    w = 0;
                }
                else if (level == "3") {
                    level = "4";
                    w = 0;
                }
                else if (level == "4") {
                    w = 1;

                }
                nextlvl = 0;
                foodset = 0;
            }


            for (int i = 0; i < 64; i++) {
                food[i]->checkPlayer(*p);
                window.draw(food[i]->food);

            }            
            window.draw(p->car);     
            window.draw(en[0]->car);
            window.draw(lifetxt);
            window.draw(scortxt);
            window.draw(lvltxt);
            score = p->score;


            //////////////////////////////////////////////


         //   window.draw(background);  // setting background

            window.display();  //Displying all the sprites
        }


    }




};

#endif //GAME_H