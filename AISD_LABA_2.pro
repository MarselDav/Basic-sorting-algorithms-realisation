TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        heapsort.cpp \
        introsort.cpp \
        introsortfromsite.cpp \
        main.cpp \
        mergesort.cpp \
        quicksort.cpp \
        quicksortmediana.cpp \
        shellsort.cpp \
        timsort.cpp

HEADERS += \
    heapsort.h \
    introsort.h \
    introsortfromsite.h \
    mergesort.h \
    quicksort.h \
    quicksortmediana.h \
    shellsort.h \
    sortings.h \
    swap.h \
    timsort.h
