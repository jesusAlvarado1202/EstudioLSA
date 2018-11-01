#ifndef CVPROCESS_H
#define CVPROCESS_H

#include <stdio.h>
#include <ctime>
 #include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <opencv2/opencv.hpp>
#include "opencv2/face.hpp"
#include <opencv2/dnn.hpp>


#include <QVector>
#include <QMutex>
#include <QThread>
#include <ctime>
#include <QDateTime>
#include <QImage>

//#include <player.h>
//#include "testclass.h"

using namespace std;
using namespace cv;
using namespace cv::face;
using namespace cv::dnn;


class cvProcess : public QThread
{    Q_OBJECT

public:

     QMutex mutex;

    CascadeClassifier face_cascade;
    FacemarkLBF::Params params;
    Ptr<Facemark> facemark;
    Mat templ;
    int nfaces;
    std::vector<Rect> rects ,rects_scaled ;
    std::vector<std::vector<Point2f> > landmarks;
    CascadeClassifier cc;
    std::vector<cv::Point2d> face_points;
    VideoCapture *cap1;
    int framestop;
    int framestart;
    Mat debugframe;
//    bool finished;

    std::vector<cv::Point3d> model_points;
    std::vector<cv::Point2d> image_points;

    size_t inWidth;
    size_t inHeight;
    double inScaleFactor;
    Scalar meanVal;

    int im_rec_width;
    int im_rec_height;

    enum Modes{train, gaze} modes;
    struct frame_results{
        float head_angle_x;
        float head_angle_y;
        float head_angle_z;
        float left_eye_loc_x;
        float left_eye_loc_y;
        float right_eye_loc_x;
        float right_eye_loc_y;
        bool face_found;
        int frame_idx;
    };

    vector<frame_results> result_vector;


    Net net;
    vector<Mat> preTrainingFaces;
    Ptr<LBPHFaceRecognizer> model;
    vector<int> labels;
    vector<Mat> TrainingFaces;

    QVector<double> y,y1;

    double __time__, __elapse_time__;


    explicit cvProcess(QObject *parent = 0);
    void gazeEstimation();//(int &i, Mat &img);

    static bool myDetector(InputArray image, OutputArray ROIs, CascadeClassifier *face_cascade);
    double faceDetection(const Mat frame);
    bool conditionFace(Mat frame);
    Point match(Mat scene);
    Mat equalizeIntensity(const Mat& inputImage);

    void getTrainFaces();
    bool faceDetection1(Mat frame, int i);
    bool faceRecognitionTraining();
    bool faceRecognition(Mat &frame);
    bool isInside(Rect rect, Mat &img);
    void findEyes(Mat frame_gray, Rect face, int i);
    bool headPoseEstimation(Mat frame, int i);

    void showDebugFrame(Mat img);
    bool saveFaceModel(string saveModelPath);
    bool loadFaceModel(string saveModelPath);



    void Start();
    void Stop();
    bool isStopped() const;
    bool showpoints;

signals:
 //Signal to output frame to be displayed
      void progressValue(int value);
      void progressTime(double time);
      void progressFrame(QImage img1);
      void progressFinished();

private:
    String cascade_path,model_path, video_path;
    bool stop;


protected:
    void run();

};

#endif // CVPROCESS_H
