
set tools_path=

set cxx_path=%tools_path%/
set cxx=asm51 
set cxx_flags=

set link_path=%tools_path%/
set link=oh
set link_flags=

set sim_path=%tools_path%/
set sim=sim8052
set sim_flags=

%cxx_path%%cxx% %cxx_flags% %1.asm
if not errorlevel 0 goto :error_cxx

%link_path%%link% %link_flags% %1.obj
if not errorlevel 0 goto :error_link

if %2 -d 
%sim_path%%sim% %sim_flags% %1.hex
goto :end

:error_cxx
echo Ошибка компяляции
notepad %1.lst
goto :end

:error_link
echo Ошибка линковки
goto :end

:end
pause