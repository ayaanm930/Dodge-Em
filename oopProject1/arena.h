#ifndef ARENA_H
#define ARENA_H
//22i-0861
//Ayaan Mughal
// CS-C
#include <SFML/Graphics.hpp>
#include<string.h>
using namespace sf;

class Arena
{
public:
    Texture texture;
    Sprite sprite;
    float xPos;
    float yPos;
    float blockWidth;
    float blockHeight;


    Arena (float x=50, float y=100) :xPos(x), yPos(y)
    {
        texture.loadFromFile("img/boundary.png");
        sprite.setTexture(texture);
        x = 100; y =100;
        sprite.setPosition(x, y);
        sprite.setScale(0.65,0.65);

    }


    

    void createArena(RenderWindow& window, Arena* a) {
          ////////////////////////////////////////////////////////
         ///////////////////HARDCODING ARENA/////////////////////
        ////////////////////////////////////////////////////////
         
        //////////////////////////////////////LAYER 1///////////

        a[0].sprite.setPosition(50, 100);
        a[0].sprite.setScale(0.75, 9);
        window.draw(a[0].sprite);
        a[1].sprite.setPosition(50, 510);
        a[1].sprite.setScale(0.75, 9);
        window.draw(a[1].sprite);

        a[2].sprite.setPosition(50,100 );
        a[2].sprite.setScale(13, 0.5);
        window.draw(a[2].sprite);
        a[3].sprite.setPosition(50,790);
        a[3].sprite.setScale(13, 0.5);
        window.draw(a[3].sprite);

        a[4].sprite.setPosition(1100, 100);
        a[4].sprite.setScale(0.75,9);
        window.draw(a[4].sprite);
        a[5].sprite.setPosition(1100, 510);
        a[5].sprite.setScale(0.75, 9);
        window.draw(a[5].sprite);

        a[6].sprite.setPosition(708, 100);
        a[6].sprite.setScale(13, 0.5);
        window.draw(a[6].sprite);
        a[7].sprite.setPosition(708, 790);
        a[7].sprite.setScale(13, 0.5);
        window.draw(a[7].sprite);
        
        //////////////////////////////////////LAYER 2////////////////////

        a[8].sprite.setPosition(140, 180);
        a[8].sprite.setScale(0.75, 6.5);
        window.draw(a[8].sprite);
        a[9].sprite.setPosition(140, 510);
        a[9].sprite.setScale(0.75, 6.5);
        window.draw(a[9].sprite);

        a[10].sprite.setPosition(140, 180);
        a[10].sprite.setScale(10.15, 0.5);
        window.draw(a[10].sprite);
        a[11].sprite.setPosition(140, 700);
        a[11].sprite.setScale(10.15, 0.5);
        window.draw(a[11].sprite);

        a[12].sprite.setPosition(1010, 180);
        a[12].sprite.setScale(0.75, 6.5);
        window.draw(a[12].sprite);
        a[13].sprite.setPosition(1010, 510);
        a[13].sprite.setScale(0.75, 6.5);
        window.draw(a[13].sprite);

        a[14].sprite.setPosition(708, 180);
        a[14].sprite.setScale(10.15, 0.5);
        window.draw(a[14].sprite);
        a[15].sprite.setPosition(708, 700);
        a[15].sprite.setScale(10.15, 0.5);
        window.draw(a[15].sprite);

        ////////////////////////////////////////LAYER 3////////////
        a[16].sprite.setPosition(230, 260);
        a[16].sprite.setScale(0.75, 4);
        window.draw(a[16].sprite);
        a[17].sprite.setPosition(230, 510);
        a[17].sprite.setScale(0.75, 4);
        window.draw(a[17].sprite);
        
        a[18].sprite.setPosition(230, 260);
        a[18].sprite.setScale(7.25, 0.5);
        window.draw(a[18].sprite);
        a[19].sprite.setPosition(230, 620);
        a[19].sprite.setScale(7.25, 0.5);
        window.draw(a[19].sprite);

        a[20].sprite.setPosition(920, 260);
        a[20].sprite.setScale(0.75, 4);
        window.draw(a[20].sprite);
        a[21].sprite.setPosition(920, 510);
        a[21].sprite.setScale(0.75, 4);
        window.draw(a[21].sprite);

        a[22].sprite.setPosition(708, 260);
        a[22].sprite.setScale(7.25, 0.5);
        window.draw(a[22].sprite);
        a[23].sprite.setPosition(708, 620);
        a[23].sprite.setScale(7.25, 0.5);
        window.draw(a[23].sprite);

        /////////////////////////////////////LAYER 4///////////

        a[24].sprite.setPosition(320, 340);
        a[24].sprite.setScale(0.75, 1.5);
        window.draw(a[24].sprite);
        a[25].sprite.setPosition(320, 510);
        a[25].sprite.setScale(0.75, 1.5);
        window.draw(a[25].sprite);

        a[26].sprite.setPosition(320, 340);
        a[26].sprite.setScale(4.35, 0.5);
        window.draw(a[26].sprite);
        a[27].sprite.setPosition(320, 550);
        a[27].sprite.setScale(4.35, 0.5);
        window.draw(a[27].sprite);

        a[28].sprite.setPosition(825, 340);
        a[28].sprite.setScale(0.75, 1.5);
        window.draw(a[28].sprite);
        a[29].sprite.setPosition(825, 510);
        a[29].sprite.setScale(0.75, 1.5);
        window.draw(a[29].sprite);

        a[30].sprite.setPosition(708, 340);
        a[30].sprite.setScale(4.35, 0.5);
        window.draw(a[30].sprite);
        a[31].sprite.setPosition(708, 550);
        a[31].sprite.setScale(4.35, 0.5);
        window.draw(a[31].sprite);


        /////////////////////////////////////////MIDDLE BOX////////////////

        a[32].sprite.setPosition(420, 410);
        a[32].sprite.setScale(10, 0.5);
        window.draw(a[32].sprite);
        a[33].sprite.setPosition(420, 470);
        a[33].sprite.setScale(10, 0.5);
        window.draw(a[33].sprite);

        a[34].sprite.setPosition(420, 410);
        a[34].sprite.setScale(0.75, 1);
        window.draw(a[34].sprite);
        a[35].sprite.setPosition(420, 450);
        a[35].sprite.setScale(0.75, 1);
        window.draw(a[35].sprite);

        a[36].sprite.setPosition(720, 410);
        a[36].sprite.setScale(0.75, 1);
        window.draw(a[36].sprite);
        a[37].sprite.setPosition(720, 450);
        a[37].sprite.setScale(0.75, 1);
        window.draw(a[37].sprite);

    }

};

#endif // ARENA_H