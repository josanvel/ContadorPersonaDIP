#pragma once

namespace ProyectoConteoPersonas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::ComboBox^  cBxFormato;
	private: System::Windows::Forms::GroupBox^  gBxRoiFace;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  lblMin;

	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  lblMax;

	private: System::Windows::Forms::GroupBox^  gBxROI;
	private: System::Windows::Forms::TextBox^  txtBxLargo;
	private: System::Windows::Forms::TextBox^  txtBxAncho;
	private: System::Windows::Forms::TextBox^  txtBxPuntoY;
	private: System::Windows::Forms::TextBox^  txtBxPuntoX;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  lblPuntoY;
	private: System::Windows::Forms::Label^  lblPuntoX;

	private: System::Windows::Forms::Button^  button1;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->gBxFormato = (gcnew System::Windows::Forms::GroupBox());
			this->cBxFormato = (gcnew System::Windows::Forms::ComboBox());
			this->gBxRoiFace = (gcnew System::Windows::Forms::GroupBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->lblMin = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->lblMax = (gcnew System::Windows::Forms::Label());
			this->gBxROI = (gcnew System::Windows::Forms::GroupBox());
			this->txtBxLargo = (gcnew System::Windows::Forms::TextBox());
			this->txtBxAncho = (gcnew System::Windows::Forms::TextBox());
			this->txtBxPuntoY = (gcnew System::Windows::Forms::TextBox());
			this->txtBxPuntoX = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->lblPuntoY = (gcnew System::Windows::Forms::Label());
			this->lblPuntoX = (gcnew System::Windows::Forms::Label());
			this->tbClVentana->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->gBxFormato->SuspendLayout();
			this->gBxRoiFace->SuspendLayout();
			this->gBxROI->SuspendLayout();
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
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(220, 319);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(184, 34);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Guardar Configuracion";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// gBxFormato
			// 
			this->gBxFormato->Controls->Add(this->cBxFormato);
			this->gBxFormato->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gBxFormato->Location = System::Drawing::Point(331, 179);
			this->gBxFormato->Name = L"gBxFormato";
			this->gBxFormato->Size = System::Drawing::Size(278, 100);
			this->gBxFormato->TabIndex = 4;
			this->gBxFormato->TabStop = false;
			this->gBxFormato->Text = L"Formato Imagenes";
			// 
			// cBxFormato
			// 
			this->cBxFormato->AccessibleName = L"";
			this->cBxFormato->FormattingEnabled = true;
			this->cBxFormato->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"JPEG; PNG" });
			this->cBxFormato->Location = System::Drawing::Point(17, 60);
			this->cBxFormato->Name = L"cBxFormato";
			this->cBxFormato->Size = System::Drawing::Size(211, 26);
			this->cBxFormato->TabIndex = 3;
			// 
			// gBxRoiFace
			// 
			this->gBxRoiFace->Controls->Add(this->textBox2);
			this->gBxRoiFace->Controls->Add(this->lblMin);
			this->gBxRoiFace->Controls->Add(this->textBox1);
			this->gBxRoiFace->Controls->Add(this->lblMax);
			this->gBxRoiFace->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gBxRoiFace->Location = System::Drawing::Point(20, 176);
			this->gBxRoiFace->Name = L"gBxRoiFace";
			this->gBxRoiFace->Size = System::Drawing::Size(271, 103);
			this->gBxRoiFace->TabIndex = 2;
			this->gBxRoiFace->TabStop = false;
			this->gBxRoiFace->Text = L"ROI Face";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(102, 68);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(137, 24);
			this->textBox2->TabIndex = 10;
			// 
			// lblMin
			// 
			this->lblMin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMin->Location = System::Drawing::Point(25, 70);
			this->lblMin->Name = L"lblMin";
			this->lblMin->Size = System::Drawing::Size(71, 18);
			this->lblMin->TabIndex = 9;
			this->lblMin->Text = L"Minimo";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(102, 27);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(137, 24);
			this->textBox1->TabIndex = 8;
			// 
			// lblMax
			// 
			this->lblMax->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMax->Location = System::Drawing::Point(25, 29);
			this->lblMax->Name = L"lblMax";
			this->lblMax->Size = System::Drawing::Size(71, 18);
			this->lblMax->TabIndex = 3;
			this->lblMax->Text = L"Maximo";
			// 
			// gBxROI
			// 
			this->gBxROI->Controls->Add(this->txtBxLargo);
			this->gBxROI->Controls->Add(this->txtBxAncho);
			this->gBxROI->Controls->Add(this->txtBxPuntoY);
			this->gBxROI->Controls->Add(this->txtBxPuntoX);
			this->gBxROI->Controls->Add(this->label2);
			this->gBxROI->Controls->Add(this->label1);
			this->gBxROI->Controls->Add(this->lblPuntoY);
			this->gBxROI->Controls->Add(this->lblPuntoX);
			this->gBxROI->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->gBxROI->Location = System::Drawing::Point(20, 25);
			this->gBxROI->Name = L"gBxROI";
			this->gBxROI->Size = System::Drawing::Size(589, 107);
			this->gBxROI->TabIndex = 1;
			this->gBxROI->TabStop = false;
			this->gBxROI->Text = L"Definir Region de Interes ROI";
			// 
			// txtBxLargo
			// 
			this->txtBxLargo->Location = System::Drawing::Point(393, 68);
			this->txtBxLargo->Name = L"txtBxLargo";
			this->txtBxLargo->Size = System::Drawing::Size(137, 24);
			this->txtBxLargo->TabIndex = 7;
			// 
			// txtBxAncho
			// 
			this->txtBxAncho->Location = System::Drawing::Point(393, 33);
			this->txtBxAncho->Name = L"txtBxAncho";
			this->txtBxAncho->Size = System::Drawing::Size(137, 24);
			this->txtBxAncho->TabIndex = 6;
			// 
			// txtBxPuntoY
			// 
			this->txtBxPuntoY->Location = System::Drawing::Point(102, 68);
			this->txtBxPuntoY->Name = L"txtBxPuntoY";
			this->txtBxPuntoY->Size = System::Drawing::Size(137, 24);
			this->txtBxPuntoY->TabIndex = 5;
			// 
			// txtBxPuntoX
			// 
			this->txtBxPuntoX->Location = System::Drawing::Point(102, 32);
			this->txtBxPuntoX->Name = L"txtBxPuntoX";
			this->txtBxPuntoX->Size = System::Drawing::Size(137, 24);
			this->txtBxPuntoX->TabIndex = 4;
			this->txtBxPuntoX->TextChanged += gcnew System::EventHandler(this, &Ventana::txtBxPuntoX_TextChanged);
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(316, 70);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 18);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Altura";
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(316, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Ancho";
			// 
			// lblPuntoY
			// 
			this->lblPuntoY->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPuntoY->Location = System::Drawing::Point(25, 70);
			this->lblPuntoY->Name = L"lblPuntoY";
			this->lblPuntoY->Size = System::Drawing::Size(71, 18);
			this->lblPuntoY->TabIndex = 1;
			this->lblPuntoY->Text = L"Punto Y";
			// 
			// lblPuntoX
			// 
			this->lblPuntoX->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPuntoX->Location = System::Drawing::Point(25, 34);
			this->lblPuntoX->Name = L"lblPuntoX";
			this->lblPuntoX->Size = System::Drawing::Size(71, 18);
			this->lblPuntoX->TabIndex = 0;
			this->lblPuntoX->Text = L"Punto X";
			// 
			// Ventana
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(674, 424);
			this->Controls->Add(this->tbClVentana);
			this->Name = L"Ventana";
			this->Text = L"Ventana";
			this->Load += gcnew System::EventHandler(this, &Ventana::Ventana_Load);
			this->tbClVentana->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->gBxFormato->ResumeLayout(false);
			this->gBxRoiFace->ResumeLayout(false);
			this->gBxRoiFace->PerformLayout();
			this->gBxROI->ResumeLayout(false);
			this->gBxROI->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Ventana_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void txtBxPuntoX_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void tabPage1_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
