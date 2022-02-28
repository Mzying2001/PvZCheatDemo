unit Cheat;

{$mode ObjFPC}{$H+}

interface

uses
  Classes, SysUtils, Dialogs;

procedure SetSun(val: Integer);
procedure SetCoin(val: Integer);
procedure SetAdvProg(val: Integer);

implementation

{ 修改阳光 }
procedure SetSun(val: Integer);
begin
  ShowMessage('修改阳光: ' + IntToStr(val));
end;

{ 修改金币 }
procedure SetCoin(val: Integer);
begin
  ShowMessage('修改金币: ' + IntToStr(val));
end;

{ 修改冒险关卡 }
procedure SetAdvProg(val: Integer);
begin
  ShowMessage('修改冒险关卡: ' + IntToStr(val));
end;

end.

