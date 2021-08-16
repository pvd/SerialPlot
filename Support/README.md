### Running the script `bundleframeworks_SerialPlot.sh`

**Important Note**: Only run this script when *building* the application - it is not for general use.

 - Run from the directory containing `SerialPlot.app`,
   - unless you change `app_bundle_path` to the full path, i.e. `/Users/username/qtcodeworkspace/SerialPlot`
 - It expects the application bundle to be called `SerialPlot`
   - unless you change `application` to a different name
 - Create the `SerialPlot.app/Contents/Frameworks` directory manually
   - if you plan to copy `qwt.framework` over manually first to `SerialPlot.app/Contents/Frameworks` (i.e. the following step)
   - The directory will be created automatically (by the script) if it does not exist
 - Copy `qwt.framework` over manually first to `SerialPlot.app/Contents/Frameworks`, and run `install_name_tool -change qwt.framework/Versions/6/qwt @rpath/qwt.framework/Versions/6/qwt SerialPlot.app/Contents/MacOS/SerialPlot`
   - unless you set `do_qwt_copy` to `true`.
   - You may need to change `path_qwt` if the `qwt` source directory doesn't share the same parent folder as the directory containing the application bundle
 - Copy the Qt frameworks over manually first to `SerialPlot.app/Contents/Frameworks`,
   - unless you set `do_copy` to `true`.
 - Leave `do_id` as `false`
   - Setting the `-id` causes the application to crash (reason unknown)
 - Leave `do_qwt` as `true`
   - This sets `qwt.framework` to point to the bundled Qt frameworks
 - Leave `do_qextserialport_copy` as `true`
   - Unless you copy over the four release libraries and set all of the `@rpath` requirements manually
   - This copies over the four `libqextserialport` release libraries
   - It also sets all of the dependancies' names
 - `do_core` does nothing (yet)
   - It was meant for a test to leave `QtCore.framework` unbundled - to prevent the crash caused by the unbundled `libqcocoa.dylib`
   - Unimplemented
