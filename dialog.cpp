#include "dialog.h"
#include "ui_dialog.h"
#include "Game.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(clicked()), this, SLOT(game()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::game()
{
        Game * game;

        game = new Game();
        game->show();

        //added
        game->displayMainMenu();
}
