# 3D CA

A 3-dimensional cellular automata engine written in C++, powered by Vulkan.
It allows for viewing and customizing various cellular automata.
It's fast and allows for rendering huge grids of cells using ray marching through a dense voxel octree. 
The automaton's states are updated on a set interval using compute shaders.
This project currently works only for Windows.

### Compilation

To compile this code you need to have the [LunarG Vulkan SDK](https://vulkan.lunarg.com/) installed.

The project is compiled simply using `cmake`, but for it to work properly it needs to be compiled so that the executable is in some subdirectory 
(i.e. one level deeper than the root directory), for example:
```
cmake --build <build-directory-name>
```
Next you also need to compile shaders by going into the `shaders` subdirectory and executing `compile.bat`.
After these two steps the executable should be working correctly.

Keep in mind that currently this project requires your machine to support Vulkan 1.3 (which is subject for change in the future).
All other dependencies are included in the `deps` subdirectory.

### Controls

Press `` ` `` to open/close the GUI, `F1` to lock/unlock the mouse.
`WASD` for camera movement, arrows or mouse for camera rotation.

### Gallery

![image](https://github.com/quazuo/3d-ca/assets/25569500/08870470-1ffc-4b22-a03e-e90935c870b2)
![image](https://github.com/quazuo/3d-ca/assets/25569500/719b8c23-59af-4131-b756-59babd427ddf)
![image](https://github.com/quazuo/3d-ca/assets/25569500/a3d2d9ce-f394-4740-aec1-18f694fd48aa)
![image](https://github.com/quazuo/3d-ca/assets/25569500/f6e552f2-f25e-4b10-a79f-3e5583b19484)

### Potential improvements/extensions

* make the code look a bit nicer as it's pretty rough right now
* make the vulkan renderer a bit more low-end machine friendly
* more automaton presets or customization options
* more ways to customize coloring of cells
* try packing two cells into one byte to halve memory usage and optimize a bit
* further optimize the fragment shader
* render automaton bounds so it's easier to see where it actually is
* maybe allow for non-power-of-two grid widths
* maybe support linux