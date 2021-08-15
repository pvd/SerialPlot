# What is SerialPlot?

This is a graph plotting application that can be controlled from a serial port. This is a QT based application and currently only build & tested for OS X. I'm working on a Arduino library class that can control (add plots & samples) from the Arduino. Dependencies are QWT and qextserialport.

SerialPlot is graphing application that uses the serial port as a data source. An example of use is to replace the limited graphing facility built in to the Arduino IDE.

It is built primarily for OS X, but *may* compile/build on Win32/64 and Linux, with a little coaxing.

# How to build SerialPlot?

## Summary

The entire process can be summarised into the following steps:

1. Create a workspace directory to put the source files in, i.e. `~/qt-workspace`.
2. Download required source files
   1. [pvd](https://github.com/pvd)/[**SerialPlot**](https://github.com/pvd/SerialPlot)
   2. [qextserialport](https://github.com/qextserialport)/[**qextserialport**](https://github.com/qextserialport/qextserialport)
   3. [qwt 6.0.1](https://sourceforge.net/projects/qwt/files/qwt/6.0.1/)
3. Unzip and place all three in the workspace. Ensure that the directory names match the names of `.pro` files (i.e., no version numbers):
   - `SerialPlot`
   - `qextserialport`
   - `qwt`
4. Install [QtCreator 4.5](https://download.qt.io/official_releases/qtcreator/4.5/4.5.0/qt-creator-opensource-mac-x86_64-4.5.0.dmg) from the [repository](https://download.qt.io/official_releases/qtcreator/4.5/4.5.0/)
5. Install `qt` library, 4 or 5:
   - Either
      - `brew tap cartr/qt4`
      - `brew tap-pin cartr/qt4`
      - `brew install qt@4`
   - or
      - `brew install cartr/qt4/pyqt@4`
6. Install `qwt` (not strictly necessary as we are going to build the framework anyway)
   - `brew install qwt`
7. Create a `qt` directory in the workspace and within it symlink to the `include` directory under the qt install location.
8. Modify the following `.pro` files under the `qwt/` directory, to use `INCLUDEPATH`
   1. `src/src.pro`
   2. `textengines/mathml/mathml.pro`
   3. `designer/designer.pro`
9. Modify `SerialPlot.pro` to point to the correct directories
10. Build in this order:
    1. `qwt`
    2. `qextserialport`
    3. `SerialPlot`

## Details

Note that all of the following was done in a terminal, rather than use QtCreator.

### Pre-requisite - qt

Note: You will need to install qt first (see at the top of the page)
```
brew tap cartr/qt4
brew install qt@4
```
Link in `/etc`
```
ln -s /usr/local/Cellar/qt@4/4.8.7_6_reinstall/etc/qt4 /usr/local/etc/qt4
```
### Setting up the workspace

Create a new directory `~/qtcode2` and place within it new (and freshly unzipped) versions of the packages (`qwt-6.0.1`, `SerialPlot` and `qextserialport`) .

Add a new directory `~/qtcode2/qt`, into which add a symlink to the `qt4/include` directory
```
$ ln -s /usr/local/Cellar/qt4/4.8.7_6.reinstall/include include
```
This is purely for the ease of specifying the include paths for the compilation of `qwt`.

### qwt - using `INCLUDEPATH`

Regarding compiling qwt, in order to not have to copy over all of the headers, use `INCLUDEPATH`, in each of the projects' `.pro` files (`src.pro`, `mathml.pro` and `designer.pro`) taking into consideration the *depth* of the individual `.pro` files, within the directory hierarchy. See this [answer](https://stackoverflow.com/a/2752396/4424636) to [How to add include path in Qt Creator?](https://stackoverflow.com/q/2752352/4424636)

Note that nothing needs to be added to `qwt.pro` itself.

Add to `src/src.pro` the following:
```
INCLUDEPATH += $$PWD/../../qt/include/QtSvg
```
Note the double parent folders `/../../` as `qwt/src` is two directory levels deep

In `textengines/mathml/mathml.pro`
```
INCLUDEPATH += $$PWD/../../../qt/include/QtXml
```
Note the triple parent folder navigation, `/../../../` as `qwt/textengines/mathml/` is three directory levels deep

In `designer/designer.pro`
```
INCLUDEPATH += $$PWD/../../qt/include/QtDesigner
INCLUDEPATH += $$PWD/../../qt/include
```
Note the `qt/include` is for access to `QtDesigner/sdk_global.h` as the path is within the `#include`

Then run `qmake`
```
$ /usr/local/Cellar/qt@4/4.8.7_6.reinstall/bin/qmake qwt.pro
```
and finally `make`.

After that you get the `rcc` error
```
compiling moc/moc_qwt_designer_plotdialog.cpp
rcc qwt_designer_plugin.qrc
Error: unknown command "qwt_designer_plugin" for "rcc"
Run 'rcc --help' for usage.
Error: [rcc v9.16.0] unknown command "qwt_designer_plugin" for "rcc"
make[1]: *** [resources/qrc_qwt_designer_plugin.cpp] Error 1
make: *** [sub-designer-make_default-ordered] Error 2
$ 
```

To avoid this, omit the building of QwtDesigner by commenting out the following line, in `qwtconfig.pri`
```
QWT_CONFIG     += QwtDesigner
```
Then run `qmake` again
```
$ /usr/local/Cellar/qt@4/4.8.7_6.reinstall/bin/qmake qwt.pro
```
and finally `make`.

### qextserialport

No changes required to the `.pro` file. Just run `qmake`
```
/usr/local/Cellar/qt@4/4.8.7_6.reinstall/bin/qmake qextserialport.pro 
```
and then `make`.

### SerialPlot

In `SerialPlot.pro` change the path to `qwt/`
```
include(../qextserialport/src/qextserialport.pri)  # mgj

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../qwt-6.0.1/lib/release/ -lqwt
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../qwt-6.0.1/lib/debug/ -lqwt
#else:mac: LIBS += -F$$PWD/../qwt-6.0.1/lib/ -framework qwt
#else:unix: LIBS += -L$$PWD/../qwt-6.0.1/lib/ -lqwt

#INCLUDEPATH += $$PWD/../qwt-6.0.1/src
#DEPENDPATH += $$PWD/../qwt-6.0.1/src

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../qwt/lib/release/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../qwt/lib/debug/ -lqwt
else:mac: LIBS += -F$$PWD/../qwt/ -framework qwt
else:unix: LIBS += -L$$PWD/../qwt/ -lqwt

INCLUDEPATH += $$PWD/../qwt/src
DEPENDPATH += $$PWD/../qwt/src
```
and change the location of the dynlibs
```
#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../qextserialport/src/build/ -lqextserialport
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../qextserialport/src/build/ -lqextserialportd
#else:unix:!symbian: LIBS += -L$$PWD/../qextserialport/src/build/ -lqextserialport

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../qextserialport/ -lqextserialport
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../qextserialport/ -lqextserialportd
else:unix:!symbian: LIBS += -L$$PWD/../qextserialport/ -lqextserialport
```

Run `qmake`
```
$ /usr/local/Cellar/qt@4/4.8.7_6.reinstall/bin/qmake SerialPlot.pro
```
then `make`

Finally an application is created.

[![Created binary][1]][1]

However, when double clicked, it crashes with the error:
```
Dyld Error Message:
  Library not loaded: /usr/local/lib/libqextserialport.1.dylib
  Referenced from: /Users/USER/*/SerialPlot.app/Contents/MacOS/SerialPlot
  Reason: image not found
```
Copy all four *release* (**not** debug) `.dylib` files from the `qexterialport` directory to `/usr/local/lib`

[![Dynamic libraries to be copied][2]][2]

and then the application runs:

[![Running application][3]][3]

## Bundling the Qwt and Qt frameworks into SerialPlot

To make SerialPlot portable, the Qwt, QExtSerialPort and Qt frameworks, upon which SerialPlot depends, need to be bundled into the `SerialPlot.app` application bundle. 

See [Qt for macOS - Deployment](https://doc.qt.io/qt-5/macos-deployment.html) for further details.

This bundling of the frameworks can be done either manually, which I cover below, or by using the purpose built script `bundleframeworks_SerialPlot.sh`, which is in the `support/` directory on the Github repository. You *could* also use the [macdeployqt](https://doc.qt.io/qt-5/macos-deployment.html#the-mac-deployment-tool) command, which I am not going to cover here.

If you want an *explanation* as to why these commands are necessary then see the whole framework/library dependancy discovery process in the last section of [SerialPlot – a Qt adventure on OS X](https://gr33nonline.wordpress.com/2021/07/25/serialplot-a-qt-adventure-on-os-x/).

### Preparation

First we need to create a directory into which we will place the bundled frameworks and libraries.

Either:

 - in the Finder, right click the **SerialPlot** application and select **Show Package Contents**. Then in the `Contents/` folder, make a new folder called `Frameworks/`.
 - in a terminal, type `mkdir SerialPlot.app/Contents/Frameworks`.

### Bundle Qwt framework

First copy in the `qwt.framework` into the newly created `SerialPlot.app/Contents/Frameworks` directory:
```
$ cp -R ../qwt/lib/qwt.framework SerialPlot.app/Contents/Frameworks
```
Change the reference for the application binary
```
$ install_name_tool -change qwt.framework/Versions/6/qwt @rpath/qwt.framework/Versions/6/qwt SerialPlot.app/Contents/MacOS/SerialPlot
```
### Bundle the QExtSerialPort library

Copy the `qextserialport` library, all four *release* versions:
```
$ cp -R ../qextserialport/libqextserialport.dylib SerialPlot.app/Contents/Frameworks
$ cp -R ../qextserialport/libqextserialport.1.dylib SerialPlot.app/Contents/Frameworks 
$ cp -R ../qextserialport/libqextserialport.1.2.dylib SerialPlot.app/Contents/Frameworks 
$ cp -R ../qextserialport/libqextserialport.1.2.0.dylib SerialPlot.app/Contents/Frameworks
```
Change the reference for the application binary
```
$ install_name_tool -change /usr/local/lib/libqextserialport.1.dylib @rpath/libqextserialport.1.dylib SerialPlot.app/Contents/MacOS/SerialPlot
```
### Bundle Qt frameworks

Copy the Qt frameworks
```
$ cp -R /Library/Frameworks/QtGui.framework SerialPlot.app/Contents/Frameworks 
$ cp -R /Library/Frameworks/QtCore.framework SerialPlot.app/Contents/Frameworks
$ cp -R /Library/Frameworks/QtCore.framework SerialPlot.app/Contents/Frameworks
```
Change the references for the application binary
```
$ install_name_tool -change /usr/local/opt/qt@4/lib/QtGui.framework/Versions/4/QtGui @rpath/QtGui.framework/Versions/4/QtGui SerialPlot.app/Contents/MacOS/SerialPlot
$ install_name_tool -change /usr/local/opt/qt@4/lib/QtCore.framework/Versions/4/QtCore @rpath/QtCore.framework/Versions/4/QtCore SerialPlot.app/Contents/MacOS/SerialPlot
```
**Note**: We don't need to do it for QtSvg as it is `qwt` that calls it, *not* the application binary.

Change the reference names for `qwt`
```
$ install_name_tool -change /usr/local/opt/qt@4/lib/QtCore.framework/Versions/4/QtCore @rpath/QtCore.framework/Versions/4/QtCore SerialPlot.app/Contents/Frameworks/qwt.framework/Versions/6/qwt 

$ install_name_tool -change /usr/local/opt/qt@4/lib/QtGui.framework/Versions/4/QtGui @rpath/QtGui.framework/Versions/4/QtGui SerialPlot.app/Contents/Frameworks/qwt.framework/Versions/6/qwt 

$ install_name_tool -change /usr/local/opt/qt@4/lib/QtSvg.framework/Versions/4/QtSvg @rpath/QtSvg.framework/Versions/4/QtSvg SerialPlot.app/Contents/Frameworks/qwt.framework/Versions/6/qwt
```
Change the reference name for `libqextserialport`
```
$ install_name_tool -change /usr/local/opt/qt@4/lib/QtCore.framework/Versions/4/QtCore @rpath/QtCore.framework/Versions/4/QtCore SerialPlot.app/Contents/Frameworks/libqextserialport.1.dylib
```
Change the reference name for QtGui
```
$ install_name_tool -change /usr/local/Cellar/qt@4/4.8.7_6/lib/QtCore.framework/Versions/4/QtCore @rpath/QtCore.framework/Versions/4/QtCore SerialPlot.app/Contents/Frameworks/QtGui.framework/Versions/4/QtGui
```
Change the reference names for QtSvg
```
$ install_name_tool -change /usr/local/Cellar/qt@4/4.8.7_6/lib/QtCore.framework/Versions/4/QtCore @rpath/QtCore.framework/Versions/4/QtCore SerialPlot.app/Contents/Frameworks/QtSvg.framework/Versions/4/QtSvg $ install_name_tool -change /usr/local/Cellar/qt@4/4.8.7_6/lib/QtGui.framework/Versions/4/QtGui @rpath/QtGui.framework/Versions/4/QtGui SerialPlot.app/Contents/Frameworks/QtSvg.framework/Versions/4/QtSvg
```
Optional: If you want to perform a sanity check to ensure that all of the frameworks use `@rpath` then run the following:
```
$ otool -L SerialPlot.app/Contents/Resources/MacOS/SerialPlot 
$ otool -L SerialPlot.app/Contents/Frameworks/qwt.framework/Versions/6/qwt $ otool -L SerialPlot.app/Contents/Frameworks/libqextserialport.1.dylib 
$ otool -L SerialPlot.app/Contents/Frameworks/QtSvg.framework/Versions/4/QtSvg 
$ otool -L SerialPlot.app/Contents/Frameworks/QtGui.framework/Versions/4/QtGui 
$ otool -L SerialPlot.app/Contents/Frameworks/QtCore.framework/Versions/4/QtCore
```
That's it!!! The bundling is now complete and the application *should* now be portable.

### Bundle Cocoa platform plugin

**Note**: Unlike Qt5, there doesn't seem to be a libqcocoa.dylib library.

## Further build details

An extensive build log is avaiable on the *Gr33nonline* blog, [SerialPlot - a Qt adventure on OS X](https://gr33nonline.wordpress.com/2021/07/25/serialplot-a-qt-adventure-on-os-x/)

A brief HOWTO is here, [Compiling Qt SerialPlot (for OS X)](https://gr33nonline.wordpress.com/2021/08/03/compiling-qt-serialplot-for-os-x/), which is more or less the same as this [`README.md`](https://github.com/pvd/SerialPlot/blob/main/README.md)

# Known Issues

Blah blah...

# Further Work

Blah blah...

  [1]: https://gr33nonline.files.wordpress.com/2021/07/serialplot-application-in-finder.png "Created binary"
  [2]: https://gr33nonline.files.wordpress.com/2021/07/four-qextserialport-libraries.png "Dynamic libraries to be copied"
  [3]: https://gr33nonline.files.wordpress.com/2021/07/serialplot.png "Running application"
