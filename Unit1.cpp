//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "mod_dann.h"
#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonPlayClick(TObject *Sender)
{
	Form1->Visible=false;
	Form4 = new TForm4(this);
	Form4->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonExitClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormActivate(TObject *Sender)
{
	DataModule1->ADOQuery_mas->Active=false;
	DataModule1->ADOQuery_mas->Parameters->ParamByName("p")->Value = 1;
	DataModule1->ADOQuery_mas->Active=true;

		while (!DataModule1->ADOQuery_mas->Eof){
			numb_quest1[count_level1] = DataModule1->ADOQuery_mas->FieldByName("cod")->AsInteger;
			count_level1++;
			DataModule1->ADOQuery_mas->Next();
		}

	DataModule1->ADOQuery_mas->Active=false;
	DataModule1->ADOQuery_mas->Parameters->ParamByName("p")->Value = 2;
	DataModule1->ADOQuery_mas->Active=true;

		while (!DataModule1->ADOQuery_mas->Eof){
			numb_quest2[count_level2] = DataModule1->ADOQuery_mas->FieldByName("cod")->AsInteger;
			count_level2++;
			DataModule1->ADOQuery_mas->Next();
		}

	DataModule1->ADOQuery_mas->Active=false;
	DataModule1->ADOQuery_mas->Parameters->ParamByName("p")->Value = 3;
	DataModule1->ADOQuery_mas->Active=true;

		while (!DataModule1->ADOQuery_mas->Eof){
			numb_quest3[count_level3] = DataModule1->ADOQuery_mas->FieldByName("cod")->AsInteger;
			count_level3++;
			DataModule1->ADOQuery_mas->Next();
		}

        priz_mas[0]=100;
for (int i = 1; i < 15; i++) {
	if(i == 2) priz_mas[i] = 300;
	else if(i == 3) priz_mas[i] = 500;
	else if(i == 11) priz_mas[i] = 125000;
	else priz_mas[i] = priz_mas[i-1]*2;
}
}
//---------------------------------------------------------------------------

