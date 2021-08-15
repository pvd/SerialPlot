#!/bin/sh

# Paths (change these)

application='SerialPlot'
app_bundle_path='.'
qt_brew_path='/usr/local/Cellar/qt@4/4.8.7_6'
lib_path_opt='/usr/local/opt/qt@4/lib'

# Paths (try not to change these)

app_name="${app_bundle_path}/${application}"
lib_path_brew="${qt_brew_path}/lib"
path_cocoa="${qt_brew_path}/plugins/platforms"
app_binary_path="${app_name}.app/Contents/MacOS/${app_name}"
app_frame_path="${app_name}.app/Contents/Frameworks"
plugplat='PlugIns/platforms'
app_plugin_path="${app_name}.app/Contents/${plugplat}"
path_qwt="${app_bundle_path}/../qwt/lib"
path_qextserialport="${app_bundle_path}/../qextserialport"
lib_path_qwt="."  # not used, as there is no prefix/path
lib_path_qextserialport='/usr/local/lib'

# Flags

do_copy="true" 
do_qwt="true" 
do_id="false"
do_qwt_copy="true"
do_qextserialport_copy="true"
do_core='true'

# Copy

if [ "X$do_copy" = "Xtrue" ]
then

  mkdir -p $app_frame_path

  cp -R ${lib_path_brew}/QtCore.framework $app_frame_path 
  cp -R ${lib_path_brew}/QtGui.framework $app_frame_path 

  if [ "X$do_qwt" = "Xtrue" ]
  then
    cp -R ${lib_path_brew}/QtSvg.framework $app_frame_path 
  fi

  if [ "X$do_qwt_copy" = "Xtrue" ]
  then
    cp -R ${path_qwt}/qwt.framework $app_frame_path 
  fi

  if [ "X$do_qextserialport_copy" = "Xtrue" ]
  then
    cp -R ${path_qextserialport}/libqextserialport.dylib $app_frame_path 
    cp -R ${path_qextserialport}/libqextserialport.1.dylib $app_frame_path 
    cp -R ${path_qextserialport}/libqextserialport.1.2.dylib $app_frame_path 
    cp -R ${path_qextserialport}/libqextserialport.1.2.0.dylib $app_frame_path 
  fi
fi

# Change

# Change app binary

install_name_tool -change ${lib_path_opt}/QtGui.framework/Versions/4/QtGui @rpath/QtGui.framework/Versions/4/QtGui $app_binary_path
install_name_tool -change ${lib_path_opt}/QtCore.framework/Versions/4/QtCore @rpath/QtCore.framework/Versions/4/QtCore $app_binary_path

if [ "X$do_qwt_copy" = "Xtrue" ]
then
#  install_name_tool -change ${lib_path_qwt}/qwt.framework/Versions/6/qwt @rpath/qwt.framework/Versions/6/qwt $app_binary_path
  install_name_tool -change qwt.framework/Versions/6/qwt @rpath/qwt.framework/Versions/6/qwt $app_binary_path
fi

if [ "X$do_qextserialport_copy" = "Xtrue" ]
then
  install_name_tool -change ${lib_path_qextserialport}/libqextserialport.1.dylib @rpath/libqextserialport.1.dylib $app_binary_path
fi

# Change qwt

if [ "X$do_qwt" = "Xtrue" ]
then
  chmod +w ${app_frame_path}/qwt.framework/Versions/6/qwt
  install_name_tool -change ${lib_path_opt}/QtCore.framework/Versions/4/QtCore @rpath/QtCore.framework/Versions/4/QtCore ${app_frame_path}/qwt.framework/Versions/6/qwt
  install_name_tool -change ${lib_path_opt}/QtGui.framework/Versions/4/QtGui @rpath/QtGui.framework/Versions/4/QtGui ${app_frame_path}/qwt.framework/Versions/6/qwt
  install_name_tool -change ${lib_path_opt}/QtSvg.framework/Versions/4/QtSvg @rpath/QtSvg.framework/Versions/4/QtSvg ${app_frame_path}/qwt.framework/Versions/6/qwt
  chmod -w ${app_frame_path}/qwt.framework/Versions/6/qwt
fi

# Change QtGui

chmod +w ${app_frame_path}/QtGui.framework/Versions/4/QtGui
install_name_tool -change ${lib_path_brew}/QtCore.framework/Versions/4/QtCore @rpath/QtCore.framework/Versions/4/QtCore ${app_frame_path}/QtGui.framework/Versions/4/QtGui
chmod -w ${app_frame_path}/QtGui.framework/Versions/4/QtGui

# Change qextserialport

if [ "X$do_qextserialport_copy" = "Xtrue" ]
then
  install_name_tool -change ${lib_path_opt}/QtCore.framework/Versions/4/QtCore @rpath/QtCore.framework/Versions/4/QtCore ${app_frame_path}/libqextserialport.1.dylib
fi

# Change QtSvg

if [ "X$do_qwt" = "Xtrue" ]
then
  chmod +w ${app_frame_path}/QtSvg.framework/Versions/4/QtSvg
  install_name_tool -change ${lib_path_brew}/QtCore.framework/Versions/4/QtCore @rpath/QtCore.framework/Versions/4/QtCore ${app_frame_path}/QtSvg.framework/Versions/4/QtSvg
  install_name_tool -change ${lib_path_brew}/QtGui.framework/Versions/4/QtGui @rpath/QtGui.framework/Versions/4/QtGui ${app_frame_path}/QtSvg.framework/Versions/4/QtSvg
  chmod -w ${app_frame_path}/QtSvg.framework/Versions/4/QtSvg
fi

# Check

otool -L ${app_binary_path}
echo
echo
otool -L ${app_frame_path}/QtGui.framework/QtGui
echo
echo
otool -L ${app_frame_path}/QtCore.framework/QtCore
if [ "X$do_qwt" = "Xtrue" ]
then
  echo
  echo
  otool -L ${app_frame_path}/qwt.framework/qwt
  echo
  echo
  otool -L ${app_frame_path}/QtSvg.framework/QtSvg
fi
if [ "X$do_qextserialport_copy" = "Xtrue" ]
then
  echo
  echo
  otool -L ${app_frame_path}/libqextserialport.1.dylib
fi
