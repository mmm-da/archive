#include <QApplication>
#include "mail_client.h"
int main(int argc, char *argv[]){
    QApplication app(argc,argv);
    MailClient client;
    client.show();
    return app.exec();
}