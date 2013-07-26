/*
 * testmain.cpp

 *
 *  Created on: Jul 24, 2013
 *      Author: scorpiolin
 */
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/highgui/highgui.hpp>
#include "MakeupManager.h"
using namespace std;
using namespace cv;
int main() {
	MakeupManager* makeupManager = new MakeupManager;
	makeupManager->loadImage("test.jpg");
	makeupManager->runAMFilter(5.0, 0.06);
	Mat& outImg = makeupManager->getOutImg();

	imshow("test",outImg);
	waitKey(0);
	return 0;
}

