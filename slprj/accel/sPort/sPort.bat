@echo off
set MATLAB=D:\Program Files\MATLAB\R2015a
"%MATLAB%\bin\win64\gmake" -f sPort.mk  ISPROTECTINGMODEL=NOTPROTECTING
