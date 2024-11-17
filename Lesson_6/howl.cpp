#include "howl.h"
#include "ui_howl.h"

Howl::Howl(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Howl)
{
    ui->setupUi(this);

    m_file = new QMenu("File");
    m_select = new QAction("Select Files");

    m_file->addAction(m_select);
    ui->menubar->addMenu(m_file);

    m_audioOutput = new QAudioOutput();
    m_player = new QMediaPlayer();

    m_player->setAudioOutput(m_audioOutput);

    ui->sl_volume->setRange(0, 100);

    connect (m_player, &QMediaPlayer::positionChanged, this, &Howl::setProgress);
    connect (m_player, &QMediaPlayer::playbackStateChanged, this, &Howl::playStateChanged);
    connect (ui->b_play, &QPushButton::clicked, m_player, &QMediaPlayer::play);

    connect (m_select, &QAction::triggered, this, &Howl::selectFiles);

    connect (ui->sl_volume, &QSlider::valueChanged, this, &Howl::setVolume);
    connect (ui->sl_volume, &QSlider::valueChanged, this, &Howl::setVolumeText);

    connect (ui->lw_playlist, &QListWidget::currentTextChanged, this, &Howl::setMedia);


    ui->sl_volume->setValue(c_startVolume);
    m_audioOutput->setVolume((float)c_startVolume / 100);
}

Howl::~Howl()
{
    delete m_file;
    delete m_select;

    m_player->stop();
    delete m_player;

    delete ui;
}

void Howl::selectFiles()
{
    QStringList files = QFileDialog::getOpenFileNames(
        this,
        "Select one or more files to open",
        "",
        "Music (*.mp3)");

    ui->lw_playlist->clear();
    ui->lw_playlist->addItems(files);
}

void Howl::setVolumeText(int volume)
{
    ui->l_volume->setText(QString::number(volume));
}

void Howl::setMedia(QString text)
{
    m_player->setSource(QUrl::fromLocalFile(text));
    ui->l_name->setText(text.remove(0, text.lastIndexOf("/")+1));
}

void Howl::setProgress(qint64 progress)
{
    ui->s_progress->setValue(progress / (m_player->duration()/100));
}

void Howl::setVolume(int volume)
{
    m_audioOutput->setVolume(((float)volume)/100);
}

void Howl::playStateChanged(QMediaPlayer::PlaybackState state)
{
    switch(state) {
        case QMediaPlayer::PlayingState: {
            disconnect (ui->b_play, &QPushButton::clicked, m_player, &QMediaPlayer::play);
            connect (ui->b_play, &QPushButton::clicked, m_player, &QMediaPlayer::pause);
            ui->b_play->setText("||");
        } break;
        case QMediaPlayer::PausedState: {
            ui->b_play->setText(">");
            disconnect (ui->b_play, &QPushButton::clicked, m_player, &QMediaPlayer::pause);
            connect (ui->b_play, &QPushButton::clicked, m_player, &QMediaPlayer::play);
        } break;
        case QMediaPlayer::StoppedState:
            ui->lw_playlist->setCurrentRow(ui->lw_playlist->currentRow() + 1);
            break;
    }
}
