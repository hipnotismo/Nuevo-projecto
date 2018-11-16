echo %1
MKDIR "%2res"
XCOPY "%1res" "%2res" /E /H /R /Y
echo hola
XCOPY "%1lib\SFML\bin\sfml-audio-d-2.dll" "%1bin\Debug" /E /H /R /Y
XCOPY "%1lib\SFML\bin\sfml-graphics-d-2.dll" "%1bin\Debug" /E /H /R /Y
XCOPY "%1lib\SFML\bin\sfml-network-d-2.d" "%1bin\Debug" /E /H /R /Y
XCOPY "%1lib\SFML\bin\sfml-system-d-2.dll" "%1bin\Debug" /E /H /R /Y
XCOPY "%1lib\SFML\bin\sfml-window-d-2.dll" "%1bin\Debug" /E /H /R /Y
XCOPY "%1lib\STP\bin\STP-d.dll" "%1bin\Debug" /E /H /R /Y
XCOPY "%1lib\STP\bin\zlibd.dll" "%1bin\Debug" /E /H /R /Y
