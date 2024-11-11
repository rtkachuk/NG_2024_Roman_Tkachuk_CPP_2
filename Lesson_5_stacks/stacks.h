#ifndef STACKS_H
#define STACKS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Stacks;
}
QT_END_NAMESPACE

class Stacks : public QMainWindow
{
    Q_OBJECT

public:
    Stacks(QWidget *parent = nullptr);
    ~Stacks();

private:
    Ui::Stacks *ui;
};
#endif // STACKS_H
