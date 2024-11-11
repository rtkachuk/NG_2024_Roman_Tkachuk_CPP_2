#include "example.h"
#include "ui_example.h"

#ifdef _WIN64
#include "windows.h"
#endif

Example::Example(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Example)
{
    ui->setupUi(this);

    #ifdef _WIN64
        qDebug() << "Windows!";
    #else
        qDebug() << "Unix!";
    #endif

    connect (ui->bGetLength, &QPushButton::clicked, this, &Example::calculateChars);
    connect (ui->eUserInput, &QLineEdit::textChanged, this, &Example::autoCalculateChars);
    connect (ui->dial, &QDial::valueChanged, ui->progressBar, &QProgressBar::setValue);
}

Example::~Example()
{
    delete ui;
}

void Example::calculateChars()
{
    ui->lCharAmount->setText(QString::number(ui->eUserInput->text().size()));
}

void Example::autoCalculateChars()
{
    ui->lAutoCalculate->setText(QString::number(ui->eUserInput->text().size()));
    qDebug() << "Now elements: " << ui->eUserInput->text().size();
}
