#pragma once
#include <QtWidgets>

#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>
#include <QTcpSocket>

class MailClient : public QWidget{
    Q_OBJECT
    public:
        MailClient();
    private:
        QString log;
        bool connected;
        QTcpSocket socket;
        int curr_msg = 0;

        QHBoxLayout generalLayout; 
            QVBoxLayout configLayout;
                QFormLayout formLayout;
                    QLabel passwordLabel,adressLabel,serverAdressLabel;
                    QLineEdit passwordLine,adressLine,serverAdressLine;
                QPushButton loginButton;
            QVBoxLayout emailListLayout;
                QListWidget mailList;
                QPushButton updateButton;
            QVBoxLayout emailContentLayout;
                QTextEdit emailContent;
                QPushButton deleteButton;
    public slots:
        void loginButtonPush();
        void updateButtonPush();
        void delButtonPush();
        void listItemClicked(QListWidgetItem *item);
}; 
