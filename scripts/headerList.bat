@echo off
set prefix=%1
set mypath=
cd %prefix%
call :treeProcess
goto :eof
echo test
:treeProcess
setlocal
for %%f in (*.h*) do echo #include ^<%prefix%/%mypath%%%f^>
for /D %%d in (*) do (
    set mypath=%mypath%%%d\
    cd %%d
    call :treeProcess
    cd ..
)
endlocal

REM forfiles /s /m *.h* /c "cmd /c echo @relpath"
:eof

exit /b
