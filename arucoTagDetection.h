
#include <opencv2/highgui.hpp>
#include <opencv2/aruco.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>

using namespace cv;

//R and translation vectors
extern std::vector< Vec3d > rvecs, tvecs;
// indication for read R and translation vectors
extern bool readyDetection; 

/*
* read camera parameters from provided file
*/
static bool readCameraParameters(std::string filename, Mat &camMatrix, Mat &distCoeffs);

/*
* grab frames from camera
* get dictionary for aruco, read cam parameters
* call detect function, draw tag
*/
void getFrameFromCam();

/*
* detect tag in image frame 
* get rotational n translation vector
*/
void detectTag(Mat img);

/*
*	draw the frame on screen with marker detection 
*  and axis on marker
*/
void drawMarkers();

//return rotational vector
std::vector< Vec3d > getRotationVector();

//return translation vector
std::vector< Vec3d > getTranslationVector();

//run tag detection in thread
void RunTagThread();