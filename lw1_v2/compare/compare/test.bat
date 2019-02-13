@echo off

echo First Test

set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

%PROGRAM% file1.txt file2.txt > %OUT%

fc %OUT% compare-equal-out.txt || goto err


%PROGRAM% file3.txt file4.txt > %OUT%
fc %OUT% compare-line2deferent-out.txt || goto err
exit /B 0


:err
echo Testing failed
exit /B 1