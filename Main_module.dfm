object Form1: TForm1
  Left = 325
  Top = 171
  Width = 1270
  Height = 760
  HorzScrollBar.Visible = False
  Caption = 'AOStend 1.2'
  Color = clBtnFace
  Constraints.MinHeight = 750
  Constraints.MinWidth = 1260
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  Visible = True
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  OnResize = FormResize
  OnShow = FormShow
  DesignSize = (
    1254
    722)
  PixelsPerInch = 96
  TextHeight = 16
  object PageControl1: TPageControl
    Left = 987
    Top = 395
    Width = 268
    Height = 276
    ActivePage = TabSheet1
    Anchors = [akTop, akRight]
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -17
    Font.Name = 'Arial'
    Font.Style = [fsBold]
    MultiLine = True
    ParentFont = False
    Style = tsButtons
    TabHeight = 25
    TabIndex = 0
    TabOrder = 0
    TabWidth = 130
    OnChange = PageControl1Change
    object TabSheet1: TTabSheet
      Caption = #1048#1079#1084#1077#1088#1080#1090#1100
      Highlighted = True
      object GroupBox12: TGroupBox
        Left = 132
        Top = -3
        Width = 128
        Height = 113
        Caption = ' '#1092#1086#1085' '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        object Button30: TButton
          Left = 14
          Top = 25
          Width = 100
          Height = 25
          Caption = #1089#1095#1080#1090#1072#1090#1100
          TabOrder = 0
          OnClick = Button30Click
        end
        object Button31: TButton
          Left = 14
          Top = 79
          Width = 100
          Height = 25
          Caption = #1086#1073#1085#1091#1083#1080#1090#1100
          TabOrder = 1
          OnClick = Button31Click
        end
        object Panel55: TPanel
          Left = 14
          Top = 51
          Width = 100
          Height = 25
          BevelOuter = bvNone
          TabOrder = 2
        end
      end
      object GroupBox2: TGroupBox
        Left = 1
        Top = -3
        Width = 128
        Height = 113
        Caption = ' '#1040#1063#1061' '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        object Button26: TButton
          Left = 14
          Top = 79
          Width = 100
          Height = 25
          Caption = #1089#1090#1086#1087
          Enabled = False
          TabOrder = 0
          OnClick = Button26Click
        end
        object CheckBox3: TCheckBox
          Left = 14
          Top = 21
          Width = 106
          Height = 17
          Caption = #1085#1077#1087#1088#1077#1088#1099#1074#1085#1086
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
        end
        object Button27: TButton
          Left = 14
          Top = 44
          Width = 100
          Height = 25
          Caption = #1089#1090#1072#1088#1090
          TabOrder = 2
          OnClick = Button27Click
        end
      end
      object GroupBox8: TGroupBox
        Left = 2
        Top = 111
        Width = 258
        Height = 52
        Caption = ' '#1096#1072#1075', '#1052#1043#1094' '
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 2
        object ScrollBar1: TScrollBar
          Left = 6
          Top = 21
          Width = 211
          Height = 18
          LargeChange = 5
          Min = 5
          PageSize = 0
          Position = 25
          SmallChange = 5
          TabOrder = 0
          OnChange = ScrollBar1Change
        end
        object Panel32: TPanel
          Left = 221
          Top = 14
          Width = 32
          Height = 32
          Caption = '25'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -19
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 1
        end
      end
      object CheckBox2: TCheckBox
        Left = 11
        Top = 172
        Width = 55
        Height = 17
        Caption = 'log'
        Checked = True
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
        State = cbChecked
        TabOrder = 3
        OnClick = CheckBox2Click
      end
      object Button29: TButton
        Left = 80
        Top = 216
        Width = 90
        Height = 25
        Caption = #1086#1090#1082#1088#1099#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 4
        OnClick = Button29Click
      end
      object Button28: TButton
        Left = 171
        Top = 216
        Width = 90
        Height = 25
        Caption = #1089#1086#1093#1088#1072#1085#1080#1090#1100
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 5
        OnClick = Button28Click
      end
      object Button4: TButton
        Left = 2
        Top = 216
        Width = 76
        Height = 25
        Caption = #1090#1077#1089#1090
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 6
        OnClick = Button4Click
      end
      object CheckBox9: TCheckBox
        Left = 131
        Top = 172
        Width = 92
        Height = 17
        Caption = #1089' '#1092#1086#1085#1086#1084
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 7
      end
      object CheckBox5: TCheckBox
        Left = 11
        Top = 193
        Width = 100
        Height = 17
        Caption = #1079#1085#1072#1095#1077#1085#1080#1103
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 8
        OnClick = CheckBox5Click
      end
    end
    object TabSheet2: TTabSheet
      Caption = #1043#1088#1072#1092#1080#1082
      ImageIndex = 1
      DesignSize = (
        260
        241)
      object GroupBox5: TGroupBox
        Left = 2
        Top = -8
        Width = 258
        Height = 251
        Anchors = [akTop, akRight]
        TabOrder = 0
        object CheckBox4: TCheckBox
          Left = 6
          Top = 15
          Width = 78
          Height = 17
          Caption = #1090#1086#1095#1082#1080
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 0
          OnClick = CheckBox4Click
        end
        object TrackBar1: TTrackBar
          Left = 83
          Top = 13
          Width = 130
          Height = 30
          Max = 5
          Min = 1
          Orientation = trHorizontal
          PageSize = 1
          Frequency = 1
          Position = 3
          SelEnd = 0
          SelStart = 0
          TabOrder = 1
          TickMarks = tmBottomRight
          TickStyle = tsAuto
          OnChange = TrackBar1Change
        end
        object Panel6: TPanel
          Left = 219
          Top = 13
          Width = 28
          Height = 28
          BevelInner = bvLowered
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = []
          ParentFont = False
          TabOrder = 2
        end
        object TrackBar3: TTrackBar
          Left = 83
          Top = 84
          Width = 130
          Height = 30
          Min = 1
          Orientation = trHorizontal
          PageSize = 1
          Frequency = 1
          Position = 5
          SelEnd = 0
          SelStart = 0
          TabOrder = 3
          TickMarks = tmBottomRight
          TickStyle = tsAuto
          OnChange = TrackBar3Change
        end
        object TrackBar4: TTrackBar
          Left = 83
          Top = 118
          Width = 130
          Height = 30
          Min = 1
          Orientation = trHorizontal
          PageSize = 1
          Frequency = 1
          Position = 4
          SelEnd = 0
          SelStart = 0
          TabOrder = 4
          TickMarks = tmBottomRight
          TickStyle = tsAuto
          OnChange = TrackBar4Change
        end
        object TrackBar2: TTrackBar
          Left = 83
          Top = 48
          Width = 130
          Height = 30
          Min = 1
          Orientation = trHorizontal
          PageSize = 1
          Frequency = 1
          Position = 4
          SelEnd = 0
          SelStart = 0
          TabOrder = 5
          TickMarks = tmBottomRight
          TickStyle = tsAuto
          OnChange = TrackBar2Change
        end
        object Panel8: TPanel
          Left = 4
          Top = 84
          Width = 85
          Height = 25
          BevelOuter = bvNone
          Caption = #1094#1074#1077#1090' '#1090#1086#1095'.'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 6
        end
        object Panel9: TPanel
          Left = 219
          Top = 82
          Width = 28
          Height = 28
          BevelInner = bvLowered
          TabOrder = 7
        end
        object TrackBar5: TTrackBar
          Left = 83
          Top = 153
          Width = 130
          Height = 30
          Min = 1
          Orientation = trHorizontal
          PageSize = 1
          Frequency = 1
          Position = 5
          SelEnd = 0
          SelStart = 0
          TabOrder = 8
          TickMarks = tmBottomRight
          TickStyle = tsAuto
          OnChange = TrackBar5Change
        end
        object Panel11: TPanel
          Left = 4
          Top = 48
          Width = 85
          Height = 25
          BevelOuter = bvNone
          Caption = #1088#1072#1079#1084#1077#1088
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 9
        end
        object Panel17: TPanel
          Left = 219
          Top = 48
          Width = 28
          Height = 28
          BevelInner = bvLowered
          TabOrder = 10
        end
        object Panel38: TPanel
          Left = 4
          Top = 118
          Width = 85
          Height = 25
          BevelOuter = bvNone
          Caption = #1090#1086#1083#1097'.'#1083#1080#1085'.'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 11
        end
        object TrackBar6: TTrackBar
          Left = 83
          Top = 187
          Width = 130
          Height = 30
          Min = 1
          Orientation = trHorizontal
          PageSize = 1
          Frequency = 1
          Position = 8
          SelEnd = 0
          SelStart = 0
          TabOrder = 12
          TickMarks = tmBottomRight
          TickStyle = tsAuto
          OnChange = TrackBar6Change
        end
        object Panel39: TPanel
          Left = 219
          Top = 118
          Width = 28
          Height = 28
          BevelInner = bvLowered
          TabOrder = 13
        end
        object Panel40: TPanel
          Left = 4
          Top = 153
          Width = 85
          Height = 25
          BevelOuter = bvNone
          Caption = #1094#1074#1077#1090' '#1083#1080#1085'.'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 14
        end
        object Panel41: TPanel
          Left = 4
          Top = 187
          Width = 85
          Height = 25
          BevelOuter = bvNone
          Caption = #1094#1074#1077#1090' '#1092#1086#1085#1072
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -16
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          ParentFont = False
          TabOrder = 15
        end
        object Panel42: TPanel
          Left = 219
          Top = 153
          Width = 28
          Height = 28
          BevelInner = bvLowered
          TabOrder = 16
        end
        object Panel43: TPanel
          Left = 219
          Top = 187
          Width = 28
          Height = 28
          BevelInner = bvLowered
          TabOrder = 17
        end
        object RadioGroup4: TRadioGroup
          Left = 5
          Top = 215
          Width = 244
          Height = 33
          Caption = ' '#1096#1072#1073#1083#1086#1085#1099' '
          Columns = 5
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clNavy
          Font.Height = -13
          Font.Name = 'Arial'
          Font.Style = [fsBold]
          Items.Strings = (
            ''
            ''
            ''
            ''
            '')
          ParentFont = False
          TabOrder = 18
          OnClick = RadioGroup4Click
        end
      end
    end
  end
  object StringGrid1: TStringGrid
    Left = 893
    Top = -1
    Width = 97
    Height = 630
    Anchors = [akTop, akRight]
    ColCount = 2
    DefaultColWidth = 37
    DefaultRowHeight = 15
    FixedCols = 0
    RowCount = 60
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'Arial'
    Font.Style = []
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goThumbTracking]
    ParentFont = False
    TabOrder = 1
  end
  object Panel3: TPanel
    Left = 0
    Top = 675
    Width = 1251
    Height = 45
    Anchors = [akLeft]
    BevelInner = bvRaised
    BevelOuter = bvLowered
    TabOrder = 3
    object Button2: TButton
      Left = 4
      Top = 2
      Width = 85
      Height = 20
      Caption = #1050#1086#1085#1090#1088#1086#1083#1083#1077#1088
      TabOrder = 0
      OnClick = Button2Click
    end
    object Button7: TButton
      Left = 90
      Top = 2
      Width = 105
      Height = 20
      Caption = #1087#1077#1088#1077#1079#1072#1075#1088#1091#1079#1080#1090#1100
      TabOrder = 1
      OnClick = Button7Click
    end
    object Button1: TButton
      Left = 196
      Top = 2
      Width = 63
      Height = 20
      Caption = #1079#1072#1082#1088#1099#1090#1100
      TabOrder = 2
      OnClick = Button1Click
    end
    object Button12: TButton
      Left = 196
      Top = 22
      Width = 63
      Height = 20
      Caption = #1079#1072#1082#1088#1099#1090#1100
      TabOrder = 3
      OnClick = Button12Click
    end
    object Button11: TButton
      Left = 90
      Top = 22
      Width = 105
      Height = 20
      Caption = #1087#1077#1088#1077#1079#1072#1075#1088#1091#1079#1080#1090#1100
      TabOrder = 4
      OnClick = Button11Click
    end
    object Button8: TButton
      Left = 4
      Top = 22
      Width = 85
      Height = 20
      Caption = #1060#1055#1059
      TabOrder = 5
      OnClick = Button8Click
    end
    object Panel29: TPanel
      Left = 261
      Top = 2
      Width = 215
      Height = 20
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
    end
    object Panel14: TPanel
      Left = 261
      Top = 22
      Width = 215
      Height = 20
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
    end
    object Panel15: TPanel
      Left = 477
      Top = 2
      Width = 80
      Height = 20
      BevelOuter = bvNone
      TabOrder = 8
    end
    object Panel16: TPanel
      Left = 477
      Top = 22
      Width = 80
      Height = 20
      BevelOuter = bvNone
      TabOrder = 9
    end
    object Panel4: TPanel
      Left = 596
      Top = -1
      Width = 65
      Height = 16
      BevelInner = bvLowered
      Caption = '850 MHz'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 10
      OnClick = Panel4Click
    end
    object Panel10: TPanel
      Left = 559
      Top = 27
      Width = 37
      Height = 16
      BevelInner = bvLowered
      Caption = #1052#1086#1076'.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 11
    end
    object Panel13: TPanel
      Left = 596
      Top = 27
      Width = 65
      Height = 16
      BevelInner = bvLowered
      Caption = 'OFF'
      TabOrder = 12
      OnClick = Panel13Click
    end
    object Panel35: TPanel
      Left = 596
      Top = 13
      Width = 65
      Height = 16
      BevelInner = bvLowered
      Caption = 'ON'
      TabOrder = 13
      OnClick = Panel35Click
    end
    object Panel36: TPanel
      Left = 559
      Top = -1
      Width = 37
      Height = 16
      BevelInner = bvLowered
      Caption = 'F'
      TabOrder = 14
    end
    object Panel37: TPanel
      Left = 559
      Top = 13
      Width = 37
      Height = 16
      BevelInner = bvLowered
      Caption = #1042#1099#1093'.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'MS Sans Serif'
      Font.Style = []
      ParentFont = False
      TabOrder = 15
    end
    object Button3: TButton
      Left = 664
      Top = 2
      Width = 60
      Height = 40
      Caption = #1050#1086#1085#1090#1088'.'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 16
      OnClick = Button3Click
    end
    object Panel44: TPanel
      Left = 725
      Top = -1
      Width = 30
      Height = 16
      BevelInner = bvLowered
      Caption = 'dB'
      TabOrder = 17
    end
    object Panel45: TPanel
      Left = 725
      Top = 13
      Width = 30
      Height = 16
      BevelInner = bvLowered
      Caption = 'max'
      TabOrder = 18
    end
    object Panel46: TPanel
      Left = 725
      Top = 27
      Width = 30
      Height = 16
      BevelInner = bvLowered
      Caption = 'min'
      TabOrder = 19
    end
    object Panel47: TPanel
      Left = 755
      Top = -1
      Width = 45
      Height = 16
      BevelInner = bvLowered
      Caption = '4096,0'
      TabOrder = 20
    end
    object Panel48: TPanel
      Left = 755
      Top = 13
      Width = 45
      Height = 16
      BevelInner = bvLowered
      Caption = '4096,0'
      TabOrder = 21
    end
    object Panel49: TPanel
      Left = 755
      Top = 27
      Width = 45
      Height = 16
      BevelInner = bvLowered
      Caption = '4096,0'
      TabOrder = 22
    end
    object Button23: TButton
      Left = 802
      Top = 2
      Width = 91
      Height = 40
      Caption = 'Clear'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 23
      OnClick = Button23Click
    end
    object Panel30: TPanel
      Left = 1111
      Top = 5
      Width = 43
      Height = 37
      BevelInner = bvRaised
      BevelOuter = bvLowered
      Caption = 'x1'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 24
    end
    object RadioGroup1: TRadioGroup
      Left = 896
      Top = 1
      Width = 214
      Height = 41
      Caption = ' Ku '
      Columns = 4
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ItemIndex = 0
      Items.Strings = (
        ' x1'
        ' x2'
        ' x5'
        ' x10')
      ParentFont = False
      TabOrder = 25
      OnClick = RadioGroup1Click
    end
  end
  object GroupBox1: TGroupBox
    Left = 987
    Top = -3
    Width = 268
    Height = 392
    Anchors = [akTop, akRight]
    BiDiMode = bdLeftToRight
    ParentBiDiMode = False
    TabOrder = 4
    object Panel22: TPanel
      Left = 7
      Top = 14
      Width = 150
      Height = 25
      Alignment = taLeftJustify
      BevelOuter = bvNone
      Caption = ' '#1063#1072#1089#1090#1086#1090#1072', '#1052#1043#1094
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 0
    end
    object Panel2: TPanel
      Left = 155
      Top = 14
      Width = 107
      Height = 25
      BevelOuter = bvNone
      Caption = '850'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -21
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
    end
    object ScrollBar2: TScrollBar
      Left = 5
      Top = 48
      Width = 258
      Height = 18
      LargeChange = 10
      Max = 3000
      Min = 500
      PageSize = 0
      Position = 850
      TabOrder = 2
      OnChange = ScrollBar2Change
    end
    object Button5: TButton
      Left = 5
      Top = 92
      Width = 258
      Height = 25
      Caption = #1091#1089#1090#1072#1085#1086#1074#1080#1090#1100
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      OnClick = Button5Click
    end
    object Panel5: TPanel
      Left = 179
      Top = 354
      Width = 82
      Height = 25
      BevelOuter = bvNone
      Caption = #1042#1099#1082#1083'.0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 4
    end
    object RadioGroup3: TRadioGroup
      Left = 5
      Top = 273
      Width = 258
      Height = 70
      Caption = ' '#1052#1086#1076#1091#1083#1103#1094#1080#1103' '
      Columns = 3
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ItemIndex = 2
      Items.Strings = (
        #1042#1082#1083'.'
        #1042#1099#1082#1083'.1'
        #1042#1099#1082#1083'.0')
      ParentFont = False
      TabOrder = 5
      OnClick = RadioGroup3Click
    end
    object ScrollBar4: TScrollBar
      Left = 5
      Top = 357
      Width = 178
      Height = 18
      Max = 19
      Min = 1
      PageSize = 0
      Position = 1
      TabOrder = 6
      OnChange = ScrollBar4Change
    end
    object CheckBox7: TCheckBox
      Left = 7
      Top = 72
      Width = 140
      Height = 17
      Caption = #1072#1074#1090#1086#1091#1089#1090#1072#1085#1086#1074#1082#1072
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 7
      OnClick = CheckBox7Click
    end
    object GroupBox3: TGroupBox
      Left = 5
      Top = 122
      Width = 258
      Height = 70
      Caption = ' '#1057#1074#1080#1087#1080#1088#1086#1074#1072#1085#1080#1077' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 8
      object Button9: TButton
        Left = 15
        Top = 27
        Width = 100
        Height = 25
        Caption = #1089#1090#1072#1088#1090
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        OnClick = Button9Click
      end
      object Button10: TButton
        Left = 141
        Top = 27
        Width = 100
        Height = 25
        Caption = #1089#1090#1086#1087
        Enabled = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
        OnClick = Button10Click
      end
    end
    object GroupBox6: TGroupBox
      Left = 5
      Top = 200
      Width = 258
      Height = 70
      Caption = ' '#1042#1099#1093#1086#1076' '#1089#1080#1085#1090#1077#1079#1072#1090#1086#1088#1072' '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Arial'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 9
      object Button22: TButton
        Left = 12
        Top = 20
        Width = 164
        Height = 40
        Caption = 'RF'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clNavy
        Font.Height = -21
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 0
        OnClick = Button22Click
      end
      object Panel12: TPanel
        Left = 196
        Top = 13
        Width = 50
        Height = 50
        Caption = 'ON'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -21
        Font.Name = 'Arial'
        Font.Style = [fsBold]
        ParentFont = False
        TabOrder = 1
      end
    end
  end
  object GroupBox4: TGroupBox
    Left = 0
    Top = 629
    Width = 892
    Height = 41
    Anchors = [akLeft, akBottom]
    TabOrder = 5
    object Panel18: TPanel
      Left = 66
      Top = 10
      Width = 56
      Height = 23
      BevelOuter = bvNone
      Caption = 'F'#1085
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
    end
    object Panel19: TPanel
      Left = 2
      Top = 10
      Width = 65
      Height = 23
      BevelOuter = bvNone
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
    end
    object ScrollBar6: TScrollBar
      Left = 122
      Top = 13
      Width = 305
      Height = 18
      LargeChange = 100
      Max = 2900
      Min = 500
      PageSize = 0
      Position = 600
      SmallChange = 50
      TabOrder = 2
      OnChange = ScrollBar6Change
    end
    object ScrollBar7: TScrollBar
      Left = 464
      Top = 13
      Width = 305
      Height = 18
      LargeChange = 100
      Max = 3000
      Min = 600
      PageSize = 0
      Position = 1100
      SmallChange = 50
      TabOrder = 3
      OnChange = ScrollBar7Change
    end
    object Panel31: TPanel
      Left = 429
      Top = 13
      Width = 33
      Height = 18
      BevelOuter = bvNone
      Caption = '200'
      TabOrder = 4
    end
    object Panel20: TPanel
      Left = 769
      Top = 10
      Width = 56
      Height = 23
      BevelOuter = bvNone
      Caption = 'F'#1074
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
    end
    object Panel21: TPanel
      Left = 824
      Top = 10
      Width = 63
      Height = 23
      BevelOuter = bvNone
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clNavy
      Font.Height = -19
      Font.Name = 'Arial'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
    end
  end
  object Chart1: TChart
    Left = -1
    Top = 0
    Width = 893
    Height = 635
    BackWall.Brush.Color = clWhite
    BackWall.Color = 8454143
    MarginBottom = 1
    MarginLeft = 1
    MarginRight = 2
    MarginTop = 2
    Title.Text.Strings = (
      'TChart')
    Title.Visible = False
    OnScroll = Chart1Scroll
    OnZoom = Chart1Zoom
    BackColor = 8454143
    BottomAxis.Automatic = False
    BottomAxis.AutomaticMaximum = False
    BottomAxis.AutomaticMinimum = False
    BottomAxis.Maximum = 2500
    LeftAxis.Automatic = False
    LeftAxis.AutomaticMaximum = False
    LeftAxis.AutomaticMinimum = False
    LeftAxis.LabelsFont.Charset = ANSI_CHARSET
    LeftAxis.LabelsFont.Color = clBlack
    LeftAxis.LabelsFont.Height = -11
    LeftAxis.LabelsFont.Name = 'Arial'
    LeftAxis.LabelsFont.Style = []
    LeftAxis.Maximum = 4096
    LeftAxis.Minimum = 1
    Legend.Visible = False
    View3D = False
    BevelOuter = bvNone
    TabOrder = 2
    OnDblClick = Chart1DblClick
    object Panel54: TPanel
      Left = 7
      Top = 0
      Width = 35
      Height = 13
      BevelOuter = bvNone
      Caption = 'time'
      TabOrder = 0
    end
    object Series1: TLineSeries
      Marks.Arrow.Visible = False
      Marks.ArrowLength = 10
      Marks.Style = smsValue
      Marks.Visible = False
      SeriesColor = 10485760
      Dark3D = False
      LinePen.Width = 4
      Pointer.Brush.Color = 10485760
      Pointer.HorizSize = 6
      Pointer.InflateMargins = False
      Pointer.Pen.Visible = False
      Pointer.Style = psTriangle
      Pointer.VertSize = 6
      Pointer.Visible = False
      XValues.DateTime = False
      XValues.Name = 'X'
      XValues.Multiplier = 1
      XValues.Order = loAscending
      YValues.DateTime = False
      YValues.Name = 'Y'
      YValues.Multiplier = 1
      YValues.Order = loNone
    end
  end
  object Button6: TButton
    Left = 894
    Top = 632
    Width = 97
    Height = 41
    Caption = 'Break'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    TabOrder = 6
    OnClick = Button6Click
  end
  object OpenDialog1: TOpenDialog
    InitialDir = 'c:\'
    Left = 104
  end
  object SaveDialog1: TSaveDialog
    InitialDir = 'c:\'
    Left = 144
    Top = 65535
  end
end
