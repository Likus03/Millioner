//---------------------------------------------------------------------------

#ifndef mod_dannH
#define mod_dannH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
//---------------------------------------------------------------------------
class TDataModule1 : public TDataModule
{
__published:	// IDE-managed Components
	TDataSource *DataSource1;
	TADOQuery *ADOQuery_quest;
	TADOTable *ADOTable_answ;
	TADOConnection *ADOConnection1;
	TDataSource *DataSource2;
	TADOQuery *ADOQuery_mas;
private:	// User declarations
public:		// User declarations
	__fastcall TDataModule1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDataModule1 *DataModule1;
//---------------------------------------------------------------------------
#endif
