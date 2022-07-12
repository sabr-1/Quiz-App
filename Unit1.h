//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Question;
	TRadioButton *Option1;
	TRadioButton *Option2;
	TRadioButton *Option3;
	TLabel *Points;
	TLabel *actualPoints;
	TButton *Submit;
	TLabel *DevelopedBy;
	void __fastcall Option1Change(TObject *Sender);
	void __fastcall Option2Change(TObject *Sender);
	void __fastcall Option3Change(TObject *Sender);
	void __fastcall SubmitClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
