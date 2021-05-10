#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"

#include "Enemy2.h"

#include <QMediaPlayer>
#include <QBrush>
#include <QImage>

//added

#include "Button.h"
#include <string>


extern Game * game;

Game::Game(QWidget *parent){
    // set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
}

void Game::start(){
    // clear the screen
        scene->clear();

        scene = new QGraphicsScene();
        scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
        setBackgroundBrush(QBrush(QImage(":/images/bg.jpg")));

        // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
        // it can be used to visualize scenes)
        setScene(scene);
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFixedSize(800,600);

        // create the player
        player = new Player();
        player->setPos(400,500); // TODO generalize to always be in the middle bottom of screen
        // make the player focusable and set it to be the current focus
        player->setFlag(QGraphicsItem::ItemIsFocusable);
        player->setFocus();
        // add the player to the scene
        scene->addItem(player);

        // create the score/health
        score = new Score();
        scene->addItem(score);
        health = new Health();
        //health->setPos(health->x(),health->y()+25);
        health->setPos(health->x()+700,health->y());
        scene->addItem(health);

        // spawn enemies
        QTimer * timer = new QTimer();
        QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
        timer->start(2000);

           // play background music
        QMediaPlayer * music = new QMediaPlayer();
        music->setMedia(QUrl("qrc:/sounds/bgsound.mp3"));
        music->play();
        show();
}

void Game::displayMainMenu(){
    // create background added
     setBackgroundBrush(QBrush(QImage(":/images/bg.jpg")));

    // create the title text
    QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Duck Clash"));
    QFont titleFont("Courier New",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 150;
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

void Game::GameOver(){


    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);
    // set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);


    int john = game->score->getScore();
    std::string jay = std::to_string(john);
    QString qstr = QString::fromStdString(jay);

    // create background added
     setBackgroundBrush(QBrush(QImage(":/images/bg.jpg")));


    // create the title text
     QGraphicsTextItem* titleText = new QGraphicsTextItem(QString("Game Over"));

    QFont titleFont("Impact",50);
    titleText->setFont(titleFont);
    int txPos = this->width()/2 - titleText->boundingRect().width()/2;
    int tyPos = 25;  // changed from 150 to 25
    titleText->setPos(txPos,tyPos);
    scene->addItem(titleText);

    // create the final score
     QGraphicsTextItem* scoreText = new QGraphicsTextItem(QString("Final Score: ")+qstr);
     QFont scoreFont("comic sans",80);
     scoreText->setFont(titleFont);
     int sxPos = this->width()/2 - scoreText->boundingRect().width()/2;
     int syPos = 150;  // changed from 150 to 25
     scoreText->setPos(sxPos,syPos);
     scene->addItem(scoreText);

    // create the play button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    // create the quit button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

}
