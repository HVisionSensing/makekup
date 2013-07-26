/*
 * blend_mode.cpp
 *
 *  Created on: Jul 26, 2013
 *      Author: scorpiolin
 */
#include "blend_mode.h"
using namespace std;
void BlendDarken(const Mat& baseImg, const Mat& topImg, Mat& dst) {

	int rows = baseImg.rows;
	int cols = baseImg.cols;

	// Step through and apply the "Darken" method
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			// Calculate the value of the
			// destination image pixel
			dst.at<Vec3b>(i, j) = Vec3b(
					std::min(baseImg.at<Vec3b>(i, j)[0],
							topImg.at<Vec3b>(i, j)[0]),
					std::min(baseImg.at<Vec3b>(i, j)[1],
							topImg.at<Vec3b>(i, j)[1]),
					std::min(baseImg.at<Vec3b>(i, j)[2],
							topImg.at<Vec3b>(i, j)[2]) );
		}
	}
}

