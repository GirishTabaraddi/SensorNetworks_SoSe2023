Set fso = CreateObject("Scripting.FileSystemObject")
Set usrBinDir = fso.GetFolder("C:\Program Files\GIT\eclipse\mingw\usr\bin\")
Set mingwBinDir = fso.GetFolder("C:\Program Files\GIT\eclipse\mingw\mingw64\bin\")
Set graphvizBinDir = fso.GetFolder("C:\Program Files\GIT\eclipse\graphviz\bin\")

Set Shell = CreateObject("Wscript.Shell")
Set Env = Shell.Environment("Process")
Env("PATH") = Env("PATH") + ";" + mingwBinDir.ShortPath + ";" + usrBinDir.ShortPath + ";" + graphvizBinDir.ShortPath
Shell.Run """C:\Program Files\GIT\eclipse\eclipse.exe""", 1, False
