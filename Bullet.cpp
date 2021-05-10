#include "Bullet.h"
#include <QTimer>
#include <QGraphicsPixmapItem>

#include <QList>
#include "Enemy.h"

#include "Enemy2.h"

#include "Game.h"

extern Game * game; // there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw graphics

    const QString &fileName = ":/images/bullet.png";
    QPixmap bgPixmap(fileName);
    QPixmap scaled = bgPixmap.scaled(QSize(64, 64));

    setPixmap(scaled);

    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // timer
    timer->start(50);
}

void Bullet::move(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // bullet colliding with duck
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){
            // increase the score
            game->score->increase();

            // remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;

            // return
            return;
        }
    }

    //  move the bullet forward
    setPos(x(),y()-50);
    // if the bullet is off the screen, destroy it
    if (pos().y() < 0){
           scene()->removeItem(this);
           delete this;
       }
}
