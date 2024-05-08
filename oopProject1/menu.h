//22i-0861
//Ayaan Mughal
// CS-C
#include "game.h"
class Menu {
public:
    Text* options;
    Text start;
    Font font;

    Sprite cursor;
    Texture curtex;

    int move;
    bool res;
    bool w;

    int slide = 0;
    //add menu attributes here
    Menu()
    {

        curtex.loadFromFile("img/player1.png");
        cursor.setTexture(curtex);
        cursor.setScale(1, 1);
        cursor.setPosition(200, 400);
        font.loadFromFile("content.ttf");
        start.setFont(font);
        start.setCharacterSize(80);
        start.setString("DODGE 'EM");
        start.setFillColor(Color::Yellow);
        start.setPosition(250, 150);

        options = new Text[3];
        font.loadFromFile("content.ttf");
        options[0].setFont(font);
        options[0].setCharacterSize(42);
        options[0].setString("Start Game");
        options[0].setFillColor(Color::Yellow);
        options[0].setPosition(300, 400);

        options[1].setFont(font);
        options[1].setCharacterSize(42);
        options[1].setString("Instructions");
        options[1].setFillColor(Color::Yellow);
        options[1].setPosition(270, 500);

        options[2].setFont(font);
        options[2].setCharacterSize(42);
        options[2].setString("Leaderboard");
        options[2].setFillColor(Color::Yellow);
        options[2].setPosition(275, 600);

        move = 0;



        //constructors body
    }

    void display_menu() {


        Game g;
        //display menu screen here
        RenderWindow menu(VideoMode(780, 780), "menu");
        while (menu.isOpen())
        {

            Event e;
            while (menu.pollEvent(e))
            {
                if (e.type == Event::Closed) // If cross/close is clicked/pressed
                    menu.close(); //close the game   

                for (int i = 0; i < 3; i++) {
                    if (i == move)
                        i++;
                    options[i].setFillColor(Color::Yellow);
                }
                options[move].setFillColor(Color::White);

                // add functionality of all the menu options here
                if (e.type == Event::KeyPressed) {

                    if (e.key.code == Keyboard::Up && move > 0) {
                        move--;
                        cursor.move(0, -100);
                    }
                    if (e.key.code == Keyboard::Down && move < 2) {
                        move++;
                        cursor.move(0, 100);

                    }


                    //if Start game option is chosen

                    if (e.key.code == Keyboard::Enter && move == 0) {
                        menu.close();
                        g.start_game(w, res);
                        if (!res)
                            endGame(g);
                        else if (res) {
                            menu.close();
                            display_menu();

                        }


                    }

                    if (e.key.code == Keyboard::Enter && move == 1) {
                        menu.close();
                        inst_page();

                    }
                }
            }


            menu.clear(Color(135, 17, 41, 1)); //clears the screen
          //  menu.draw(background);  // setting background
            menu.draw(start);
            menu.draw(cursor);
            menu.draw(options[0]);
            menu.draw(options[1]);
            menu.draw(options[2]);
            menu.display();

        }
    }




    void inst_page() {
        RenderWindow inst(VideoMode(780, 780), "instructions");
        while (inst.isOpen()) {
            Event einst;
            while (inst.pollEvent(einst)) {
                if (einst.type == Event::Closed || (einst.type == Event::KeyPressed && einst.key.code == Keyboard::Escape)) {// If cross/close is clicked/pressed
                    inst.close(); //close the game   
                    display_menu();
                }

                Text intext;
                Text title;


                title.setFont(font);
                title.setCharacterSize(30);
                title.setString("Instructions");
                title.setFillColor(Color::Yellow);
                title.setPosition(250, 50);




                Text botline;
                botline.setFont(font);
                botline.setCharacterSize(20);
                botline.setFillColor(Color::Yellow);
                botline.setPosition(25, 750);


                if (einst.type == Event::KeyPressed) {
                    if (einst.key.code == Keyboard::Left && slide > 0) {
                        slide--;
                    }
                    if (einst.key.code == Keyboard::Right && slide < 3) {
                        slide++;
                    }
                }









                if (slide == 0) {
                    intext.setFont(font);
                    intext.setCharacterSize(30);
                    intext.setString("The game is played in a racing arena where the player drives his brown\n colored car to pick the maximum rewards,\n avoiding a head - on collision with the blue opponent \ncar(s) run by the computer\n");
                    intext.setFillColor(Color::Yellow);
                    intext.setPosition(25, 200);
                    botline.setString("\t\t\t\t\t\t\t\t\t\t\t\tBack to Menu (Esc)\t\t\t\t\t\tPLayer >>");

                }


                if (slide == 1) {
                    intext.setFont(font);
                    intext.setCharacterSize(30);
                    intext.setString("Each roadway in the arena has four turns – one each after covering one-fourth of the roadway.\n The player car starts from the middle of the topmost roadway on the screen,\n while the opponent car(s) start randomly at any turn at least one\n turn away from the player car on the same roadway.\nThe player car is controlled by the keyboard –arrow keys to turn.\n");
                    intext.setFillColor(Color::Yellow);
                    botline.setString("<< Intro\t\t\t\t\t\t\tBack to Menu (Esc)\t\t\t\t\t\tLevels >>");
                    intext.setPosition(25, 200);

                }


                if (slide == 2) {
                    intext.setFont(font);
                    intext.setCharacterSize(20);
                    intext.setString("\t\t\t\tLEVELS\n\nLevel 1: At this level, the opponent car is less active and can nottake the\n top and the bottom turns on any roadway.However, the player\n can take any of the four turns to avoid the collision.\nLevel 2 : At this level, the opponent car is in the active mode and can take any turn just like the player car.\nLevel 3 : At this level, the opponent car is in active mode and its speed is also increased.\n Level 4 : At this level, two opponent cars start chasing the player car in the active mode as in level 2.\n");
                    intext.setFillColor(Color::Yellow);
                    botline.setString("<< Arena\t\t\t\t\t\t\tBack to Menu (Esc)\t\t\t\t\t\tFood >>");
                    intext.setPosition(25, 200);
                }

                if (slide == 3) {
                    intext.setFont(font);
                    intext.setCharacterSize(20);
                    intext.setString("There will be 4 types of food in the game.\n\n1. Red Rectangle shaped food will award you 10 points.\n\n 2. Green circle shaped food will give an extra life and you get 20 points.\n\n 3. Orange Hexagon shaped food will increase your speed by 1.5x for 10 seconds and will give\n\n you 10 points.\n\n4. White triangular food will make the enemies disappear for 10 seconds.");
                    intext.setFillColor(Color::Yellow);
                    botline.setString("<< Levels\t\t\t\t\t\tBack to Menu (Esc)\t\t\t\t\t\t");
                    intext.setPosition(25, 200);
                }




                inst.clear(Color::Black);
                inst.draw(title);
                inst.draw(botline);
                inst.draw(intext);
                inst.display();
            }
        }

    }


    void endGame(Game& g) {
        RenderWindow gameover(VideoMode(780, 780), "gameover");
        while (gameover.isOpen()) {
            Event o;

            while (gameover.pollEvent(o)) {
                if (o.type == Event::Closed || (o.type == Event::KeyPressed && o.key.code == Keyboard::Escape)) // If cross/close is clicked/pressed
                    gameover.close();

                if (o.type == Event::KeyPressed && o.key.code == Keyboard::Enter) {
                    gameover.close();
                    display_menu();
                }

                Text over;

                over.setFont(font);
                over.setCharacterSize(40);
                over.setFillColor(Color::Yellow);




                if (w) {
                    over.setString("\t\t\t\t\t\tYOU WON!!\n\n\nPress ENTER to Restart\n\nPress ESC to End\n\nPress H to see scoreboard");
                    over.setPosition(50, 100);
                }
                if (!w)
                    over.setString("\t\t\t\t\tYOU LOST :(\n\n\nPress ENTER to Restart\n\nPress ESC to End\n\nPress H to see scoreboard");
                over.setPosition(50, 100);

                Text scores;
                scores.setFont(font);
                scores.setCharacterSize(30);
                scores.setFillColor(Color::Yellow);
                string sc = "Score: ";
                sc += to_string(g.score);
                scores.setString(sc);
                scores.setPosition(300, 200);



                gameover.clear(Color::Black);
                gameover.draw(over);
                gameover.draw(scores);
                gameover.display();
            }
        }

    }


};
