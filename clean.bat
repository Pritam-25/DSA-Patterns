@echo off
for /r %%f in (*.exe) do del "%%f"
echo All .exe files deleted.