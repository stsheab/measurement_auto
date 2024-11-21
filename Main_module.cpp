//---------------------------------------------------------------------------

#include <vcl.h>
#include <fstream.h>
#include <iomanip.h>
#include <math.h>                 
#pragma hdrstop

#include "Main_module.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}



// Действия при запуске приложения ------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{

        PageControl1->TabIndex = 0;
        TabSheet1->Visible = true;
        TabSheet2->Visible = false;

        ScrollBar4->Enabled = false;

        // шапка таблицы
        StringGrid1->Cells[0][0] = " №";
        StringGrid1->Cells[1][0] = "data";
                                                                                
        StartFreq = ScrollBar6->Position;
        StopFreq = ScrollBar7->Position;
        Panel19->Caption = StartFreq;
        Panel21->Caption = StopFreq;

        Chart1->BottomAxis->Maximum = StopFreq;
        Chart1->BottomAxis->Minimum = StartFreq;
        Chart1->LeftAxis->Logarithmic = true;
        Series1->Clear();
        
        FreqStep = ScrollBar1->Position;  
        Panel32->Caption = FreqStep;
        points_numb = (StopFreq - StartFreq)/FreqStep + 1;
        Panel31->Caption = points_numb;

        freq_s = 850;

        pow_set[1] = pow_on;
        
        Panel12->Color = clBlue;
        Panel12->BevelOuter = bvLowered;

        // файл конфигурации графика
        Ini = new TIniFile(ExtractFilePath(Application->ExeName)+
                                                        "aoconfig.ini");

        points_check_on = Ini->ReadBool("Graph","PointsOn",false);
        marks_check_on = Ini->ReadBool("Graph","MarksOn",false);
        points_style = Ini->ReadInteger("Graph","PointStyle",5);
        points_size = Ini->ReadInteger("Graph","PointSize",8);
        points_color = Ini->ReadInteger("Graph","PointColor",5);
        line_width = Ini->ReadInteger("Graph","LineWidth",5);
        line_color = Ini->ReadInteger("Graph","LineColor",5);
        background_color = Ini->ReadInteger("Graph","BackgroundColor",8);
                                        

        for (int i=0; i<points_graph; i++){
                Series1->AddXY(600+50*i, 1, "");     
        }
        
        CheckBox4->Checked = points_check_on;
        CheckBox5->Checked = marks_check_on;

        TrackBar1->Position = points_style;
        TrackBar1Change(Sender);

        TrackBar2->Position = points_size;
        TrackBar2Change(Sender);

        TrackBar3->Position = points_color;
        TrackBar3Change(Sender);

        TrackBar4->Position = line_width;
        TrackBar4Change(Sender);

        TrackBar5->Position = line_color;
        TrackBar5Change(Sender);

        TrackBar6->Position = background_color;
        TrackBar6Change(Sender);


        ADC_FPU_Get[1] = ADC_FPU_10;


        // адаптивность при создании формы
        Chart1->Width = Form1->Width-StringGrid1->Width-GroupBox1->Width-
                                                                form_edge;
        Chart1->Height = Form1->Height-Panel3->Height*2-GroupBox4->Height;
        StringGrid1->Left = Form1->Width-StringGrid1->Width-GroupBox1->Width-
                                                                form_edge;
        StringGrid1->Height = Chart1->Height;
        Button6->Left = Form1->Width-Button6->Width-GroupBox1->Width-
                                                                form_edge;
        Button6->Top = StringGrid1->Height;

        GroupBox1->Left = Form1->Width-GroupBox1->Width-form_edge;
        PageControl1->Left = Form1->Width-GroupBox1->Width-form_edge;
        PageControl1->Top = GroupBox1->Height-5;
        Panel3->Top = Form1->Height-Panel3->Height*2;
        Panel3->Width = Form1->Width-form_edge;
        GroupBox4->Top = Form1->Height-Panel3->Height*2-GroupBox4->Height;
        GroupBox4->Width = Chart1->Width;

}

// адаптивность при изменении размеров --------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
        Chart1->Width = Form1->Width-StringGrid1->Width-GroupBox1->Width-
                                                                form_edge;
        Chart1->Height = Form1->Height-Panel3->Height*2-GroupBox4->Height;
        StringGrid1->Left = Form1->Width-StringGrid1->Width-GroupBox1->Width-
                                                                form_edge;
        StringGrid1->Height = Chart1->Height;
        Button6->Left = Form1->Width-Button6->Width-GroupBox1->Width-
                                                                form_edge;
        Button6->Top = StringGrid1->Height;

        GroupBox1->Left = Form1->Width-GroupBox1->Width-form_edge;
        PageControl1->Left = Form1->Width-GroupBox1->Width-form_edge;
        PageControl1->Top = GroupBox1->Height-5;
        Panel3->Top = Form1->Height-Panel3->Height*2;
        Panel3->Width = Form1->Width-form_edge;
        GroupBox4->Top = Form1->Height-Panel3->Height*2-GroupBox4->Height;
        GroupBox4->Width = Chart1->Width;
}

// действия по показу формы -------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
        // инициализация платы управления (контроллера)
        Button2Click(Sender);
        // инициализация платы ФПУ
        Button8Click(Sender);
        // загрузка тестовой АЧХ
        Button4Click(Sender);
}

// действия по закрытию приложения ------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender,
                                  TCloseAction &Action)
{                        
        delete Ini;
        Ini = NULL;

        if (!Button27->Enabled) {
                Application->MessageBoxA("Остановите сбор данных", "", MB_OK);
                Action = caNone;
                return;
        }

        if (!Button9->Enabled) {
                Application->MessageBoxA("Остановите свипирование", "", MB_OK);
                Action = caNone;
                return;
        }

        // закрываем платы
        FT_Close(ftHandle_Contrl);
        FT_Close(ftHandle_FPU);
}                                    

// функция контроля состояния порта ФПУ -------------------------------------
void __fastcall TForm1::FTStatFPU(AnsiString Ind)
{
        if (ftStatus_FPU == FT_OK) {

                Indicator1 = Ind;
                Panel14->Font->Color = clBlue;
        }

        else  {
                Panel14->Font->Color = clRed;

                switch (ftStatus_FPU) {

                        case FT_INVALID_HANDLE:
                                Indicator1 = "неверный дескриптор";
                                break;

                        case FT_DEVICE_NOT_FOUND:
                                Indicator1 = "устройство не найдено";
                                break;

                        case FT_DEVICE_NOT_OPENED:
                                Indicator1 = "невозможно открыть";
                                break;

                        default:
                                Indicator1 = "ошибка открытия";
                }
        }

        Panel14->Caption = Indicator1;
} 

// получение информации от ФПУ ----------------------------------------------
void __fastcall TForm1::GetInfoFT2(unsigned char *pData,
                                   DWORD ToRead)
{
        Loop_Break_1 = false;
        //int i=0;
        Sleep(SleepInterv);

        do {
                /*
                if (i>TryToRead) {
                        Panel14->Font->Color = clRed;
                        Panel14->Caption = "Превышен интервал чтения";
                        break;
                }     */

                //Sleep(SleepInterv);

                // проверяем приёмный буфер на наличие данных
                FT_GetQueueStatus(ftHandle_FPU,&RxBytes2);

                Application->ProcessMessages(); 
                //i++;

                if (RxBytes2 > 0) {

                        ftStatus_FPU = FT_Read(ftHandle_FPU,
                                               pData,
                                               ToRead,
                                               &BReturned2);

                        if (ftStatus_FPU != FT_OK) {
                                Panel14->Font->Color = clRed;
                                Panel14->Caption = "ошибка чтения";
                                continue;
                        }
                }

                else {
                        Panel14->Font->Color = clRed;
                        Panel14->Caption = "буфер пуст";
                        continue;
                } 
        
                Panel14->Font->Color = clBlue;
                Panel14->Caption = "OK";
                break;
        }
        while (!Loop_Break_1);
}

// запись в плату ФПУ -------------------------------------------------------
void __fastcall TForm1::WriteFT2(AnsiString Ind,
                                 LPVOID lpBuffer,
		                 DWORD dwBytesToWrite)
{
        ftStatus_FPU =
                FT_Write(ftHandle_FPU,
                         lpBuffer,
                         dwBytesToWrite,
                         &BWritten2);

        if (ftStatus_FPU != FT_OK) {
                Panel14->Font->Color = clRed;
                Panel14->Caption = Ind;
                return;
        }
}

// инициализация ФПУ --------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
        FPU_Name = FPU_Name1;
        
        ftStatus_FPU =
                FT_OpenEx((void*)FPU_Name.c_str(),
                           FT_OPEN_BY_SERIAL_NUMBER,
                           &ftHandle_FPU);
                           
        FTStatFPU("ФПУ подключено");
        
        if (ftStatus_FPU != FT_OK) {
                FPU_Name = FPU_Name2;
                ftStatus_FPU =
                        FT_OpenEx((void*)FPU_Name.c_str(),
                                   FT_OPEN_BY_SERIAL_NUMBER,
                                   &ftHandle_FPU);
                FTStatFPU("ФПУ OK");
        }
        
        if (ftStatus_FPU != FT_OK) {

                Application->MessageBoxA("Подключите ФПУ", "", MB_OK);
                return;
        }

        Panel16->Caption = FPU_Name;

        // Задаем формат данных
        ftStatus_FPU =
                FT_SetDataCharacteristics(ftHandle_FPU,
                                          FT_BITS_8,
                                          FT_STOP_BITS_1,
                                          FT_PARITY_NONE);
                                          
        if(ftStatus_FPU != FT_OK) {
                Panel14->Font->Color = clRed;
                Panel14->Caption = "Ошибка параметров ФПУ";
                return;
        }

        // Задаем скорость порта ФПУ
        ftStatus_FPU =
                FT_SetBaudRate(ftHandle_FPU,
                               StrToInt(FPU_Name));

        if(ftStatus_FPU != FT_OK) {
                Panel14->Font->Color = clRed;
                Panel14->Caption = "BaudRate error";
                return;
        }    

        // Очищаем FT2   
        ftStatus_FPU =
                FT_Purge(ftHandle_FPU, FT_PURGE_RX | FT_PURGE_TX); 
        if (ftStatus_FPU != FT_OK) {
                Panel14->Font->Color = clRed;
                Panel14->Caption = "ошибка очистки";
        }
}

// сбрасываем ФПУ -----------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{
       ftStatus_FPU = FT_ResetDevice(ftHandle_FPU);
       FTStatFPU("ФПУ сброшено");
}

// закрываем порт ФПУ -------------------------------------------------------
void __fastcall TForm1::Button12Click(TObject *Sender)
{
       ftStatus_FPU = FT_Close(ftHandle_FPU);
       FTStatFPU("ФПУ закрыто");
}        

// контроль состояния порта платы контроллера -------------------------------
void __fastcall TForm1::FTStatContr1(AnsiString Ind)
{

        if (ftStatus_Contrl == FT_OK) {
                Indicator1 = Ind;
                Panel29->Font->Color = clBlue;
        }

        else {
                Panel29->Font->Color = clRed;

                switch (ftStatus_Contrl) {
                
                        case FT_INVALID_HANDLE:
                                Indicator1 = "неверный дескриптор";
                                break;
                        case FT_DEVICE_NOT_FOUND:
                                Indicator1 = "устройство не найдено";
                                break;
                        case FT_DEVICE_NOT_OPENED:
                                Indicator1 = "невозможно открыть";
                                break;
                        default:
                                Indicator1 = "ошибка открытия";
                                break;
                }
        }

        Panel29->Caption = Indicator1;
}

// получение информации от платы контроллера --------------------------------
void __fastcall TForm1::GetInfoFT1(unsigned char *pData,
                                   DWORD ToRead)
{

        Loop_Break_1 = false;
        //int i=0;
        Sleep(SleepInterv);

        do {
                /*
                if (i>TryToRead) {
                        Panel29->Font->Color = clRed;
                        Panel29->Caption = "Превышен интервал чтения";
                        break;
                }     */

                //Sleep(SleepInterv);

                // проверяем приёмный буфер на наличие данных
                FT_GetQueueStatus(ftHandle_Contrl,&RxBytes);

                Application->ProcessMessages(); 
                //i++;

                if (RxBytes > 0) {

                        ftStatus_Contrl = FT_Read(ftHandle_Contrl,
                                               pData,
                                               ToRead,
                                               &BReturned2);

                        if (ftStatus_Contrl != FT_OK) {
                                Panel29->Font->Color = clRed;
                                Panel29->Caption = "ошибка чтения";
                                continue;
                        }
                }

                else {      
                        Panel29->Font->Color = clRed;
                        Panel29->Caption = "буфер пуст";
                        continue;
                } 
        
                Panel29->Font->Color = clBlue;
                Panel29->Caption = "OK";
                break;
        }
        while (!Loop_Break_1);
}

// запись в плату контроллера -----------------------------------------------
void __fastcall TForm1::WriteFT1(AnsiString Ind,
                                 LPVOID lpBuffer,
                                 DWORD dwBytesToWrite)
{

        ftStatus_Contrl =
                FT_Write(ftHandle_Contrl,
                         lpBuffer,
                         dwBytesToWrite,
                         &BWritten);

        if (ftStatus_Contrl != FT_OK) {
                Panel29->Font->Color = clRed;
                Panel29->Caption = Ind;
                return;
        }
}

// инициализация платы контроллера ------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Controller_Name = Controller_Name1;

        ftStatus_Contrl =
                FT_OpenEx((void*)Controller_Name.c_str(),
                          FT_OPEN_BY_SERIAL_NUMBER,
                          &ftHandle_Contrl);

        FTStatContr1("Контроллер подключен");

        if (ftStatus_Contrl != FT_OK) {

                Controller_Name = Controller_Name2;
                ftStatus_Contrl =
                        FT_OpenEx((void*)Controller_Name.c_str(),
                                  FT_OPEN_BY_SERIAL_NUMBER,
                                  &ftHandle_Contrl);

                FTStatContr1("Контроллер подключен");
        }


        if (ftStatus_Contrl != FT_OK) {

                Application->MessageBoxA("Подключите контроллер",
                                         "",
                                         MB_OK);
                return;
        }

        Panel15->Caption = Controller_Name;

        // Задаем формат данных
        ftStatus_Contrl =
                FT_SetDataCharacteristics(ftHandle_Contrl,
                                          FT_BITS_8,
                                          FT_STOP_BITS_1,
                                          FT_PARITY_NONE);

        if(ftStatus_Contrl != FT_OK) {

                Panel29->Font->Color = clRed;
                Panel29->Caption = "Ошибка параметров порта платы контроллера";
                return;
        }

        // Задаем скорость порта контроллера
        ftStatus_Contrl =
                FT_SetBaudRate(ftHandle_Contrl,
                               115200);

        if(ftStatus_Contrl != FT_OK) {

                Panel29->Font->Color = clRed;
                Panel29->Caption = "BaudRate error";
                return;
        } 

        // Очищаем FT1
        ftStatus_Contrl = FT_Purge(ftHandle_Contrl,
                                   FT_PURGE_RX | FT_PURGE_TX);
        if (ftStatus_Contrl != FT_OK) {
                Panel29->Font->Color = clRed;
                Panel29->Caption = "ошибка очистки";
        }
}

// сброс платы контроллера --------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
       ftStatus_Contrl = FT_ResetDevice(ftHandle_Contrl);
       FTStatContr1("Контроллер сброшен");
}

// закрытие платы контроллера -----------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
       ftStatus_Contrl = FT_Close(ftHandle_Contrl);
       FTStatContr1("Контроллер закрыт");
}

// выход из зацикливания ----------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
       Loop_Break_1 = true;
}

// выбор частоты ------------------------------------------------------------
void __fastcall TForm1::ScrollBar2Change(TObject *Sender)
{

        freq_s = ScrollBar2->Position;
        Panel2->Caption = freq_s;
        
        if (CheckBox7->Checked) {
                Button5Click(Sender);
        }
}

// установка частоты без нажатия кнопки "установить" ------------------------
void __fastcall TForm1::CheckBox7Click(TObject *Sender)
{
        if (CheckBox7->Checked) {
                Button5->Enabled = false;
        }
        
        else Button5->Enabled = true;
}

// установить частоту -------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
        // 1. Очищаем FT1
        ftStatus_Contrl = FT_Purge(ftHandle_Contrl,
                                   FT_PURGE_RX | FT_PURGE_TX); 
        if (ftStatus_Contrl != FT_OK) {
                Panel29->Font->Color = clRed;
                Panel29->Caption = "ошибка очистки";
                return;
        }

        // 2. Отправляем команду
        freq_set[0] = Sync_Freq;
        freq_set[1] = (uchar)(freq_s&0x00FF);
        freq_set[2] = (uchar)((freq_s/256)&0x0F);

        WriteFT1("Ошибка записи", freq_set, sizeof(freq_set));
}

// запрос (контроль) текущей частоты в MCU ----------------------------------
void __fastcall TForm1::Panel4Click(TObject *Sender)
{
        // 1. Очищаем FT1
        ftStatus_Contrl = FT_Purge(ftHandle_Contrl,
                                   FT_PURGE_RX | FT_PURGE_TX);
        if (ftStatus_Contrl != FT_OK) {
                Panel29->Font->Color = clRed;
                Panel29->Caption = "ошибка очистки";
                return;
        }

        // 2. Отправляем запрос частоты
        Param_Req[0] = Sync_Req;
        Param_Req[1] = Freq_Req;

        WriteFT1("Ошибка записи",
                 Param_Req,
                 sizeof(Param_Req));
        
        // 3. Получаем информацию
        GetInfoFT1(freq_get, sizeof(freq_get));
                    
        // 4. Проверяем синхробайт кадра
        if (freq_get[0] != Sync_Freq) {
                Panel29->Font->Color = clRed;
                Panel29->Caption = "Ошибка кадра";
                return;
        }

        // 5. Утилизируем данные 
        freq_fact = (WORD)(freq_get[1]&0xFF)+(WORD)(freq_get[2]&0x0F)*256;

        Panel4->Caption = IntToStr(freq_fact) + " MHz";          
}

// запрос (контроль) текущего уровня синтезатора в MCU ----------------------
void __fastcall TForm1::Panel35Click(TObject *Sender)
{           
        // 1. Очищаем FT1
        ftStatus_Contrl = FT_Purge(ftHandle_Contrl,
                                   FT_PURGE_RX | FT_PURGE_TX);
        if (ftStatus_Contrl != FT_OK) {
                Panel29->Font->Color = clRed;
                Panel29->Caption = "ошибка очистки";
                return;
        }

        // 2. Отправляем запрос состояния выхода
        Param_Req[0] = Sync_Req;
        Param_Req[1] = Ampl_Req;

        WriteFT1("Ошибка записи",
                 Param_Req,
                 sizeof(Param_Req));

        // 3. Получаем информацию
        GetInfoFT1(pow_get,
                   sizeof(pow_get));
                    
        // 4. Проверяем синхробайт кадра
        if (pow_get[0] != Sync_Pow) {
                Panel29->Font->Color = clRed;
                Panel29->Caption = "Ошибка кадра";
                return;
        }

        // 5. Утилизируем данные 
        pow_fact = pow_get[1];
      
        switch (pow_fact) {

                case pow_off:
                        Panel35->Caption = "OFF";
                        Bevel = bvRaised;
                        cl = clRed;
                        break;

                case pow_p5:
                        Panel35->Caption = "ON";
                        Bevel = bvLowered;
                        cl = clBlue;
                        break;
        }                         
}

// RF on/off (вкл./выкл. выход синтезатора) ---------------------------------
void __fastcall TForm1::Button22Click(TObject *Sender)
{                       
        pow_set[0] = Sync_Pow;
        
        RFOn = RFOn+1;

        switch (RFOn%2) {

                case 0:  // RF ON
                        pow_set[1] = pow_on;
                        Panel12->Caption = "ON";
                        break;

                case 1:  // RF OFF
                        pow_set[1] = pow_off;
                        Panel12->Caption = "OFF";
                        break;
        }

        // 1. Очищаем FT1
        ftStatus_Contrl = FT_Purge(ftHandle_Contrl,
                                   FT_PURGE_RX | FT_PURGE_TX);  
        if (ftStatus_Contrl != FT_OK) {
                Panel29->Font->Color = clRed;
                Panel29->Caption = "ошибка очистки";
                return;
        }
        
        // 2. Отправляем команду
        WriteFT1("Ошибка записи",
                 pow_set,
                 sizeof(pow_set));
                  
        // 3. Индицируем
        pow_fact = pow_set[1];
      
        switch (pow_fact) {

                case pow_off:
                        Indicator1 = "OFF";
                        Bevel = bvRaised;
                        cl = clRed;
                        break;

                case pow_on:
                        Indicator1 = "ON";
                        Bevel = bvLowered;
                        cl = clBlue;
                        break;
        }

        Panel12->Caption = Indicator1;
        Panel12->Color = cl;
        Panel12->BevelOuter = Bevel; 

}

// Модуляция вкл/выкл -------------------------------------------------------
void __fastcall TForm1::RadioGroup3Click(TObject *Sender)
{                                                         
        switch (RadioGroup3->ItemIndex) {

                case 0:
                        ScrollBar4->Enabled = true;

                        if (ScrollBar4->Position == 10) {
                                ScrollBar4Change(Sender);
                        }
                        else {
                                ScrollBar4->Position = 10;
                        }
                        break;

                case 1:
                        ScrollBar4->Enabled = false;
                        modul_set[1] = modul_off_1;
                        Panel5->Caption = "Выкл.1";
                        goto wrt;

                case 2:
                        ScrollBar4->Enabled = false;
                        modul_set[1] = modul_off_0;
                        Panel5->Caption = "Выкл.0";
                        goto wrt;
        }

        return;

wrt:
        // 1. Очищаем FT1
        ftStatus_Contrl = FT_Purge(ftHandle_Contrl,
                                   FT_PURGE_RX | FT_PURGE_TX); 
        if (ftStatus_Contrl != FT_OK) {
                Panel29->Font->Color = clRed;
                Panel29->Caption = "ошибка очистки";
                return;
        }
         
        // 2. Отправляем команду
        modul_set[0] = Sync_Modul;
        WriteFT1("Ошибка записи",
                 modul_set,
                 sizeof(modul_set));  
}

// Модуляция (частота) ------------------------------------------------------
void __fastcall TForm1::ScrollBar4Change(TObject *Sender)
{
        modul_Bar = ScrollBar4->Position;

        if (modul_Bar <= 9) {

                modul_s = 0x10 + modul_Bar;
                Panel5->Caption = IntToStr(modul_Bar*100) + " Гц";
        }

        if (modul_Bar > 9 && modul_Bar <= 18) {

                modul_s = 0x20+modul_Bar-9;
                Panel5->Caption = IntToStr(modul_Bar-9) + " кГц";
        }

        if (modul_Bar == 19) {

                modul_s = 0x41;
                Panel5->Caption = "10 кГц";
        }

        // 1. Очищаем FT1
        ftStatus_Contrl = FT_Purge(ftHandle_Contrl,
                                   FT_PURGE_RX | FT_PURGE_TX);
        if (ftStatus_Contrl != FT_OK) {
                Panel29->Font->Color = clRed;
                Panel29->Caption = "ошибка очистки";
                return;
        }

        // 2. Отправляем команду
        modul_set[0] = Sync_Modul;
        modul_set[1] = modul_s;
        WriteFT1("Ошибка записи",
                 modul_set,
                 sizeof(modul_set));  
} 

// Модуляция (запрос параметров) --------------------------------------------
void __fastcall TForm1::Panel13Click(TObject *Sender)
{
        // 1. Очищаем FT1
        ftStatus_Contrl = FT_Purge(ftHandle_Contrl,
                                   FT_PURGE_RX | FT_PURGE_TX); 
        if (ftStatus_Contrl != FT_OK) {
                Panel29->Font->Color = clRed;
                Panel29->Caption = "ошибка очистки";
                return;
        }

        // 2. Отправляем запрос информации о параметрах модуляции
        Param_Req[0] = Sync_Req;
        Param_Req[1] = Modul_Req;

        WriteFT1("Ошибка записи",
                 Param_Req,
                 sizeof(Param_Req));

        // 3. Получаем информацию
        GetInfoFT1(modul_get,
                   sizeof(modul_get));

        // 4. Проверяем синхробайт кадра
        if (modul_get[0] != Sync_Modul) {
                Panel29->Font->Color = clRed;
                Panel29->Caption = "Ошибка кадра";
                return;
        }

        // 5. Утилизируем данные
        modul_fact = modul_get[1];

        switch (modul_fact) {

                case modul_off_1:
                        Panel13->Caption = "Выкл.1";
                        break;

                case modul_off_0:
                        Panel13->Caption = "Выкл.0";
                        break;

                case modul_on:
                        Panel13->Caption = "Вкл.";
                        break;
        }
}  

// Контроль всех параметров -------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        Panel4Click(Sender);
        Panel35Click(Sender);
        Panel13Click(Sender);
} 

// Нижняя частота измерений Fн ----------------------------------------------
void __fastcall TForm1::ScrollBar6Change(TObject *Sender)
{
        ScrollBar6->Position = ((ScrollBar6->Position)/50)*50;
        if ((ScrollBar6->Position) >= (ScrollBar7->Position)-50) {

                ScrollBar6->Position = (ScrollBar7->Position) - 100;
        }

        StartFreq = ScrollBar6->Position;
        Panel19->Caption = StartFreq;
        
        Chart1->BottomAxis->Automatic = false;
        Chart1->BottomAxis->Minimum = StartFreq;
               
        Freq = (StartFreq+StopFreq)/2;
        ScrollBar2->Position = Freq;

        // кол-во точек
        points_numb = (StopFreq - StartFreq)/FreqStep + 1;
        Panel31->Caption = points_numb;
}

// Верхняя частота измерений Fв ---------------------------------------------
void __fastcall TForm1::ScrollBar7Change(TObject *Sender)
{
        ScrollBar7->Position = ((ScrollBar7->Position)/50)*50;
        if ((ScrollBar7->Position) <= (ScrollBar6->Position)+50) {

                ScrollBar7->Position = (ScrollBar6->Position) + 100;
        }

        StopFreq = ScrollBar7->Position;
        Panel21->Caption = StopFreq;

        Chart1->BottomAxis->Automatic = false;
        Chart1->BottomAxis->Maximum = StopFreq;
        
        Freq = (StartFreq+StopFreq)/2;
        ScrollBar2->Position = Freq;

        // кол-во точек
        points_numb = (StopFreq - StartFreq)/FreqStep + 1;
        Panel31->Caption = points_numb;
}

// Частотный шаг ------------------------------------------------------------
void __fastcall TForm1::ScrollBar1Change(TObject *Sender)
{             
        ScrollBar1->Position = ((ScrollBar1->Position)/5)*5;
        FreqStep = ScrollBar1->Position;
        Panel32->Caption = FreqStep;

        // кол-во точек
        points_numb = (StopFreq - StartFreq)/FreqStep + 1;
        Panel31->Caption = points_numb;
}

// Отображение точек вкл./выкл. ---------------------------------------------
void __fastcall TForm1::CheckBox4Click(TObject *Sender)
{
        if (CheckBox4->Checked) {
                points_check_on = true;
        }
        else {
                points_check_on = false;
        }
        
        Ini->WriteBool("Graph","PointsOn", points_check_on);
        Series1->Pointer->Visible = points_check_on;
} 

// Стиль точек --------------------------------------------------------------
void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{

        points_style = TrackBar1->Position;
        Panel6->Caption = points_style;
        Ini->WriteInteger("Graph","PointStyle", points_style);

        switch (points_style) {

                case 1:
                        Series1->Pointer->Style = psRectangle;
                        break;

                case 2:
                        Series1->Pointer->Style = psCircle;
                        break;

                case 3:
                        Series1->Pointer->Style = psTriangle;
                        break;

                case 4:
                        Series1->Pointer->Style = psDownTriangle;
                        break;

                case 5:
                        Series1->Pointer->Style = psDiamond;
                        break;

          /*
                case 6:
                        Series1->Pointer->Style = psCross;
                        break;

                case 7:
                        Series1->Pointer->Style = psDiagCross;
                        break;

                case 8:
                        Series1->Pointer->Style = psStar;
                        break;

                case 9:
                        Series1->Pointer->Style = psSmallDot;
                        break;  */
        }
}

// Размер точек -------------------------------------------------------------
void __fastcall TForm1::TrackBar2Change(TObject *Sender)
{
        points_size = TrackBar2->Position;
        Panel17->Caption = points_size;
        Ini->WriteInteger("Graph","PointSize", points_size);
        Series1->Pointer->HorizSize = points_size;
        Series1->Pointer->VertSize = points_size;
}

// Цвет точек ---------------------------------------------------------------
void __fastcall TForm1::TrackBar3Change(TObject *Sender)
{

        points_color = TrackBar3->Position;
        Panel9->Caption = points_color;
        Ini->WriteInteger("Graph","PointColor", points_color);

        switch (points_color) {
           
                case 1:
                        points_col_full = clBlack; 
                        break;

                case 2:
                        points_col_full = clWhite;
                        break;

                case 3:
                        points_col_full = clRed;
                        break;

                case 4:
                        points_col_full = clBlue;
                        break;

                case 5:
                        points_col_full = (TColor)0xA00000;
                        break;

                case 6:
                        points_col_full = clGreen;
                        break;

                case 7:
                        points_col_full = clYellow;
                        break;

                case 8:
                        points_col_full = (TColor)0x80FFFF;
                        break;

                case 9:
                        points_col_full = clLtGray;
                        break;

                case 10:
                        points_col_full = clGray;
                        break;
        }

        Series1->Pointer->Brush->Color = points_col_full;
        Panel9->Color = points_col_full;                        
}

// Толщина линии ------------------------------------------------------------
void __fastcall TForm1::TrackBar4Change(TObject *Sender)
{
        line_width = TrackBar4->Position;
        Panel39->Caption = line_width;
        Ini->WriteInteger("Graph", "LineWidth", line_width);
        Series1->LinePen->Width = line_width;
}

// Цвет линии ---------------------------------------------------------------
void __fastcall TForm1::TrackBar5Change(TObject *Sender)
{

        line_color = TrackBar5->Position;
        Panel42->Caption = line_color;
        Ini->WriteInteger("Graph", "LineColor", line_color);

        switch (line_color) {

                case 1:
                        line_col_full = clBlack;
                        break;

                case 2:
                        line_col_full = clWhite;
                        break;

                case 3:
                        line_col_full = clRed;
                        break;

                case 4:
                        line_col_full = clBlue;
                        break;

                case 5:
                        line_col_full = (TColor)0xA00000;
                        break;

                case 6:
                        line_col_full = clGreen;
                        break;

                case 7:
                        line_col_full = clYellow;
                        break;

                case 8:
                        line_col_full = (TColor)0x80FFFF;
                        break;

                case 9:
                        line_col_full = clLtGray;
                        break;

                case 10:
                        line_col_full = clGray;
                        break;
        }

        Series1->LinePen->Color = line_col_full;
        Panel42->Color = line_col_full;

        for(int i=0; i<points_graph; i++) {
                Series1->ValueColor[i] = line_col_full;
        }
}

// Цвет фона ----------------------------------------------------------------
void __fastcall TForm1::TrackBar6Change(TObject *Sender)
{

        background_color = TrackBar6->Position;
        Panel43->Caption = background_color;
        Ini->WriteInteger("Graph","BackgroundColor",background_color);

        switch (background_color) {

                case 1:
                        background_col_full = clBlack;
                        break;

                case 2:
                        background_col_full = clWhite;
                        break;

                case 3:
                        background_col_full = clRed;
                        break;

                case 4:
                        background_col_full = clBlue;
                        break;

                case 5:
                        background_col_full = (TColor)0xA00000;
                        break;

                case 6:
                        background_col_full = clGreen;
                        break;

                case 7:
                        background_col_full = clYellow;
                        break;

                case 8:
                        background_col_full = (TColor)0x80FFFF;
                        break;

                case 9:
                        background_col_full = clLtGray;
                        break;

                case 10:
                        background_col_full = clGray;
                        break;
        }

        Chart1->BackWall->Color = background_col_full;
        Panel43->Color = background_col_full;
}

// Графические шаблоны ------------------------------------------------------
void __fastcall TForm1::RadioGroup4Click(TObject *Sender)
{

        switch (RadioGroup4->ItemIndex) {
        
                case 0:
                        graph_template = 0;
                        TrackBar3->Position = 1;
                        TrackBar5->Position = 1;
                        TrackBar6->Position = 2;
                        TrackBar4->Position = 5;
                        CheckBox4->Checked = false;
                        break;

                case 1:
                        graph_template = 1;
                        TrackBar3->Position = 1;
                        TrackBar5->Position = 2;
                        TrackBar6->Position = 2;
                        TrackBar4->Position = 1;
                        CheckBox4->Checked = true;
                        break;

                case 2:
                        graph_template = 2;
                        TrackBar3->Position = 2;
                        TrackBar5->Position = 2;
                        TrackBar6->Position = 1;
                        TrackBar4->Position = 5;
                        CheckBox4->Checked = false;
                        break;

                case 3:
                        graph_template = 3;
                        TrackBar3->Position = 2;
                        TrackBar5->Position = 1;
                        TrackBar6->Position = 1;
                        TrackBar4->Position = 1;
                        CheckBox4->Checked = true;
                        break;

                case 4:
                        graph_template = 4;
                        TrackBar3->Position = 5;
                        TrackBar4->Position = 5;
                        TrackBar5->Position = 5;
                        TrackBar6->Position = 8;
                        CheckBox4->Checked = false;
                        break;    
        }   
}

// Очистка отображаемой информации ------------------------------------------
void __fastcall TForm1::Button23Click(TObject *Sender)
{

        for(int i=0; i<sizeof(buf); i++) {
                buf[i] = 0;
                StringGrid1->Cells[0][i+1] = "";
                StringGrid1->Cells[1][i+1] = "";
        }

        Panel4->Caption = "";
        Panel13->Caption = "";
        Panel35->Caption = "";
        Panel47->Caption = "";
        Panel48->Caption = "";
        Panel49->Caption = "";
        
        Series1->Clear();        
}

// Открыть АЧХ --------------------------------------------------------------
void __fastcall TForm1::Button29Click(TObject *Sender)
{

        if(OpenDialog1->Execute()) {

                char* FileIn=(OpenDialog1->FileName).c_str();

                // открываем файл
                ifstream in2(FileIn);

                // считываем АЧХ
                points_graph1 = 0;

                do {

                        in2 >> freq_[points_graph1] >> lev_[points_graph1];
                        if (in2.eof()) break;

                        StringGrid1->Cells[0][points_graph1+1] =
                                FormatFloat("###0", freq_[points_graph1]);
                        StringGrid1->Cells[1][points_graph1+1] =
                                FormatFloat("###0.0", lev_[points_graph1]);
             
                        points_graph1++;
                }
                while (!in2.eof());

                in2.close(); 
        
                Chart1->BottomAxis->Maximum = freq_[points_graph1-1];
                Chart1->BottomAxis->Minimum = freq_[0];

                // выводим на график
                maxafr = 0;
                minafr = 4100;
                flatness = 0;

                Series1->Clear();

                for (int j=0; j<points_graph1; j++) {

                        Series1->AddXY(freq_[j], lev_[j], "", line_col_full);

                        if (lev_[j]>maxafr) maxafr = lev_[j];
                        if (lev_[j]<minafr) minafr = lev_[j];
                        if (minafr==0) minafr = 1; 
                }

                // неравномерность в дБ
                flatness = 10*log10(maxafr/minafr);

                // выводим информацию
                Panel47->Caption = FormatFloat("###0.0",flatness);
                Panel48->Caption = FormatFloat("###0.0",maxafr);
                Panel49->Caption = FormatFloat("###0.0",minafr);
        }
}

// Сохранить АЧХ ------------------------------------------------------------
void __fastcall TForm1::Button28Click(TObject *Sender)
{
        if(SaveDialog1->Execute()) {

                char* FileOut=(SaveDialog1->FileName).c_str();

                // открываем файл
                ofstream out1(FileOut);

                // сохраняем АЧХ
                for (int j=0; j<points_numb; j++) {

                        out1 << freq_[j] << '\t' << lev_[j] << endl;

                        StringGrid1->Cells[0][j+1] =
                                        FormatFloat("###0", freq_[j]);
                        StringGrid1->Cells[1][j+1] =
                                        FormatFloat("###0.0", lev_[j]);
                }

                out1.close();
        } 
}

// Открыть тест-АЧХ ---------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
        points_graph1 = 0;

        for (int k=0; k<11; k++) {

             freq_[k] = freq_test_[k];
             lev_[k] = lev_test_[k];
             StringGrid1->Cells[0][k+1] = freq_[k];
             StringGrid1->Cells[1][k+1] = lev_[k];
             points_graph1++;
        }

        Series1->Clear();

        Chart1->BottomAxis->Maximum = freq_[points_graph1-1];
        Chart1->BottomAxis->Minimum = freq_[0];

        // выводим на график
        maxafr = 0;
        minafr = 4100;
        flatness = 0;

        for (int j=0; j<points_graph1; j++) {

                Series1->AddXY(freq_[j], lev_[j], "", line_col_full);
                                  
                if (lev_[j]>maxafr) maxafr = lev_[j];
                if (lev_[j]<minafr) minafr = lev_[j];
        }

        flatness = 10*log10(maxafr/minafr);

        // display
        Panel47->Caption = FormatFloat("###0.0",flatness);
        Panel48->Caption = FormatFloat("###0.0",maxafr);
        Panel49->Caption = FormatFloat("###0.0",minafr); 
}

// Старт измерений ----------------------------------------------------------
void __fastcall TForm1::Button27Click(TObject *Sender)
{

        for(int i=0; i<50; i++) {
                StringGrid1->Cells[0][i+1] = "";
                StringGrid1->Cells[1][i+1] = "";
        }       
        
        Button23Click(Sender);

        if (CheckBox3->Checked) {

                Loop_Break_2 = false;

                Button27->Enabled = false;
                Button26->Enabled = true;
        
                GroupBox8->Enabled = false;
                GroupBox12->Enabled = false;
                GroupBox1->Enabled = false;
                GroupBox4->Enabled = false;
                
                Button4->Enabled = false;
                Button28->Enabled = false;
                Button29->Enabled = false;
                Chart1->Enabled = false;
                Panel3->Enabled = false;
        }

        else {
                Loop_Break_2 = true;
        }

        points_graph1 = points_numb;

        ADC_FPU_Get[0] = ADC_FPU_sync;
        ADC_FPU_Get[1] = ADC_FPU_10;

        // Очищаем FT2    
        ftStatus_FPU =
                FT_Purge(ftHandle_FPU, FT_PURGE_RX | FT_PURGE_TX);
        if (ftStatus_FPU != FT_OK) {
                Panel14->Font->Color = clRed;
                Panel14->Caption = "ошибка очистки";
                return;
        }

        // Очищаем FT1
        ftStatus_Contrl = FT_Purge(ftHandle_Contrl,
                                   FT_PURGE_RX | FT_PURGE_TX);
        if (ftStatus_Contrl != FT_OK) {
                Panel29->Font->Color = clRed;
                Panel29->Caption = "ошибка очистки";
                return;
        }


        if (CheckBox7->Checked) {
                CheckBox7->Checked = false;
        }
        
        do {   // поехали

                // подсчет времени отработки одной АЧХ (одного кадра)
                __int64 start, stop, f;
                QueryPerformanceCounter((_LARGE_INTEGER*)&start);
                QueryPerformanceFrequency((_LARGE_INTEGER*)&f);

                Application->ProcessMessages();

                maxafr = 0;
                minafr = 4100;
                flatness = 0;

                for (int pn=0; pn < points_numb; pn++) {

                        freq_s = StartFreq + pn*FreqStep;
                        ScrollBar2->Position = freq_s;  


                        // устанавливаем частоту
                        freq_set[0] = Sync_Freq;
                        freq_set[1] = (uchar)(freq_s&0x00FF);
                        freq_set[2] = (uchar)((freq_s/256)&0x0F);

                        // отправляем команду
                        WriteFT1("Ошибка записи",
                                 freq_set,
                                 sizeof(freq_set));
        

                        // Шлём запрос на получение уровня сигнала
                        WriteFT2("Ошибка записи",
                                 ADC_FPU_Get,
                                 sizeof(ADC_FPU_Get));

                        // Считываем 
                        GetInfoFT2(buf, ADC_FPU_buf_size*3+2);

                        Application->ProcessMessages();

                        meas_number = 0;       // кол-во значений
                        mean_value = 0;

                        for (int i=0; i<ADC_FPU_buf_size; i++) {
                                ADC[i] =
                                    (buf[i*3+1]&0x3F)+((buf[i*3+2]&0x3F)*64);
                                mean_value += ADC[i];
                                meas_number++;
                        }

                        // с фоном
                        if (CheckBox9->Checked) {
                                lev_[pn] = mean_value / meas_number;
                        }
                        // без
                        else {
                                lev_[pn] = mean_value / meas_number - noise1;
                                if (lev_[pn]<1) lev_[pn]=1;
                        }

                        if (lev_[pn]>maxafr) maxafr = lev_[pn];
                        if (lev_[pn]<minafr) minafr = lev_[pn];

                        freq_[pn] = freq_s;
                                
                        StringGrid1->Cells[0][pn+1] = freq_[pn]; 
                        StringGrid1->Cells[1][pn+1] = lev_[pn];

                }   // for operator end

                flatness = 10*(log10(maxafr/minafr));

                // рисуем
                Panel47->Caption = FormatFloat("###0.0",flatness);
                Panel48->Caption = maxafr;
                Panel49->Caption = minafr;

                Series1->Clear();

                for(int i=0; i<points_numb; i++) {
                        Series1->AddXY(freq_[i], lev_[i], "", line_col_full);
                }


                QueryPerformanceCounter((_LARGE_INTEGER*)&stop);
                //время в миллисекундах
                double time = 1000*(((double)(stop-start))/(double)f);
                Panel54->Caption = FormatFloat("###0",time);
        }
        while (!Loop_Break_2); 
}

// Стоп измерений -----------------------------------------------------------
void __fastcall TForm1::Button26Click(TObject *Sender)
{                        
        Loop_Break_2 = true;

        Button27->Enabled = true;
        Button26->Enabled = false;

        GroupBox8->Enabled = true;
        GroupBox12->Enabled = true;
        GroupBox1->Enabled = true;
        GroupBox4->Enabled = true;

        Button4->Enabled = true;
        Button28->Enabled = true;
        Button29->Enabled = true;
        Chart1->Enabled = true;
        Panel3->Enabled = true;  
}

// Логарифмич. ось графика вкл./выкл. ---------------------------------------
void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
        if (CheckBox2->Checked) {
                Chart1->LeftAxis->Logarithmic = true;
        }
        else {
                Chart1->LeftAxis->Logarithmic = false;
        }
}

// Отображение значений вкл./выкл.  -----------------------------------------
void __fastcall TForm1::CheckBox5Click(TObject *Sender)
{
        if (CheckBox5->Checked) {
                marks_check_on = true;
        }
        else {
                marks_check_on = false;
        }

        Ini->WriteBool("Graph","MarksOn", marks_check_on);
        Series1->Marks->Visible = marks_check_on;
}

// Считать уровень фона -----------------------------------------------------
void __fastcall TForm1::Button30Click(TObject *Sender)
{

        // Очищаем FT2    
        ftStatus_FPU =
                FT_Purge(ftHandle_FPU, FT_PURGE_RX | FT_PURGE_TX);
        if (ftStatus_FPU != FT_OK) {
                Panel14->Font->Color = clRed;
                Panel14->Caption = "ошибка очистки";
                return;
        }

        ADC_FPU_Get[0] = ADC_FPU_sync;
        ADC_FPU_Get[1] = ADC_FPU_10;

        // Шлем запрос
        WriteFT2("Ошибка записи",
                 ADC_FPU_Get,
                 sizeof(ADC_FPU_Get));

        // Считываем
        GetInfoFT2(buf, ADC_FPU_buf_size*3+2);

        Application->ProcessMessages();

        meas_number = 0;
        noise1 = 0;

        for (int i=0;i<ADC_FPU_buf_size;i++) {
                ADC[i] = (buf[i*3+1]&0x3F)+((buf[i*3+2]&0x3F)*64);
                noise1 += ADC[i];
                meas_number++;
        }
        // среднее из meas_number значений
        noise1 /= meas_number;

        Panel55->Caption = noise1;
}

// обнулить фон -------------------------------------------------------------
void __fastcall TForm1::Button31Click(TObject *Sender)
{
        noise1 = 0;
        Panel55->Caption = noise1;
}

// Двойной щелчок по графику ------------------------------------------------
void __fastcall TForm1::Chart1DblClick(TObject *Sender)
{
        // возврат в исходное - готовность
        // измерять и отображать данные диапазона 600...1100 МГц
        ScrollBar6->Position = 600;
        ScrollBar6Change(Sender);
        ScrollBar7->Position = 1100;
        ScrollBar7Change(Sender);
        ScrollBar1->Position = 25;
        ScrollBar1Change(Sender);  
}

// Действия при прокрутке графика -------------------------------------------
void __fastcall TForm1::Chart1Scroll(TObject *Sender)
{
        // Недопущение отображения значений < единицы  
        if (Chart1->LeftAxis->Minimum < 1) {
                Chart1->LeftAxis->Minimum = 1;
        }
}

// Действия при масштабировании графика -------------------------------------
void __fastcall TForm1::Chart1Zoom(TObject *Sender)
{
        // Недопущение отображения значений < единицы
        if (Chart1->LeftAxis->Minimum < 1) {
                Chart1->LeftAxis->Minimum = 1;
        }
} 

// Переключение вкладок "Измерить" / "График" -------------------------------
void __fastcall TForm1::PageControl1Change(TObject *Sender)
{

        switch (PageControl1->TabIndex) {

                case 0:
                        TabSheet1->Visible = true;
                        TabSheet1->Highlighted = true;
                        TabSheet2->Visible = false;
                        TabSheet2->Highlighted = false;

                        points_graph = points_graph1;
                        Chart1->UndoZoom();
                        Chart1->BottomAxis->Maximum =  StopFreq;
                        Chart1->BottomAxis->Minimum =  StartFreq;

                        if (CheckBox2->Checked) {
                                Chart1->LeftAxis->Logarithmic = true;
                        }
                        else {
                                Chart1->LeftAxis->Logarithmic = false;
                        }
                
                        break;

                case 1:
                        TabSheet1->Visible = false;
                        TabSheet1->Highlighted = false;
                        TabSheet2->Visible = true;
                        TabSheet2->Highlighted = true;
                        break;
        }           
}

// свипирование старт -------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{

        Loop_Break_2 = false;

        Button9->Enabled = false;
        Button10->Enabled = true;
        GroupBox4->Enabled = false;
        RadioGroup3->Enabled = false;
        ScrollBar2->Enabled = false;
        ScrollBar4->Enabled = false;
        Button5->Enabled = false;
        Button22->Enabled = false;
        CheckBox7->Enabled = false;
        Button23->Enabled = false;
        Button3->Enabled = false;

        Panel3->Enabled = false;
        Chart1->Enabled = false;
        PageControl1->Enabled = false;

        points_graph1 = points_numb;

        // Очищаем FT1
        ftStatus_Contrl = FT_Purge(ftHandle_Contrl,
                                   FT_PURGE_RX | FT_PURGE_TX);   
        if (ftStatus_Contrl != FT_OK) {
                Panel29->Font->Color = clRed;
                Panel29->Caption = "ошибка очистки";
                return;
        }        

        if (CheckBox7->Checked) {
                CheckBox7->Checked = false;
        }


        do {  

                // подсчет времени свипирования
                __int64 start, stop, f;
                QueryPerformanceCounter((_LARGE_INTEGER*)&start);
                QueryPerformanceFrequency((_LARGE_INTEGER*)&f);

                Application->ProcessMessages();

                for(int i=0; i<50; i++) {
                StringGrid1->Cells[0][i+1] = "";
                StringGrid1->Cells[1][i+1] = "";
                } 

                for (int pn=0; pn < points_numb; pn++) {

                        freq_s = StartFreq + pn*FreqStep;
                        ScrollBar2->Position = freq_s;

                        // устанавливаем частоту
                        freq_set[0] = Sync_Freq;
                        freq_set[1] = (uchar)(freq_s&0x00FF);
                        freq_set[2] = (uchar)((freq_s/256)&0x0F);

                        // отправляем команду
                        WriteFT1("Ошибка записи", freq_set, sizeof(freq_set));

                        Sleep(SleepInterv/5);
                        Application->ProcessMessages();

                        StringGrid1->Cells[0][pn+1] = freq_s;
                                                       
                }


                QueryPerformanceCounter((_LARGE_INTEGER*)&stop);
                //время в миллисекундах
                double time = 1000*(((double)(stop-start))/(double)f);
                Panel54->Caption = FormatFloat("###0",time);
        }
        while (!Loop_Break_2);
}

// свипирование стоп --------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
        Loop_Break_2 = true;

        Button9->Enabled = true;
        Button10->Enabled = false;
        GroupBox4->Enabled = true;
        RadioGroup3->Enabled = true;
        ScrollBar2->Enabled = true;
        ScrollBar4->Enabled = true;
        Button5->Enabled = true;
        Button22->Enabled = true;
        CheckBox7->Enabled = true;
        Button23->Enabled = true;
        Button3->Enabled = true;

        Panel3->Enabled = true;
        Chart1->Enabled = true;
        PageControl1->Enabled = true;
}

// установка коэффициента видеоусиления Ку ----------------------------------
void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{

        // Формируем кадр
        switch (RadioGroup1->ItemIndex) {

                case 0:
                        Amp_Ku_Set[1] = Ku_set_1;
                        break;
                case 1:
                        Amp_Ku_Set[1] = Ku_set_2;
                        break;
                case 2:
                        Amp_Ku_Set[1] = Ku_set_5;
                        break;
                case 3:
                        Amp_Ku_Set[1] = Ku_set_10;
                        break;
        }

        Amp_Ku_Set[0] = Ku_sync;

        // Очищаем FT2    
        ftStatus_FPU =
                FT_Purge(ftHandle_FPU, FT_PURGE_RX | FT_PURGE_TX);
        if (ftStatus_FPU != FT_OK) {
                Panel14->Font->Color = clRed;
                Panel14->Caption = "ошибка очистки";
                return;
        }

        // Отправляем
        WriteFT2("Ошибка записи", Amp_Ku_Set, sizeof(Amp_Ku_Set));


        // Получаем информацию
        GetInfoFT2(Amp_Ku_Get, sizeof(Amp_Ku_Get));


        // Проверяем синхробайт кадра
        if (Amp_Ku_Get[0] != Ku_sync) {
                Panel14->Font->Color = clRed;
                Panel14->Caption = "Ошибка кадра";;
                return;
        }

        // Утилизируем данные 
        switch (Amp_Ku_Get[1]) {
        
                case Ku_set_1:
                        Ku_str = "x1";
                        break;
                case Ku_set_2:
                        Ku_str = "x2";
                        break;
                case Ku_set_5:
                        Ku_str = "x5";
                        break;
                case Ku_set_10:
                        Ku_str = "x10";
                        break;
        }

        Panel30->Caption = Ku_str;
}

//---------------------------------------------------------------------------





