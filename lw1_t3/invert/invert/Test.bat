@echo off


set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

%PROGRAM% input_1st.txt > %OUT%
fc %OUT% output_1st_matrix.txt || goto err

%PROGRAM% input_zero.txt > %OUT%
fc %OUT% output_zero.txt || goto err

%PROGRAM% > %OUT%
fc %OUT% output_argument_error.txt || goto err

echo "Tests passed!"
exit /B 0

:err
echo Testing failed
exit /B 1