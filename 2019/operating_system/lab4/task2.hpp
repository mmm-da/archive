#include <QtWidgets>
#include <windows.h>
#include "qcustomplot.h"


class AxisTag : public QObject
{
  Q_OBJECT
public:
  explicit AxisTag(QCPAxis *parentAxis);
  virtual ~AxisTag();
   
  // setters:
  void setPen(const QPen &pen);
  void setBrush(const QBrush &brush);
  void setText(const QString &text);
   
  // getters:
  QPen pen() const { return mLabel->pen(); }
  QBrush brush() const { return mLabel->brush(); }
  QString text() const { return mLabel->text(); }
   
  // other methods:
  void updatePosition(double value);
   
protected:
  QCPAxis *mAxis;
  QPointer<QCPItemTracer> mDummyTracer;
  QPointer<QCPItemLine> mArrow;
  QPointer<QCPItemText> mLabel;
};


class Task2: public QWidget{
    Q_OBJECT
    private:
        QCustomPlot *customPlot1, *customPlot2, *customPlot3;
        AxisTag *mTag1_0, *mTag1_1, *mTag2_0, *mTag2_1, *mTag3_0, *mTag3_1;
        MEMORYSTATUSEX memStatus;
        QTimer *dataTimer;
        QProgressBar *memUsage;
    public:
        Task2();
    public slots:
        void realtimeDataSlot();
};

