# bmcawork-v1
 final project work

needs mlpack to function.
install with vcpkg, then change the include directory to the required library files in the .pro file.
finally, add the directive below into "additional arguments" in build steps of qmake:

PKG_CONFIG_PATH=<vcpkg-source>\installed\x64-windows\lib\pkgconfig