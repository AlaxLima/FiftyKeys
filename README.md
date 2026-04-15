# FiftyKeys
A personal documentation of my from-scratch handwired 50-key keyboard design.

![FiftyKeys](https://github.com/AlaxLima/FiftyKeys/blob/main/images/Board.png?raw=true)

This project has been done back in **May 2025**. However, I have made the decision to publish this project as of April 2026.
The name FiftyKeys was chosen because this keyboard has exactly 50 keys, which had several design choices in mind that will be described further.

#### Note about licensing: 
This project is only for personal showcase, and is licensed under the [Creative Commons BY-NC-ND 4.0 License](https://github.com/AlaxLima/FiftyKeys/blob/main/LICENSE.txt).

Commercial use and redistribution of modified or works are strictly prohibited. See usage terms below for details.


### A personal goal achieved for this project
FiftyKeys does not use flashed **QMK** firmware. Yes, this keyboard is **fully programmed using Arduino C++**, and still mimics features like scanning speed adjustment, layer switching, macro mapping.

## Keyboard layout
Originally, I have decided to design a true minimal 40% layout, which only features the alpha cluster and several basic modifiers on the bottom row. However, after a while using a replica of an open-source project that featured such layout - the [Tanuki 40%](https://github.com/SethSenpai/Tanuki) by [SethSenpai](https://github.com/SethSenpai), the heavy use of layer shifting key combos eventually showed its constraints from a person who came from 65% boards.
Therefore, to maintain the minimalism of not having the number row, but keep certain areas reachable, the standard layout of this keyboard adopted:
- A standard 6.25U spacebar
- [HKKB](https://happyhackingkb.com/)-style bottom corners
- Fully accessible arrow cluster
- Delete key next to Enter/Backspace (Inspired by the Filco Majestouch Minila Air) (image different from personal adjustments)
- 3 modifers of Win, Ctrl and Shift all present
- Play/Pause media key

![Layout](https://github.com/AlaxLima/FiftyKeys/blob/main/images/Layout%20with%20legends.png?raw=true)

## Case and matrix design

### Plate and Case

While sandwich-design boards are easier and simpler to design, having a solid piece of plastic bottom case and a thick top bezel is my personal preference. Therefore, based on the original key size from KLE, further perimeter is added to work on the bezel and screw holes (via QCAD and FreeCAD).

![FreeCAD screenshot](https://github.com/AlaxLima/FiftyKeys/blob/main/images/FreeCAD%20screenshot.png?raw=true)

Even though the plate is also modelled here, it is meant for a lasercutting for a 1.5mm aluminium plate (or Inox/Steel, any sheet metal material that can provide adequate rigidity).
Assembly uses M3 heat-threaded inserts inside the 3D printed bottom case, and installed with countersunk M3 screws

### Matrix circuitry

Like many other handwired projects, FiftyKeys uses an Arduino Pro Micro on a handwired matrix. On this matrix, all rows and columns are mapped out from A to F and 1 to 9, which later corresponds to the pins on the microcontroller. The rows are chained with 1N4148 diodes (basic anti-ghosting component for keyboards), while gauge wire are used for columns, and further soft wires to the microcontroller.

Handrawn matrix to reference to during solder, keymapping and pin mapping in code:
![Matrix mapping](https://github.com/AlaxLima/FiftyKeys/blob/main/images/Matrix%20mapping.jpg?raw=true)

Since I do not have SMD solder experience, I had to use a pin breakout board instead for a pigtail cable. Therefore, the acoustic foam mod for the keyboard requires a cutout solely for the bulky part of the microcontroller and the pigtail board itself. In addition, the Elaina sticker is in the center to prevent the microcontroller's flashing light getting through the PETG plastic's 3D print.

![Interior1 image](https://github.com/AlaxLima/FiftyKeys/blob/main/images/Interior1.png?raw=true)

### Arduino code

This project's personally hardest part lies in the big number one goal at the start: It needs to be an entire code structure that at least does certain basic things that QMK does out of the box. However, another personal wanting was made during back during the making: To intentionally add a certain level of modularity to the code so that it can later be easily fixed, or reused for any future personal projects (which is clearly a low likelihood).

There is a sheer amount of repetitiveness and certain choices made that could have been improved (which gave birth to the idea of a .h file to focus more on the complex part instead of the repetitive part), but any further development was stopped to prevent personal scope creep.

If you would like to view the code and understand further how it works, the [.ino code file](https://github.com/AlaxLima/FiftyKeys/blob/main/code/FiftyKeys_Firmware.ino) and its [lookup .h file](https://github.com/AlaxLima/FiftyKeys/blob/main/code/KeyLookupSwitch.h) is available in this repository. A snippet of temporary troubleshooter code was also included, which you can see it as a snapshot of my work half-done during then.

Still, to have a brief showcase, here is a TL;DR tree structure simplified using my own language:

```
Keyboard codebase (.ino file, uploaded via Arduino IDE)
├── Keymapping
│   └── Which key to map on all keys in every layer
├── Direct Port Control macro setup
│   └── Simplify all port manipulation codes into functions
├── Timer1 Interrupt
│   └── Initial setup
├── void setup()
│   └── Arduino configuration for pins and libraries
├── Matrix reading
│   ├── Logic to read through columns per driven row
│   │   ├── Keycode lookup (keycode, keytype and layer)
│   │   └── Press and release management
│   └── Logic loop
├── Sleep mechanism
│   ├── Secondary tick for sleep modes
│   └── Adjust Timer1 by sleep status
└── Macro Engine
    └── MacroMap interpreter
Offset file (.h file, included inside the codebase)
├── Filter between macro/consumer/keyboard keys and press/release state
│   ├── Keyboard.h keys lookup
│   ├── Consumer.h keys lookup
│   └── Macro keys lookup
└── Macro array configuration
```

### Usage terms regarding license restrictions

This project and documentation is made as a personal showcase of my own work in keyboard design and microcontroller code development. It is open to non-commercial use, which includes:
- Reference, learning from the code and design
- Create personal replicas
However, the following uses are not permitted:
- Commercial use or production of any of the project's material
- Redistribution of derivative or modified works
- Use any material in this project in other projects intended for distribution
- Reposting/republishing of any content from this repository elsewhere

Re-implementation is allowed, however it must not be direct use of any assets. Feel free to contact me for any use beyond these terms.


