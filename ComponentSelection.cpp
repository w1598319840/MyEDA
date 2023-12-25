#include "ComponentSelection.h"
#include "MyFrame.h"
#include <wx/wx.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>


void Coon_01x04::addCoon_01x04(vector<Component>& allComponent, string filePath) {
	string str = "\\Coon_01x04.txt";
	filePath = filePath + str;
	Component::readFile(allComponent, 1, filePath);
}

void Resistance::addResistance(vector<Component>& allComponent, string filePath) {
	string str = "\\Resistance.txt";
	filePath = filePath + str;
	Component::readFile(allComponent, 1, filePath);
}

void Capacitor::addCapacitor(vector<Component>& allComponent, string filePath) {
	string str = "\\Capacitor.txt";
	filePath = filePath + str;
	Component::readFile(allComponent, 1, filePath);
}

ComponentSelection::ComponentSelection(const wxString& title, const wxSize& size, MyPanel* myPanel) : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, size) {
	this->myPanel = myPanel;
	char cwd[256];
	_getcwd(cwd, sizeof(cwd));
	filePath = cwd;
	string str = "\\ComponentLibrary";
	filePath = filePath + str;
	SetPosition(wxPoint(40, 40));
	wxPanel* panel = new wxPanel(this, wxID_ANY);
	wxTextCtrl* text1 = new wxTextCtrl(panel, wxID_ANY, "", wxDefaultPosition, wxDefaultSize);
	text1->SetPosition(wxPoint(10, 10));
	text1->SetSize(wxSize(500, 20));
	wxButton* Coon_01x04_Button = new wxButton(panel, wxID_ANY, "Coon_01x04", wxPoint(10, 50), wxSize(500, 20));
	wxButton* Resistance_Button = new wxButton(panel, wxID_ANY, "Resistance", wxPoint(10, 70), wxSize(500, 20));
	wxButton* Capacitor_Button = new wxButton(panel, wxID_ANY, "Capacitor", wxPoint(10, 90), wxSize(500, 20));

	Coon_01x04_Button->Bind(wxEVT_BUTTON, &ComponentSelection::coon_01x04Click, this);
	Resistance_Button->Bind(wxEVT_BUTTON, &ComponentSelection::resistanceClick, this);
	Capacitor_Button->Bind(wxEVT_BUTTON, &ComponentSelection::capacitorClick, this);

	Show();
}

void ComponentSelection::coon_01x04Click(wxCommandEvent& event) {
	Coon_01x04::addCoon_01x04(allComponent, filePath);
	myPanel->Refresh();
	Close();
	/// @warning 记得析构 
}

void ComponentSelection::resistanceClick(wxCommandEvent& event) {
	Resistance::addResistance(allComponent, filePath);
	myPanel->Refresh();
	Close();
}

void ComponentSelection::capacitorClick(wxCommandEvent& event) {
	Capacitor::addCapacitor(allComponent, filePath);
	myPanel->Refresh();
	Close();
}