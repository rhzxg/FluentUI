#pragma once

#include "FluWidget.h"
#include <QPainter>
#include <QtMath>
#include <QTimer>
#include "../FluUtils/FluUtils.h"

class FluBusyProgressRing : public FluWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor circleColor READ getCircleColor WRITE setCircleColor)
  public:
    class WorkData
    {
      public:
        int m_workAngle;
        QPointF m_point;
    };

  public:
    FluBusyProgressRing(QWidget* parent = nullptr) : FluWidget(parent)
    {
        setFixedSize(60, 60);
        m_nTimes = 0;

        m_workingTimer = new QTimer(parent);
        m_workingTimer->setInterval(12);
        m_workingTimer->start();
        m_workAngle = 270;

        setCircleColor(QColor(0, 90, 158));
        onThemeChanged();
        connect(m_workingTimer, &QTimer::timeout, [=]() {
            // m_workAngle--;

            m_nTimes %= 16;
            if (m_workDatas.size() < 6 && m_nTimes == 0)
            {
                WorkData wd;
                wd.m_workAngle = 270;
                wd.m_point = getPoint(wd.m_workAngle);
                m_workDatas.push_back(wd);
            }

            for (int i = 0; i < m_workDatas.size(); i++)
            {
                m_workDatas[i].m_workAngle += getSpeed(m_workDatas[i].m_workAngle);
                if (m_workDatas[i].m_workAngle >= 360)
                    m_workDatas[i].m_workAngle = m_workDatas[i].m_workAngle % 360;
                m_workDatas[i].m_point = getPoint(m_workDatas[i].m_workAngle);
            }

            m_nTimes++;
            update();
        });
    }

    QColor getCircleColor()
    {
        return m_circleColor;
    }

    void setCircleColor(QColor color)
    {
        m_circleColor = color;
        update();
    }

    QPointF getPoint(int angle)
    {
        // LOG_DEBUG << "angle:" << angle;
        float r = qMin(width(), height()) / 2;
        float x = (r - 6) * qCos(angle * 1.0 / 180 * M_PI) + r;
        float y = (r - 6) * qSin(angle * 1.0 / 180 * M_PI) + r;
        return QPointF(x, y);
    }

    int getSpeed(int angle)
    {
        int nCurI = 0;
        for (int i = 0; i < 8; i++)
        {
            if (angle >= 45 * i && angle < 45 * (i + 1))
            {
                nCurI = i;
            }
        }

        switch (nCurI)
        {
            case 0:
                return 4;
            case 1:
                return 8;
            case 2:
                return 8;
            case 3:
                return 4;
            case 4:
                return 2;
            case 5:
                return 1;
            case 6:
                return 1;
            case 7:
                return 2;
                // default:
                //     return 0;
        }

        return 1;
    }

    void paintEvent(QPaintEvent* event)
    {
        QPainter painter(this);
        painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

        // draw circle;
        QPen pen;
        // pen.setWidth(7);
        // pen.setColor(Qt::red);

        //  painter.setPen(pen);
        //  float minWH = qMin(width(), height());
        //  float trunkW = 6;

        //   QRectF outerC(4, 4, minWH - trunkW - 2, minWH - trunkW - 2);
        //   painter.drawEllipse(outerC);

        painter.setPen(Qt::NoPen);
        //if (FluThemeUtils::isLightTheme())
        //    painter.setBrush(QBrush(QColor(0, 90, 158)));
        //else if (FluThemeUtils::isDarkTheme())
        //    painter.setBrush(QBrush(QColor(118, 185, 237)));

        painter.setBrush(QBrush(m_circleColor));
        for (int i = 0; i < m_workDatas.size(); i++)
        {
            QRectF rf = QRectF(m_workDatas[i].m_point.x() - 3, m_workDatas[i].m_point.y() - 3, 6, 6);
            painter.drawEllipse(rf);
        }
    }
  public slots:
      void onThemeChanged()
      {
          if (FluThemeUtils::isLightTheme())
          {
              FluStyleSheetUitls::setQssByFileName("../StyleSheet/light/FluBusyProgressRing.qss", this);
          }
          else
          {
              FluStyleSheetUitls::setQssByFileName("../StyleSheet/dark/FluBusyProgressRing.qss", this);
          }
      }
  protected:
    QTimer* m_workingTimer;
    int m_nTimes;
    int m_workAngle;
    QPointF m_point;

    QColor m_circleColor;
    std::vector<WorkData> m_workDatas;
};
