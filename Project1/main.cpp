#include "main.h"
#include "FileHandler.h"
#include "KeyGenerator.h"
#include "AES.h"
#include <iostream>
#include <sstream>
#include <iomanip>



using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project1::main^ form = gcnew Project1::main();
	Application::Run(form);
}

