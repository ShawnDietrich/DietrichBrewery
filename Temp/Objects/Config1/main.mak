SHELL := cmd.exe
CYGWIN=nontsec
export PATH := C:\Program Files (x86)\Rockwell Software\RSCommon;C:\Program Files (x86)\Common Files\Oracle\Java\javapath;C:\WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\WINDOWS\System32\WindowsPowerShell\v1.0\;C:\Program Files\dotnet\;C:\Program Files\Git\cmd;C:\Users\Shawn\AppData\Local\Microsoft\WindowsApps;C:\Users\Shawn\AppData\Local\Programs\Microsoft VS Code\bin;C:\Program Files (x86)\Common Files\Hilscher GmbH\TLRDecode;C:\Users\Shawn\AppData\Local\Microsoft\WindowsApps;C:\Users\Shawn\AppData\Local\Programs\Microsoft VS Code\bin;C:\Program Files (x86)\Common Files\Hilscher GmbH\TLRDecode;C:\BrAutomation\AS410\Bin-en\4.10;C:\BrAutomation\AS410\Bin-en\4.9;C:\BrAutomation\AS410\Bin-en\4.8;C:\BrAutomation\AS410\Bin-en\4.7;C:\BrAutomation\AS410\Bin-en\4.6;C:\BrAutomation\AS410\Bin-en\4.5;C:\BrAutomation\AS410\Bin-en\4.4;C:\BrAutomation\AS410\Bin-en\4.3;C:\BrAutomation\AS410\Bin-en\4.2;C:\BrAutomation\AS410\Bin-en\4.1;C:\BrAutomation\AS410\Bin-en\4.0;C:\BrAutomation\AS410\Bin-en
export AS_BUILD_MODE := BuildAndTransfer
export AS_VERSION := 4.10.2.37
export AS_WORKINGVERSION := 4.10
export AS_COMPANY_NAME := Microsoft
export AS_USER_NAME := Shawn
export AS_PATH := C:/BrAutomation/AS410
export AS_BIN_PATH := C:/BrAutomation/AS410/bin-en
export AS_PROJECT_PATH := C:/Users/Shawn/Documents/GitHub/Dietrich\ Brewery
export AS_PROJECT_NAME := DietrichBrewing
export AS_SYSTEM_PATH := C:/BrAutomation/AS/System
export AS_VC_PATH := C:/BrAutomation/AS410/AS/VC
export AS_TEMP_PATH := C:/Users/Shawn/Documents/GitHub/Dietrich\ Brewery/Temp
export AS_CONFIGURATION := Config1
export AS_BINARIES_PATH := C:/Users/Shawn/Documents/GitHub/Dietrich\ Brewery/Binaries
export AS_GNU_INST_PATH := C:/BrAutomation/AS410/AS/GnuInst/V4.1.2
export AS_GNU_BIN_PATH := C:/BrAutomation/AS410/AS/GnuInst/V4.1.2/4.9/bin
export AS_GNU_INST_PATH_SUB_MAKE := C:/BrAutomation/AS410/AS/GnuInst/V4.1.2
export AS_GNU_BIN_PATH_SUB_MAKE := C:/BrAutomation/AS410/AS/GnuInst/V4.1.2/4.9/bin
export AS_INSTALL_PATH := C:/BrAutomation/AS410
export WIN32_AS_PATH := "C:\BrAutomation\AS410"
export WIN32_AS_BIN_PATH := "C:\BrAutomation\AS410\bin-en"
export WIN32_AS_PROJECT_PATH := "C:\Users\Shawn\Documents\GitHub\Dietrich Brewery"
export WIN32_AS_SYSTEM_PATH := "C:\BrAutomation\AS\System"
export WIN32_AS_VC_PATH := "C:\BrAutomation\AS410\AS\VC"
export WIN32_AS_TEMP_PATH := "C:\Users\Shawn\Documents\GitHub\Dietrich Brewery\Temp"
export WIN32_AS_BINARIES_PATH := "C:\Users\Shawn\Documents\GitHub\Dietrich Brewery\Binaries"
export WIN32_AS_GNU_INST_PATH := "C:\BrAutomation\AS410\AS\GnuInst\V4.1.2"
export WIN32_AS_GNU_BIN_PATH := "$(WIN32_AS_GNU_INST_PATH)\\bin" 
export WIN32_AS_INSTALL_PATH := "C:\BrAutomation\AS410"

.suffixes:

ProjectMakeFile:

	@'$(AS_BIN_PATH)/4.9/BR.AS.AnalyseProject.exe' '$(AS_PROJECT_PATH)/DietrichBrewing.apj' -t '$(AS_TEMP_PATH)' -c '$(AS_CONFIGURATION)' -o '$(AS_BINARIES_PATH)'   -sfas -buildMode 'BuildAndTransfer'   

