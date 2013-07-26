/*
 * blend_mode.h
 *
 *  Created on: Jul 26, 2013
 *      Author: scorpiolin
 */

#ifndef BLEND_MODE_H_
#define BLEND_MODE_H_
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
void BlendDarken(const Mat& baseImg, const Mat& topImg, Mat& dst);



#endif /* BLEND_MODE_H_ */
