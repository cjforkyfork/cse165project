#include "Enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h> // rand() -> really large int
#include "Game.h"


extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // set duck position
     setPos(x()-240,y()+240);

    // duck img
   const QString &fileName = ":/images/enemy.png";
   QPixmap bgPixmap(fileName);
   QPixmap scaled = bgPixmap.scaled(QSize(80, 80));

   setPixmap(scaled);

   setTransformOriginPoint(50,50);
   setRotation(80);

    // make/connect a timer
    QTimer * timer = new QTimer(this);
   connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(50);


}

void Enemy::move(){
    // move duck east
 setPos(x()+10,y());

    // destroy enemy when it goes out of the screen
    if (pos().y() > 600){
        //decrease the health

        //game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
