@echo off

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

%PROGRAM% 6 > %OUT%
fc %OUT% 6.txt || goto err

%PROGRAM% 255 > %OUT%
fc %OUT% 255.txt || goto err

%PROGRAM% 0 > %OUT%
fc %OUT% 0.txt || goto err

%PROGRAM% 97 > %OUT%
fc %OUT% 97.txt || goto err


::Вне диапазона
%PROGRAM% 999 > %OUT%
fc %OUT% out_of_range.txt || goto err

::Строка без числа
%PROGRAM% line > %OUT%
fc %OUT% line_not_a_number.txt || goto err

exit /B 0

:err
echo Testing failed
exit /B 1