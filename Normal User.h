#pragma once


namespace GG {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for NormalUser
	/// </summary>
	public ref class NormalUser : public System::Windows::Forms::Form
	{
	public:
		NormalUser(void)
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
		~NormalUser()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Back;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DateTimePicker^  dateTimePicker1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button2;
	protected:

	protected:

	protected:

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
			this->Back = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Back
			// 
			this->Back->Location = System::Drawing::Point(12, 226);
			this->Back->Name = L"Back";
			this->Back->Size = System::Drawing::Size(75, 23);
			this->Back->TabIndex = 0;
			this->Back->Text = L"Back";
			this->Back->UseVisualStyleBackColor = true;
			this->Back->Click += gcnew System::EventHandler(this, &NormalUser::Back_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(119, 66);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &NormalUser::button1_Click);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(83, 2);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(200, 20);
			this->dateTimePicker1->TabIndex = 2;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 66);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(101, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &NormalUser::textBox1_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(79, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"MM/DD/YYYY";
			this->label1->Click += gcnew System::EventHandler(this, &NormalUser::label1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(197, 66);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// NormalUser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->Back);
			this->Name = L"NormalUser";
			this->Text = L"Deposit";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Back_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Hide();
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

}
};
}
