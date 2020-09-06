#include <QtWidgets>
#include <windows.h>
#include <tlhelp32.h>
#include <psapi.h>

void th32SnapToQTable(QTableWidget* table);
void memoryMapToQTable(QTableWidget* table,QString processName);
HANDLE getProcessHandleByName(QString &pName);

class Task3: public QWidget{
    Q_OBJECT
    private:
        QTableWidget *processList;
        QTableWidget *memMap;
    public:
        Task3();
        void updateMap(int processId);
    public slots:
        void memoryMapBuild(int row, int column);
    signals:
        void clearMapTable();

};
