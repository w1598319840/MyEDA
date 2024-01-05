#pragma once
#ifndef MYFRAME_H
#define  MYFRAME_H
#include "Element.h"
#include "ComponentSelection.h"
#include <wx/wx.h>
using namespace std;

class MyPanel : public wxPanel {
public:
	wxButton* ConnectButton;
	MyPanel(wxFrame* parent);
	int cur = 1;
	int sel = -1;
	clock_t a, b;
	int originalX, originalY;
	bool isDragging;
	bool isConnecting;
	bool isDrawing;

	void OnPaint(wxPaintEvent& event);
	void OnMouseMove(wxMouseEvent& event);
	void Drag(wxMouseEvent& event);
	void Connect(wxCommandEvent& event);
	void OnMouseLeftDown(wxMouseEvent& event);
	void OnMouseLeftUp(wxMouseEvent& event);
	void OnMouseDoubleClick(wxMouseEvent& event);
};



class MyFrame : public wxFrame {
	MyPanel* myPanel = new MyPanel(this);
	string destPath = "";
public:
	MyFrame(const wxString& title, const wxSize& size);
	void addComponent(wxCommandEvent& event);
	void OnNew(wxCommandEvent& event);
	void OnOpen(wxCommandEvent& event);
	void OnSave_sch(wxCommandEvent& event);
	void OnSave_net(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
};


#endif
