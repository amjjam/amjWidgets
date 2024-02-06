#include "amjWidgets.H"

#include <QPainter>

amjLED::amjLED(QWidget *parent):QWidget(parent),scaledSize(1000){
  flashing=false;
  timer.callOnTimeout(this,&amjLED::timeout);
  connect(&timer,&QTimer::timeout,this,&amjLED::timeout);
  setFixedSize(24,24);
  setColors({Qt::black,Qt::red,Qt::green,Qt::blue});
  set(0);
}

void amjLED::setFlash(int T, int fc){
  setFlash(T,colors[fc]);
}

void amjLED::setFlash(int T, QColor fc){
  timer.stop();
  timer.setInterval(T);
  flash_color=fc;
  flashing=true;
}

void amjLED::flash(){
  if(timer.isActive())
    return;
  set(flash_color); 
}

void amjLED::paintEvent(QPaintEvent *){
  qreal realSize = qMin(width(), height());

  QRadialGradient gradient;
  QPainter painter(this);
  QPen pen(Qt::black);
  pen.setWidth(1);

  painter.setRenderHint(QPainter::Antialiasing);
  painter.translate(width()/2, height()/2);
  painter.scale(realSize/scaledSize, realSize/scaledSize);

  gradient = QRadialGradient (QPointF(-500,-500), 1500, QPointF(-500,-500));
  gradient.setColorAt(0, QColor(224,224,224));
  gradient.setColorAt(1, QColor(28,28,28));
  painter.setPen(pen);
  painter.setBrush(QBrush(gradient));
  painter.drawEllipse(QPointF(0,0), 500, 500);

  gradient = QRadialGradient (QPointF(500,500), 1500, QPointF(500,500));
  gradient.setColorAt(0, QColor(224,224,224));
  gradient.setColorAt(1, QColor(28,28,28));
  painter.setPen(pen);
  painter.setBrush(QBrush(gradient));
  painter.drawEllipse(QPointF(0,0), 450, 450);

  painter.setPen(pen);

  gradient=QRadialGradient (QPointF(-500,-500), 1500, QPointF(-500,-500));
  gradient.setColorAt(0,color);
  gradient.setColorAt(1,QColor(color.red()*0.67,color.green()*0.67,color.blue()*0.67));

  painter.setBrush(gradient);
  painter.drawEllipse(QPointF(0,0), 400, 400);
}

void amjLED::resizeEvent(QResizeEvent *){
  update();
}

void amjLED::timeout(){
  if(flashing||counter==0){
    color=colors[0];
    repaint();
  }
  counter=0;
}
