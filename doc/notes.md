# Optional prompt: Second Pass

It's a fight.
Your enemy has a knife.
You have a gun.
Try to win.

It's a time loop.


# Tasks
- [x] Implement enemy knife attack
- [x] Implement enemy dodging
- [x] Implement complex movement

- [ ] Implement enemy knife throw

- [x] Win screen
- [x] Limit time loop to 30 seconds (needs UI)


# Bot tasks
- [ ] Don't stay wary of players who have finished their timeline events
    - [ ] Properly approach those who have finished with activated weapon
- [ ] Proper respawn positions for 2+ enemies
- [ ] Nullify naant's trick (don't keep following a player for too long based on human reaction perception)


# Removed description from jam page:

Description:

A difficult game i made in 16 hours.

You cooperate with your time shadows inside a 25 second time loop using firearms against a guy who entered a gunfight with a knife. But he damn well knew what he was doing.


Requires: libSDL2

Resources/source prepared before the jam:
Most of the commits in the engine branch on github. They are utilities for handling user input, scenes, random number generators and rendering utilities that i use in most of my SDL projects. Alternatively, they can be considered as a game engine that has no mechanics included.

Closest optional prompt match: Second pass

Note: web version has a bit different textures to save on resources.
(Honestly, i was debugging an issue and disabled the original textures.
The simpler ones i used actually look as cool as the originals, so i kept them in one of the versions.
The issue was a single character typo.)

Note 2: The game was developed using vim, GCC, GNU make and GIMP (yes, i used GIMP while making a game that has no graphic assets)


