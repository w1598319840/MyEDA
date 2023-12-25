#pragma once
#ifndef MYFRAME_H
#define  MYFRAME_H
#include "Element.h"
#include "ComponentSelection.h"
#include <wx/wx.h>
using namespace std;

class MyPanel : public wxPanel {
public:
	MyPanel(wxFrame* parent);
	int cur = 1;
	int sel = -1;
	clock_t a, b;
	int originalX, originalY;
	bool isDragging;

	void OnPaint(wxPaintEvent& event);
	void OnButton1Click(wxCommandEvent& event);
	void OnMouseMove(wxMouseEvent& event);
	void OnMouseLeftDown(wxMouseEvent& event);
	void OnMouseLeftUp(wxMouseEvent& event);
	void OnMouseDoubleClick(wxMouseEvent& event);
};



class MyFrame : public wxFrame {
	MyPanel* myPanel = new MyPanel(this);
public:
	MyFrame(const wxString& title, const wxSize& size);
	void OnOpen(wxCommandEvent& event);
	void OnSave(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
};


#endif
