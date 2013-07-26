// minimal.cpp: Display the landmarks of a face in an image.
//              This demonstrates stasm_search_single.

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "stasm_lib.h"
#include "../ColorSelection.h"
using namespace cv;
using namespace std;
void rotate(cv::Mat& src, double angle, cv::Mat& dst) {
	int len = std::max(src.cols, src.rows);
	cv::Point2f pt(len / 2., len / 2.);
	cv::Mat r = cv::getRotationMatrix2D(pt, angle, 1.0);

	cv::warpAffine(src, dst, r, cv::Size(len, len));
}
void runASM(char * pathname) {
	cv::Mat_<unsigned char> img(cv::imread(pathname, CV_LOAD_IMAGE_GRAYSCALE));
	Mat srcImg = imread(pathname);

	if (!img.data) {
		printf("Cannot load %s\n", pathname);
		exit(1);
	}

	int foundface;
	float landmarks[2 * stasm_NLANDMARKS]; // x,y coords (note the 2)

	if (!stasm_search_single(&foundface, landmarks, (const char*) img.data,
			img.cols, img.rows, pathname, "./model")) {
		printf("Error in stasm_search_single: %s\n", stasm_lasterr());
		exit(1);
	}

	if (!foundface)
		printf("No face found in %s\n", pathname);
	else {
		// draw the landmarks on the image as white dots (image is monochrome)
		stasm_force_points_into_image(landmarks, img.cols, img.rows);
		for (int i = 0; i < stasm_NLANDMARKS; i++) {

			srcImg.at<Vec3b>(cvRound(landmarks[i * 2 + 1]),
					cvRound(landmarks[i * 2]))[0] = 255;
			srcImg.at<Vec3b>(cvRound(landmarks[i * 2 + 1]),
					cvRound(landmarks[i * 2]))[1] = 255;
			srcImg.at<Vec3b>(cvRound(landmarks[i * 2 + 1]),
					cvRound(landmarks[i * 2]))[2] = 255;
		}
		//	cout << cvRound(landmarks[i * 2 + 1]) << endl << cvRound(landmarks[i * 2]) << endl;
		//	cvPutText(img,"2",Point())

	}

	cv::imwrite("minimal.bmp", srcImg);
	int num_points = 10;
	Point* points = new Point[num_points];
	int points_ID[10] = { 59, 60, 61, 62, 63, 64, 65, 66, 67, 68 };
	//	int points_ID[10] = { 71, 70, 69, 76, 75, 74, 73, 72};
	for (int i = 0; i < num_points; i++) {
		points[i] = Point(cvRound(landmarks[points_ID[i] * 2]),
				cvRound(landmarks[points_ID[i] * 2 + 1]));
		//	cout << points[i].x << endl << points[i].y << endl;
	}
	cout<<(unsigned short)srcImg.at<Vec3b>(points[0].y,points[0].x)[0]<<endl;
	cout<<(unsigned short)srcImg.at<Vec3b>(points[0].y,points[0].x)[1]<<endl;
	cout<<(unsigned short)srcImg.at<Vec3b>(points[0].y,points[0].x)[2]<<endl;
	Mat maskImg = srcImg.clone();
	fillConvexPoly(maskImg, points, num_points, ColorSelection::getColor(1));
	Mat result;
	addWeighted(srcImg, 0.7, maskImg, 0.3, 0, result);

	cv::imshow(pathname, result);
}
//int main() {
//	runASM("test.jpg");
////	runASM("rotate.jpg");
////	Mat img = imread("test.jpg");
////	Mat rotateImg;
////	rotate(img, -15, rotateImg);
////	imwrite("rotate.jpg",rotateImg);
//	cv::waitKey();
//	return 0;
//}
