#include "people_counting.h"

namespace FAV1
{
	IplImage* img_input1 = 0;
	IplImage* img_input2 = 0;
	int roi_x0 = 0;
	int roi_y0 = 0;
	int roi_x1 = 0;
	int roi_y1 = 0;
	int numOfRec = 0;
	int startDraw = 0;
	bool roi_defined = false;
	bool use_roi = true;
	void PeopleCouting_on_mouse(int evt, int x, int y, int flag, void* param)
	{
		if (!use_roi)
			return;

		if (evt == CV_EVENT_LBUTTONDOWN)
		{
			if (!startDraw)
			{
				roi_x0 = x;
				roi_y0 = y;
				startDraw = 1;
			}
			else
			{
				roi_x1 = x;
				roi_y1 = y;
				startDraw = 0;
				roi_defined = true;
			}
		}

		if (evt == CV_EVENT_MOUSEMOVE && startDraw)
		{
			//redraw ROI selection
			img_input2 = cvCloneImage(img_input1);
			cvLine(img_input2, cvPoint(roi_x0, roi_y0), cvPoint(x, y), CV_RGB(255, 0, 255));
			cvShowImage("PersonCouting", img_input2);
			cvReleaseImage(&img_input2);
		}
	}
}

PeopleCouting::PeopleCouting() : firstTime(true), showOutput(true), key(0), countAB(0), countBA(0), showAB(0)
{
	std::cout << "PeopleCouting()" << std::endl;
}

PeopleCouting::~PeopleCouting()
{
	std::cout << "~PeopleCouting()" << std::endl;
}

void PeopleCouting::setInput(const cv::Mat &i)
{
	//i.copyTo(img_input);
	img_input = i;
}

void PeopleCouting::setTracks(const cvb::CvTracks &t)
{
	tracks = t;
}

PeoplePosition PeopleCouting::getPeoplePosition(const CvPoint2D64f centroid)
{
	PeoplePosition PeoplePosition = PP_NONE;

	if (laneOrientation == LO_HORIZONTAL)
	{
		if (centroid.x < FAV1::roi_x0)
		{
			cv::putText(img_input, "STATE: A", cv::Point(10, img_h / 2), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255));
			PeoplePosition = PP_A;
		}

		if (centroid.x > FAV1::roi_x0)
		{
			cv::putText(img_input, "STATE: B", cv::Point(10, img_h / 2), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255));
			PeoplePosition = PP_B;
		}
	}

	if (laneOrientation == LO_VERTICAL)
	{
		if (centroid.y > FAV1::roi_y0)
		{
			cv::putText(img_input, "STATE: A", cv::Point(10, img_h / 2), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255));
			PeoplePosition = PP_A;
		}

		if (centroid.y < FAV1::roi_y0)
		{
			cv::putText(img_input, "STATE: B", cv::Point(10, img_h / 2), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255));
			PeoplePosition = PP_B;
		}
	}

	return PeoplePosition;
}

void PeopleCouting::process()
{
	if (img_input.empty())
		return;

	img_w = img_input.size().width;
	img_h = img_input.size().height;

	loadConfig();

	//--------------------------------------------------------------------------

	if (FAV1::use_roi == true && FAV1::roi_defined == false && firstTime == true)
	{
		do
		{
			cv::putText(img_input, "Please, set the counting line", cv::Point(10, 15), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(0, 0, 255));
			cv::imshow("PeopleCouting", img_input);
			FAV1::img_input1 = new IplImage(img_input);
			cvSetMouseCallback("PeopleCouting", FAV1::PeopleCouting_on_mouse, NULL);
			key = cvWaitKey(0);
			delete FAV1::img_input1;

			if (FAV1::roi_defined)
			{
				std::cout << "Counting line defined (" << FAV1::roi_x0 << "," << FAV1::roi_y0 << "," << FAV1::roi_x1 << "," << FAV1::roi_y1 << ")" << std::endl;
				break;
			}
			else
				std::cout << "Counting line undefined!" << std::endl;
		} while (1);
	}

	if (FAV1::use_roi == true && FAV1::roi_defined == true)
		cv::line(img_input, cv::Point(FAV1::roi_x0, FAV1::roi_y0), cv::Point(FAV1::roi_x1, FAV1::roi_y1), cv::Scalar(0, 255, 0));

	bool ROI_OK = false;

	if (FAV1::use_roi == true && FAV1::roi_defined == true)
		ROI_OK = true;

	if (ROI_OK)
	{
		laneOrientation = LO_NONE;

		if (abs(FAV1::roi_x0 - FAV1::roi_x1) < abs(FAV1::roi_y0 - FAV1::roi_y1))
		{
			if (!firstTime)
				cv::putText(img_input, "HORIZONTAL", cv::Point(10, 15), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255));
			laneOrientation = LO_HORIZONTAL;

			cv::putText(img_input, "(A)", cv::Point(FAV1::roi_x0 - 32, FAV1::roi_y0), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255));
			cv::putText(img_input, "(B)", cv::Point(FAV1::roi_x0 + 12, FAV1::roi_y0), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255));
		}

		if (abs(FAV1::roi_x0 - FAV1::roi_x1) > abs(FAV1::roi_y0 - FAV1::roi_y1))
		{
			if (!firstTime)
				cv::putText(img_input, "VERTICAL", cv::Point(10, 15), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255));
			laneOrientation = LO_VERTICAL;

			cv::putText(img_input, "(A)", cv::Point(FAV1::roi_x0, FAV1::roi_y0 + 22), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255));
			cv::putText(img_input, "(B)", cv::Point(FAV1::roi_x0, FAV1::roi_y0 - 12), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255));
		}
	}

	//--------------------------------------------------------------------------

	for (std::map<cvb::CvID, cvb::CvTrack*>::iterator it = tracks.begin(); it != tracks.end(); it++)
	{
		//std::cout << (*it).first << " => " << (*it).second << std::endl;
		cvb::CvID id = (*it).first;
		cvb::CvTrack* track = (*it).second;

		CvPoint2D64f centroid = track->centroid;
		/*
		std::cout << "---------------------------------------------------------------" << std::endl;
		std::cout << "0)id:" << id << " (" << centroid.x << "," << centroid.y << ")" << std::endl;
		std::cout << "track->active:" << track->active << std::endl;
		std::cout << "track->inactive:" << track->inactive << std::endl;
		std::cout << "track->lifetime:" << track->lifetime << std::endl;
		*/

		//----------------------------------------------------------------------------

		if (track->inactive == 0)
		{
			if (positions.count(id) > 0)
			{
				std::map<cvb::CvID, PeoplePosition>::iterator it2 = positions.find(id);
				PeoplePosition old_position = it2->second;

				PeoplePosition current_position = getPeoplePosition(centroid);

				if (current_position != old_position)
				{
					if (old_position == PP_A && current_position == PP_B)
						countAB++;

					if (old_position == PP_B && current_position == PP_A)
						countBA++;

					positions.erase(positions.find(id));
				}
			}
			else
			{
				PeoplePosition peoplePosition = getPeoplePosition(centroid);

				if (peoplePosition != PP_NONE)
					positions.insert(std::pair<cvb::CvID, PeoplePosition>(id, peoplePosition));
			}
		}
		else
		{
			if (positions.count(id) > 0)
				positions.erase(positions.find(id));
		}

		//----------------------------------------------------------------------------

		if (points.count(id) > 0)
		{
			std::map<cvb::CvID, std::vector<CvPoint2D64f>>::iterator it2 = points.find(id);
			std::vector<CvPoint2D64f> centroids = it2->second;

			std::vector<CvPoint2D64f> centroids2;
			if (track->inactive == 0 && centroids.size() < 30)
			{
				centroids2.push_back(centroid);

				for (std::vector<CvPoint2D64f>::iterator it3 = centroids.begin(); it3 != centroids.end(); it3++)
				{
					centroids2.push_back(*it3);
				}

				for (std::vector<CvPoint2D64f>::iterator it3 = centroids2.begin(); it3 != centroids2.end(); it3++)
				{
					cv::circle(img_input, cv::Point((*it3).x, (*it3).y), 3, cv::Scalar(255, 255, 255), -1);
				}

				points.erase(it2);
				points.insert(std::pair<cvb::CvID, std::vector<CvPoint2D64f>>(id, centroids2));
			}
			else
			{
				points.erase(it2);
			}
		}
		else
		{
			if (track->inactive == 0)
			{
				std::vector<CvPoint2D64f> centroids;
				centroids.push_back(centroid);
				points.insert(std::pair<cvb::CvID, std::vector<CvPoint2D64f>>(id, centroids));
			}
		}

		//cv::waitKey(0);
	}

	//--------------------------------------------------------------------------

	std::string countABstr = "A->B: " + std::to_string(countAB);
	std::string countBAstr = "B->A: " + std::to_string(countBA);

	if (showAB == 0)
	{
		cv::putText(img_input, countABstr, cv::Point(10, img_h - 20), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255));
		cv::putText(img_input, countBAstr, cv::Point(10, img_h - 8), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255));
	}

	if (showAB == 1)
		cv::putText(img_input, countABstr, cv::Point(10, img_h - 8), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255));

	if (showAB == 2)
		cv::putText(img_input, countBAstr, cv::Point(10, img_h - 8), cv::FONT_HERSHEY_PLAIN, 1, cv::Scalar(255, 255, 255));

	if (showOutput)
		cv::imshow("PeopleCouting", img_input);



	firstTime = false;
}

void PeopleCouting::saveConfig()
{
	CvFileStorage* fs = cvOpenFileStorage("config/Calibracion.xml", 0, CV_STORAGE_WRITE);

	cvWriteInt(fs, "calibrado", showOutput);
	cvWriteInt(fs, "showAB", showAB);

	cvWriteInt(fs, "calibrado", FAV1::use_roi);
	cvWriteInt(fs, "calibrado", FAV1::roi_defined);
	cvWriteInt(fs, "limitador_x0", FAV1::roi_x0);
	cvWriteInt(fs, "limitador_y0", FAV1::roi_y0);
	cvWriteInt(fs, "limitador_x1", FAV1::roi_x1);
	cvWriteInt(fs, "limitador_y1", FAV1::roi_y1);

	cvReleaseFileStorage(&fs);
}

void PeopleCouting::loadConfig()
{
	CvFileStorage* fs = cvOpenFileStorage("config/Calibracion.xml", 0, CV_STORAGE_READ);
	int x0, y0;
	showOutput = cvReadIntByName(fs, 0, "calibrado", true);
	showAB = cvReadIntByName(fs, 0, "showAB", 1);
	x0 = cvReadIntByName(fs, 0, "roi_x0", true);
	y0 = cvReadIntByName(fs, 0, "roi_y0", true);
	FAV1::use_roi = cvReadIntByName(fs, 0, "calibrado", true);
	FAV1::roi_defined = cvReadIntByName(fs, 0, "calibrado", false);
	FAV1::roi_x0 = cvReadIntByName(fs, 0, "limitador_x0", 0) - x0;
	FAV1::roi_y0 = cvReadIntByName(fs, 0, "limitador_y0", 0) - y0;
	FAV1::roi_x1 = cvReadIntByName(fs, 0, "limitador_x1", 0) - x0;
	FAV1::roi_y1 = cvReadIntByName(fs, 0, "limitador_y1", 0) - y0;

	cvReleaseFileStorage(&fs);
}
