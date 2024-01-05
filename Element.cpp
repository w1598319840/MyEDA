﻿#include "Element.h"
#include <chrono>
#include <sstream>
#include <iomanip>
extern Information infor;
extern vector<Net> allNet;

void MyText::draw(wxDC& dc) {
	dc.SetFont(wxFont(textSize, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
	dc.SetTextForeground(wxColour(tr, tg, tb));
	if (content != "无源") {
		dc.DrawRotatedText(content, x + centerx, y + centery, degree);
	}
}
void MyText::readText(int centerX, int centerY) {
	centerx = centerX;
	centery = centerY;
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

void MyText::addText(vector<Component>& allComponent, int x, int y, int degree, int textSize, int tr, int tg, int tb, string content) {
	MyText text = MyText();
	text.x = x;
	text.y = y;
	text.degree = degree;
	text.textSize = textSize;
	text.tr = tr;
	text.tg = tg;
	text.tb = tb;
	text.content = content;

	allComponent[allComponent.size() - 1].vText.push_back(text);
}

void MyText::saveText_sch(MyText text, ofstream& destFile) {
	destFile << "\tText\n";
	destFile << "\t\t(\n";
	destFile << "\t\ttextColor " << text.tr << " " << text.tg << " " << text.tb << "\n";
	destFile << "\t\ttextSize " << text.textSize << "\n";
	destFile << "\t\tx " << text.x << "\n";
	destFile << "\t\ty " << text.y << "\n";
	destFile << "\t\tcontent " << text.content << "\n";
	destFile << "\t\tdegree " << text.degree << "\n";
	destFile << "\t\t)\n";
}

void MyCircle::draw(wxDC& dc) {
	dc.SetPen(wxPen(wxColor(pr, pg, pb), penWidth));
	if (br == -1 || bg == -1 || bb == -1) {
		dc.SetBrush(*wxTRANSPARENT_BRUSH);
	}
	else {
		dc.SetBrush(wxColor(br, bg, bb));
	}
	dc.DrawCircle(x + centerx, y + centery, r);
}

void MyCircle::readCircle(int centerX, int centerY) {
	centerx = centerX;
	centery = centerY;
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

void MyLine::draw(wxDC& dc) {
	dc.SetPen(wxPen(wxColor(lr, lg, lb), lineWidth));
	dc.DrawLine(x1 + centerx, y1 + centery, x2 + centerx, y2 + centery);
}

void MyLine::readLine(int centerX, int centerY) {
	centerx = centerX;
	centery = centerY;
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

void MyLine::addLine(vector<Component>& allComponent, int x1, int y1, int x2, int y2, int lr, int lg, int lb, int lineWidth) {
	MyLine line = MyLine();
	line.x1 = x1;
	line.y1 = y1;
	line.x2 = x2;
	line.y2 = y2;
	line.lr = lr;
	line.lg = lg;
	line.lb = lb;
	line.lineWidth = lineWidth;

	allComponent[allComponent.size() - 1].vLine.push_back(line);
}

void MyLine::saveLine_sch(MyLine line, ofstream& destFile) {
	destFile << "\tLine\n";
	destFile << "\t\t(\n";
	destFile << "\t\tlineColor " << line.lr << " " << line.lg << " " << line.lb << "\n";
	destFile << "\t\tlineWidth " << line.lineWidth << "\n";
	destFile << "\t\tx1 " << line.x1 << "\n";
	destFile << "\t\ty1 " << line.y1 << "\n";
	destFile << "\t\tx2 " << line.x2 << "\n";
	destFile << "\t\ty2 " << line.y2 << "\n";
	destFile << "\t\t)\n";
}


void MyPolygon::draw(wxDC& dc) {
	wxPoint points[10];
	for (int i = 0; i <= xi; i++) {
		points[i] = wxPoint(x[i] + centerx, y[i] + centery);
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

void MyPolygon::readPolygon(int centerX, int centerY) {
	centerx = centerX;
	centery = centerY;
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

void MyRectangle::draw(wxDC& dc) {
	dc.SetPen(wxPen(wxColor(pr, pg, pb), penWidth));
	if (br == -1 || bg == -1 || bb == -1) {
		dc.SetBrush(*wxTRANSPARENT_BRUSH);
	}
	else {
		dc.SetBrush(wxColor(br, bg, bb));
	}
	//printf("%d %d %d %d %d %d\n",x,y,centerx,centery,x+centerx,y+centery);
	dc.DrawRectangle(x + centerx, y + centery, width, height);
}

void MyRectangle::readRectangle(int centerX, int centerY) {
	centerx = centerX;
	centery = centerY;
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

void MyRectangle::addRectangle(vector<Component>& allComponent, int x, int y, int width, int height, int penWidth, int pr, int pg, int pb, int br, int bg, int bb) {
	MyRectangle rectangle = MyRectangle();
	rectangle.x = x;
	rectangle.y = y;
	rectangle.width = width;
	rectangle.height = height;
	rectangle.penWidth = penWidth;
	rectangle.pr = pr;
	rectangle.pg = pg;
	rectangle.pb = pb;
	rectangle.br = br;
	rectangle.bg = bg;
	rectangle.bb = bb;

	allComponent[allComponent.size() - 1].vRectangle.push_back(rectangle);
}

void MyRectangle::saveRectangle_sch(MyRectangle rectangle, ofstream& destFile) {
	destFile << "\tRectangle\n";
	destFile << "\t\t(\n";
	destFile << "\t\tpenColor " << rectangle.pr << " " << rectangle.pg << " " << rectangle.pb << "\n";
	destFile << "\t\tpenWidth " << rectangle.penWidth << "\n";
	destFile << "\t\tbrushColor " << rectangle.br << " " << rectangle.bg << " " << rectangle.bb << "\n";
	destFile << "\t\tx " << rectangle.x << "\n";
	destFile << "\t\ty " << rectangle.y << "\n";
	destFile << "\t\twidth " << rectangle.width << "\n";
	destFile << "\t\theight " << rectangle.height << "\n";
	destFile << "\t\t)\n";
}

void MyCurve::draw(wxDC& dc) {
	wxPoint points[10];
	for (int i = 0; i <= xi; i++) {
		points[i] = wxPoint(x[i] + centerx, y[i] + centery);
	}
	dc.SetPen(wxPen(wxColor(pr, pg, pb), penWidth));
	dc.DrawSpline(xi, points);
}

void MyCurve::readCurve(int centerX, int centerY) {
	centerx = centerX;
	centery = centerY;
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

void Component::readFile(vector<Component>& allComponent, int flag, string filePath) {
	if (flag == 0) {//flag为0时，把vector数组中所有数据清空，此时是执行导入文件的程序
		allComponent.clear();
		freopen(filePath.c_str(), "r", stdin);
	}
	if (flag == 1) {//flag为1时,此时执行添加电气元件，因此不用清空
		freopen(filePath.c_str(), "r", stdin);
	}
	cin.clear();
	cin.seekg(0, ios::beg);
	//freopen("F:\\MyEDAComponent\\component.txt", "r", stdin);
	string s;
	while (cin >> s) {
		if (s == "{") {
			cin >> s;
			if (s == "Information") {
				infor.readInformation(allComponent);
			}
			else if (s == "Net") {
				Net::readNet(allNet, 0, filePath);
			}
			else {
				allComponent.push_back(Component());
				int i = allComponent.size() - 1;
				allComponent[i].name = s;
				allComponent[i].readComponent(allComponent);
			}
		}
	}
}

void Component::drawComponent(wxDC& dc, vector<Component>& allComponent) {
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

void Component::drawInformation(wxDC& dc, vector<Component>& allComponent, wxSize size) {
	int width = size.GetWidth();
	int height = size.GetHeight();
	int	x = size.x;
	int y = size.y;
	dc.SetPen(wxPen(wxColor(132, 0, 0), 1));
	dc.SetBrush(wxColor(245, 244, 239));
	dc.DrawRectangle(0.60 * x, 0.82 * y, width - 0.599 * x, height - 0.82 * y);
	dc.DrawLine(0.60 * x, 0.90 * y, x, 0.90 * y);
	dc.DrawLine(0.60 * x, 0.93 * y, x, 0.93 * y);
	dc.DrawLine(0.60 * x, 0.955 * y, x, 0.955 * y);
	dc.DrawLine(0.60 * x, 0.973 * y, x, 0.973 * y);
	dc.DrawLine(0.675 * x, 0.955 * y, 0.675 * x, 0.973 * y);
	dc.DrawLine(0.906 * x, 0.955 * y, 0.906 * x, 0.973 * y);

	dc.SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT));
	dc.SetTextForeground(wxColour(132, 0, 0));
	if (allComponent.size() == 0) {
		dc.DrawRotatedText("Sheet: ", 0.605 * x, 0.901 * y, 0);
		dc.DrawRotatedText("File: ", 0.605 * x, 0.915 * y, 0);
		dc.SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
		dc.DrawRotatedText("Title: ", 0.605 * x, 0.932 * y, 0);
		dc.SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT));
		dc.SetTextForeground(wxColour(132, 0, 0));
		dc.DrawRotatedText("Size: ", 0.605 * x, 0.9565 * y, 0);
		dc.DrawRotatedText("Date: ", 0.68 * x, 0.9565 * y, 0);
		dc.DrawRotatedText("Rev: ", 0.91 * x, 0.9565 * y, 0);
	}
	else {
		dc.DrawRotatedText("Sheet: /", 0.605 * x, 0.901 * y, 0);
		dc.DrawRotatedText("File: " + infor.file, 0.605 * x, 0.915 * y, 0);
		dc.SetFont(wxFont(12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
		dc.DrawRotatedText("Title: " + infor.title, 0.605 * x, 0.932 * y, 0);
		dc.SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_LIGHT));
		dc.SetTextForeground(wxColour(132, 0, 0));
		dc.DrawRotatedText("Size: " + infor.size, 0.605 * x, 0.9565 * y, 0);
		dc.DrawRotatedText("Date: " + infor.date, 0.68 * x, 0.9565 * y, 0);
		dc.DrawRotatedText("Rev: " + infor.rev, 0.91 * x, 0.9565 * y, 0);
	}
	dc.DrawRotatedText("MyCad E.D.A   mycad 1.0.0 ", 0.605 * x, 0.98 * y, 0);


}

void Component::readComponent(vector<Component>& allComponent) {
	string s;

	while (cin >> s) {

		if (s == "[") {
			while (s != "]") {
				int k = allComponent.size() - 1;
				cin >> s;
				if (s == "Center")
				{
					cin >> allComponent[k].centerX;
					cin >> allComponent[k].centerY;
				}
				if (s == "Rectangle") {
					MyRectangle rect;
					rect.readRectangle(allComponent[k].centerX, allComponent[k].centerY);
					allComponent[k].vRectangle.push_back(rect);
				}
				if (s == "Circle") {
					MyCircle circle;
					circle.readCircle(allComponent[k].centerX, allComponent[k].centerY);
					allComponent[k].vCircle.push_back(circle);
				}
				if (s == "Line") {
					MyLine line;
					line.readLine(allComponent[k].centerX, allComponent[k].centerY);
					allComponent[k].vLine.push_back(line);
				}
				if (s == "Text") {
					MyText text;
					text.readText(allComponent[k].centerX, allComponent[k].centerY);
					allComponent[k].vText.push_back(text);
				}
				if (s == "Polygon") {
					MyPolygon polygon;
					polygon.readPolygon(allComponent[k].centerX, allComponent[k].centerY);
					allComponent[k].vPolygon.push_back(polygon);
				}
				if (s == "Curve") {
					MyCurve curve;
					curve.readCurve(allComponent[k].centerX, allComponent[k].centerY);
					allComponent[k].vCurve.push_back(curve);
				}
			}
			if (s == "]") {
				return;
			}
		}
	}
}

void Information::readInformation(vector<Component>& allComponent) {
	string s;
	while (cin >> s) {
		if (s == "Size") {
			cin >> infor.size;
		}
		if (s == "Title") {
			cin >> infor.title;
		}
		if (s == "Date") {
			cin >> infor.date;
		}
		if (s == "Rev") {
			cin >> infor.rev;
		}
		if (s == "File") {
			cin >> infor.file;
		}
		if (s == "}") {
			return;
		}
	}
}

void Component::saveComponent_sch(vector<Component>& allComponent, string destPath, string fileName) {
	ofstream destFile(destPath);
	Information::saveInformation(destFile, fileName);
	for (Component component : allComponent) {
		destFile << "{\n";
		destFile << component.name + "\n";
		destFile << "\t[\n";
		destFile << "\tCenter " << component.centerX << " " << component.centerY << "\n";
		for (MyRectangle rectangle : component.vRectangle) {
			rectangle.saveRectangle_sch(rectangle, destFile);
		}
		for (MyLine line : component.vLine) {
			line.saveLine_sch(line, destFile);
		}
		for (MyText text : component.vText) {
			text.saveText_sch(text, destFile);
		}
		destFile << "\t]\n";
		destFile << "}\n";

	}
	destFile.close();
}

void Component::saveComponent_net(vector<Component>& allComponent, string destPath, string filePath) {
	ofstream destFile(destPath);
	destFile << "(export (version \"E\")\n";
	destFile << "\t(design\n";
	destFile << "\t\t(source " << "\"" << filePath << "\")\n";
	auto now = chrono::system_clock::now();
	time_t now_time = chrono::system_clock::to_time_t(now);
	tm* local_time = localtime(&now_time);
	stringstream ss;
	ss << put_time(local_time, "%Y-%m-%d %H:%M:%S");
	string current_time = ss.str();
	destFile << "\t\t(date " << "\"" << current_time << "\")\n";
	destFile << "\t\t(tool \"LYXCAD 1.0.0\")\n";
	destFile << "\t\t(sheet (number \"1\") (name \" / \") (tstamps \" / \"))\n";
	destFile << "\t)\n";
	destFile << "\t(components\n";
	for (Component component : allComponent) {
		destFile << "\t\t(comp (ref \"" << component.name << "\"" << ")\n";
		destFile << "\t\t\t(value \"" << component.name << "\"" << ")\n";
		destFile << "\t\t\t(footprint \"UserLib:" << component.name << "\")\n";
		destFile << "\t\t)\n";
	}
	destFile << "\t)\n";
	destFile << ")\n";
}

void Net::drawNet(wxDC& dc, vector<Net>& allNet) {
	for (int i = 0; i < allNet.size(); i++) {
		dc.SetPen(wxPen(wxColor(0, 150, 0), 2));
		int midx = (allNet[i].Px[0] + allNet[i].Px[1]) / 2;
		dc.DrawLine(allNet[i].Px[0], allNet[i].Py[0], midx, allNet[i].Py[0]);
		dc.DrawLine(midx, allNet[i].Py[0], midx, allNet[i].Py[1]);
		dc.DrawLine(midx, allNet[i].Py[1], allNet[i].Px[1], allNet[i].Py[1]);
	}
}

void Net::ReadNet(vector<Net>& allNet) {
	string s;
	while (s != "Px")cin >> s;
	int x1, x2;
	cin >> x1 >> x2;
	int i = allNet.size() - 1;
	allNet[i].Px.push_back(x1);
	allNet[i].Px.push_back(x2);

	while (s != "Py")cin >> s;
	int y1, y2;
	cin >> y1 >> y2;
	allNet[i].Py.push_back(y1);
	allNet[i].Py.push_back(y2);
	while (s != "}")cin >> s;
}

void Net::SaveNet_sch(vector<Net>& allNet, ofstream& destFile) {
	for (Net net : allNet) {
		destFile << "{\n";
		destFile << "Net\n";
		destFile << "\tPx " << net.Px[0] << " " << net.Px[1] << "\n";
		destFile << "\tPy " << net.Py[0] << " " << net.Py[1] << "\n";

		destFile << "}\n";
	}

}

void Net::SaveNet_net(vector<Net>& allNet, string destPath, string filePath) {
	ofstream destFile(destPath);
	for (Net net : allNet) {
		destFile << "(Net\n";
		destFile << "\tPx " << net.Px[0] << " " << net.Px[1] << "\n";
		destFile << "\tPy " << net.Py[0] << " " << net.Py[1] << "\n";

		destFile << ")\n";
	}
}

void Net::readNet(vector<Net>& allNet, int flag, string filePath) {
	if (flag == 0) {//flag为0时，把vector数组中所有数据清空，此时是执行导入文件的程序
		allNet.clear();
		freopen(filePath.c_str(), "r", stdin);
	}
	if (flag == 1) {//flag为1时,此时执行添加电气元件，因此不用清空
		freopen(filePath.c_str(), "r", stdin);
	}
	cin.clear();
	cin.seekg(0, ios::beg);
	//freopen("F:\\MyEDAComponent\\component.txt", "r", stdin);
	string s;
	while (cin >> s) {
		if (s == "{") {
			allNet.push_back(Net());
			allNet[allNet.size() - 1].ReadNet(allNet);
		}
	}
}

void Information::saveInformation(ofstream& destFile, string  fileName) {
	infor.file = fileName;
	if (infor.date == "") {
		auto now = chrono::system_clock::now();
		time_t now_time = chrono::system_clock::to_time_t(now);
		tm* local_time = localtime(&now_time);
		stringstream ss;
		ss << put_time(local_time, "%Y-%m-%d %H:%M:%S");
		infor.date = ss.str();
	}
	destFile << "{\n";
	destFile << "Information\n";
	destFile << "\tSize " << infor.size << "\n";
	destFile << "\tDate " << infor.date << "\n";
	destFile << "\tRev " << infor.rev << "\n";
	destFile << "\tFile " << infor.file << "\n";
	destFile << "}\n";
}