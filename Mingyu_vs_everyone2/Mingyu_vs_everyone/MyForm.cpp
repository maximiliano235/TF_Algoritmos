#include "MyForm.h"

using namespace Mingyuvseveryone;

[STAThread]
void main() {

	Application::EnableVisualStyles();
	Application::Run(gcnew MyForm());
}