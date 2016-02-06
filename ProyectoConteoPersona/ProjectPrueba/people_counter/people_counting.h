#pragma once

#include <iostream>
#include <string>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv2\opencv.hpp>

#include "../cvBlob/cvblob.h"

enum LaneOrientation
{
	LO_NONE = 0,
	LO_HORIZONTAL = 1,
	LO_VERTICAL = 2
};

enum PeoplePosition
{
	PP_NONE = 0,
	PP_A = 1,
	PP_B = 2
};

class PeopleCouting
{
private:
	bool firstTime;
	bool showOutput;
	int key;
	cv::Mat img_input;
	cvb::CvTracks tracks;
	std::map<cvb::CvID, std::vector<CvPoint2D64f> > points;
	LaneOrientation laneOrientation;
	std::map<cvb::CvID, PeoplePosition> positions;
	long countAB;
	long countBA;
	int img_w;
	int img_h;
	int showAB;

public:
	PeopleCouting();
	~PeopleCouting();

	void setInput(const cv::Mat &i);
	void setTracks(const cvb::CvTracks &t);
	void process();

private:
	PeoplePosition getPeoplePosition(const CvPoint2D64f centroid);

	void saveConfig();
	void loadConfig();
};
