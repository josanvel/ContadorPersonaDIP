#include <opencv2\opencv.hpp>
#include <opencv\cxcore.h>
#include "opencv\cv.h"
#include "opencv\highgui.h"

#include <iostream>
#include <string>
#include <time.h>
#include <sstream>
#include <direct.h>
#include <winsock.h>
#include <stdio.h>
#include <cstdio>
#include <mysql.h>
//librerias para hacer tracking
#include "cvBlob\cvblob.h"
#include "package_tracking\BlobTracking.h"
#include "people_counter\people_counting.h"
#include "IBGS.h"
#include "PBAS\PixelBasedAdaptiveSegmenter.h"

//Libreria de Interface
#include "Ventana.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace cv;
using namespace std;
using namespace cvb;

//our sensitivity value to be used in the absdiff() function
const static int SENSITIVITY_VALUE = 20;
//size of blur used to smooth the intensity image output from absdiff() function
const static int BLUR_SIZE = 10;

//Conexion con la bases de datos
MYSQL* conexionBase();

//Region de Interes
int roi_punto_x0 = 400;
int roi_punto_y0 = 40;
int roi_punto_x1 = 260;
int roi_punto_y1 = 300;
//Linea limitadora
int linea_punto_x0 = 400;
int linea_punto_y0 = 40;
int linea_punto_x1 = 260;
int linea_punto_y1 = 300;
//Nombre del video
string video;
//cargar configuracion
Boolean loadConfig();

int main(){
	VideoCapture vcap;
	Mat frame, copy, img_blob;
	//some boolean variables for added functionality
	bool objectDetected = false;
	//these two can be toggled by pressing 'd' or 't'
	bool debugMode = false;
	bool trackingEnabled = true;
	//pause and resume code
	bool pause = false;
	//set up the matrices that we will need
	//the two frames we will be comparing
	Mat frame1, frame2, roi1, roi2;
	//their grayscale images (needed for absdiff() function)
	Mat grayImage1, grayImage2;
	//resulting difference image
	Mat differenceImage;
	//thresholded difference image (for use in findContours() function)
	Mat thresholdImage;
	//video capture object.
	VideoCapture capture;
	//Blob Tracking
	BlobTracking* blobTracking;
	blobTracking = new BlobTracking;
	/* People Counting Algorithm */
	PeopleCouting* peoplecounting;
	peoplecounting = new PeopleCouting;
	/* Background Subtraction Algorithm */
	IBGS *bgs;
	bgs = new PixelBasedAdaptiveSegmenter;


	// Create a folder containing the images of the face detection
	//_mkdir(folder_image.c_str());

	//Variable de Bases de datos
	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

	//Conexion de Bases de datos
	conn = conexionBase();

	if (mysql_query(conn, "SELECT * FROM persons;")){
		fprintf(stderr, "%s\n", mysql_error(conn));
		return(1);
	}

	res = mysql_use_result(conn);
	while ((row = mysql_fetch_row(res)) != NULL)
		printf("%s %s %s %s\n", row[0], row[1], row[2], row[3]);

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//Nombre del proyecto
	ProyectoConteoPersonas::Ventana form;
	Application::Run(%form);
	

	mysql_free_result(res);
	mysql_close(conn);

	if (loadConfig()){
		while (1){

			//we can loop the video by re-opening the capture every time the video reaches its last frame

			capture.open(video);

			if (!capture.isOpened()){
				cout << "ERROR ACQUIRING VIDEO FEED\n";
				getchar();
				return -1;
			}
			//capture.set(CV_CAP_PROP_FPS, 10);
			//check if the video has reach its last frame.
			//we add '-1' because we are reading two frames from the video at a time.
			//if this is not included, we get a memory error!
			while (capture.get(CV_CAP_PROP_POS_FRAMES) < capture.get(CV_CAP_PROP_FRAME_COUNT) - 1){

				//read first frame
				capture.read(frame);
				cv::Mat img_input;
				img_input = frame(Rect(roi_punto_x0, roi_punto_y0, roi_punto_x1 - roi_punto_x0, roi_punto_y1 - roi_punto_y0));
				cv::imshow("Input", img_input);

				// bgs->process(...) internally process and show the foreground mask image
				cv::Mat img_mask;
				bgs->process(img_input, img_mask);

				if (!img_mask.empty())
				{
					// Perform blob tracking
					blobTracking->process(img_input, img_mask, img_blob);

					// Perform vehicle counting
					peoplecounting->setInput(img_blob);
					peoplecounting->setTracks(blobTracking->getTracks());
					peoplecounting->process();
				}

				switch (waitKey(10)){

				case 27: //'esc' key has been pressed, exit program.
					return 0;
				case 112: //'p' has been pressed. this will pause/resume the code.
					pause = !pause;
					if (pause == true){
						cout << "Code paused, press 'p' again to resume" << endl;
						while (pause == true){
							//stay in this loop until 
							switch (waitKey()){
								//a switch statement inside a switch statement? Mind blown.
							case 112:
								//change pause back to false
								pause = false;
								cout << "Code Resumed" << endl;
								break;
							}
						}
					}
				}
			}
			delete peoplecounting;
			delete blobTracking;
			delete bgs;

			cvDestroyAllWindows();
			//release the capture before re-opening and looping again.
			capture.release();
		}
	}
	getchar();
	return(0);
}

MYSQL* conexionBase(){
	MYSQL *conn;

	const char *server = "localhost";
	const char *user = "root";
	const char *password = "";
	const char *database = "db_prueba";
	const int port = 3306;

	conn = mysql_init(NULL);

	if (!mysql_real_connect(conn, server, user, password, database, port, NULL, 0)){
		fprintf(stderr, "%s\n", mysql_error(conn));
	}

	return(conn);
}

Boolean loadConfig()
{
	CvFileStorage* fs = cvOpenFileStorage("config/Calibracion.xml", 0, CV_STORAGE_READ);
	string videoName = cvReadStringByName(fs, 0, "ruta_video", 0);
	int condigurado = cvReadIntByName(fs, 0, "calibrado", 0);
	if (condigurado = 1){
		video = cvReadStringByName(fs, 0, "ruta_video", 0);
		roi_punto_x0 = cvReadIntByName(fs, 0, "roi_x0", 0);
		roi_punto_y0 = cvReadIntByName(fs, 0, "roi_y0", 0);
		roi_punto_x1 = cvReadIntByName(fs, 0, "roi_x1", 0);
		roi_punto_y1 = cvReadIntByName(fs, 0, "roi_y1", 0);

		linea_punto_x0 = cvReadIntByName(fs, 0, "limitador_x0", 0);
		linea_punto_y0 = cvReadIntByName(fs, 0, "limitador_y0", 0);
		linea_punto_x1 = cvReadIntByName(fs, 0, "limitador_x1", 0);
		linea_punto_y1 = cvReadIntByName(fs, 0, "limitador_y1", 0);
		cvReleaseFileStorage(&fs);
		return true;
		
	}
	else{
		cvReleaseFileStorage(&fs);
		return false;
	}
	

	
}
