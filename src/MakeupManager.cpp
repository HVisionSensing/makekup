/*
 * MakeupManager.cpp
 *
 *  Created on: Jul 26, 2013
 *      Author: scorpiolin
 */

#include "MakeupManager.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/contrib/contrib.hpp>
#include "amfilter/adaptive_manifold_filter.hpp"
#include "ColorSelection.h"
#include <stdio.h>
#include <iostream>
using namespace std;
using namespace cv;
MakeupManager::MakeupManager() {
	// TODO Auto-generated constructor stub

}
void MakeupManager::loadImage(string imgName) {
	int index_dot = imgName.find('.');
	image_name = imgName.substr(0, index_dot);
	srcImg = imread(imgName);
	if (srcImg.empty()) {
		cerr << "Can't open image - " << imgName << endl;
	}
	outImg= srcImg.clone();
}
void MakeupManager::runAMFilter(double sigma_s, double sigma_r) {

	Ptr<AdaptiveManifoldFilter> filter = AdaptiveManifoldFilter::create();
	filter->set("sigma_s", sigma_s);
	filter->set("sigma_r", sigma_r);

	Mat dst, tilde_dst;
	Mat jointImg;
	TickMeter tm;
	tm.start();
	filter->apply(outImg, outImg, tilde_dst, jointImg);
	tm.stop();
	cout << "Time : " << tm.getTimeMilli() << " ms" << endl;
	imwrite(image_name + "_filter.jpg", outImg);

}

void MakeupManager::runASMLocation() {
	cv::Mat_<unsigned char> img;
	cvtColor(outImg,img,CV_BGR2GRAY);

	if (!img.data) {
		printf("Cannot load\n");
		exit(1);
	}

	int foundface;

	if (!stasm_search_single(&foundface, landmarks, (const char*) img.data,
			img.cols, img.rows, image_name.c_str(), "./model")) {
		printf("Error in stasm_search_single: %s\n", stasm_lasterr());
		exit(1);
	}

	if (!foundface)
		printf("No face found in %s\n", image_name.c_str());
	else {
		// draw the landmarks on the image as white dots (image is monochrome)
		stasm_force_points_into_image(landmarks, img.cols, img.rows);
		for (int i = 0; i < stasm_NLANDMARKS; i++) {

			outImg.at<Vec3b>(cvRound(landmarks[i * 2 + 1]),
					cvRound(landmarks[i * 2]))[0] = 255;
			outImg.at<Vec3b>(cvRound(landmarks[i * 2 + 1]),
					cvRound(landmarks[i * 2]))[1] = 255;
			outImg.at<Vec3b>(cvRound(landmarks[i * 2 + 1]),
					cvRound(landmarks[i * 2]))[2] = 255;
		}
		//	cout << cvRound(landmarks[i * 2 + 1]) << endl << cvRound(landmarks[i * 2]) << endl;
		//	cvPutText(img,"2",Point())

	}

	cv::imwrite(image_name+"_asm.jpg", outImg);
	int num_points = 10;
	Point* points = new Point[num_points];
	int points_ID[10] = { 59, 60, 61, 62, 63, 64, 65, 66, 67, 68 };
	//	int points_ID[10] = { 71, 70, 69, 76, 75, 74, 73, 72};
	for (int i = 0; i < num_points; i++) {
		points[i] = Point(cvRound(landmarks[points_ID[i] * 2]),
				cvRound(landmarks[points_ID[i] * 2 + 1]));
		//	cout << points[i].x << endl << points[i].y << endl;
	}
//	cout << (unsigned short) srcImg.at<Vec3b>(points[0].y, points[0].x)[0]
//			<< endl;
//	cout << (unsigned short) srcImg.at<Vec3b>(points[0].y, points[0].x)[1]
//			<< endl;
//	cout << (unsigned short) srcImg.at<Vec3b>(points[0].y, points[0].x)[2]
//			<< endl;
	Mat maskImg = outImg.clone();
	fillConvexPoly(maskImg, points, num_points, ColorSelection::getColor(1));
	addWeighted(outImg, 0.7, maskImg, 0.3, 0, outImg);

}
void MakeupManager::runLipMakeup() {

}
Mat& MakeupManager::getOutImg() {
	return outImg;
}
MakeupManager::~MakeupManager() {
	// TODO Auto-generated destructor stub
}

