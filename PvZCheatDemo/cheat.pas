unit Cheat;

{$mode ObjFPC}{$H+}

interface

uses
  Classes, SysUtils;

function GetHandle(): Boolean;
procedure SetSun(val: Integer);
procedure SetCoin(val: Integer);
procedure SetAdvProg(val: Integer);

var
  hProc: THandle;

implementation

{ dll函数 }
function PVZGetHandle(): THandle; stdcall; external 'cheat.dll';
procedure PVZSetSun(hProcess: THandle; val: Integer); stdcall; external 'cheat.dll';
procedure PVZSetCoin(hProcess: THandle; val: Integer); stdcall; external 'cheat.dll';
procedure PVZSetAdvProg(hProcess: THandle; val: Integer); stdcall; external 'cheat.dll';

{ 获取进程ID }
function GetHandle(): Boolean;
begin
  hProc := PVZGetHandle();
  result := hProc <> 0;
end;

{ 修改阳光 }
procedure SetSun(val: Integer);
begin
  PVZSetSun(hProc, val);
end;

{ 修改金币 }
procedure SetCoin(val: Integer);
begin
  PVZSetCoin(hProc, val);
end;

{ 修改冒险关卡 }
procedure SetAdvProg(val: Integer);
begin
  PVZSetAdvProg(hProc, val);
end;

end.

