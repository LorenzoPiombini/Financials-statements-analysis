##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=CppHTTPrequests
ConfigurationName      :=Release
WorkspaceConfiguration :=Release
WorkspacePath          :=/Users/stephaniepsiaki/CppWorkspaces/Workspace1
ProjectPath            :=/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/CppHTTPrequests
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Stephanie Psiaki
Date                   :=12/01/2024
CodeLitePath           :=/Users/stephaniepsiaki/.codelite
MakeDirCommand         :=mkdir -p
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -dynamiclib -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=/Users/stephaniepsiaki/CppWorkspaces/Workspace1/build-$(WorkspaceConfiguration)/bin
OutputFile             :=../build-$(WorkspaceConfiguration)/bin/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NDEBUG 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)curl 
ArLibs                 :=  "libcurl" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -O2 -std=c++17 -Wall $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Cashflowstatment.cpp$(ObjectSuffix) $(IntermediateDirectory)/incomestatement.cpp$(ObjectSuffix) $(IntermediateDirectory)/Historicalprice.cpp$(ObjectSuffix) $(IntermediateDirectory)/HistoryStockPrice.cpp$(ObjectSuffix) $(IntermediateDirectory)/Balancesheet.cpp$(ObjectSuffix) $(IntermediateDirectory)/keyratios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Sharesfloat.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "$(IntermediateDirectory)"
	@$(MakeDirCommand) "$(OutputDirectory)"

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "$(IntermediateDirectory)"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Cashflowstatment.cpp$(ObjectSuffix): Cashflowstatment.cpp $(IntermediateDirectory)/Cashflowstatment.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/Cashflowstatment.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Cashflowstatment.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Cashflowstatment.cpp$(DependSuffix): Cashflowstatment.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Cashflowstatment.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Cashflowstatment.cpp$(DependSuffix) -MM Cashflowstatment.cpp

$(IntermediateDirectory)/Cashflowstatment.cpp$(PreprocessSuffix): Cashflowstatment.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Cashflowstatment.cpp$(PreprocessSuffix) Cashflowstatment.cpp

$(IntermediateDirectory)/incomestatement.cpp$(ObjectSuffix): incomestatement.cpp $(IntermediateDirectory)/incomestatement.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/incomestatement.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/incomestatement.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/incomestatement.cpp$(DependSuffix): incomestatement.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/incomestatement.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/incomestatement.cpp$(DependSuffix) -MM incomestatement.cpp

$(IntermediateDirectory)/incomestatement.cpp$(PreprocessSuffix): incomestatement.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/incomestatement.cpp$(PreprocessSuffix) incomestatement.cpp

$(IntermediateDirectory)/Historicalprice.cpp$(ObjectSuffix): Historicalprice.cpp $(IntermediateDirectory)/Historicalprice.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/Historicalprice.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Historicalprice.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Historicalprice.cpp$(DependSuffix): Historicalprice.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Historicalprice.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Historicalprice.cpp$(DependSuffix) -MM Historicalprice.cpp

$(IntermediateDirectory)/Historicalprice.cpp$(PreprocessSuffix): Historicalprice.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Historicalprice.cpp$(PreprocessSuffix) Historicalprice.cpp

$(IntermediateDirectory)/HistoryStockPrice.cpp$(ObjectSuffix): HistoryStockPrice.cpp $(IntermediateDirectory)/HistoryStockPrice.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/HistoryStockPrice.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/HistoryStockPrice.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/HistoryStockPrice.cpp$(DependSuffix): HistoryStockPrice.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/HistoryStockPrice.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/HistoryStockPrice.cpp$(DependSuffix) -MM HistoryStockPrice.cpp

$(IntermediateDirectory)/HistoryStockPrice.cpp$(PreprocessSuffix): HistoryStockPrice.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/HistoryStockPrice.cpp$(PreprocessSuffix) HistoryStockPrice.cpp

$(IntermediateDirectory)/Balancesheet.cpp$(ObjectSuffix): Balancesheet.cpp $(IntermediateDirectory)/Balancesheet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/Balancesheet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Balancesheet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Balancesheet.cpp$(DependSuffix): Balancesheet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Balancesheet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Balancesheet.cpp$(DependSuffix) -MM Balancesheet.cpp

$(IntermediateDirectory)/Balancesheet.cpp$(PreprocessSuffix): Balancesheet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Balancesheet.cpp$(PreprocessSuffix) Balancesheet.cpp

$(IntermediateDirectory)/keyratios.cpp$(ObjectSuffix): keyratios.cpp $(IntermediateDirectory)/keyratios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/keyratios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/keyratios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/keyratios.cpp$(DependSuffix): keyratios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/keyratios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/keyratios.cpp$(DependSuffix) -MM keyratios.cpp

$(IntermediateDirectory)/keyratios.cpp$(PreprocessSuffix): keyratios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/keyratios.cpp$(PreprocessSuffix) keyratios.cpp

$(IntermediateDirectory)/Sharesfloat.cpp$(ObjectSuffix): Sharesfloat.cpp $(IntermediateDirectory)/Sharesfloat.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/Sharesfloat.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Sharesfloat.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Sharesfloat.cpp$(DependSuffix): Sharesfloat.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Sharesfloat.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Sharesfloat.cpp$(DependSuffix) -MM Sharesfloat.cpp

$(IntermediateDirectory)/Sharesfloat.cpp$(PreprocessSuffix): Sharesfloat.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Sharesfloat.cpp$(PreprocessSuffix) Sharesfloat.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


