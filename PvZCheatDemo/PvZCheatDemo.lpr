program PvZCheatDemo;

{$mode objfpc}{$H+}

uses
  {$IFDEF UNIX}
  cthreads,
  {$ENDIF}
  {$IFDEF HASAMIGA}
  athreads,
  {$ENDIF}
  Interfaces, // this includes the LCL widgetset
  Forms, MainUnit, Cheat, Dialogs;

{$R *.res}

begin
  if InitCheat() then
  begin
    RequireDerivedFormResource:=True;
    Application.Scaled:=True;
    Application.Initialize;
    Application.CreateForm(TMainForm, MainForm);
    Application.Run;
  end else
  begin
    ShowMessage('找不到游戏');
    Application.Terminate;
  end;
end.

