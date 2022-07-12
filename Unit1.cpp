//---------------------------------------------------------------------------

#include <fmx.h>
#include<queue>

#pragma hdrstop


#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TForm1 *Form1;
class Question{
	public:
		String question;
		String option1;
		String option2;
		String option3;
		String correctAnswer;

		Question(){
		}

		Question(String q,String o1,String o2,String o3,String ans){

			question=q;
			option1=o1;
			option2=o2;
			option3=o3;
			correctAnswer=ans;

		}


};

std::queue<Question> questions;
Question currentQuestion;
int points=0;
int selectedOption;

std::queue<Question> loadQuestions(){
	Question q1("Who invented C++?","Dennis Ritchie","Brian Kernighan","Bjarne Stroustrup",3);
	Question q2("What is C++?","C++ supports both procedural and object oriented programming","C++ is a procedural programming language","C++ is an object oriented programming language",1);
	Question q3("Which of the following is the correct syntax of including a user defined header files in C++?","#include <userdefined.h>","#include <userdefined>"," #include “userdefined”",3);
	Question q4("Which of the following is used for comments in C++?","/* comment */","// comment","both // comment or /* comment */",3);
	Question q5("Which of the following type is provided by C++ but not C?","double","bool","int",2);
	Question q6("Which of the following symbol is used to declare the preprocessor directives in C++?","#","$","%",1);
	Question q7("Which of the following feature is not provided by C?","Structures","References","Pointers",2);
	Question q8("What is the best case for linear search?","O(logn)","O(n)","O(1)",3);
	Question q9("What is the worst case for linear search?","O(n)","O(logn)","O(1)",1);
	Question q10("In what manner is a state-space tree for a backtracking algorithm constructed?","Depth-first search","Breadth-first search","Nearest neighbour first",1);

	std::queue<Question> questionSet;
	questionSet.push(q1);
	questionSet.push(q2);
	questionSet.push(q3);
	questionSet.push(q4);
	questionSet.push(q5);
	questionSet.push(q6);
	questionSet.push(q7);
	questionSet.push(q8);
	questionSet.push(q9);
	questionSet.push(q10);

	return questionSet;

}



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	questions=loadQuestions();
	currentQuestion=questions.front();

	Question->Text=currentQuestion.question;
	Option1->Text=currentQuestion.option1;
	Option2->Text=currentQuestion.option2;
	Option3->Text=currentQuestion.option3;

	actualPoints->Text=points;

	questions.pop();


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Option1Change(TObject *Sender)
{
		selectedOption=1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Option2Change(TObject *Sender)
{
		selectedOption=2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Option3Change(TObject *Sender)
{
        selectedOption=3;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::SubmitClick(TObject *Sender)
{
		if(selectedOption==currentQuestion.correctAnswer){
			points++;
            actualPoints->Text=points;
		}

		Option1->IsChecked=false;
		Option2->IsChecked=false;
		Option3->IsChecked=false;


		if(!questions.empty()){
			   currentQuestion=questions.front();

               Question->Text=currentQuestion.question;
			   Option1->Text=currentQuestion.option1;
			   Option2->Text=currentQuestion.option2;
			   Option3->Text=currentQuestion.option3;



			   questions.pop();
		}else{
			 Submit->Enabled=false;

			 Submit->Text="Quiz Over";
        }
}
//---------------------------------------------------------------------------
