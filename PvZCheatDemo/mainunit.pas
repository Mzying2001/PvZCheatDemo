unit MainUnit;

{$mode objfpc}{$H+}

interface

uses
  Classes, SysUtils, Forms, Controls, Graphics, Dialogs, StdCtrls, Cheat;

type

  { TMainForm }

  TMainForm = class(TForm)

    BtnSun:       TButton;
    BtnCoin:      TButton;
    BtnAdvProg:   TButton;
    EditSun:      TEdit;
    EditCoin:     TEdit;
    EditAdvProg:  TEdit;
    LabelSun:     TLabel;
    LabelCoin:    TLabel;
    LabelAdvProg: TLabel;

    procedure ChangeAdvProg(Sender: TObject);
    procedure ChangeCoin(Sender: TObject);
    procedure ChangeSun(Sender: TObject);
    procedure FormCreate(Sender: TObject);

  private

  public

  end;

var
  MainForm: TMainForm;

implementation

{$R *.lfm}

{ TMainForm }

{ 窗口创建事件 }
procedure TMainForm.FormCreate(Sender: TObject);
begin
  if not GetHWND() then
  begin
    ShowMessage('找不到游戏');
    Application.Terminate;
  end;
end;

{ 修改阳光 }
procedure TMainForm.ChangeSun(Sender: TObject);
var
  value: Integer;
begin
  try
    value := StrToInt(EditSun.Text);
    SetSun(value);
  except
    on e: Exception do
    begin
      ShowMessage(e.Message);
    end;
  end;
end;

{ 修改金币 }
procedure TMainForm.ChangeCoin(Sender: TObject);
var
  value: Integer;
begin
  try
    value := StrToInt(EditCoin.Text) div 10;
    SetCoin(value);
  except
    on e: Exception do
    begin
      ShowMessage(e.Message);
    end;
  end;
end;

{ 修改冒险关卡 }
procedure TMainForm.ChangeAdvProg(Sender: TObject);
var
  value: Integer;
begin
  try
    value := StrToInt(EditAdvProg.Text);
    SetAdvProg(value);
  except
    on e: Exception do
    begin
      ShowMessage(e.Message);
    end;
  end;
end;

end.

