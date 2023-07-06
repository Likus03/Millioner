object Form4: TForm4
  Left = 0
  Top = 0
  BorderIcons = []
  BorderStyle = bsSingle
  Caption = #1053#1077#1089#1075#1086#1088#1072#1077#1084#1072#1103' '#1089#1091#1084#1084#1072
  ClientHeight = 315
  ClientWidth = 170
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 0
    Top = 0
    Width = 170
    Height = 13
    Align = alTop
    Alignment = taCenter
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1085#1077#1089#1075#1086#1088#1072#1077#1084#1091#1102' '#1089#1091#1084#1084#1091
    Color = clGreen
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -11
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    ExplicitWidth = 152
  end
  object RadioGroupNesgorSum: TRadioGroup
    Left = 0
    Top = 13
    Width = 170
    Height = 270
    Align = alClient
    Color = clInfoBk
    Items.Strings = (
      '500 000 '#1088#1091#1073'.'
      '250 000 '#1088#1091#1073'.'
      '125 000 '#1088#1091#1073'.'
      '  64 000 '#1088#1091#1073'.'
      '  32 000 '#1088#1091#1073'.'
      '  16 000 '#1088#1091#1073'.'
      '    8 000 '#1088#1091#1073'.'
      '    4 000 '#1088#1091#1073'.'
      '    2 000 '#1088#1091#1073'.'
      '    1 000 '#1088#1091#1073'.'
      '       500 '#1088#1091#1073'.'
      '       300 '#1088#1091#1073'.'
      '       200 '#1088#1091#1073'.'
      '       100 '#1088#1091#1073'.')
    ParentBackground = False
    ParentColor = False
    TabOrder = 0
  end
  object BitBtnStart: TBitBtn
    Left = 0
    Top = 283
    Width = 170
    Height = 32
    Align = alBottom
    Caption = #1053#1072#1095#1072#1090#1100' '#1080#1075#1088#1091
    TabOrder = 1
    OnClick = BitBtnStartClick
  end
end
