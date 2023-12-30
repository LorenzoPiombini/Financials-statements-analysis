##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=CppHTTPrequests
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=/Users/stephaniepsiaki/CppWorkspaces/Workspace1
ProjectPath            :=/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests
IntermediateDirectory  :=../build-$(WorkspaceConfiguration)/CppHTTPrequests
OutDir                 :=$(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Stephanie Psiaki
Date                   :=30/12/2023
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
Preprocessors          :=
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
CXXFLAGS :=  -O0 -gdwarf-2 -std=c++17 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Balancesheet.cpp$(ObjectSuffix) $(IntermediateDirectory)/CashFlowStatementClasses.cpp$(ObjectSuffix) $(IntermediateDirectory)/incomestatement.cpp$(ObjectSuffix) $(IntermediateDirectory)/BalancesheetClasses.cpp$(ObjectSuffix) $(IntermediateDirectory)/Cashflowstatment.cpp$(ObjectSuffix) $(IntermediateDirectory)/ComprehensiveIncome.cpp$(ObjectSuffix) $(IntermediateDirectory)/Response.cpp$(ObjectSuffix) $(IntermediateDirectory)/Financials.cpp$(ObjectSuffix) $(IntermediateDirectory)/ComprehensiveIncomeStatementClasses.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/IncomestatementClasses.cpp$(ObjectSuffix) 



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

# PreCompiled Header
/Users/stephaniepsiaki/Downloads/json-develop/single_include/nlohmann/json_fwd.hpp.gch: /Users/stephaniepsiaki/Downloads/json-develop/single_include/nlohmann/json_fwd.hpp
	$(CXX) $(SourceSwitch) /Users/stephaniepsiaki/Downloads/json-develop/single_include/nlohmann/json_fwd.hpp $(PCHCompileFlags) $(CXXFLAGS) $(IncludePath)



##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/Balancesheet.cpp$(ObjectSuffix): Balancesheet.cpp $(IntermediateDirectory)/Balancesheet.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/Balancesheet.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Balancesheet.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Balancesheet.cpp$(DependSuffix): Balancesheet.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Balancesheet.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Balancesheet.cpp$(DependSuffix) -MM Balancesheet.cpp

$(IntermediateDirectory)/Balancesheet.cpp$(PreprocessSuffix): Balancesheet.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Balancesheet.cpp$(PreprocessSuffix) Balancesheet.cpp

$(IntermediateDirectory)/CashFlowStatementClasses.cpp$(ObjectSuffix): CashFlowStatementClasses.cpp $(IntermediateDirectory)/CashFlowStatementClasses.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/CashFlowStatementClasses.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/CashFlowStatementClasses.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/CashFlowStatementClasses.cpp$(DependSuffix): CashFlowStatementClasses.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/CashFlowStatementClasses.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/CashFlowStatementClasses.cpp$(DependSuffix) -MM CashFlowStatementClasses.cpp

$(IntermediateDirectory)/CashFlowStatementClasses.cpp$(PreprocessSuffix): CashFlowStatementClasses.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/CashFlowStatementClasses.cpp$(PreprocessSuffix) CashFlowStatementClasses.cpp

$(IntermediateDirectory)/incomestatement.cpp$(ObjectSuffix): incomestatement.cpp $(IntermediateDirectory)/incomestatement.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/incomestatement.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/incomestatement.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/incomestatement.cpp$(DependSuffix): incomestatement.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/incomestatement.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/incomestatement.cpp$(DependSuffix) -MM incomestatement.cpp

$(IntermediateDirectory)/incomestatement.cpp$(PreprocessSuffix): incomestatement.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/incomestatement.cpp$(PreprocessSuffix) incomestatement.cpp

$(IntermediateDirectory)/BalancesheetClasses.cpp$(ObjectSuffix): BalancesheetClasses.cpp $(IntermediateDirectory)/BalancesheetClasses.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/BalancesheetClasses.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/BalancesheetClasses.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/BalancesheetClasses.cpp$(DependSuffix): BalancesheetClasses.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/BalancesheetClasses.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/BalancesheetClasses.cpp$(DependSuffix) -MM BalancesheetClasses.cpp

$(IntermediateDirectory)/BalancesheetClasses.cpp$(PreprocessSuffix): BalancesheetClasses.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/BalancesheetClasses.cpp$(PreprocessSuffix) BalancesheetClasses.cpp

$(IntermediateDirectory)/Cashflowstatment.cpp$(ObjectSuffix): Cashflowstatment.cpp $(IntermediateDirectory)/Cashflowstatment.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/Cashflowstatment.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Cashflowstatment.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Cashflowstatment.cpp$(DependSuffix): Cashflowstatment.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Cashflowstatment.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Cashflowstatment.cpp$(DependSuffix) -MM Cashflowstatment.cpp

$(IntermediateDirectory)/Cashflowstatment.cpp$(PreprocessSuffix): Cashflowstatment.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Cashflowstatment.cpp$(PreprocessSuffix) Cashflowstatment.cpp

$(IntermediateDirectory)/ComprehensiveIncome.cpp$(ObjectSuffix): ComprehensiveIncome.cpp $(IntermediateDirectory)/ComprehensiveIncome.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/ComprehensiveIncome.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ComprehensiveIncome.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ComprehensiveIncome.cpp$(DependSuffix): ComprehensiveIncome.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ComprehensiveIncome.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ComprehensiveIncome.cpp$(DependSuffix) -MM ComprehensiveIncome.cpp

$(IntermediateDirectory)/ComprehensiveIncome.cpp$(PreprocessSuffix): ComprehensiveIncome.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ComprehensiveIncome.cpp$(PreprocessSuffix) ComprehensiveIncome.cpp

$(IntermediateDirectory)/Response.cpp$(ObjectSuffix): Response.cpp $(IntermediateDirectory)/Response.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/Response.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Response.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Response.cpp$(DependSuffix): Response.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Response.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Response.cpp$(DependSuffix) -MM Response.cpp

$(IntermediateDirectory)/Response.cpp$(PreprocessSuffix): Response.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Response.cpp$(PreprocessSuffix) Response.cpp

$(IntermediateDirectory)/Financials.cpp$(ObjectSuffix): Financials.cpp $(IntermediateDirectory)/Financials.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/Financials.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Financials.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Financials.cpp$(DependSuffix): Financials.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Financials.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Financials.cpp$(DependSuffix) -MM Financials.cpp

$(IntermediateDirectory)/Financials.cpp$(PreprocessSuffix): Financials.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Financials.cpp$(PreprocessSuffix) Financials.cpp

$(IntermediateDirectory)/ComprehensiveIncomeStatementClasses.cpp$(ObjectSuffix): ComprehensiveIncomeStatementClasses.cpp $(IntermediateDirectory)/ComprehensiveIncomeStatementClasses.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/ComprehensiveIncomeStatementClasses.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ComprehensiveIncomeStatementClasses.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ComprehensiveIncomeStatementClasses.cpp$(DependSuffix): ComprehensiveIncomeStatementClasses.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ComprehensiveIncomeStatementClasses.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ComprehensiveIncomeStatementClasses.cpp$(DependSuffix) -MM ComprehensiveIncomeStatementClasses.cpp

$(IntermediateDirectory)/ComprehensiveIncomeStatementClasses.cpp$(PreprocessSuffix): ComprehensiveIncomeStatementClasses.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ComprehensiveIncomeStatementClasses.cpp$(PreprocessSuffix) ComprehensiveIncomeStatementClasses.cpp

$(IntermediateDirectory)/IncomestatementClasses.cpp$(ObjectSuffix): IncomestatementClasses.cpp $(IntermediateDirectory)/IncomestatementClasses.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Users/stephaniepsiaki/CppWorkspaces/Workspace1/CppHTTPrequests/IncomestatementClasses.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/IncomestatementClasses.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/IncomestatementClasses.cpp$(DependSuffix): IncomestatementClasses.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/IncomestatementClasses.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/IncomestatementClasses.cpp$(DependSuffix) -MM IncomestatementClasses.cpp

$(IntermediateDirectory)/IncomestatementClasses.cpp$(PreprocessSuffix): IncomestatementClasses.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/IncomestatementClasses.cpp$(PreprocessSuffix) IncomestatementClasses.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)
	$(RM) /Users/stephaniepsiaki/Downloads/json-develop/single_include/nlohmann/json_fwd.hpp.gch


