#pragma once
#ifndef COMPONENTSELECTION_H
#define  COMPONENTSELECTION_H
#include "Element.h"
using namespace std;
class MyPanel;
extern std::vector<Component> allComponent;

class Coon_01x04 {
public:
	static void addCoon_01x04(vector<Component>& allComponent, string filePath);
};

class Resistance {
public:
	static void addResistance(vector<Component>& allComponent, string filePath);
};

class Capacitor {
public:
	static void addCapacitor(vector<Component>& allComponent, string filePath);
};

class ComponentSelectionPanel;

class ComponentSelection : public wxFrame {
public:
	ComponentSelectionPanel* componentSelectionPanel;
	MyPanel* myPanel;
	string filePath;
public:
	ComponentSelection(const wxString& title, const wxSize& size, MyPanel* myPanel);

	void coon_01x04Click(wxCommandEvent& event);
	void coon_01x04View(wxCommandEvent& event);
	void resistanceClick(wxCommandEvent& event);
	void resistanceView(wxCommandEvent& event);
	void capacitorClick(wxCommandEvent& event);
	void capacitorView(wxCommandEvent& event);
};

class ComponentSelectionPanel : public wxPanel {
public:
	ComponentSelectionPanel(wxFrame* parent);
	void OnPaint(wxPaintEvent& event);
};

#endif
