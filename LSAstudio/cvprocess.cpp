#include "cvprocess.h"
#include <stdio.h>
#include <constants.h>
#include <findEyeCenter.h>
#include <findEyeCorner.h>

cvProcess::cvProcess(QObject *parent): QThread(parent)
{

//    cascade_path= "";//"/home/treelab/Programs/opencv-master/data/lbpcascades/lbpcascade_frontalface.xml";
    model_path="/home/maquina2/Downloads/LSAstudio/data/lbf.model";
//    video_path = "/home/treelab/Videos/FK-Noemi.mp4";

//    face_cascade.load(cascade_path);
    params.model_filename = model_path;
    params.cascade_face = cascade_path;

    facemark = FacemarkLBF::create(params);
//    facemark->setFaceDetector((FN_FaceDetector)myDetector, &face_cascade);
    facemark->loadModel(params.model_filename.c_str());

//    cc.load(params.cascade_face.c_str());
//    templ = imread("/home/treelab/Work/LSAproject/pupil1.png",-1);
//    resize(templ, templ, Size((int)(templ.cols/2), (int)(templ.rows/2)), 0, 0, INTER_LINEAR_EXACT);
//    templ =  equalizeIntensity(templ);

    stop = true;
    showpoints =false;

    __elapse_time__ = 0;

    String modelConfiguration = "/home/maquina2/Downloads/LSAstudio/data/deploy.prototxt";
    String modelBinary = "/home/maquina2/Downloads/LSAstudio/data/res10_300x300_ssd_iter_140000.caffemodel";
    net = readNetFromCaffe(modelConfiguration, modelBinary);
    inWidth = 100;//300;
    inHeight = 100;//300;



    inScaleFactor = 1.0;
    meanVal=Scalar(104.0, 177.0, 123.0);

    im_rec_width=80;
    im_rec_height=80;

    model_points.push_back(cv::Point3d(0.0f, 0.0f, 0.0f));               // Nose tip
    model_points.push_back(cv::Point3d(0.0f, -330.0f, -65.0f));          // Chin
    model_points.push_back(cv::Point3d(-225.0f, 170.0f, -135.0f));       // Left eye left corner
    model_points.push_back(cv::Point3d(225.0f, 170.0f, -135.0f));        // Right eye right corner
    model_points.push_back(cv::Point3d(-150.0f, -150.0f, -125.0f));      // Left Mouth corner
    model_points.push_back(cv::Point3d(150.0f, -150.0f, -125.0f));       // Right mouth corner

    //y1[(int)cap->get(CAP_PROP_FRAME_COUNT)];

//    createCornerKernels();

}

void cvProcess::Start()
{
    if (!isRunning()) {
        if (isStopped()){
            stop = false;
        }
        start(LowPriority);
    }
}

void cvProcess::Stop()
{
    stop = true;
}


void cvProcess::run()
{
    switch (modes) {
    case train:
        getTrainFaces();
        break;
    case gaze:

        if(result_vector.empty())
            result_vector.resize(framestop-framestart+1);

        gazeEstimation();
        break;
    default:
        break;
    }

}

void cvProcess::getTrainFaces()
{
    Mat img;
    cout<< "getTrainFaces  "<< framestart << "  " << framestop<<endl;
//    waitKey(30);

   framestart+=1;
   for(int i = framestart;i<=framestop; i += cap1->get(CAP_PROP_FPS)){

       cap1->set(CAP_PROP_POS_FRAMES,i-1); // read regresa el siguiente frame, set uno antes del deseado
       cout<< i << " "<< cap1->get(CAP_PROP_FPS) << " "<< cap1->get(CAP_PROP_POS_FRAMES);

        if (!cap1->read(img) || stop)
        {
            cout<< " break " <<endl;
            stop = true;
            break;
        }

       cout<<" "<< cap1->get(CAP_PROP_POS_FRAMES) <<endl;

//       imshow("img",img);
//       waitKey();

        faceDetection1(img,i);
        emit progressValue(i);

//       cap1->set(CAP_PROP_POS_FRAMES, i);


    }

   if(cap1->get(CAP_PROP_POS_FRAMES)>=framestop-cap1->get(CAP_PROP_FPS))
    emit progressFinished();
}


void cvProcess::gazeEstimation()
{
    Mat img;


   cout<< "gazeEstimation  "<< framestart << "  " << framestop<<endl;

   int ii=0;
   framestart+=1;
   cap1->set(CAP_PROP_POS_FRAMES,framestart-1);

   __time__ = (double)getTickCount() - __elapse_time__;

      for(int i = framestart;i<=framestop;i++){
       cout<< i << " "<< cap1->get(CAP_PROP_FPS) <<endl;
       if (!cap1->read(img) || stop)
        {
            break;
        }

        faceDetection1(img,ii);
        ii++;

        __elapse_time__ = ((getTickCount() - __time__));
       emit progressTime(__elapse_time__);

        if(showpoints){
            debugframe = img;
            showDebugFrame(debugframe);
        }
//        imshow("detections", img);
//        waitKey(1);

        emit progressValue(i);

    }

   if(cap1->get(CAP_PROP_POS_FRAMES)>=framestop-cap1->get(CAP_PROP_FPS))
    emit progressFinished();

}


void cvProcess::showDebugFrame(Mat img)
{
    QImage img1;
            Mat RGBframe1;
            if (img.channels()== 3){
                cv::cvtColor(img, RGBframe1, cv::COLOR_BGR2RGB);
                img1 = QImage((const unsigned char*)(RGBframe1.data),
                                  RGBframe1.cols,RGBframe1.rows,QImage::Format_RGB888);
            }
            else
            {
                img1 = QImage((const unsigned char*)(img.data),
                                     img.cols,img.rows,QImage::Format_Indexed8);
            }
            emit progressFrame(img1);

}


bool cvProcess::isStopped() const{
    return this->stop;
}


//bool cvProcess::myDetector(InputArray image, OutputArray faces, CascadeClassifier *face_cascade)
//{
//    Mat gray;

//    if (image.channels() > 1)
//        cvtColor(image, gray, COLOR_BGR2GRAY);
//    else
//        gray = image.getMat().clone();


//    equalizeHist(gray, gray);


//    std::vector<Rect> faces_;
//    face_cascade->detectMultiScale(gray, faces_, 1.4, 2, CASCADE_SCALE_IMAGE, Size(30, 30));
//    Mat(faces_).copyTo(faces);
//    return true;
//}




//Mat cvProcess::equalizeIntensity(const Mat& inputImage)
//{
//    if(inputImage.channels() >= 3)
//    {
//        Mat ycrcb;

//        cvtColor(inputImage,ycrcb,CV_BGR2YCrCb);

//        vector<Mat> channels;
//        split(ycrcb,channels);

//        equalizeHist(channels[0], channels[0]);

//        Mat result;
//        merge(channels,ycrcb);

//        cvtColor(ycrcb,result,CV_YCrCb2BGR);

//        return result;
//    }
//    return Mat();
//}


bool cvProcess::isInside(Rect rect, Mat &img)
{
    return (rect & cv::Rect(0, 0, img.cols, img.rows)) == rect;
}

void cvProcess::findEyes(cv::Mat frame_gray, cv::Rect face, int i) {
  cv::Mat faceROI = frame_gray(face);
//  cv::Mat debugFace = faceROI;

  //if (kSmoothFaceImage) {

    double sigma = kSmoothFaceFactor * face.width;
    GaussianBlur( faceROI, faceROI, cv::Size( 0, 0 ), sigma);
  //}
  //-- Find eye regions and draw them
  int eye_region_width = face.width * (kEyePercentWidth/100.0);
  int eye_region_height = face.width * (kEyePercentHeight/100.0);
  int eye_region_top = face.height * (kEyePercentTop/100.0);
  cv::Rect leftEyeRegion(face.width*(kEyePercentSide/100.0),
                         eye_region_top,eye_region_width,eye_region_height);
  cv::Rect rightEyeRegion(face.width - eye_region_width - face.width*(kEyePercentSide/100.0),
                          eye_region_top,eye_region_width,eye_region_height);

  //-- Find Eye Centers
  cv::Point leftPupil = findEyeCenter(faceROI,leftEyeRegion,"Left Eye");
  cv::Point rightPupil = findEyeCenter(faceROI,rightEyeRegion,"Right Eye");
  // get corner regions
  cv::Rect leftRightCornerRegion(leftEyeRegion);
  leftRightCornerRegion.width -= leftPupil.x;
  leftRightCornerRegion.x += leftPupil.x;
  leftRightCornerRegion.height /= 2;
  leftRightCornerRegion.y += leftRightCornerRegion.height / 2;
  cv::Rect leftLeftCornerRegion(leftEyeRegion);
  leftLeftCornerRegion.width = leftPupil.x;
  leftLeftCornerRegion.height /= 2;
  leftLeftCornerRegion.y += leftLeftCornerRegion.height / 2;
  cv::Rect rightLeftCornerRegion(rightEyeRegion);
  rightLeftCornerRegion.width = rightPupil.x;
  rightLeftCornerRegion.height /= 2;
  rightLeftCornerRegion.y += rightLeftCornerRegion.height / 2;
  cv::Rect rightRightCornerRegion(rightEyeRegion);
  rightRightCornerRegion.width -= rightPupil.x;
  rightRightCornerRegion.x += rightPupil.x;
  rightRightCornerRegion.height /= 2;
  rightRightCornerRegion.y += rightRightCornerRegion.height / 2;

  // change eye centers to face coordinates
  rightPupil.x += rightEyeRegion.x ;
  rightPupil.y += rightEyeRegion.y ;
  leftPupil.x += leftEyeRegion.x;
  leftPupil.y += leftEyeRegion.y ;
  // draw eye centers

  result_vector.at(i).left_eye_loc_x = (float)( (leftEyeRegion.width/2)- (leftPupil.x - leftEyeRegion.x ))/(float)leftEyeRegion.width;
  result_vector.at(i).left_eye_loc_y = (float)( (leftEyeRegion.height/2) -(leftPupil.y - leftEyeRegion.y))/(float)leftEyeRegion.height;
  result_vector.at(i).right_eye_loc_x = (float)( (rightEyeRegion.width/2) - (rightPupil.x -rightEyeRegion.x) )/(float)rightEyeRegion.width;
  result_vector.at(i).right_eye_loc_y = (float)( (rightEyeRegion.height/2) - (rightPupil.y -rightEyeRegion.y))/(float)rightEyeRegion.height;

//  float lp_x = (float)( (leftEyeRegion.width/2)- (leftPupil.x - leftEyeRegion.x ))/(float)leftEyeRegion.width;
//  float lp_y = (float)( (leftEyeRegion.height/2) -(leftPupil.y - leftEyeRegion.y))/(float)leftEyeRegion.height;
//  float rp_x = (float)( (rightEyeRegion.width/2) - (rightPupil.x -rightEyeRegion.x) )/(float)rightEyeRegion.width;
//  float rp_y = (float)( (rightEyeRegion.height/2) - (rightPupil.y -rightEyeRegion.y))/(float)rightEyeRegion.height;

//  cout <<"lp_x "<< lp_x <<"  lp_y "<< lp_y<< "  rp_x "<< rp_x << "  rp_y " << rp_y<<endl;


  if(showpoints){

      circle(debugframe, rightPupil, 3, Scalar(0,200,0),-1);
      circle(debugframe, leftPupil, 3, Scalar(0,0,200),-1);
      rectangle(debugframe,leftEyeRegion,Scalar(0,0,200));
      rectangle(debugframe,rightEyeRegion,Scalar(0,200,0));

      rightPupil.x += face.x;
      rightPupil.y += face.y;
      leftPupil.x += face.x;
      leftPupil.y += face.y;

      leftRightCornerRegion.x+=face.x;
      leftRightCornerRegion.y+=face.y;
      leftLeftCornerRegion.x+=face.x;
      leftLeftCornerRegion.y+=face.y;

      rightLeftCornerRegion.x+=face.x;
      rightLeftCornerRegion.y+=face.y;
      rightRightCornerRegion.x+=face.x;
      rightRightCornerRegion.y+=face.y;

        rectangle(debugframe,leftRightCornerRegion,200);
        rectangle(debugframe,leftLeftCornerRegion,200);
        rectangle(debugframe,rightLeftCornerRegion,200);
        rectangle(debugframe,rightRightCornerRegion,200);

      leftEyeRegion.x += face.x;
      leftEyeRegion.y += face.y;
      rightEyeRegion.x += face.x;
      rightEyeRegion.y += face.y;


      rectangle(debugframe,leftEyeRegion,200);
      rectangle(debugframe,rightEyeRegion,200);

//  circle(debugFace, rightPupil, 3, 1234);
//  circle(debugFace, leftPupil, 3, 1234);
  circle(debugframe, rightPupil, 3, 1234,-1);
  circle(debugframe, leftPupil, 3, 1234,-1);

  }

  bool kEnableEyeCorner=false;
  //-- Find Eye Corners
  if (kEnableEyeCorner) {
    cv::Point2f leftRightCorner = findEyeCorner(faceROI(leftRightCornerRegion), true, false);
    leftRightCorner.x += leftRightCornerRegion.x;
    leftRightCorner.y += leftRightCornerRegion.y;
    cv::Point2f leftLeftCorner = findEyeCorner(faceROI(leftLeftCornerRegion), true, true);
    leftLeftCorner.x += leftLeftCornerRegion.x;
    leftLeftCorner.y += leftLeftCornerRegion.y;
    cv::Point2f rightLeftCorner = findEyeCorner(faceROI(rightLeftCornerRegion), false, true);
    rightLeftCorner.x += rightLeftCornerRegion.x;
    rightLeftCorner.y += rightLeftCornerRegion.y;
    cv::Point2f rightRightCorner = findEyeCorner(faceROI(rightRightCornerRegion), false, false);
    rightRightCorner.x += rightRightCornerRegion.x;
    rightRightCorner.y += rightRightCornerRegion.y;

  }

}


bool cvProcess::headPoseEstimation(Mat frame,int i)
{
    // Camera internals
  double focal_length = frame.cols; // Approximate focal length.
  Point2d center = cv::Point2d(frame.cols/2,frame.rows/2);
  cv::Mat camera_matrix = (cv::Mat_<double>(3,3) << focal_length, 0, center.x, 0 , focal_length, center.y, 0, 0, 1);
  cv::Mat dist_coeffs = cv::Mat::zeros(4,1,cv::DataType<double>::type); // Assuming no lens distortion

  //cout << "Camera Matrix " << endl << camera_matrix << endl ;
  // Output rotation and translation
  cv::Mat rotation_vector; // Rotation in axis-angle form
  cv::Mat translation_vector;

  //cout<<"flag 1" <<endl;
  // Solve for pose
  cv::solvePnP(model_points, image_points, camera_matrix, dist_coeffs, rotation_vector, translation_vector);

  //cout<<"flag 2" <<endl;
  // Project a 3D point (0, 0, 1000.0) onto the image plane.
  // We use this to draw a line sticking out of the nose

  vector<Point3d> nose_end_point3D;
  vector<Point2d> nose_end_point2D;
  nose_end_point3D.push_back(Point3d(0,0,1000.0));

  projectPoints(nose_end_point3D, rotation_vector, translation_vector, camera_matrix, dist_coeffs, nose_end_point2D);

  cv::Mat rotation_mat;                           //3 x 3 R
  cv::Mat pose_mat = cv::Mat(3, 4, CV_64FC1);     //3 x 4 R | T
  cv::Mat euler_angle = cv::Mat(3, 1, CV_64FC1);

  //temp buf for decomposeProjectionMatrix()
  cv::Mat out_intrinsics = cv::Mat(3, 3, CV_64FC1);
  cv::Mat out_rotation = cv::Mat(3, 3, CV_64FC1);
  cv::Mat out_translation = cv::Mat(3, 1, CV_64FC1);

  std::ostringstream outtext;

//calc euler angle
  cv::Rodrigues(rotation_vector, rotation_mat);
  cv::hconcat(rotation_mat, translation_vector, pose_mat);
  cv::decomposeProjectionMatrix(pose_mat, out_intrinsics, out_rotation, out_translation, cv::noArray(), cv::noArray(), cv::noArray(), euler_angle);

  result_vector.at(i).head_angle_x = euler_angle.at<double>(0);
  result_vector.at(i).head_angle_y = euler_angle.at<double>(1);
  result_vector.at(i).head_angle_z = euler_angle.at<double>(2);


  if(showpoints){
      cv::line(debugframe,image_points[0], nose_end_point2D[0], cv::Scalar(255,0,0), 2);

    //show angle result
          outtext << "X: " << std::setprecision(3) << euler_angle.at<double>(0);
          cv::putText(debugframe, outtext.str(), cv::Point(50, 40), cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(0, 0, 0));
          outtext.str("");
          outtext << "Y: " << std::setprecision(3) << euler_angle.at<double>(1);
          cv::putText(debugframe, outtext.str(), cv::Point(50, 60), cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(0, 0, 0));
          outtext.str("");
          outtext << "Z: " << std::setprecision(3) << euler_angle.at<double>(2);
          cv::putText(debugframe, outtext.str(), cv::Point(50, 80), cv::FONT_HERSHEY_SIMPLEX, 0.75, cv::Scalar(0, 0, 0));
          outtext.str("");

  }

}


bool cvProcess::faceDetection1(Mat frame,int ii)
{
            //! [Prepare blob]
            Mat inputBlob = blobFromImage(frame, inScaleFactor,
                                          Size(inWidth, inHeight), meanVal, false, false); //Convert Mat to batch of images
            //! [Prepare blob]

            //! [Set input blob]
            net.setInput(inputBlob, "data"); //set the network input
            //! [Set input blob]

            //! [Make forward pass]
            Mat detection = net.forward("detection_out"); //compute output
            //! [Make forward pass]


            Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

            if(stop)
                return false;

            bool foundFace =false;
            float confidenceThreshold = 0.5;
            for(int i = 0; i < detectionMat.rows; i++)
            {
                float confidence = detectionMat.at<float>(i, 2);

                if(confidence > confidenceThreshold)
                {

                    int s=1.2;
//                    tmp_detectionMat.push_back(detectionMat.row(i));
                    int xLeftBottom = static_cast<int>(detectionMat.at<float>(i, 3) * frame.cols * s);
                    int yLeftBottom = static_cast<int>(detectionMat.at<float>(i, 4) * frame.rows * s);
                    int xRightTop = static_cast<int>(detectionMat.at<float>(i, 5) * frame.cols * s);
                    int yRightTop = static_cast<int>(detectionMat.at<float>(i, 6) * frame.rows * s);

                    Rect object((int)xLeftBottom, (int)yLeftBottom,
                                (int)((xRightTop - xLeftBottom)),
                                (int)((yRightTop - yLeftBottom)) );

                    if (!isInside(object, frame))
                        continue;

                    if(modes==train)
                        preTrainingFaces.push_back(frame(object).clone());
                    else{
                        Mat tmp_gray_frame;
                        cvtColor(frame, tmp_gray_frame, COLOR_BGR2GRAY);


                        int prediction = model->predict(tmp_gray_frame(object));

                        if(showpoints){
                            rectangle(debugframe, object, Scalar(0, 255,0), 1);
                            // Create the text we will annotate the box with:
                            string box_text = format("Prediction = %d", prediction);
                            // Calculate the position for annotated text (make sure we don't
                            // put illegal values in there):
                            int pos_x = std::max(object.tl().x - 10, 0);
                            int pos_y = std::max(object.tl().y - 10, 0);
                            // And now put it into the image:
                            putText(debugframe, box_text, Point(pos_x, pos_y), FONT_HERSHEY_PLAIN, 1.0, Scalar(0,255,0), 2);
                        }

                        if(prediction==0)
                        {
                            rects.clear();
                            image_points.clear();
                            rects.push_back(object);
                            facemark->fit(tmp_gray_frame, rects, landmarks);
                            image_points.push_back(Point2d(landmarks[0][30]));
                            image_points.push_back(Point2d(landmarks[0][8]));
                            image_points.push_back(Point2d(landmarks[0][36]));
                            image_points.push_back(Point2d(landmarks[0][45]));
                            image_points.push_back(Point2d(landmarks[0][48]));
                            image_points.push_back(Point2d(landmarks[0][54]));
                            headPoseEstimation(tmp_gray_frame,ii);

                            if(showpoints)
                                for(unsigned long k=0;k<landmarks[0].size();k++)
                                    cv::circle(debugframe,landmarks[0][k],5,cv::Scalar(0,0,255),FILLED);


                            findEyes(tmp_gray_frame, object,ii);

                            foundFace = true;
                            result_vector.at(ii).face_found = true;
                            result_vector.at(ii).frame_idx = ii+framestart;

                        }

                    }

                    if(showpoints){


                        vector<double> layersTimings;
                        double freq = getTickFrequency() / 1000;
                        double time = net.getPerfProfile(layersTimings) / freq;

                        ostringstream ss;
                        ss << "FPS: " << 1000/time << " ; time: " << time << " ms";
                        putText(debugframe, ss.str(), Point(20,20), 0, 0.5, Scalar(0,0,255));

                        rectangle(debugframe, object, Scalar(0, 255, 0));
                        ss.str("");
                        ss << confidence;
                        String conf(ss.str());
                        String label = "Face: " + conf;
                        int baseLine = 0;
                        Size labelSize = getTextSize(label, FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
                        rectangle(debugframe, Rect(Point(xLeftBottom, yLeftBottom - labelSize.height),
                                              Size(labelSize.width, labelSize.height + baseLine)),
                                  Scalar(255, 255, 255), cv::FILLED);
                        putText(debugframe, label, Point(xLeftBottom, yLeftBottom),
                                FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0,0,0));
                    }


                }
            }



            if(!foundFace && modes==gaze)
            {
//                cout<<"true "<<endl;
                result_vector.at(ii).head_angle_x = -999;
                result_vector.at(ii).head_angle_y = -999;
                result_vector.at(ii).head_angle_z = -999;
                result_vector.at(ii).left_eye_loc_x = -999;
                result_vector.at(ii).left_eye_loc_y = -999;
                result_vector.at(ii).right_eye_loc_x = -999;
                result_vector.at(ii).right_eye_loc_y = -999;
                result_vector.at(ii).face_found = false;
                result_vector.at(ii).frame_idx = ii+framestart;

            }

            return foundFace;
//           imshow("detections", frame);
//           waitKey(1);


}

bool cvProcess::faceRecognitionTraining()
{
//        vector<Mat> images;
//        vector<int> labels;

        // Create a FaceRecognizer and train it on the given images:
        //Ptr<FisherFaceRecognizer> model = FisherFaceRecognizer::create();
    for(int i=0;i<TrainingFaces.size();i++)
    {
        cv::cvtColor( TrainingFaces[i], TrainingFaces[i] , cv::COLOR_BGR2GRAY );  //BLUE+GREEN+RED
        cout<<"labels "<< labels[i] <<endl;
    }


        model = LBPHFaceRecognizer::create();
        model->train(TrainingFaces, labels);

}

bool cvProcess::faceRecognition(Mat &frame)
{
    Mat tmp_gray_frame;
    cvtColor(frame, tmp_gray_frame, COLOR_BGR2GRAY);

    int prediction = model->predict(tmp_gray_frame);

}

bool cvProcess::saveFaceModel(string saveModelPath)
{
    if(!model.empty()){
        cout<<"model not empy :"<< saveModelPath <<endl;
        model->save(saveModelPath);
        return true;

    }else{
        cout<<"model empty " <<endl;
        return false;

    }
}

bool cvProcess::loadFaceModel(string saveModelPath)
{
    if(model.empty()){
        cout<<"model empty :"<< saveModelPath <<endl;
        model = Algorithm::load<LBPHFaceRecognizer>(saveModelPath);
        return true;

    }else{
        cout<<"model not empty " <<endl;
        return false;

    }
}

