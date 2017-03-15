#ifndef IMUCALIBRATIONWIDGET_H
#define IMUCALIBRATIONWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QScrollArea>
#include <QSplitter>
#include <QTabWidget>
#include <QListWidget>
#include <QTableWidget>
#include <QPushButton>
#include <QTime>
#include <QMap>
#include <glviewer.h>

#include <opencv2/opencv.hpp>

struct CvImageStamped
{
    QTime timestamp;
    cv::Mat image;
};

struct ImuStamped
{
    QTime timestamp;
    double ax,ay,az;
    double rx,ry,rz;
};

struct ImuCalibData
{
    geometry_msgs::PoseStamped imupose;
    cv::Point2f imagepose;
};


class ImuCalibrationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ImuCalibrationWidget(QString devices, QString intrinsicfilename, QWidget *parent = 0);
protected:
    cv::Mat cameramat;
    cv::Mat distcoeff;
protected:
    QVector<cv::Mat> initposes;
    QVector<cv::Mat> initvelocity;
protected:
    QMap<QString,int> devicemap;
protected:
    QVector<CvImageStamped> images;
    QVector<QVector<
    QVector<QVector<geometry_msgs::PoseStamped> > imuposes;
protected:
    QVector<QVector<ImuCalibData> > imageposes;
protected:
    QVBoxLayout * layout;
    QSplitter * splitter;

    QScrollArea * scrollarea;
    QLabel * imageview;

    QTabWidget * imuviewtabs;
    QVector<RobotSDK::GLViewer *> imuviewers;

    QTableWidget * calibdataview;

    QHBoxLayout * btnlayout;
    QPushButton * btncalib;
    QPushButton * btnproject;
signals:

public slots:
};

#endif // IMUCALIBRATIONWIDGET_H
