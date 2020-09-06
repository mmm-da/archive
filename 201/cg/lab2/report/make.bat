@echo off
echo -------------------
echo Считываем конфиг
echo -------------------
set file1=conf.json
set file2=config.tex

if not exist %file2% ( 
    goto build
)

for %%i in (%file1%) do set date1=%%~ti
for %%i in (%file2%) do set date2=%%~ti

if "%date1%"=="%date2%" ( 
    goto build
)

for /f %%i in ('dir /b /o:d %file1% %file2%') do set newest=%%i
if "%newest%"=="%file1%" ( 
    goto build
) else ( 
    goto end
)

:build
python build.py

:end
echo -------------------
echo Компиляция Markdown
echo -------------------
pandoc -o task_md.tex task.md
pandoc -o work_progress_md.tex work_progress.md
echo -------------------
echo Сборка листингов
echo -------------------
python build_listings.py
echo ----------------
echo Компиляция LaTeX
echo ----------------
pdflatex --shell-escape --halt-on-error lab.tex

if %ERRORLEVEL% NEQ 0 ( 
    echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    echo Компиляция завершилась с ошибкой
    echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
)

echo -------------------------
echo Удаление временных файлов
echo -------------------------
rmdir /s /q _markdown_lab 2> nul
del lab.markdown.in 2> nul
del lab.markdown.lua 2> nul
del lab.markdown.out 2> nul
del lab.log 2> nul
del lab.aux 2> nul
del lab.out 2> nul
del lab.fls 2> nul
del lab.fdb_latexmk 2> nul
del lab.synctex.gz 2> nul
pause