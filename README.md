# 3D CA

A 3-dimensional cellular automata engine written in C++, powered by Vulkan.
It allows for viewing and customizing various cellular automata.
It's fast and allows for rendering huge grids of cells using ray marching through a dense voxel octree. 
The automaton's states are updated on a set interval using compute shaders.
This project currently works only for Windows.

## Compilation

To compile this code you need to have the [LunarG Vulkan SDK](https://vulkan.lunarg.com/) installed.

The project is compiled simply using `cmake`:
```
cmake --build <build-directory-name>
```

When modifying shaders, they need to be recompiled. To compile shaders, first go into the `shaders` directory and run:
```
./compile.bat
```

Then, run an exporter tool (which is compiled alongside the main executable) that exports shader Spir-V code into an embeddable C++ source file:
```
cd <build-directory-name>
shader_export.exe
```

Keep in mind that currently this project requires your machine to support Vulkan 1.3 (which is subject for change in the future).
All other dependencies are included in the `deps` subdirectory.

## Controls

Press `` ` `` to open/close the GUI, `F1` to lock/unlock the mouse.
`WASD` for standard camera movement, `Space` to move up, `LShift` to move down, arrows or mouse for camera rotation.

## Gallery

![image](https://github.com/quazuo/3d-ca/assets/25569500/da286278-067c-4d62-bcda-8c3a2a472075)
![image](https://github.com/quazuo/3d-ca/assets/25569500/faea29a9-e3e6-4a6b-bffc-98b350bf3d5d)
![image](https://github.com/quazuo/3d-ca/assets/25569500/6510b63a-647d-4dc9-a17c-6df98862bc0c)

## Potential improvements/extensions

* make the code look a bit nicer as it's pretty rough right now
* make the vulkan renderer a bit more low-end machine friendly
* more automaton presets or customization options
* more ways to customize cell coloring
* try packing two cells into one byte to halve memory usage and see how performance changes
* further optimize the fragment shader
* render automaton bounds so it's easier to see where it actually is
* maybe allow for non-power-of-two grid widths
* maybe support linux
