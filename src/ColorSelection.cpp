/*
 * ColorSelection.cpp
 *
 *  Created on: Jul 25, 2013
 *      Author: scorpiolin
 */

#include "ColorSelection.h"
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
ColorSelection::ColorSelection() {
	// TODO Auto-generated constructor stub

}
Scalar ColorSelection::getColor(int ID){
	return Scalar(27,41,211);
}

ColorSelection::~ColorSelection() {
	// TODO Auto-generated destructor stub
}

