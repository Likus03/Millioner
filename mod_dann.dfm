object DataModule1: TDataModule1
  OldCreateOrder = False
  Height = 191
  Width = 287
  object DataSource1: TDataSource
    DataSet = ADOQuery_quest
    Left = 215
    Top = 120
  end
  object ADOQuery_quest: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'p'
        Attributes = [paNullable]
        DataType = ftInteger
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = 0
      end>
    SQL.Strings = (
      'SELECT question, cod'
      'FROM questions'
      'WHERE cod=p')
    Left = 215
    Top = 72
  end
  object ADOTable_answ: TADOTable
    Connection = ADOConnection1
    CursorType = ctStatic
    IndexFieldNames = 'cod_quest'
    MasterFields = 'cod'
    MasterSource = DataSource1
    TableName = 'answers'
    Left = 111
    Top = 72
  end
  object ADOConnection1: TADOConnection
    ConnectionString = 
      'Provider=Microsoft.ACE.OLEDB.16.0;Data Source=base\kursovaya_202' +
      '1-05-04.accdb;Persist Security Info=False;Jet OLEDB:Database Pas' +
      'sword=k4uKK4uz;'
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.ACE.OLEDB.16.0'
    Left = 151
    Top = 8
  end
  object DataSource2: TDataSource
    DataSet = ADOTable_answ
    Left = 111
    Top = 128
  end
  object ADOQuery_mas: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <
      item
        Name = 'p'
        Attributes = [paNullable]
        DataType = ftInteger
        NumericScale = 255
        Precision = 255
        Size = 510
        Value = Null
      end>
    SQL.Strings = (
      'SELECT questions.cod'
      'FROM questions'
      'WHERE (((questions.level)=[p]));')
    Left = 23
    Top = 70
  end
end
