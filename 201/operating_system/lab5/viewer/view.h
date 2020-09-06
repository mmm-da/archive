#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QString>
#include <windows.h>
#include <QInputDialog>
#include <QMessageBox>
#include <QByteArray>

class view : public QWidget
{
    Q_OBJECT
private:
    QByteArray arr;
public:
    explicit view(QWidget *parent = nullptr);
    void test(QByteArray arr);
    HKEY root;
};

#endif // VIEW_H
