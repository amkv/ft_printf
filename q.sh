#!/bin/bash
# kalmykov.artem@gmail.com
# Student at 42 US, Fremont
# Computer science: Programming

# The name of the program
NAME=a.out

# Files for compiling
# add new CFILES="main.c second.c" or add new line CFILES+="third.c"
CFILES="temp/main.c"
CFILES+=" libftprintf.a"
CFILES+=" ft_printf.c"

# Preset argument
# ARG=file.txt or ARG="this is my test string"
ARG=

# Usefull flags
WFLAGS="-Wall -Wextra -Werror"

# Memory sanitizer flags
MFLAGS="-I. -fsanitize=address"

# Other flags OFLAGS="-I"
OFLAGS=

# cat -e 
CAT=

# Compiler
CC=gcc

# Download folder
DWNFOLDER=~/Downloads/

# Compile
COMPILE="$CC $WFLAGS $MFLAGS $OFLAGS $CFILES -o $NAME"

# colors ANSI escape codes:
RED='\033[0;31m'
CLN='\033[0m'
GRN='\033[32;1m'
BLU='\033[1;34m'
WHT='\033[1m'

# Date variable for log file
DATE=$(date)

# Logs and macro LOG "text"
LOGS=logs_compiler.txt
LOG()
{
	echo -e "${DATE}\t$@" >> $LOGS
}

# First launch, creating log file
IS_FILE_EXIST=1
if [ -a $LOGS ]
then
	LOG "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -"
	LOG "starting..."
else
	echo -e $WHT"\n\t>>> привет! this is your first launch, read the usage <<< \n"$CLN
	IS_FILE_EXIST=0
	touch $LOGS
	LOG "logs file created"
fi

# usage info
if [ "$1" == "--help" -o "$1" == "-h" -o $IS_FILE_EXIST == 0 ]
then
	LOG "you have read about how to use this script"
	echo -e "usage:  ${WHT}art compiler${CLN}\n\tscript helps you to compile and launch your program"
	echo -e "\twith 0 arguments, with multiple arguments, with preset or empty (default) argument"
	echo -e "\tand save history of your compilations and launches"
	echo -e "\tdon't forget to configure...\n"
	echo -e "q.sh" "\t\t\tcompile and launch with preset argument"
	echo -e "q.sh${WHT} arg1 <...>${CLN}" "\tcompile and launch with multiple arguments"
	echo -e "q.sh ${WHT}-0"${CLN} "\t\tcompile and launch without arguments"
	echo -e "q.sh ${WHT}-a"${CLN}"\t\t\tedit preset argument"
	echo -e "q.sh ${WHT}-c"${CLN}"\t\t\tshow colored compiler's errors"
	echo -e "q.sh ${WHT}-f"${CLN}"\t\t\tedit/add project's *.c files"
	echo -e "q.sh ${WHT}-h"${CLN}"\t\t\tor --help to show this help"
	echo -e "q.sh ${WHT}-l"${CLN}"\t\t\tshow log file"
	echo -e "q.sh ${WHT}-i"${CLN} arg1"\t\tshow the files in your library.a file"
	echo -e "q.sh ${WHT}-n"${CLN}"\t\t\tcheck project's files with normenette"
	echo -e "q.sh ${WHT}-o"${CLN}"\t\t\topen project folder in Finder"
	echo -e "q.sh ${WHT}-t"${CLN}"\t\t\tshow time for executable"
	echo -e "q.sh ${WHT}-u"${CLN}"\t\t\tshow used functions in your executable file"
	echo
	echo -e "${WHT}Download other usefull tools${CLN} to ${DWNFOLDER}tool_name"
	echo -e "read the manuals! (README.md)"
	echo -e "q.sh ${WHT}-d1"${CLN}"\t\tLDAP get student's phone number"
	echo -e "q.sh ${WHT}-d2"${CLN}"\t\t42FileChecker"
	echo
	exit 0
fi

# Download other usefull tools, 42FileChecker
if [ "$1" == "-d1" ]
then
	TOOLNAME="ldap-get-phone-number"
	git clone https://github.com/amkv/ldap-get-phone-number.git ${DWNFOLDER}${TOOLNAME}
	echo -e "look at your new tool here (copy/paste):\ncd ${WHT}${DWNFOLDER}${TOOLNAME}${CLN}"
	exit 0
fi

if [ "$1" == "-d2" ]
then
	TOOLNAME="42FileChecker"
	git clone https://github.com/jgigault/42FileChecker.git ${DWNFOLDER}${TOOLNAME}
	echo -e "look at your new tool here (copy/paste):\ncd ${WHT}${DWNFOLDER}${TOOLNAME}${CLN}"
	exit 0
fi

# Show the files in the library.a file
if [ "$1" == "-i" ]
then
	ar t "$2"
	exit 0
fi

# Show log file
if [ "$1" == "-l" ]
then
	LOG "looking this log file"
	cat $LOGS
	exit 0
fi

# Edit preset argument
if [ "$1" == "-a" ]
then
	vim +15 q.sh
	exit 0
fi

# Edit/add project's *.c files
if [ "$1" == "-f" ]
then
	vim +11 q.sh
	exit 0
fi

# Check project files with norminette
if [ "$1" == "-n" ]
then
	LOG "check $CFILES with the norminette"
	norminette $CFILES | tee -a $LOGS
	exit 0
fi


# Open project folder in Finder
if [ "$1" == "-o" ]
then
	open .
	exit 0
fi

# Show used functions in your exucutable file
if [ "$1" == "-u" ]
then
	if [ -a $NAME ]
	then
		nm $NAME | grep "U _" | grep -v "___" | tr -d " " | sed 's/^.//'
	else
		echo "file $NAME doesn't exist, recompile your exectutable file"
	fi
	exit 0
fi

# If the output file exist - delete it before new compiling
if [ -a $NAME ]
then
	rm -rf $NAME
	LOG "${NAME} executable deleted"
else
	LOG "${NAME} does not exist"
fi

# clear the screen
clear

# Compiling 
# add new Flags here
LOG "$COMPILE"
if [ "$1" == "-c" ]
then
	LOG "output color compiler errors"
	$COMPILE
else
	$COMPILE 2>&1 | tee -a $LOGS
fi

# IF compiled, IF No arguments, IF 0 to 3... arguments, IF preset argument value
if [ -a $NAME ]
then
	echo -e "${NAME}$BLU compiled"$CLN
	LOG "${NAME} successfully compiled"
	if [ "$#" -gt 0 ]
	then
		if [ "$1" == "-0" ]
		then
			echo -e $GRN"no arguments"$CLN
			LOG "running ${NAME} without arguments\n"
			./$NAME | tee -a $LOGS
			exit 0
		fi
		if [ "$1" == "-t" ]
		then
			LOG "shows time"
			time 2>&1 ./$NAME | tee -a $LOGS
			exit 0
		fi
		LOG "running ${NAME} with $# arguments: $@\n"
		echo -e $GRN$# "argument(s):"$CLN $@
		./$NAME "$@" | tee -a $LOGS
	else
		if [ "$ARG" == "" ]
		then
			LOG "running ${NAME} with empty preset argument\n"
		else
			LOG "running ${NAME} with 1 preset argument: $ARG\n"
			echo -e $GRN"preset argument:"$CLN $ARG
		fi
		./$NAME "$ARG" | tee -a $LOGS
	fi
else
	LOG "error compiling"
	echo -e $RED"compiling error"$CLN
fi
