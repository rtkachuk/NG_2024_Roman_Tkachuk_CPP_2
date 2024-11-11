#ifndef EXAMPLE_H
#define EXAMPLE_H

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui {
class Example;
}
QT_END_NAMESPACE

class Example : public QMainWindow
{
    Q_OBJECT

public:
    Example(QWidget *parent = nullptr);
    ~Example();

private slots:
    void calculateChars();
    void autoCalculateChars();

private:
    Ui::Example *ui;
};
#endif // EXAMPLE_H
