//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.FMTBcd.hpp>
#include <Data.SqlExpr.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBCtrls.hpp>
#include <Vcl.Mask.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonPlay;
	TButton *ButtonExit;
	TImage *Image1;
	TImage *Image2;
	void __fastcall ButtonPlayClick(TObject *Sender);
	void __fastcall ButtonExitClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
int priz_mas[15];
int numb_quest1[200]; //массив для вопросов первого уровня
int numb_quest2[200]; //массив для вопросов второго уровня
int numb_quest3[200]; //массив для вопросов третьего уровня
int count_level1;   //счетчик для количества вопросов первого уровня
int count_level2;   //счетчик для количества вопросов второго уровня
int count_level3;   //счетчик для количества вопросов третьего уровня
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
