/*
 * ColorSelection.h
 *
 *  Created on: Jul 25, 2013
 *      Author: scorpiolin
 */

#ifndef COLORSELECTION_H_
#define COLORSELECTION_H_
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
class ColorSelection {
public:
	ColorSelection();
	static Scalar getColor(int ID);
	virtual ~ColorSelection();
};

#endif /* COLORSELECTION_H_ */
