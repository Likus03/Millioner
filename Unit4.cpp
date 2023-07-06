//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm4::BitBtnStartClick(TObject *Sender)
{
	if(RadioGroupNesgorSum->ItemIndex != -1){
		nesgor_index = 13-RadioGroupNesgorSum->ItemIndex;
		Form2 = new TForm2(this);
		Form2->Show();
		Close();
	}
	else ShowMessage("Выберите несгораемую сумму");
}
//---------------------------------------------------------------------------


