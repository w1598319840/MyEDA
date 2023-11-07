#include <wx/wx.h>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
class MyPanel : public wxPanel {
public:
	MyPanel(wxFrame* parent) : wxPanel(parent) {
		Bind(wxEVT_PAINT, &MyPanel::OnPaint, this);
	}

public:
	void drawText(wxDC& dc) {
		string s, content;
		int x, y, degree, textSize, tr, tg, tb;
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
					dc.SetFont(wxFont(textSize, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
					dc.SetTextForeground(wxColour(tr, tg, tb));
					dc.DrawRotatedText(content, x, y, degree);
					return;
				}
			}
		}
	}

public:
	void drawLine(wxDC& dc) {
		string s;
		int x1, x2, y1, y2, lr, lg, lb, lineWidth;
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
					dc.SetPen(wxPen(wxColor(lr, lg, lb), lineWidth));
					dc.DrawLine(x1, y1, x2, y2);
					return;
				}
			}
		}
	}

public:
	void drawRectangle(wxDC& dc) {
		string s;
		int x, y, width, height, penWidth, pr, pg, pb, br, bg, bb;
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
					dc.SetPen(wxPen(wxColor(pr, pg, pb), penWidth));
					if (br == -1 || bg == -1 || bb == -1) {
						dc.SetBrush(*wxTRANSPARENT_BRUSH);
					}
					else {
						dc.SetBrush(wxColor(br, bg, bb));
					}
					dc.DrawRectangle(x, y, width, height);
					return;
				}
			}
		}
	}

public:
	void drawCircle(wxDC& dc) {
		string s;
		int x, y, r, pr, pg, pb, br, bg, bb, penWidth;
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
					dc.SetPen(wxPen(wxColor(pr, pg, pb), penWidth));
					if (br == -1 || bg == -1 || bb == -1) {
						dc.SetBrush(*wxTRANSPARENT_BRUSH);
					}
					else {
						dc.SetBrush(wxColor(br, bg, bb));
					}
					dc.DrawCircle(x, y, r);
					return;
				}
			}
		}
	}

public:
	void drawPolygon(wxDC& dc) {
		string s;
		int penWidth, pr, pg, pb, br, bg, bb;
		int xi = 0, yi = 0;
		int x[10] = { -1 };
		int y[10] = { -1 };
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
					return;
				}
			}
		}
	}

public:
	void drawCurve(wxDC& dc) {
		string s;
		int penWidth, pr, pg, pb;
		int xi = 0, yi = 0;
		int x[10] = { -1 };
		int y[10] = { -1 };
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
					wxPoint points[10];
					for (int i = 0; i <= xi; i++) {
						points[i] = wxPoint(x[i], y[i]);
					}
					dc.SetPen(wxPen(wxColor(pr, pg, pb), penWidth));
					dc.DrawSpline(xi, points);
					return;
				}
			}
		}
	}

public:
	void drawComponent(wxDC& dc) {
		string s;
		while (cin >> s) {
			if (s == "[") {
				while (s != "]") {
					cin >> s;
					if (s == "Rectangle") {
						drawRectangle(dc);
					}
					if (s == "Circle") {
						drawCircle(dc);
					}
					if (s == "Line") {
						drawLine(dc);
					}
					if (s == "Text") {
						drawText(dc);
					}
					if (s == "Polygon") {
						drawPolygon(dc);
					}
					if (s == "Curve") {
						drawCurve(dc);
					}
				}
				if (s == "]") {
					return;
				}
			}
		}
	}

	void myRead(wxDC& dc) {
		freopen("F:\\MyEDAComponent\\test.txt", "r", stdin);
		string s;
		while (cin >> s) {
			if (s == "{") {
				cin >> s;
				drawComponent(dc);
			}
		}
	}

	void OnPaint(wxPaintEvent& event) {
		wxPaintDC dc(this);//实例化wxPaintDC类的对象dc，将当前窗口控件传入
		myRead(dc);

	}
};


class App : public wxApp {
public:
	bool OnInit()override {
		wxFrame* window = new wxFrame(NULL, wxID_ANY, "原理图编辑器", wxDefaultPosition, wxSize(1000, 700));//实例化一个Frame,
		window->Centre();

		MyPanel* myPanel = new MyPanel(window);
		window->Show();

		return true;
	}
};

wxIMPLEMENT_APP(App);//程序入口

