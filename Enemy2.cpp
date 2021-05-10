#include "Enemy2.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"


extern Game * game;

Enemy2::Enemy2(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){


    //set random x position
    int random_number = rand() % 700;
    setPos(random_number,0);

    // drew the rect
   const QString &fileName = ":/images/bomb.png";
   QPixmap bgPixmap(fileName);
   QPixmap scaled = bgPixmap.scaled(QSize(80, 80));

   setPixmap(scaled);

   setTransformOriginPoint(50,50);
   setRotation(80);

    // make/connect a timer to move() the enemy every so often
    QTimer * timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);

}

void Enemy2::move(){

    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();


    // if one of the colliding items is a player decrease life
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player) ){
            // increase the score
            game->health->decrease();

          // delete them from the heap to save memory

             scene()->removeItem(this);
            delete this;

            // return (all code below refers to a non existint bullet)
            return;
        }
    }

    if(game->health->getHealth()==0)
    {
        game->GameOver();
    }

    // move bomb down
    setPos(x(),y()+95);


    // destroy bomb when it goes out of the screen
    if (pos().y() > 600){

        scene()->removeItem(this);
        delete this;
    }
}
