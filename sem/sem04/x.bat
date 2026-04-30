for %%i in (0 1 2 3) do (
    @REM @echo off
    @echo %i%
    @g++ .\sem4\%i%.cpp
    @.\a.exe
    @REM pause
)