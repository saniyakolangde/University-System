#include "MyForm.h"
#include <array>
using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
Void Main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Assignment1::MyForm form;
	Application::Run(% form);
}

