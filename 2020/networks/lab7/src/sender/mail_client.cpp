#include "mail_client.h"

MailClient::MailClient(){
    QObject::connect(&sendButton, SIGNAL(pressed()), this, SLOT(sendButtonClicked()));
    QObject::connect(&attachButton, SIGNAL(pressed()), this, SLOT(attachButtonClicked()));
    generalLayout.addLayout(&configLayout);
        serverAdressLabel.setText("Адрес почтового сервера: ");
        serverPortLabel.setText("Порт почтового сервер: ");
        adressLabel.setText("Адрес электронной почты: ");
        passwordLabel.setText("Пароль: ");
    
        configLayout.addRow(&serverAdressLabel,&serverAdressLine);
        configLayout.addRow(&serverPortLabel,&serverPortLine);
        configLayout.addRow(&adressLabel,&adressLine);
        configLayout.addRow(&passwordLabel,&passwordLine);
    generalLayout.addLayout(&emailLayout);
        emailLayout.addLayout(&editorHeadLayout);
            destAdrLabel.setText("Адрес получателя: ");
            titleLabel.setText("Тема: ");
            
            editorHeadLayout.addRow(&destAdrLabel,&destAdrLine);
            editorHeadLayout.addRow(&titleLabel,&titleLine);
            editorHeadLayout.addRow(&attachLabel,&attachButton);
        bodyLabel.setText("Текст: ");
        attachLabel.setText("Путь к вложению");
        attachButton.setText("Прикрепить файлы");
        sendButton.setText("Отправить");
        emailLayout.addWidget(&bodyEdit);
        emailLayout.addWidget(&sendButton);
    this->setLayout(&generalLayout);
};

void MailClient::sendButtonClicked(){
QTextStream log_stream(&log);
    QString request;
    QString response;
    if (this->connected){
        request = "QUIT\r\n";
        socket.write(request.toLocal8Bit());
        socket.waitForBytesWritten();
        qDebug() << "[Client]: " << request;
        log_stream << "[Client]: " << request;
        socket.waitForReadyRead();
        response = socket.readAll();
        qDebug() << "[Server]: " << response;
        log_stream << "[Server]: " << response;

        socket.close();
        this->connected = false;
        QMessageBox msgBox;
        msgBox.setText("Лог сессии");
        msgBox.setDetailedText(log);msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }else{
        qDebug() << "Connecting...";
        socket.connectToHost(serverAdressLine.text(), 25);
        if(socket.waitForConnected(5000)){
            qDebug() << "Connected!";
            socket.waitForReadyRead();
            response = socket.readAll();
            qDebug() << "[Server]: " << response;
            log_stream << "[Server]: " << response;
            request = "HELO " + serverAdressLine.text() + "\r\n";
            socket.write(request.toLocal8Bit());
            socket.waitForBytesWritten();
            qDebug() << "[Client]: " << request;
            log_stream << "[Client]: " << request;

            socket.waitForReadyRead();
            response = socket.readAll();
            qDebug() << "[Server]: " << response;
            log_stream << "[Server]: " << response;
            request = "AUTH LOGIN\r\n";
            socket.write(request.toLocal8Bit());
            socket.waitForBytesWritten();
            qDebug() << "[Client]: " << request;
            log_stream << "[Client]: " << request;

            socket.waitForReadyRead();
            response = socket.readAll();
            qDebug() << "[Server]: " << response;
            log_stream << "[Server]: " << response;
            request = adressLine.text().toUtf8().toBase64() + "\r\n";
            socket.write(request.toLocal8Bit());
            socket.waitForBytesWritten();
            qDebug() << "[Client]: " << request;
            log_stream << "[Client]: " << request;

            socket.waitForReadyRead();
            response = socket.readAll();
            qDebug() << "[Server]: " << response;
            log_stream << "[Server]: " << response;
            request = passwordLine.text().toUtf8().toBase64() + "\r\n";
            socket.write(request.toLocal8Bit());
            socket.waitForBytesWritten();
            qDebug() << "[Client]: " << request;
            log_stream << "[Client]: " << request;

            socket.waitForReadyRead();
            response = socket.readAll();
            qDebug() << "[Server]: " << response;
            log_stream << "[Server]: " << response;

            this->connected = true;

        }else{
            qDebug() << "Not connected!";
        }
    }

    if (this->connected){
        qDebug() << "Sending mail";

        request = "MAIL FROM: <" + adressLine.text() + ">\r\n";
        socket.write(request.toLocal8Bit());
        socket.waitForBytesWritten();
        qDebug() << "[Client]: " << request;
        log_stream << "[Client]: " << request;

        socket.waitForReadyRead();
        response = socket.readAll();
        qDebug() << "[Server]: " << response;
        log_stream << "[Server]: " << response;

        request = "RCPT TO: <" + destAdrLine.text() + ">\r\n";
        socket.write(request.toLocal8Bit());
        socket.waitForBytesWritten();
        qDebug() << "[Client]: " << request;
        log_stream << "[Client]: " << request;

        socket.waitForReadyRead();
        response = socket.readAll();
        qDebug() << "[Server]: " << response;
        log_stream << "[Server]: " << response;

        request = "DATA\r\n";
        socket.write(request.toLocal8Bit());
        socket.waitForBytesWritten();
        qDebug() << "[Client]: " << request;
        log_stream << "[Client]: " << request;

        socket.waitForReadyRead();
        response = socket.readAll();
        qDebug() << "[Server]: " << response;
        log_stream << "[Server]: " << response;

        request = "";
        QTextStream message(&request);
        message << "From: " << adressLine.text() << "\r\n";
        message << "Subject: " << titleLine.text() << "\r\n";
        message << "MIME-Version: 1.0\r\n";
        message << "Content-Type: multipart/mixed; boundary=\"**********\"\r\n";
        message << "--**********\r\n";
        message << "Content-Type: text/html; charset=\"koi8-r\"\r\n";
        message << "\r\n";
        message << bodyEdit.toPlainText() << "\r\n";
        message << "--**********\r\n";
        message << "Content-Type: application/octet-stream; name=\"" << this->attach_file << "\"\r\n";
        message << "Content-Transfer-Encoding: base64\r\n\r\n";
        message << this->attachment.toBase64() << "\r\n";
        message << "--**********\r\n";
        message << ".\r\n";

        socket.write(request.toLocal8Bit());
        socket.waitForBytesWritten();
        qDebug() << "[Client]: " << request;
        log_stream << "[Client]: " << request;

        socket.waitForReadyRead();
        response = socket.readAll();
        qDebug() << "[Server]: " << response;
        log_stream << "[Server]: " << response;
    }
}

void MailClient::attachButtonClicked(){
    this->attach_file = QFileDialog::getOpenFileName(this, "Выбрать вложение", nullptr, "Изображения (*.png *.jpg *.bmp)");
    QFile file(this->attach_file);
    file.open(QIODevice::ReadOnly);
    this->attachment = file.readAll();
    file.close();
    attachLabel.setText(this->attach_file);
};