# UYAS Polarization Axis Remote Hand Terminal ESP32 Code Using Arduino IDE

## Keypad Button Functions

### Original

|     |     |     |     |
| --- | --- | --- | --- |
| 1   | 2   | 3   | A   |
| 4   | 5   | 6   | B   |
| 7   | 8   | 9   | C   |
| *   | 0   | #   | D   |

### Mapped

|                 |                  |                  |                   |
| --------------- | ---------------- | ---------------- | ----------------- |
| +1$^\circ$      | +0.1$^\circ$     | +0.01$^\circ$    | Set as 0$^\circ$  |
| -1$^\circ$      | -0.1$^\circ$     | -0.01$^\circ$    | Set as 90$^\circ$ |
| Go to 0$^\circ$ | Go to 90$^\circ$ | Bring XY Tower   | Home              |
| Home (z Axis)   | +0.1$m$ (z Axis) | -0.1$m$ (z Axis) | Quick Stop        |

