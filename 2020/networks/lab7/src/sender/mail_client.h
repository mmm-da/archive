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
        QString attach_file;
        QByteArray attachment;
        QTcpSocket socket;
        bool connected;
        QString log;

        QHBoxLayout generalLayout; 
            QFormLayout configLayout;
                QLabel passwordLabel,adressLabel,serverAdressLabel,serverPortLabel;
                QLineEdit passwordLine,adressLine,serverAdressLine,serverPortLine;
        QVBoxLayout emailLayout;
            QFormLayout editorHeadLayout;
                QLabel destAdrLabel,titleLabel;
                QLineEdit destAdrLine,titleLine;
            QLabel attachLabel,bodyLabel;
            QTextEdit bodyEdit;
            QPushButton sendButton,attachButton;
    public slots:
        void sendButtonClicked();
        void attachButtonClicked();
}; 