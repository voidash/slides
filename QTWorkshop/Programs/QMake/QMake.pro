message("Hello world")

VALUE = 34
greaterThan(VALUE,2){
	message("34 is greater than 2")
}

unix {
	message("i am on linux")
}

win32 {
	message("i am on windows")
}


!exists( password.hx ) {
		message("create a password.h file with  define PASSWORD yourMySqlPW macro")
    error("no pasword file found  ")
}
# your .h file
HEADERS += 
# your .cpp file
SOURCES += 

#debug, release , warn_on, c11, c17
CONFIG  += 

# your executable naem 
TARGET = 

# core gui widgets sql 
QT += 

# add other libraries with
INCLUDEPATH = 
