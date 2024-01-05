#include <wx/wx.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "Element.h"
#include "ComponentSelection.h"
#include "MyFrame.h"
using namespace std;
vector<Component> allComponent;
vector<Net>allNet;

class App : public wxApp {
public:
	bool OnInit()override {
		MyFrame* window = new MyFrame("原理图编辑器", wxSize(1600, 900));
		window->Show();
		return true;
	}
};

wxIMPLEMENT_APP(App);//程序入口

