#include "mail_client.h"

MailClient::MailClient(){
    connect(&loginButton,SIGNAL(pressed()),this,SLOT(loginButtonPush()));
    connect(&updateButton,SIGNAL(pressed()),this,SLOT(updateButtonPush()));
    connect(&deleteButton,SIGNAL(pressed()),this,SLOT(delButtonPush()));
    connect(&mailList,SIGNAL(itemClicked(QListWidgetItem)),this,SLOT(listItemClicked(QListWidgetItem)));
    generalLayout.addLayout(&configLayout);
        configLayout.addLayout(&formLayout);
            serverAdressLabel.setText("Адрес почтового сервера: ");
            adressLabel.setText("Адрес электронной почты: ");
            passwordLabel.setText("Пароль: ");

            formLayout.addRow(&serverAdressLabel,&serverAdressLine);
            formLayout.addRow(&adressLabel,&adressLine);
            formLayout.addRow(&passwordLabel,&passwordLine);
        loginButton.setText("Подключиться");
        configLayout.addWidget(&loginButton);
    generalLayout.addLayout(&emailListLayout);
        updateButton.setText("Обновить список");
        emailListLayout.addWidget(&mailList);
        emailListLayout.addWidget(&updateButton);
    generalLayout.addLayout(&emailContentLayout);
        deleteButton.setText("Удалить сообщение");
        emailContentLayout.addWidget(&emailContent);
        emailContentLayout.addWidget(&deleteButton);
    this->setLayout(&generalLayout);
};


void MailClient::loginButtonPush(){
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
        loginButton.setText("Подключение");
        this->connected = false;
        QMessageBox msgBox;
        msgBox.setText("Лог сессии");
        msgBox.setDetailedText(log);msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }else{
        qDebug() << "Connecting...";
        socket.connectToHost(serverAdressLine.text(), 110);
        if(socket.waitForConnected(5000)){
            qDebug() << "Connected!";
            socket.waitForReadyRead();
            response = socket.readAll();
            qDebug() << "[Server]: " << response;
            log_stream << "[Server]: " << response;

                request = "USER " + adressLine.text() + "\r\n";
                socket.write(request.toLocal8Bit());
                socket.waitForBytesWritten();
                qDebug() << "[Client]: " << request;
                log_stream << "[Client]: " << request;

                socket.waitForReadyRead();
                response = socket.readAll();
                qDebug() << "[Server]: " << response;
                log_stream << "[Server]: " << response;

                request = "PASS " + passwordLine.text() + "\r\n";
                socket.write(request.toLocal8Bit());
                socket.waitForBytesWritten();
                qDebug() << "[Client]: " << request;
                log_stream << "[Client]: " << request;

                socket.waitForReadyRead();
                response = socket.readAll();
                qDebug() << "[Server]: " << response;
                log_stream << "[Server]: " << response;

                loginButton.setText("Отключиться");
                this->connected = true;

            }else{
                qDebug() << "Not connected!";
            }
        }
};
void MailClient::updateButtonPush(){
    mailList.clear();
    if (!connected){
        return;
    }
    QTextStream log_stream(&log);
    QString request;
    QString response;

    request = "LIST\r\n";
    socket.write(request.toLocal8Bit());
    socket.waitForBytesWritten();
    qDebug() << "[Client]: " << request;
    log_stream << "[Client]: " << request;

    socket.waitForReadyRead();
//    qDebug() << "Ready to receive " << socket.bytesAvailable() << " bytes\n";
    response = socket.readAll();
    qDebug() << "[Server]: " << response;
    log_stream << "[Server]: " << response;

    int messages = response.split(" ")[1].toInt();
    QStringList items;
    while (items.length() < messages){
        socket.waitForReadyRead();
        response = socket.readAll();
        qDebug() << "[Server]: " << response;
        log_stream << "[Server]: " << response;
        items.append(response.split("\r\n"));
    }
    for (auto item: items){
        if (item != "." && item != ""){
            mailList.addItem(item + " байт");
        }
    }
    response = socket.readAll();
    qDebug() << "[Server]: " << response;
    log_stream << "[Server]: " << response;
};
void MailClient::delButtonPush(){
    QTextStream log_stream(&log);
    QString request;
    QString response;
    int index = curr_msg;
    request = "DELE " + QString::number(index) + "\r\n";
    socket.write(request.toLocal8Bit());
    socket.waitForBytesWritten();
    qDebug() << "[Client]: " << request;
    log_stream << "[Client]: " << request;

    socket.waitForReadyRead();
//    qDebug() << "Ready to receive " << socket.bytesAvailable() << " bytes\n";
    response = socket.readAll();
    qDebug() << "[Server]: " << response;
    log_stream << "[Server]: " << response;
    curr_msg = 0;
};
void MailClient::listItemClicked(QListWidgetItem *item){
    QTextStream log_stream(&log);
    QString request;
    QString response;
    int index = item->text().split(" ")[0].toInt();
    curr_msg = index;
    request = "RETR " + QString::number(index) + "\r\n";
    socket.write(request.toLocal8Bit());
    socket.waitForBytesWritten();
    qDebug() << "[Client]: " << request;
    log_stream << "[Client]: " << request;

    socket.waitForReadyRead();
    response = socket.readAll();
    qDebug() << "[Server]: " << response;
    log_stream << "[Server]: " << response;

    QString message;
    QTextStream message_stream(&message);
    int read = 0;
    int all = response.split(" ")[1].toInt();
    while (socket.waitForReadyRead(1000)){
        read += socket.bytesAvailable();
        response = socket.readAll();
        qDebug() << read << "/" << all;
        message_stream << response;
    }

    emailContent.setText(message);
};
