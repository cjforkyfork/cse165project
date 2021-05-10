#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"


extern Game * game;

Enemy::Enemy_2(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){


    //set random x position
    int random_number = rand() % 700;

    if(game->score->getScore() % 5 == 0 && game->score->getScore() > 0)
    {

        setPos(random_number,0);
        const QString &fileName1 = ":/images/bomb.png";
        QPixmap bgPixmap(fileName1);
        QPixmap scaledd = bgPixmap.scaled(QSize(100, 100));

        setPixmap(scaledd);

        setTransformOriginPoint(50,50);
        setRotation(80);

        // make/connect a timer to move() the enemy every so often
        QTimer * timero = new QTimer(this);
        connect(timero,SIGNAL(timeout()),this,SLOT(move()));

        // start the timer
        timero->start(100);
    }

}

void Enemy::move(){
    // move enemy down
    setPos(x(),y()+5);

    // destroy enemy when it goes out of the screen
    if (pos().y() > 600){
        //decrease the health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
