# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Tools.
# ------------------------------------------------------

TEMPLATE = app
TARGET = TaskManagerEditor
DESTDIR = ../../../../vs-2019/x64/Debug
CONFIG += debug
LIBS += -L"./../../../lib/dllTestLibrary" \
    -L"$(Qt_LIBPATH_)" \
    -ldllTestLibrary \
    -l$(Qt_LIBS_)
DEPENDPATH += .
MOC_DIR += .
OBJECTS_DIR += debug
UI_DIR += .
RCC_DIR += .
include(TaskManagerEditor.pri)
