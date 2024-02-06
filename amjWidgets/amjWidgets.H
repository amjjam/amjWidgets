#ifndef AMJWIDGETS_H
#define AMJWIDGETS_H

#include <QWidget>
#include <QPixmap>
#include <QColor>
#include <QTimer>
#include <QVector>

class amjLED: public QWidget{
  Q_OBJECT
public:
  explicit amjLED(QWidget *parent=nullptr);
  ~amjLED(){};
  void setColors(QVector<QColor> _colors){colors=_colors;};
  void set(QColor _color){color=_color; repaint();};
  void set(int c){color=colors[c]; repaint();};
  void setFlash(int T, int fc);
  void setFlash(int T, QColor fc);
  void flash();
  void startWatchdog(int T){timer.start(T);};
  void stopWatchdog(){timer.stop();};
  void resetWatchdog(){counter++;};
protected:
  virtual void paintEvent(QPaintEvent *);
  virtual void resizeEvent(QResizeEvent *);
private:
  const qreal scaledSize;
  QPixmap ledBuffer;
  QVector<QColor> colors;
  QColor color;
  QColor flash_color;
  bool flashing;
  QTimer timer;
  int counter;
  void timeout();
};

#endif // AMJWIDGETS_H
