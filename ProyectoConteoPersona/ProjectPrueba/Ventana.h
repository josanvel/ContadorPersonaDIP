#pragma once
#include <opencv2/imgproc/imgproc.hpp>  // Gaussian Blur
#include <opencv2/core/core.hpp>        // Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/highgui/highgui.hpp>
#include <opencv/cv.hpp>
#include <opencv/cxcore.hpp>
#include <opencv2/core/mat.hpp>
#include <iostream>
#include <msclr\marshal_cppstd.h>



namespace ProyectoConteoPersonas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	using namespace msclr::interop;


	/// <summary>
	/// Summary for Ventana
	/// </summary>
	public ref class Ventana : public System::Windows::Forms::Form
	{
	public:
		Ventana(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Ventana()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TabControl^  tbClVentana;
	protected:

	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::GroupBox^  gBxFormato;

	private: System::Windows::Forms::GroupBox^  gBxRoiFace;






	private: System::Windows::Forms::GroupBox^  gBxROI;









	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textVideoName;





	private: System::Windows::Forms::NumericUpDown^  numericLimitY2;

	private: System::Windows::Forms::NumericUpDown^  numericLimitY1;
	private: System::Windows::Forms::NumericUpDown^  numericLimitX2;


	private: System::Windows::Forms::NumericUpDown^  numericLimitX1;


	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::NumericUpDown^  numericRoiY2;

	private: System::Windows::Forms::NumericUpDown^  numericRoiY1;
	private: System::Windows::Forms::NumericUpDown^  numericRoiX2;



	private: System::Windows::Forms::NumericUpDown^  numericRoiX1;

	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;




	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tbClVentana = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->gBxFormato = (gcnew System::Windows::Forms::GroupBox());
			this->textVideoName = (gcnew System::Windows::Forms::TextBox());
			this->gBxRoiFace = (gcnew System::Windows::Forms::GroupBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->numericLimitY2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericLimitY1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericLimitX2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericLimitX1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->gBxROI = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->numericRoiY2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericRoiY1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericRoiX2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericRoiX1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->tbClVentana->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->gBxFormato->SuspendLayout();
			this->gBxRoiFace->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericLimitY2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericLimitY1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericLimitX2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericLimitX1))->BeginInit();
			this->gBxROI->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericRoiY2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericRoiY1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericRoiX2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericRoiX1))->BeginInit();
			this->SuspendLayout();
			// 
			// tbClVentana
			// 
			this->tbClVentana->Controls->Add(this->tabPage1);
			this->tbClVentana->Location = System::Drawing::Point(12, 12);
			this->tbClVentana->Name = L"tbClVentana";
			this->tbClVentana->SelectedIndex = 0;
			this->tbClVentana->Size = System::Drawing::Size(652, 400);
			this->tbClVentana->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->gBxFormato);
			this->tabPage1->Controls->Add(this->gBxRoiFace);
			this->tabPage1->Controls->Add(this->gBxROI);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(644, 374);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"People Counting Configuracion";
			this->tabPage1->UseVisualStyleBackColor = true;
			this->tabPage1->Click += gcnew System::EventHandler(this, &Ventana::tabPage1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(103, 318);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(184, 34);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Vista Previa";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Ventana::button2_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(350, 318);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(184, 34);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Guardar Configuracion";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// gBxFormato
			// 
			this->gBxFormato->Controls->Add(this->textVideoName);
			this->gBxFormato->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gBxFormato->Location = System::Drawing::Point(395, 25);
			this->gBxFormato->Name = L"gBxFormato";
			this->gBxFormato->Size = System::Drawing::Size(243, 107);
			this->gBxFormato->TabIndex = 4;
			this->gBxFormato->TabStop = false;
			this->gBxFormato->Text = L"Señal de Video";
			// 
			// textVideoName
			// 
			this->textVideoName->AccessibleDescription = L"Ingrese la ruta de su senal de video";
			this->textVideoName->Location = System::Drawing::Point(19, 42);
			this->textVideoName->Name = L"textVideoName";
			this->textVideoName->Size = System::Drawing::Size(204, 24);
			this->textVideoName->TabIndex = 4;
			this->textVideoName->TextChanged += gcnew System::EventHandler(this, &Ventana::textBox3_TextChanged);
			// 
			// gBxRoiFace
			// 
			this->gBxRoiFace->Controls->Add(this->label3);
			this->gBxRoiFace->Controls->Add(this->label8);
			this->gBxRoiFace->Controls->Add(this->label7);
			this->gBxRoiFace->Controls->Add(this->numericLimitY2);
			this->gBxRoiFace->Controls->Add(this->numericLimitY1);
			this->gBxRoiFace->Controls->Add(this->numericLimitX2);
			this->gBxRoiFace->Controls->Add(this->numericLimitX1);
			this->gBxRoiFace->Controls->Add(this->label4);
			this->gBxRoiFace->Controls->Add(this->label5);
			this->gBxRoiFace->Controls->Add(this->label6);
			this->gBxRoiFace->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gBxRoiFace->Location = System::Drawing::Point(128, 153);
			this->gBxRoiFace->Name = L"gBxRoiFace";
			this->gBxRoiFace->Size = System::Drawing::Size(369, 103);
			this->gBxRoiFace->TabIndex = 2;
			this->gBxRoiFace->TabStop = false;
			this->gBxRoiFace->Text = L"Definir Limitador";
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(235, 64);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(30, 18);
			this->label3->TabIndex = 22;
			this->label3->Text = L"Y2";
			// 
			// label8
			// 
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(235, 33);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(33, 18);
			this->label8->TabIndex = 21;
			this->label8->Text = L"Y1";
			// 
			// label7
			// 
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(105, 68);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(33, 18);
			this->label7->TabIndex = 20;
			this->label7->Text = L"X2";
			// 
			// numericLimitY2
			// 
			this->numericLimitY2->Location = System::Drawing::Point(271, 64);
			this->numericLimitY2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericLimitY2->Name = L"numericLimitY2";
			this->numericLimitY2->Size = System::Drawing::Size(85, 24);
			this->numericLimitY2->TabIndex = 19;
			// 
			// numericLimitY1
			// 
			this->numericLimitY1->Location = System::Drawing::Point(271, 29);
			this->numericLimitY1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericLimitY1->Name = L"numericLimitY1";
			this->numericLimitY1->Size = System::Drawing::Size(85, 24);
			this->numericLimitY1->TabIndex = 18;
			// 
			// numericLimitX2
			// 
			this->numericLimitX2->Location = System::Drawing::Point(144, 66);
			this->numericLimitX2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericLimitX2->Name = L"numericLimitX2";
			this->numericLimitX2->Size = System::Drawing::Size(87, 24);
			this->numericLimitX2->TabIndex = 17;
			// 
			// numericLimitX1
			// 
			this->numericLimitX1->Location = System::Drawing::Point(144, 29);
			this->numericLimitX1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericLimitX1->Name = L"numericLimitX1";
			this->numericLimitX1->Size = System::Drawing::Size(87, 24);
			this->numericLimitX1->TabIndex = 16;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(105, 33);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(33, 18);
			this->label4->TabIndex = 14;
			this->label4->Text = L"X1";
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(9, 68);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(94, 18);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Punto Final:";
			// 
			// label6
			// 
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(9, 32);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(107, 18);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Punto Inicial:";
			this->label6->Click += gcnew System::EventHandler(this, &Ventana::label6_Click);
			// 
			// gBxROI
			// 
			this->gBxROI->Controls->Add(this->label1);
			this->gBxROI->Controls->Add(this->label2);
			this->gBxROI->Controls->Add(this->label9);
			this->gBxROI->Controls->Add(this->numericRoiY2);
			this->gBxROI->Controls->Add(this->numericRoiY1);
			this->gBxROI->Controls->Add(this->numericRoiX2);
			this->gBxROI->Controls->Add(this->numericRoiX1);
			this->gBxROI->Controls->Add(this->label10);
			this->gBxROI->Controls->Add(this->label11);
			this->gBxROI->Controls->Add(this->label12);
			this->gBxROI->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gBxROI->Location = System::Drawing::Point(20, 25);
			this->gBxROI->Name = L"gBxROI";
			this->gBxROI->Size = System::Drawing::Size(369, 107);
			this->gBxROI->TabIndex = 1;
			this->gBxROI->TabStop = false;
			this->gBxROI->Text = L"Definir Region de Interes ROI";
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(235, 64);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(30, 18);
			this->label1->TabIndex = 32;
			this->label1->Text = L"Y2";
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(235, 33);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 18);
			this->label2->TabIndex = 31;
			this->label2->Text = L"Y1";
			// 
			// label9
			// 
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(105, 68);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(33, 18);
			this->label9->TabIndex = 30;
			this->label9->Text = L"X2";
			// 
			// numericRoiY2
			// 
			this->numericRoiY2->Location = System::Drawing::Point(271, 64);
			this->numericRoiY2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericRoiY2->Name = L"numericRoiY2";
			this->numericRoiY2->Size = System::Drawing::Size(85, 24);
			this->numericRoiY2->TabIndex = 29;
			// 
			// numericRoiY1
			// 
			this->numericRoiY1->Location = System::Drawing::Point(271, 29);
			this->numericRoiY1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericRoiY1->Name = L"numericRoiY1";
			this->numericRoiY1->Size = System::Drawing::Size(85, 24);
			this->numericRoiY1->TabIndex = 28;
			// 
			// numericRoiX2
			// 
			this->numericRoiX2->Location = System::Drawing::Point(144, 66);
			this->numericRoiX2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericRoiX2->Name = L"numericRoiX2";
			this->numericRoiX2->Size = System::Drawing::Size(87, 24);
			this->numericRoiX2->TabIndex = 27;
			// 
			// numericRoiX1
			// 
			this->numericRoiX1->Location = System::Drawing::Point(144, 29);
			this->numericRoiX1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10000, 0, 0, 0 });
			this->numericRoiX1->Name = L"numericRoiX1";
			this->numericRoiX1->Size = System::Drawing::Size(87, 24);
			this->numericRoiX1->TabIndex = 26;
			// 
			// label10
			// 
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(105, 33);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(33, 18);
			this->label10->TabIndex = 25;
			this->label10->Text = L"X1";
			// 
			// label11
			// 
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(9, 68);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(94, 18);
			this->label11->TabIndex = 24;
			this->label11->Text = L"Punto Final:";
			// 
			// label12
			// 
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(9, 32);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(107, 18);
			this->label12->TabIndex = 23;
			this->label12->Text = L"Punto Inicial:";
			// 
			// Ventana
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(677, 424);
			this->Controls->Add(this->tbClVentana);
			this->Name = L"Ventana";
			this->Text = L"Ventana";
			this->Load += gcnew System::EventHandler(this, &Ventana::Ventana_Load);
			this->tbClVentana->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->gBxFormato->ResumeLayout(false);
			this->gBxFormato->PerformLayout();
			this->gBxRoiFace->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericLimitY2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericLimitY1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericLimitX2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericLimitX1))->EndInit();
			this->gBxROI->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericRoiY2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericRoiY1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericRoiX2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericRoiX1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Ventana_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void txtBxPuntoX_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	cv::VideoCapture vcap;
	cv::Mat frame,copy;
	int maxX, maxY;
	int roiX1, roiY1, roiX2, roiY2;
	int limitX1, limitY1, limitX2, limitY2;
	using namespace Runtime::InteropServices;
	const char* chars =(const char*)(Marshal::StringToHGlobalAnsi(textVideoName->Text)).ToPointer();
	
	string videoName = chars;
	if (videoName == "")
		MessageBox::Show("Ingrese URL o nombre del video","Atención", MessageBoxButtons::OKCancel,MessageBoxIcon::Asterisk);
	else if(!vcap.open(videoName)) {
		std::cout << "Error opening video stream or file" << std::endl;
		MessageBox::Show("No se pudo abrir la señal de video", "Atención", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
	}
	else {
		while (1){
			if (!vcap.open(videoName)) {
				std::cout << "Error opening video stream or file" << std::endl;
			}

			vcap.set(CV_CAP_PROP_FPS, 10);
			maxX = vcap.get(cv::CAP_PROP_FRAME_WIDTH);
			maxY = vcap.get(cv::CAP_PROP_FRAME_HEIGHT);
			numericRoiX1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { maxX, 0, 0, 0 });
			numericRoiX2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { maxX, 0, 0, 0 });
			numericRoiY1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { maxY, 0, 0, 0 });
			numericRoiY2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { maxY, 0, 0, 0 });

			numericLimitX1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { maxX, 0, 0, 0 });
			numericLimitX2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { maxX, 0, 0, 0 });
			numericLimitY1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { maxY, 0, 0, 0 });
			numericLimitY2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { maxY, 0, 0, 0 });

			while (vcap.get(CV_CAP_PROP_POS_FRAMES)<vcap.get(CV_CAP_PROP_FRAME_COUNT) - 1){

				if ((int)numericRoiX1->Value <= maxX) roiX1 = (int)numericRoiX1->Value;
				if ((int)numericRoiX2->Value <= maxX) roiX2 = (int)numericRoiX2->Value;
				if ((int)numericRoiY1->Value <= maxY) roiY1 = (int)numericRoiY1->Value;
				if ((int)numericRoiY2->Value <= maxY) roiY2 = (int)numericRoiY2->Value;

				if ((int)numericLimitX1->Value <= maxX) limitX1 = (int)numericLimitX1->Value;
				if ((int)numericLimitX2->Value <= maxX) limitX2 = (int)numericLimitX2->Value;
				if ((int)numericLimitY1->Value <= maxY) limitY1 = (int)numericLimitY1->Value;
				if ((int)numericLimitY2->Value <= maxY) limitY2 = (int)numericLimitY2->Value;

				vcap.read(frame);

				copy = frame.clone();
				rectangle(copy, cv::Point(roiX1, roiY1), cv::Point(roiX2, roiY2), cv::Scalar(0, 0, 255), 2, 8, 0);
				cv::line(copy, cv::Point(limitX1, limitY1), cv::Point(limitX2, limitY2), cv::Scalar(0, 255, 0));

				imshow("SeñalesVideo", copy);

				if (cvWaitKey(1) >= 0) break;


			}
			vcap.release();
		}
	} 
	

}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label6_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
