//---------------------------------------------------------------------------

#ifndef Main_moduleH
#define Main_moduleH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>

#include "ftd2xx.h"
#include <ComCtrls.hpp>
//#include "vcl/dstring.h"

#include <IniFiles.hpp>

#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Chart.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Series.hpp>
#include <Grids.hpp>
#include <Dialogs.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components

        TChart *Chart1;
        TLineSeries *Series1;

        TOpenDialog *OpenDialog1;
        TSaveDialog *SaveDialog1;

        TStringGrid *StringGrid1;

        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;

        TScrollBar *ScrollBar1;        
        TScrollBar *ScrollBar2;
        TScrollBar *ScrollBar4;
        TScrollBar *ScrollBar6;
        TScrollBar *ScrollBar7;

        TTrackBar *TrackBar1;
        TTrackBar *TrackBar2;
        TTrackBar *TrackBar3;
        TTrackBar *TrackBar4;
        TTrackBar *TrackBar5;
        TTrackBar *TrackBar6;

        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TGroupBox *GroupBox3;
        TGroupBox *GroupBox4;
        TGroupBox *GroupBox5;
        TGroupBox *GroupBox6;
        TGroupBox *GroupBox8;
        TGroupBox *GroupBox12;

        TCheckBox *CheckBox2;
        TCheckBox *CheckBox3;
        TCheckBox *CheckBox4;
        TCheckBox *CheckBox5;
        TCheckBox *CheckBox7;
        TCheckBox *CheckBox9;

        TRadioGroup *RadioGroup1;
        TRadioGroup *RadioGroup3;
        TRadioGroup *RadioGroup4;

        TPanel *Panel2;
        TPanel *Panel3;
        TPanel *Panel4;
        TPanel *Panel5;
        TPanel *Panel6;
        TPanel *Panel8;
        TPanel *Panel9;
        TPanel *Panel10;
        TPanel *Panel11;
        TPanel *Panel12;
        TPanel *Panel13;
        TPanel *Panel14;
        TPanel *Panel15;
        TPanel *Panel16;
        TPanel *Panel17;
        TPanel *Panel18;
        TPanel *Panel19;
        TPanel *Panel20;
        TPanel *Panel21;
        TPanel *Panel22;
        TPanel *Panel29;
        TPanel *Panel30;
        TPanel *Panel31;
        TPanel *Panel32;
        TPanel *Panel35;
        TPanel *Panel36;
        TPanel *Panel37;
        TPanel *Panel38;
        TPanel *Panel39;
        TPanel *Panel40;
        TPanel *Panel41;
        TPanel *Panel42;
        TPanel *Panel43;
        TPanel *Panel44;
        TPanel *Panel45;
        TPanel *Panel46;
        TPanel *Panel47;
        TPanel *Panel48;
        TPanel *Panel49;
        TPanel *Panel54;
        TPanel *Panel55;

        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TButton *Button7;
        TButton *Button8;
        TButton *Button9;
        TButton *Button10;
        TButton *Button11;
        TButton *Button12;
        TButton *Button22;
        TButton *Button23;
        TButton *Button26;
        TButton *Button27;
        TButton *Button28;
        TButton *Button29;
        TButton *Button30;
        TButton *Button31;


        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormResize(TObject *Sender);

        void __fastcall Chart1DblClick(TObject *Sender);
        void __fastcall Chart1Scroll(TObject *Sender);
        void __fastcall Chart1Zoom(TObject *Sender);

        void __fastcall PageControl1Change(TObject *Sender);

        void __fastcall CheckBox2Click(TObject *Sender);
        void __fastcall CheckBox4Click(TObject *Sender);
        void __fastcall CheckBox5Click(TObject *Sender);
        void __fastcall CheckBox7Click(TObject *Sender);

        void __fastcall RadioGroup3Click(TObject *Sender);
        void __fastcall RadioGroup4Click(TObject *Sender);

        void __fastcall ScrollBar1Change(TObject *Sender);
        void __fastcall ScrollBar2Change(TObject *Sender);
        void __fastcall ScrollBar4Change(TObject *Sender);
        void __fastcall ScrollBar6Change(TObject *Sender);
        void __fastcall ScrollBar7Change(TObject *Sender);

        void __fastcall TrackBar1Change(TObject *Sender);
        void __fastcall TrackBar3Change(TObject *Sender);
        void __fastcall TrackBar2Change(TObject *Sender);
        void __fastcall TrackBar4Change(TObject *Sender);
        void __fastcall TrackBar5Change(TObject *Sender);
        void __fastcall TrackBar6Change(TObject *Sender);

        void __fastcall Panel4Click(TObject *Sender);
        void __fastcall Panel13Click(TObject *Sender);
        void __fastcall Panel35Click(TObject *Sender);

        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender); 
        void __fastcall Button22Click(TObject *Sender);
        void __fastcall Button23Click(TObject *Sender);
        void __fastcall Button26Click(TObject *Sender);
        void __fastcall Button27Click(TObject *Sender);
        void __fastcall Button28Click(TObject *Sender);
        void __fastcall Button29Click(TObject *Sender);
        void __fastcall Button30Click(TObject *Sender);
        void __fastcall Button31Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall RadioGroup1Click(TObject *Sender);


private:	// User declarations

public:		// User declarations
        __fastcall TForm1(TComponent* Owner);


// ���������������� ������� *************************************************

// ����� �����������

        // �������� ��������� ����� �����������
        void __fastcall FTStatContr1(AnsiString Ind);

        // ������ � ����������
        void __fastcall WriteFT1(AnsiString Ind,
                                 LPVOID lpBuffer,
		                 DWORD dwBytesToWrite);

        // ��������� ���������� �� �����������
        void __fastcall GetInfoFT1(unsigned char *pData,
                                   DWORD ToRead);



// ����� ���

        // ������� �������� ��������� ����� ���
        void __fastcall FTStatFPU(AnsiString Ind);

        // ������ � ���
        void __fastcall WriteFT2(AnsiString Ind,
                                 LPVOID lpBuffer,
		                 DWORD dwBytesToWrite);

        // ��������� ���������� �� ���
        void __fastcall GetInfoFT2(unsigned char *pData,
                                   DWORD ToRead);

// **************************************************************************

};

//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;

// ����� ********************************************************************

typedef unsigned char uchar;

TIniFile *Ini;                    // ������ TIniFile

#define buf_size 11               // ������ ������
#define afr_points 501            // ���-�� ����� ���
#define TryToRead 1000            // ���-�� ������� ������


int lev_[afr_points] = {0};       // ������ ��. �������� ������� ���
int freq_[afr_points] = {0};      // ������ ������ ���
int ADC[buf_size];                // ������� (���) ��� 12 ����.
uchar buf[32] = {0};              // ��� ������ ����� ������

// �������� ��� ��� ����������� �������� � ���������� ��������� 
int freq_test_[11] = {600, 650, 700, 750, 800, 850,
                      900, 950, 1000, 1050, 1100};
int lev_test_[11] = {10, 40, 250, 400, 700, 1000,
                     600, 500, 120, 50, 10};

// ��������� ���������� ��� ����������� ����������   
AnsiString Indicator1;

// ��������� ����������� ����������� ��������
TColor line_col_full = (TColor)0xA00000;
TColor points_col_full = (TColor)clWhite;
TColor background_col_full = (TColor)clBlack;
//TColor line_col_full = clRed;
int points_style = 3;
int points_size = 6;
int points_color = 5;
int line_width = 4;
int line_color = 5;
int background_color = 8;
bool points_check_on = false;
bool marks_check_on = false;
int graph_template = -1;
TColor cl;                                      
TBevelCut Bevel;
int form_edge = 15;

// ��������� ����������
bool Loop_Break_1;                // ����� �� ����� ������ ������
bool Loop_Break_2;                // ����� �� ����� ��������� ���

DWORD SleepInterv = 5;            // �������� Sleep(), ��
bool read_OK;                     // ������� ������ ������
int RFOn = 0;                     // ������� ������� ������ RF

// ��������� �������� ���������
int StartFreq;                    // ��������� �������
int StopFreq;                     // �������� �������
int Freq;                         // ������� �������

int FreqStep = 50;                // ��������� ���
int points_numb = 11;             // ���-�� �����
int points_graph = 11;
int points_graph1 = 11;

int meas_number = 0;              // ���-�� ��������� � ����� ��������� �����
int mean_value = 0;               // ������� �������� � ����� ��������� �����
float maxafr;                     // �������� ���
float minafr;                     // ������� ���
float flatness;                   // ��������������� ���
int noise1 = 0;                   // ������� ����


// ����� ����������� ********************************************************

FT_HANDLE ftHandle_Contrl;        // ���������� USB �����������
FT_STATUS ftStatus_Contrl;        // ��������� USB �����������

// ���. ����� USB �����������
AnsiString Controller_Name;
const AnsiString Controller_Name1 = "CTRL0001";
const AnsiString Controller_Name2 = "CTRL0002";

DWORD BWritten;                   // ���� ��������
DWORD BReturned;                  // ���� ���������
DWORD RxBytes;                    // ���� � ������ ������

// ����� �� � ������������ **************************************************

// �������
uchar freq_set[3];                // ���� ��������� ������� �����������
const uchar Sync_Freq = 0x85;     // ���������� �����
int freq_s;                       // ��������������� �������
// ����
uchar freq_get[3];                // ���� � ����������� � �������
int freq_fact = 1500;             // ����������� �������


// ���. ������� �����������
uchar pow_set[2];                 // ���� ��������� ���. ������ �����������
const uchar Sync_Pow = 0x89;      // ���������� �����
uchar pow_s;                      // ��������������� �������
uchar pow_Bar;                    // ��������� ������ ������
const uchar pow_m4 = 0x01;        // ����� 4 ���
const uchar pow_m1 = 0x02;        // ����� 1 ���
const uchar pow_p2 = 0x04;        // ���� 2 ���
const uchar pow_p5 = 0x08;        // ���� 5 ���
const uchar pow_on = 0x81;        // ����� ���
const uchar pow_off = 0x80;       // ����� ����
// ����
uchar pow_get[2];                 // ���� � ����������� �� ���������
uchar pow_fact=0x08;              // ����������� ���������


// ���������
uchar modul_set[2];               // ���� ��������� ���������� ���������
const uchar Sync_Modul = 0x91;    // ���������� �����
uchar modul_s;                    // ������� ��������
int modul_Bar;                    // ��������� ������ ������� ���������
const uchar modul_off_1 = 0x10;   // ��������� ���� ���������� ������ (�=1)
const uchar modul_off_0 = 0x99;   // ��������� ���� ���������� ������ (�=0)
const uchar modul_on = 0x21;      // ��������� ���
// ����
uchar modul_get[2];               // ���� � ����������� � ���������
uchar modul_fact=0x99;            // ����. ��������� ����������


// ������ ����������
uchar Param_Req[2];               // ���� ������� ����������
const uchar Sync_Req = 0xA1;      // ���������� �����
const uchar Ampl_Req = 0x41;      // ������ ���������
const uchar Freq_Req = 0x42;      // ������ �������
const uchar Modul_Req = 0x44;     // ������ ��������� ����������  

// ����� ��� ****************************************************************

FT_HANDLE ftHandle_FPU;           // ���������� USB ���
FT_STATUS ftStatus_FPU;           // ��������� USB ���

// ���. ����� USB ���, �� �� �������� �����
AnsiString FPU_Name;
const AnsiString FPU_Name1="625000";
const AnsiString FPU_Name2="115200";

DWORD BWritten2;                  // ���� ��������
DWORD BReturned2;                 // ���� ���������
DWORD RxBytes2;                   // ���� � ������ ������

// ����� �� � ��� ***********************************************************

uchar ADC_FPU_Get[2];             // ���� ������� �������� (����� ���) ���
const uchar ADC_FPU_sync = 0xC0;  // ���������� �����
const uchar ADC_FPU_10 = 0x21;    // ������ 10 �������� ���
const uchar ADC_FPU_100 = 0x22;   // ������ 100 �������� ���

unsigned long SleepInterv2 = 50;  // �������� Sleep() ���
const int ADC_FPU_buf_size = 10;  // ���-�� �������� ��� �� ���� �����


uchar Amp_Ku_Set[2];              // ���� ��������� ��
const uchar Ku_sync = 0x81;       // ���������� �����
const uchar Ku_set_1 = 0x10;      // �� = 1
const uchar Ku_set_2 = 0x11;      // �� = 2
const uchar Ku_set_5 = 0x12;      // �� = 5
const uchar Ku_set_10 = 0x14;     // �� = 10

uchar Amp_Ku_Get[2];              // ���� ������������� ��������� ��
AnsiString Ku_str;                       

//---------------------------------------------------------------------------------------
#endif

