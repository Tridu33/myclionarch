set /p filename=Please Input filename(No .java):
echo   the file will be compiled is :%filename%.java
javac  -encoding UTF-8  %filename%.java
java.exe  %filename%
pause




















