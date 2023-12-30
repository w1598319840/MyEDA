#pragma once
#ifndef ELEMENT_H
#define  ELEMENT_H
#include <wx/wx.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Coon_01x04;
class Component;

class MyText {
public:
	string s, content;
	int centerx, centery, x, y, degree, textSize, tr, tg, tb;
public:
	void draw(wxDC& dc);
public:
	void readText(int centerX, int centerY);
public:
	static void addText(vector<Component>& allComponent, int x, int y, int degree, int textSize, int tr, int ig, int ib, string content);
public:
	void saveText_sch(MyText text, ofstream& destFile);
};

class MyCircle {
public:
	string s;
	int centerx, centery, x, y, r, pr, pg, pb, br, bg, bb, penWidth;
public:
	void draw(wxDC& dc);
public:
	void readCircle(int centerX, int centerY);
};

class MyLine {
public:
	string s;
	int centerx, centery, x1, x2, y1, y2, lr, lg, lb, lineWidth;
public:
	void draw(wxDC& dc);
public:
	void readLine(int centerX, int centerY);
public:
	static void addLine(vector<Component>& allComponent, int x1, int y1, int x2, int y2, int lr, int lg, int lb, int lineWidth);
public:
	void saveLine_sch(MyLine line, ofstream& destFile);
};

class MyPolygon {
	string s;
	int centerx, centery, penWidth, pr, pg, pb, br, bg, bb;
	int xi = 0, yi = 0;
	int x[10] = { -1 };
	int y[10] = { -1 };
public:
	void draw(wxDC& dc);
public:
	void readPolygon(int centerX, int centerY);
};

class MyRectangle {
public:
	string s;
	int centerx, centery, x, y, width, height, penWidth, pr, pg, pb, br, bg, bb;
public:
	void draw(wxDC& dc);
public:
	void readRectangle(int centerX, int centerY);
public:
	static void addRectangle(vector<Component>& allComponent, int x, int y, int width, int height, int penWidth, int pr, int pg, int pb, int br, int bg, int bb);
public:
	void saveRectangle_sch(MyRectangle rectangle, ofstream& destFile);
};

class MyCurve {
public:
	string s;
	int centerx, centery, penWidth, pr, pg, pb;
	int xi = 0, yi = 0;
	int x[10] = { -1 };
	int y[10] = { -1 };
public:
	void draw(wxDC& dc);
public:
	void readCurve(int centerX, int centerY);
};

class Component {
public:
	string name;
	int centerX;
	int centerY;
	vector<MyCircle> vCircle;
	vector<MyCurve> vCurve;
	vector<MyLine> vLine;
	vector<MyPolygon> vPolygon;
	vector<MyRectangle> vRectangle;
	vector<MyText> vText;

public:
	static void readFile(vector<Component>& allComponent, int flag, string filePath);

public:
	static void drawComponent(wxDC& dc, vector<Component>& allComponent);

public:
	void readComponent(vector<Component>& allComponent);
public:
	static void saveComponent_sch(vector<Component>& allComponent, string destPath);
public:
	static void saveComponent_net(vector<Component>& allComponent, string destPath, string filePath);
};

#endif