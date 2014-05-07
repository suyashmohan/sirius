#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Sirius/Entity.o \
	${OBJECTDIR}/Sirius/Game.o \
	${OBJECTDIR}/Sirius/Graphic.o \
	${OBJECTDIR}/Sirius/Image.o \
	${OBJECTDIR}/Sirius/Input.o \
	${OBJECTDIR}/Sirius/Renderer.o \
	${OBJECTDIR}/Sirius/ResourceManager.o \
	${OBJECTDIR}/Sirius/Scene.o \
	${OBJECTDIR}/Sirius/Texture.o \
	${OBJECTDIR}/Sirius/Utility.o \
	${OBJECTDIR}/Sirius/Window.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-std=c++11
CXXFLAGS=-std=c++11

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Llib/SDL2-2.0.3/lib/x86 -lSDL2main -lSDL2

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sirius.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sirius.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sirius ${OBJECTFILES} ${LDLIBSOPTIONS} -static-libgcc -static-libstdc++

${OBJECTDIR}/Sirius/Entity.o: Sirius/Entity.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sirius
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilib/SDL2-2.0.3/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sirius/Entity.o Sirius/Entity.cpp

${OBJECTDIR}/Sirius/Game.o: Sirius/Game.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sirius
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilib/SDL2-2.0.3/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sirius/Game.o Sirius/Game.cpp

${OBJECTDIR}/Sirius/Graphic.o: Sirius/Graphic.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sirius
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilib/SDL2-2.0.3/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sirius/Graphic.o Sirius/Graphic.cpp

${OBJECTDIR}/Sirius/Image.o: Sirius/Image.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sirius
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilib/SDL2-2.0.3/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sirius/Image.o Sirius/Image.cpp

${OBJECTDIR}/Sirius/Input.o: Sirius/Input.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sirius
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilib/SDL2-2.0.3/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sirius/Input.o Sirius/Input.cpp

${OBJECTDIR}/Sirius/Renderer.o: Sirius/Renderer.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sirius
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilib/SDL2-2.0.3/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sirius/Renderer.o Sirius/Renderer.cpp

${OBJECTDIR}/Sirius/ResourceManager.o: Sirius/ResourceManager.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sirius
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilib/SDL2-2.0.3/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sirius/ResourceManager.o Sirius/ResourceManager.cpp

${OBJECTDIR}/Sirius/Scene.o: Sirius/Scene.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sirius
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilib/SDL2-2.0.3/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sirius/Scene.o Sirius/Scene.cpp

${OBJECTDIR}/Sirius/Texture.o: Sirius/Texture.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sirius
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilib/SDL2-2.0.3/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sirius/Texture.o Sirius/Texture.cpp

${OBJECTDIR}/Sirius/Utility.o: Sirius/Utility.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sirius
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilib/SDL2-2.0.3/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sirius/Utility.o Sirius/Utility.cpp

${OBJECTDIR}/Sirius/Window.o: Sirius/Window.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sirius
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilib/SDL2-2.0.3/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sirius/Window.o Sirius/Window.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -Ilib/SDL2-2.0.3/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/sirius.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
