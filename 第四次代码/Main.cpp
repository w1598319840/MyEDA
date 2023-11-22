#include <wx/wx.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MyText {
	string s, content;
	int x, y, degree, textSize, tr, tg, tb;
public:
	void draw(wxDC& dc) {
		dc.SetFont(wxFont(textSize, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
		dc.SetTextForeground(wxColour(tr, tg, tb));
		dc.DrawRotatedText(content, x, y, degree);
	}
public:
	void readText() {
		while (cin >> s) {
			if (s == "(") {
				while (s != ")") {
					cin >> s;
					if (s == "textColor") {
						scanf("%d", &tr);
						scanf("%d", &tg);
						scanf("%d", &tb);
					}
					if (s == "textSize") {
						scanf("%d", &textSize);
					}
					if (s == "x") {
						scanf("%d", &x);
					}
					if (s == "y") {
						scanf("%d", &y);
					}
					if (s == "degree") {
						scanf("%d", &degree);
					}
					if (s == "content") {
						cin >> content;
					}
				}
				if (s == ")") {
					return;
				}
			}
		}
	}
};

class MyCircle {
	string s;
	int x, y, r, pr, pg, pb, br, bg, bb, penWidth;
public:
	void draw(wxDC& dc) {
		dc.SetPen(wxPen(wxColor(pr, pg, pb), penWidth));
		if (br == -1 || bg == -1 || bb == -1) {
			dc.SetBrush(*wxTRANSPARENT_BRUSH);
		}
		else {
			dc.SetBrush(wxColor(br, bg, bb));
		}
		dc.DrawCircle(x, y, r);
	}
public:
	void readCircle() {
		while (cin >> s) {
			if (s == "(") {
				while (s != ")") {
					cin >> s;
					if (s == "penColor") {
						scanf("%d", &pr);
						scanf("%d", &pg);
						scanf("%d", &pb);
					}
					if (s == "penWidth") {
						scanf("%d", &penWidth);
					}
					if (s == "brushColor") {
						scanf("%d", &br);
						scanf("%d", &bg);
						scanf("%d", &bb);
					}
					if (s == "x") {
						scanf("%d", &x);
					}
					if (s == "y") {
						scanf("%d", &y);
					}
					if (s == "r") {
						scanf("%d", &r);
					}
				}
				if (s == ")") {
					return;
				}
			}
		}
	}
};

class MyLine {
	string s;
	int x1, x2, y1, y2, lr, lg, lb, lineWidth;
public:
	void draw(wxDC& dc) {
		dc.SetPen(wxPen(wxColor(lr, lg, lb), lineWidth));
		dc.DrawLine(x1, y1, x2, y2);
	}
public:
	void readLine() {
		while (cin >> s) {
			if (s == "(") {
				while (s != ")") {
					cin >> s;
					if (s == "lineColor") {
						scanf("%d", &lr);
						scanf("%d", &lg);
						scanf("%d", &lb);
					}
					if (s == "lineWidth") {
						scanf("%d", &lineWidth);
					}
					if (s == "x1") {
						scanf("%d", &x1);
					}
					if (s == "x2") {
						scanf("%d", &x2);
					}
					if (s == "y1") {
						scanf("%d", &y1);
					}
					if (s == "y2") {
						scanf("%d", &y2);
					}
				}
				if (s == ")") {
					return;
				}
			}
		}
	}
};

class MyPolygon {
	string s;
	int penWidth, pr, pg, pb, br, bg, bb;
	int xi = 0, yi = 0;
	int x[10] = { -1 };
	int y[10] = { -1 };
public:
	void draw(wxDC& dc) {
		wxPoint points[10];
		for (int i = 0; i <= xi; i++) {
			points[i] = wxPoint(x[i], y[i]);
		}
		dc.SetPen(wxPen(wxColor(pr, pg, pb), penWidth));
		if (br == -1 || bg == -1 || bb == -1) {
			dc.SetBrush(*wxTRANSPARENT_BRUSH);
		}
		else {
			dc.SetBrush(wxColor(br, bg, bb));
		}
		dc.DrawPolygon(xi, points);
	}
public:
	void readPolygon() {
		while (cin >> s) {
			if (s == "(") {
				while (s != ")") {
					cin >> s;
					if (s == "penColor") {
						scanf("%d", &pr);
						scanf("%d", &pg);
						scanf("%d", &pb);
					}
					if (s == "penWidth") {
						scanf("%d", &penWidth);
					}
					if (s == "brushColor") {
						scanf("%d", &br);
						scanf("%d", &bg);
						scanf("%d", &bb);
					}
					if (s == "x") {
						cin >> x[xi++];
					}
					if (s == "y") {
						cin >> y[yi++];
					}
				}
				if (s == ")") {
					return;
				}
			}
		}
	}
};
class MyRectangle {
	string s;
	int x, y, width, height, penWidth, pr, pg, pb, br, bg, bb;
public:
	void draw(wxDC& dc) {
		dc.SetPen(wxPen(wxColor(pr, pg, pb), penWidth));
		if (br == -1 || bg == -1 || bb == -1) {
			dc.SetBrush(*wxTRANSPARENT_BRUSH);
		}
		else {
			dc.SetBrush(wxColor(br, bg, bb));
		}
		dc.DrawRectangle(x, y, width, height);
	}
public:
	void readRectangle() {
		while (cin >> s) {
			if (s == "(") {
				while (s != ")") {
					cin >> s;
					if (s == "penColor") {
						scanf("%d", &pr);
						scanf("%d", &pg);
						scanf("%d", &pb);
					}
					if (s == "penWidth") {
						scanf("%d", &penWidth);
					}
					if (s == "brushColor") {
						scanf("%d", &br);
						scanf("%d", &bg);
						scanf("%d", &bb);
					}
					if (s == "x") {
						scanf("%d", &x);
					}
					if (s == "y") {
						scanf("%d", &y);
					}
					if (s == "width") {
						scanf("%d", &width);
					}
					if (s == "height") {
						scanf("%d", &height);
					}
				}
				if (s == ")") {
					return;
				}
			}
		}
	}
};

class MyCurve {
	string s;
	int penWidth, pr, pg, pb;
	int xi = 0, yi = 0;
	int x[10] = { -1 };
	int y[10] = { -1 };
public:
	void draw(wxDC& dc) {
		wxPoint points[10];
		for (int i = 0; i <= xi; i++) {
			points[i] = wxPoint(x[i], y[i]);
		}
		dc.SetPen(wxPen(wxColor(pr, pg, pb), penWidth));
		dc.DrawSpline(xi, points);
	}
public:
	void readCurve() {
		while (cin >> s) {
			if (s == "(") {
				while (s != ")") {
					cin >> s;
					if (s == "penColor") {
						scanf("%d", &pr);
						scanf("%d", &pg);
						scanf("%d", &pb);
					}
					if (s == "penWidth") {
						scanf("%d", &penWidth);
					}
					if (s == "x") {
						cin >> x[xi++];
					}
					if (s == "y") {
						cin >> y[yi++];
					}
				}
				if (s == ")") {
					return;
				}
			}
		}
	}
};

class Component {
public:
	string name;
	vector<MyCircle> vCircle;
	vector<MyCurve> vCurve;
	vector<MyLine> vLine;
	vector<MyPolygon> vPolygon;
	vector<MyRectangle> vRectangle;
	vector<MyText> vText;

public:
	static void readFile(vector<Component>& allComponent) {
		freopen("F:\\MyEDAComponent\\test.txt", "r", stdin);
		string s;
		while (cin >> s) {
			if (s == "{") {
				allComponent.push_back(Component());
				cin >> allComponent[allComponent.size() - 1].name;
				allComponent[allComponent.size() - 1].readComponent(allComponent);
			}
		}
	}

public:
	static void drawComponent(wxDC& dc, vector<Component>& allComponent) {
		for (int i = 0; i < allComponent.size(); i++) {
			for (int j = 0; j < allComponent[i].vCircle.size(); j++) {
				allComponent[i].vCircle[j].draw(dc);
			}
			for (int j = 0; j < allComponent[i].vCurve.size(); j++) {
				allComponent[i].vCurve[j].draw(dc);
			}
			for (int j = 0; j < allComponent[i].vLine.size(); j++) {
				allComponent[i].vLine[j].draw(dc);
			}
			for (int j = 0; j < allComponent[i].vPolygon.size(); j++) {
				allComponent[i].vPolygon[j].draw(dc);
			}
			for (int j = 0; j < allComponent[i].vRectangle.size(); j++) {
				allComponent[i].vRectangle[j].draw(dc);
			}
			for (int j = 0; j < allComponent[i].vText.size(); j++) {
				allComponent[i].vText[j].draw(dc);
			}
		}
	}

public:
	void readComponent(vector<Component>& allComponent) {
		string s;

		while (cin >> s) {
			if (s == "[") {
				while (s != "]") {
					cin >> s;
					if (s == "Rectangle") {
						MyRectangle rect;
						rect.readRectangle();
						allComponent[allComponent.size() - 1].vRectangle.push_back(rect);
					}
					if (s == "Circle") {
						MyCircle circle;
						circle.readCircle();
						allComponent[allComponent.size() - 1].vCircle.push_back(circle);
					}
					if (s == "Line") {
						MyLine line;
						line.readLine();
						allComponent[allComponent.size() - 1].vLine.push_back(line);
					}
					if (s == "Text") {
						MyText text;
						text.readText();
						allComponent[allComponent.size() - 1].vText.push_back(text);
					}
					if (s == "Polygon") {
						MyPolygon polygon;
						polygon.readPolygon();
						allComponent[allComponent.size() - 1].vPolygon.push_back(polygon);
					}
					if (s == "Curve") {
						MyCurve curve;
						curve.readCurve();
						allComponent[allComponent.size() - 1].vCurve.push_back(curve);
					}
				}
				if (s == "]") {
					return;
				}
			}
		}
	}
};

class MyPanel : public wxPanel {
public:
	MyPanel(wxFrame* parent) : wxPanel(parent) {
		Bind(wxEVT_PAINT, &MyPanel::OnPaint, this);
	}

	void OnPaint(wxPaintEvent& event) {
		wxPaintDC dc(this);//实例化wxPaintDC类的对象dc，将当前窗口控件传入

		vector<Component> allComponent;
		Component::readFile(allComponent);//调用静态函数
		Component::drawComponent(dc, allComponent);
	}
};

class MyFrame : public wxFrame {
public:
	MyFrame(const wxString& title, const wxSize& size) :wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, size)
	{
		Centre();
	}
};

class App : public wxApp {
public:
	bool OnInit()override {
		MyFrame* window = new MyFrame("原理图编辑器", wxSize(1000, 700));

		MyPanel* myPanel = new MyPanel(window);
		window->Show();

		return true;
	}
};

wxIMPLEMENT_APP(App);//程序入口

