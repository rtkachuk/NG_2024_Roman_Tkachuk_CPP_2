#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect (ui->b_start, &QPushButton::clicked, this, &MainWindow::start);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start()
{
    int threadsAmount = ui->sb_threads->value();

    for (int currentThreadIndex = 0;
        currentThreadIndex < threadsAmount;
         currentThreadIndex++) {
        QProgressBar *bar = new QProgressBar(this);
        ui->vl_threads->addWidget(bar);

        Worker *worker = new Worker();

        connect (worker, &Worker::value, bar, &QProgressBar::setValue);
        connect (worker, &Worker::finished, this, &MainWindow::workerFinished);

        m_workers[worker] = bar;
        worker->start();
    }
    ui->statusbar->showMessage("Theads started: " + QString::number(threadsAmount));
}

void MainWindow::workerFinished()
{
    Worker *worker = (Worker*)sender();
    QProgressBar *bar = m_workers[worker];

    bar->hide();
    ui->vl_threads->removeWidget(bar);
    m_workers.remove(worker);
    ui->statusbar->showMessage("Theads ongoing: " + QString::number(m_workers.keys().size()));
    delete bar;
    delete worker;
}
