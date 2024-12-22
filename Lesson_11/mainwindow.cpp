#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_dbWorker = new DbWorker();
    m_dbWorker->initDb();

    connect (ui->b_enter, &QPushButton::clicked, this, &MainWindow::b_enter);
    connect (ui->b_exit, &QPushButton::clicked, this, &MainWindow::b_exit);
    connect (ui->b_create, &QPushButton::clicked, this, &MainWindow::b_createUser);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::b_exit()
{
    m_user.id = -1;
    m_user.login.clear();
    m_user.name.clear();
    m_user.isAdmin = false;
    ui->l_greetings->clear();
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::b_createUser()
{
    m_dbWorker->createUser(
        ui->e_cname->text(),
        ui->e_clogin->text(),
        ui->e_cpassword->text(),
        ui->cb_cIsAdmin->isChecked());

    ui->e_cname->clear();
    ui->e_clogin->clear();
    ui->e_cpassword->clear();
    ui->cb_cIsAdmin->setChecked(false);
}

void MainWindow::b_enter()
{
    m_user = m_dbWorker->loginUser(ui->e_login->text(), ui->e_password->text());
    qDebug () << m_user.id;
    if (m_user.id != -1) {
        ui->l_greetings->setText("Greetings, " + m_user.name + "!");
        ui->stackedWidget->setCurrentIndex(1);
        if (m_user.isAdmin == false)
            ui->gb_admin->setVisible(false);
        else
            ui->gb_admin->setVisible(true);
    }
}
