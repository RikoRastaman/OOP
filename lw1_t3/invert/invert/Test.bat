@echo off


set PROGRAM="%~1"
set OUT="%TEMP%\out.txt"

%PROGRAM% input_1st.txt > %OUT%
fc %OUT% output_1st_matrix.txt

exit /B 0
