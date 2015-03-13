# Notes

### SDL Rendering
So far, two types of Displaying techniques have been tested. Rendering and
image blitting. Image optimization so far has not worked when using rendering.
Not sure which one is better currently. The project currently uses rendering.

### Positioning
SDL uses a reverse coordinate system for placing objects. Origin is at the top
left, y increases while going down, and x increases to the right.

### Viewport
You can specify a part of the screen as the "viewport" using
SDL_RenderSetViewport. This means that rendering would happen only in that
section, and all positions would be relative to it. Specified usign SDL_Rect
structs. If used often, should be added to the wrapper.
