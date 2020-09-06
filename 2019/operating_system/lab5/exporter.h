#ifndef EXPORTER_H
#define EXPORTER_H

#include <QWidget>
#include <QString>
#include <windows.h>
#include <QInputDialog>
#include <QMessageBox>
#include <QByteArray>

class exporter : public QWidget
{
    Q_OBJECT
private:
    QString branch_str;
public:
    QByteArray result;
    explicit exporter(QWidget *parent = nullptr);
    bool validate_branch_name();
    HKEY root;
    QByteArray get_result_array();
};

#endif // EXPORTER_H
