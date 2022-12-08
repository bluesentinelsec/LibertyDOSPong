We'll construct levels using:

1. Scene nodes
2. Scene manager

Scene nodes represent a game screen:
    - title screen
    - gameplay levels
    - cut scenes
    - credits

Scene nodes will consist of:
    - sprites (all visual game objects)
    - music
    - sound

Each scene will have: 
    - an init function which loads all assets needed for the scene
    - an update entities function
    - a draw scene function
    - an exit function

Scenes should be represented as files:

```
What game resources need to be loaded into RAM?
What sprites initially populate a scene, and what is their starting state?
What music should be playing on scene load?
```

How does the scene manager know which scene to load next?
- A simple solution could be to just write the next scene to a temporary file
- The scene manager reads the file when the current scene exits