
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <stdio.h>
using namespace cv;
using namespace std;
int main(int argc, char* argv[])
{
    int d = 0;
    char ad[300] = { 0 };
    char name;
    //从电脑摄像头读入
    VideoCapture capture1(1);
    VideoCapture capture0(0);
    capture1.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    capture1.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    capture0.set(CV_CAP_PROP_FRAME_WIDTH, 640);
    capture0.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    if (capture1.isOpened() && capture0.isOpened())
        cout << "camera is opened" << endl;
    else
        cout << "camera is not opened" << endl;
    Mat edges;
    waitKey(2000);
    //循环显示每一帧
    Mat left, right;
    while (1)
    {
        capture0 >> left;//读取当前帧
        capture1 >> right;
        imshow("left", left);
        imshow("right", right);

        int k = waitKey(30);//延时30ms
        if (k == 'e' || cvGetWindowHandle("left") == nullptr || cvGetWindowHandle("right") == nullptr)
            break;
        else if (k == 'c')
        {
            sprintf_s(ad,300, "F:\\CodeFiles\\VS\\opencv\\StereoCalib\\ReadCalibationPictures\\CalibPicture_1\\left%02d.jpg", ++d);
            imwrite(ad, left);
            sprintf_s(ad,300, "F:\\CodeFiles\\VS\\opencv\\StereoCalib\\ReadCalibationPictures\\CalibPicture_1\\right%02d.jpg", d);
            imwrite(ad, right);
            cout << "the  " << d << "th  picture has been saved. " << endl;
        }
    }
    return 0;
}