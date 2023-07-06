//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TDBText *question;
	TButton *ButtonGiveAnsw;
	TButton *Button50_50;
	TButton *ButtonHelpComput;
	TButton *ButtonMakeMistk;
	TButton *ButtonNewQuest;
	TPanel *answer1;
	TPanel *answer2;
	TPanel *answer3;
	TPanel *answer4;
	TListBox *ListBoxLevel;
	TButton *ButtonTakeMoney;
	TImage *Image1;
	void __fastcall ButtonGiveAnswClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall Button50_50Click(TObject *Sender);
	void __fastcall answer1Click(TObject *Sender);
	void __fastcall ButtonNewQuestClick(TObject *Sender);
	void __fastcall ButtonHelpComputClick(TObject *Sender);
	void __fastcall ButtonMakeMistkClick(TObject *Sender);
	void __fastcall ButtonTakeMoneyClick(TObject *Sender);
	void __fastcall ListBoxLevelDrawItem(TWinControl *Control, int Index, TRect &Rect, TOwnerDrawState State);
private:	// User declarations
	void quest(int p);
	void panel_on_off(TPanel *panel, boolean flag);
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
	int lv;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
