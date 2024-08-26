# Compiling
## GLFW
To compile GLFW:
```
cd ~/software/system
git clone https://github.com/glfw/glfw.git --depth 1
cd glfw
cmake -S . -B build
cd build
make
sudo make install

========================
Output:
[ 38%] Built target glfw
[ 40%] Built target boing
[ 41%] Built target gears
[ 42%] Built target heightmap
[ 44%] Built target offscreen
[ 47%] Built target particles
[ 48%] Built target sharing
[ 50%] Built target splitview
[ 51%] Built target triangle-opengl
[ 53%] Built target triangle-opengles
[ 55%] Built target wave
[ 57%] Built target windows
[ 58%] Built target allocator
[ 60%] Built target clipboard
[ 62%] Built target events
[ 65%] Built target msaa
[ 68%] Built target glfwinfo
[ 71%] Built target iconify
[ 73%] Built target monitors
[ 75%] Built target reopen
[ 77%] Built target cursor
[ 80%] Built target empty
[ 82%] Built target gamma
[ 84%] Built target icon
[ 86%] Built target inputlag
[ 88%] Built target joysticks
[ 90%] Built target tearing
[ 92%] Built target threads
[ 94%] Built target timeout
[ 96%] Built target title
[ 98%] Built target triangle-vulkan
[100%] Built target window
Install the project...
-- Install configuration: ""
-- Installing: /usr/local/lib/libglfw3.a
-- Installing: /usr/local/include/GLFW
-- Installing: /usr/local/include/GLFW/glfw3native.h
-- Installing: /usr/local/include/GLFW/glfw3.h
-- Installing: /usr/local/lib/cmake/glfw3/glfw3Config.cmake
-- Installing: /usr/local/lib/cmake/glfw3/glfw3ConfigVersion.cmake
-- Installing: /usr/local/lib/cmake/glfw3/glfw3Targets.cmake
-- Installing: /usr/local/lib/cmake/glfw3/glfw3Targets-noconfig.cmake
-- Installing: /usr/local/lib/pkgconfig/glfw3.pc
```

## Main
```
g++ -Wall -c -I include main.cpp &&            
g++ -c glad.c -I include &&
g++ main.o -o main glad.o -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl &&
./main
```
