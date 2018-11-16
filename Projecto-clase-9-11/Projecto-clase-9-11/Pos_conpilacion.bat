MKDIR "%2res"
XCOPY "%1res" "%2res" /E /H /R /Y

if %3 == debug (
XCOPY "%1lib\SFML\bin\sfml-audio-d-2.dll" "%1bin\Debug" /E /H /R /Y
XCOPY "%1lib\SFML\bin\sfml-graphics-d-2.dll" "%1bin\Debug" /E /H /R /Y
XCOPY "%1lib\SFML\bin\sfml-network-d-2.d" "%1bin\Debug" /E /H /R /Y
XCOPY "%1lib\SFML\bin\sfml-system-d-2.dll" "%1bin\Debug" /E /H /R /Y
XCOPY "%1lib\SFML\bin\sfml-window-d-2.dll" "%1bin\Debug" /E /H /R /Y
XCOPY "%1lib\STP\bin\STP-d.dll" "%1bin\Debug" /E /H /R /Y
XCOPY "%1lib\STP\bin\zlibd.dll" "%1bin\Debug" /E /H /R /Y
)
else
(
XCOPY "%1lib\SFML\bin\sfml-audio-2.dll" "%1bin\Release" /E /H /R /Y
XCOPY "%1lib\SFML\bin\sfml-graphics-2.dll" "%1bin\Release" /E /H /R /Y
XCOPY "%1lib\SFML\bin\sfml-network-2.d" "%1bin\Release" /E /H /R /Y
XCOPY "%1lib\SFML\bin\sfml-system-2.dll" "%1bin\Release" /E /H /R /Y
XCOPY "%1lib\SFML\bin\sfml-window-2.dll" "%1bin\Release" /E /H /R /Y
XCOPY "%1lib\STP\bin\STP.dll" "%1bin\Release" /E /H /R /Y
XCOPY "%1lib\STP\bin\zlib.dll" "%1bin\Release" /E /H /R /Y
)
