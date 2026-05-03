import bpy

INPUT = 
OUTPUT = "build/raster/"

bpy.context.scene.render.film_transparent = True
bpy.context.scene.render.filepath = OUTPUT
bpy.ops.render.render(write_still=True)

bpy.context.scene.render.film_transparent = False
