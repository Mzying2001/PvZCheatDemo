unit Cheat;

{$mode ObjFPC}{$H+}

interface

uses
  Classes, SysUtils;

function InitCheat(): Boolean;
procedure SetSun(val: Integer);
procedure SetCoin(val: Integer);
procedure SetAdvProg(val: Integer);

type
  HWND = LongWord;

var
  hPVZ: HWND;

implementation

{ dll函数 }
function PVZGetHWND(): HWND; cdecl; external 'cheat.dll';
procedure PVZSetSun(hPVZ: HWND; val: Integer); cdecl; external 'cheat.dll';
procedure PVZSetCoin(hPVZ: HWND; val: Integer); cdecl; external 'cheat.dll';
procedure PVZSetAdvProg(hPVZ: HWND; val: Integer); cdecl; external 'cheat.dll';

{ 初始化 - 获取PVZ窗口句柄 }
function InitCheat(): Boolean;
begin
  hPVZ := PVZGetHWND();
  result := hPVZ <> 0;
end;

{ 修改阳光 }
procedure SetSun(val: Integer);
begin
  PVZSetSun(hPVZ, val);
end;

{ 修改金币 }
procedure SetCoin(val: Integer);
begin
  PVZSetCoin(hPVZ, val);
end;

{ 修改冒险关卡 }
procedure SetAdvProg(val: Integer);
begin
  PVZSetAdvProg(hPVZ, val);
end;

end.

