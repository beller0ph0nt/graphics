echo off

set BUILD_DIR=.build
set INSTALL_DIR=.install
set BUILD_TYPE=release

rmdir /s /q %BUILE_DIR% %INSTALL_DIR%
mkdir %BUILE_DIR% %INSTALL_DIR%

cmake -DCMAKE_BUILD_TYPE=%BUILD_TYPE% -S . -B %BUILD_DIR% && cmake --build %BUILD_DIR% --config %BUILD_TYPE% && cmake --install %BUILD_DIR% --prefix %INSTALL_DIR%