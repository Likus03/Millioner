//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include "Unit2.h"
#include "Unit1.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormActivate(TObject *Sender)
{
Image1->Canvas->Brush->Color=clRed;
Image1->Canvas->Rectangle(0,0,Image1->Width, Image1->Height);
	if(Form1->priz_mas[Form2->lv-2]<=Form1->priz_mas[Form4->nesgor_index]) {Label2->Caption="\n\nЭто не правильный ответ.\nВаш выигрыш составил: 0 руб.\nИгра закончена.";}
	else {Label2->Caption="Это не правильный ответ.\nВаш выигрыш составил: "+IntToStr(Form1->priz_mas[Form4->nesgor_index])+" руб.\nИгра закончена.";}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button1Click(TObject *Sender)
{
	Form1->Visible = true;
	Form2->Hide();
	Close();
}
//---------------------------------------------------------------------------



