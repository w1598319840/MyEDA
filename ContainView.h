#pragma once
#pragma once
#ifndef CONTAINVIEW_H
#define  CONTAINVIEW_H
#include "Element.h"
using namespace std;
class MyPanel;
extern std::vector<Component> allComponent;

class ContainView : public wxFrame
{
public:
	int index;
	MyPanel* myPanel;
public:
	ContainView(const wxString& title, const wxSize& size, MyPanel* myPanel, int index);
};

#endif