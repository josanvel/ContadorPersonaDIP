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

//Libreria de Interface
#include "Ventana.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace cv;
using namespace std;

//Conexion con la bases de datos
MYSQL* conexionBase();

// Create a new Haar classifier
static CvHaarClassifierCascade* cascade = 0;
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

//Region de Interes
int punto_x = 400;
int punto_y = 40;
int ancho = 260;
int largo = 300;

// Function prototype for detecting and drawing an object from an image
void detect_and_draw(Mat img);
//Function  store face
void guardar_rostro(Mat face, int num);
// Create a string that contains the cascade name
const char* cascade_name = "haarcascade_frontalface_alt.xml";

// Create a folder containing the images of the face detection
const string folder_image = "face_img";
const string folder = "face";

int main(){
	VideoCapture vcap;
	Mat frame, copy;

	// Create a folder containing the images of the face detection
	_mkdir(folder_image.c_str());

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

	if (!face_cascade.load(cascade_name)){ printf("--(!)Error loading\n"); return -1; };
	//if (!eyes_cascade.load(eyes_cascade_name)){ printf("--(!)Error loading\n"); return -1; };

	if (!vcap.open("video1.avi")) {
		std::cout << "Error opening video stream or file" << std::endl;
		return -1;
	}

	vcap.set(CV_CAP_PROP_FPS, 10);
	vcap.set(CV_CAP_PROP_FRAME_WIDTH, 1080);
	vcap.set(CV_CAP_PROP_FRAME_HEIGHT, 620);
	for (;;) {

		

		if (!vcap.read(frame)) {
			std::cout << "No frame" << std::endl;
			cvWaitKey();
			break;
		}
		resize(frame, frame, Size(1080, 620), 0, 0, INTER_CUBIC);
		copy = frame.clone();
		detect_and_draw(copy);
		cv::imshow("SeñalesVideo", copy);

		if (cvWaitKey(1) >= 0) break;

	}
	vcap.release();


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



// Funcion para detectar y dibujar ciertas caracteristicas dentro de una imagen
void detect_and_draw(Mat img){
std::vector<Rect> faces;
Mat frame_gray;
Mat roi = img(Rect(punto_x, punto_y, ancho, largo));
cvtColor(roi, frame_gray, CV_BGR2GRAY);
equalizeHist(frame_gray, frame_gray);

rectangle(img, Point(punto_x, punto_y), Point(punto_x + ancho, punto_y + largo), Scalar(0, 0, 255), 2, 8, 0);

//-- Detect faces
face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(10, 10));
for (size_t i = 0; i < faces.size(); i++)
{
//Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
//ellipse(roi, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(0, 0, 255), 4, 8, 0);
rectangle(roi, Point(faces[i].x - 10, faces[i].y - 10), Point(faces[i].width + faces[i].x + 10, faces[i].height + faces[i].y + 10),
Scalar(0, 0, 255), 2, 8, 0);

rectangle(img, Point(punto_x + faces[i].x, punto_y + faces[i].y),
Point(faces[i].width + faces[i].x + punto_x,
faces[i].height + faces[i].y + punto_y),
Scalar(0, 0, 255), 2, 8, 0);
guardar_rostro(roi(Rect(faces[i].x, faces[i].y, faces[i].width, faces[i].height)), i);
//Mat faceROI = frame_gray(faces[i]);
//std::vector<Rect> eyes;

////-- In each face, detect eyes
//eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(15, 15));

//for (size_t j = 0; j < eyes.size(); j++)
//{
//Point center(faces[i].x + eyes[j].x + eyes[j].width*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5);
//int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
//circle(roi, center, radius, Scalar(255, 0, 0), 4, 8, 0);
//}
}

cv::imshow("SeñalesVideo", img);
cv::imshow("Region de interes", roi);
}

//Function  store face
void guardar_rostro(Mat face, int num){
time_t     now = time(0);
struct tm  tstruct;
char       buf[80];
localtime_s(&tstruct, &now);

char dia[50];
char hora[50];
string namefile;
string name_folder;
strftime(dia, sizeof(dia), "%Y%m%d", &tstruct);
strftime(hora, sizeof(hora), "%H-%M-%S", &tstruct);
vector<int> compression_params;
compression_params.push_back(IMWRITE_PNG_COMPRESSION);
compression_params.push_back(9);
namefile = "/" + string(hora) + ".png";

name_folder = folder + "_" + string(dia);

string guardar = folder_image + "/" + name_folder;
_mkdir(guardar.c_str());

try {
imwrite(namefile, face, compression_params);
imwrite(guardar + namefile, face, compression_params);
}
catch (cv::Exception& ex) {
fprintf(stderr, "Exception converting image to PNG format: %s\n", ex.what());

}

//imwrite("/rostros/" + String(dia) + "-" + String(hora) + ".jpg", face);
}
