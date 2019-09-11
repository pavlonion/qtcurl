include(version.pri)

win32: DEFINES += _WINDOWS WIN32_LEAN_AND_MEAN NOMINMAX

MOC_DIR      = $$PRJDIR/out/tmp/$$TARGET/moc
OBJECTS_DIR  = $$PRJDIR/out/tmp/$$TARGET/obj
RCC_DIR      = $$PRJDIR/out/tmp/$$TARGET/rcc
UI_DIR       = $$PRJDIR/out/tmp/$$TARGET/ui

LIBS        += -L$$PRJDIR/out/lib

isEqual(TEMPLATE, "lib"){
    DESTDIR      = $$PRJDIR/out/lib
}else{
    DESTDIR      = $$PRJDIR/out/bin
}

INCLUDEPATH +=  . $$PRJDIR/src $$PRJDIR/3rdParty


