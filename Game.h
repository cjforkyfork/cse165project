#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Health.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    Game(QWidget * parent=0);

    //public methods added this
    void displayMainMenu();

    // new one
    void GameOver();

    // public attributes
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Health * health;

    //added this
public slots:
    void start();

};

#endif // GAME_H
