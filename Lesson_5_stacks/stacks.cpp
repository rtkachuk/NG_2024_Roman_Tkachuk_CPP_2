#include "stacks.h"
#include "ui_stacks.h"

Stacks::Stacks(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Stacks)
{
    ui->setupUi(this);
}

Stacks::~Stacks()
{
    delete ui;
}
