/*
 * MakeupManager.h
 *
 *  Created on: Jul 26, 2013
 *      Author: scorpiolin
 */

#ifndef MAKEUPMANAGER_H_
#define MAKEUPMANAGER_H_
#include <opencv2/highgui/highgui.hpp>
#include "asm/stasm_lib.h"
using namespace cv;
using namespace std;
class MakeupManager {
public:
	MakeupManager();
	void loadImage(string imgName);
	void runAMFilter(double sigma_s, double sigma_r);
	void runASMLocation();
	void runLipMakeup();
	Mat& getOutImg();
	virtual ~MakeupManager();
private:
	string image_name;
	Mat srcImg;
	Mat outImg;
	float landmarks[2 * stasm_NLANDMARKS];
};

#endif /* MAKEUPMANAGER_H_ */
