#pragma once

using namespace System;
using namespace System::Drawing;

class CHUD
{
private:
	int X, Y;
	int AnchoM1;
	int AnchoM2;
	int AnchoM3;

public:
	CHUD(int X, int Y, int AnchoM1, int AnchoM2, int AnchoM3);
	~CHUD();
	void Dibujar(Graphics^ g, Bitmap^ imgHP, Bitmap^ imgMedidor);
	int Get_AnchoM1();
	int Get_AnchoM2();
	int Get_AnchoM3();

};

CHUD::CHUD(int X, int Y, int AnchoM1, int AnchoM2, int AnchoM3)
{
	this->X = X;
	this->Y = Y;
	this->AnchoM1 = AnchoM1;
	this->AnchoM2 = AnchoM2;
	this->AnchoM3 = AnchoM3;
}

CHUD::~CHUD()
{
}

void CHUD::Dibujar(Graphics^ g, Bitmap^ imgHP, Bitmap^ imgMedidor)
{
	// HUD
	Rectangle OrigenF = Rectangle(0, 0, imgHP->Width, imgHP->Height);
	Rectangle DestinoF = Rectangle(X+100, Y, imgHP->Width, imgHP->Height);

	Rectangle OrigenM = Rectangle(0, 0, imgMedidor->Width, imgMedidor->Height);
	Rectangle DestinoM1 = Rectangle(X + 78+100, Y +28 , AnchoM1, imgMedidor->Height);
	Rectangle DestinoM2 = Rectangle(X + 529+100, Y+28, AnchoM2, imgMedidor->Height);
	Rectangle DestinoM3 = Rectangle(X + 978+100, Y+28, AnchoM3, imgMedidor->Height);

	g->DrawImage(imgMedidor, DestinoM1, OrigenM, GraphicsUnit::Pixel);
	g->DrawImage(imgMedidor, DestinoM2, OrigenM, GraphicsUnit::Pixel);
	g->DrawImage(imgMedidor, DestinoM3, OrigenM, GraphicsUnit::Pixel);
	g->DrawImage(imgHP, DestinoF, OrigenF, GraphicsUnit::Pixel);
}
int CHUD::Get_AnchoM1()
{
	return this->AnchoM1;
}
int CHUD::Get_AnchoM2()
{
	return this->AnchoM2;
}
int CHUD::Get_AnchoM3()
{
	return this->AnchoM3;
}