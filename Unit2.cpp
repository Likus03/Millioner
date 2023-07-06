
//---------------------------------------------------------------------------

#include <vcl.h>
#include <set>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#include "Unit3.h"
#include "mod_dann.h"
#include <time.h>
#include "Unit4.h"
#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

using namespace std;
set<int> S;
int count = 0;
int codd;
int otv;
int pr_err;
int for_button;
int podskazki;
TPanel *panel[4];
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
panel[0]=answer1;
panel[1]=answer2;
panel[2]=answer3;
panel[3]=answer4;
}
//---------------------------------------------------------------------------
void TForm2::quest(int p){
for(int i = 0;i<4;i++){
		panel[i]->Visible = true;
}
	for_button=-1;
	randomize();
	switch (p) {
	case 1:
		do
			codd = Form1->numb_quest1[random(Form1->count_level1)];
		while (S.find(codd) != S.end());
		break;
	case 2:
		do
			codd = Form1->numb_quest2[random(Form1->count_level2)];
		while (S.find(codd) != S.end());
		break;
	case 3:
		do
			codd = Form1->numb_quest3[random(Form1->count_level3)];
		while (S.find(codd) != S.end());
		break;
	}
	DataModule1->ADOQuery_quest->Active=false;
	DataModule1->ADOQuery_quest->Parameters->ParamByName("p")->Value = codd;
	DataModule1->ADOQuery_quest->Active=true;
	S.insert(codd);
	DataModule1->ADOTable_answ->Active=false;
	DataModule1->ADOTable_answ->Active=true;
	DataModule1->ADOTable_answ->First();

	for (int i = 0; i < 4; i++) {
	panel_on_off(panel[i],false);
	panel[i]->Caption = DataModule1->ADOTable_answ->FieldByName("answer")->AsString;
	if(DataModule1->ADOTable_answ->FieldByName("true_answ")->AsBoolean==true) {otv=i;}
	DataModule1->ADOTable_answ->Next();
	}
	lv++;
}


void __fastcall TForm2::ButtonGiveAnswClick(TObject *Sender)
{

if (for_button==-1){
ShowMessage("Выберите вариант ответа.");return;
}
	if(lv>15) {
	Form5 = new TForm5(this);
	Form5->Show();
	Close();
	return;
	}


if (otv!=for_button) {
if(ButtonMakeMistk->Tag == 1){
ButtonMakeMistk->Tag = 2;
pr_err=for_button;
panel[for_button]->Color=clRed;
ShowMessage("Ответ не верный.\nПопробуйте ещё раз.");
return;
} else{
    panel[otv]->Color=clLime;
	panel[for_button]->Color=clRed;
	Form3 = new TForm3(this);
	Form3->Left=this->Left+this->Width/2-Form3->Width/2;
	Form3->Top=this->Top+380;
	Form3->ShowModal();
	return;
}
}
else{
if(ButtonMakeMistk->Tag == 2) ButtonMakeMistk->Tag = 0;
panel[otv]->Color=clLime;
ShowMessage("                                              Верно!!!");
if (lv-2==Form4->nesgor_index) {
ShowMessage("                                         Поздравляю!!!\n                        Вы выиграли несгораемую сумму.");
}
 if(lv<=5) quest(1);
	else if(lv > 5 && lv <=10) quest(2);
	else quest(3);
}

ListBoxLevel->ItemIndex--;
ListBoxLevel->Refresh();
if(lv>2)ButtonTakeMoney->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::FormActivate(TObject *Sender)
{
	lv=1;
	quest(lv);
    podskazki=0;
	ListBoxLevel->ItemIndex = 14;
	question->Width=569;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button50_50Click(TObject *Sender)
{
 int ind,ind2;

 do ind = random(4);
 while (ind==otv);

 panel[ind]->Visible = false;

 do ind2 = random(4);
  while (ind2==otv || ind2==ind);

 panel[ind2]->Visible = false;
 podskazki++;
 Button50_50->Enabled = false;
   if(podskazki>2) {
		Button50_50->Enabled = false;
		ButtonHelpComput->Enabled = false;
		ButtonMakeMistk->Enabled = false;
		ButtonNewQuest->Enabled = false;
	}
	Button50_50->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::answer1Click(TObject *Sender)
{
TPanel *pan=(TPanel*)Sender;
for (int i = 0; i < 4; i++) {
if (ButtonMakeMistk->Tag == 2 && i==pr_err) {
   panel[i]->Color = clRed;
}  else
	if (CompareText(pan->Name,panel[i]->Name)==0) {
	 panel_on_off(panel[i],true);
	 for_button = i;
	}
	else{
	 panel_on_off(panel[i],false);
	}
}

}
//---------------------------------------------------------------------------

void TForm2::panel_on_off(TPanel *panel, boolean flag){

if (flag) {
	panel->BevelInner = bvLowered;
	panel->BevelKind = bkFlat;
	panel->BevelOuter = bvLowered;
	panel->BevelWidth = 2;
	panel->Color = (TColor)RGB (217, 158, 20);
}
 else{
	panel->BevelInner = bvNone;
	panel->BevelKind = bkNone;
	panel->BevelOuter = bvRaised;
	panel->BevelWidth = 1;
	panel->Color = clBtnFace;
}
}

void __fastcall TForm2::ButtonNewQuestClick(TObject *Sender)
{   if(lv<5) quest(1);
	else if(lv >= 5 && lv <=10) quest(2);
	else quest(3);
	podskazki++;
   if(podskazki>2) {
		Button50_50->Enabled = false;
		ButtonHelpComput->Enabled = false;
		ButtonMakeMistk->Enabled = false;
		ButtonNewQuest->Enabled = false;
	}
	else ButtonNewQuest->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm2::ButtonHelpComputClick(TObject *Sender)
{
	randomize();
	int a;
	do a = random(4);
	while(a==otv);

	int res = random(2);
	if(res == 0) panel[otv]->Color = clAqua;
	else panel[a]->Color = clAqua;
	ButtonHelpComput->Enabled = false;
    podskazki++;
   if(podskazki>2) {
		Button50_50->Enabled = false;
		ButtonHelpComput->Enabled = false;
		ButtonMakeMistk->Enabled = false;
		ButtonNewQuest->Enabled = false;
	}
	else ButtonHelpComput->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ButtonMakeMistkClick(TObject *Sender)
{
   ButtonMakeMistk->Tag = 1;
   podskazki++;
   if(podskazki>2) {
		Button50_50->Enabled = false;
		ButtonHelpComput->Enabled = false;
		ButtonMakeMistk->Enabled = false;
		ButtonNewQuest->Enabled = false;
	}
	else ButtonMakeMistk->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::ButtonTakeMoneyClick(TObject *Sender)
{
	if(MessageDlg("Вы уверены, что хотите забрать деньги?",mtConfirmation, TMsgDlgButtons() << mbYes << mbNo,0) == mrYes) {
	 ShowMessage("Ваш выигрыш составил: "+IntToStr(Form1->priz_mas[lv-3])+" руб.");
	  Form1->Visible = true;
	  Close();
	}
	else return;

}
//---------------------------------------------------------------------------


void __fastcall TForm2::ListBoxLevelDrawItem(TWinControl *Control, int Index, TRect &Rect,
          TOwnerDrawState State)
{
	if (Index  == 14-Form4->nesgor_index)
	  ListBoxLevel->Canvas->Brush->Color = clLime;
	  else if (Index  == ListBoxLevel->ItemIndex) ListBoxLevel->Canvas->Brush->Color = clTeal;
	  else ListBoxLevel->Canvas->Brush->Color = clNavy;
	ListBoxLevel->Canvas->FillRect(Rect);
	ListBoxLevel->Canvas->TextOut(Rect.Left + 2, Rect.Top, ListBoxLevel->Items->Strings[Index]);

}
//---------------------------------------------------------------------------


