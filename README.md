# Console Calendar in C (Windows)

A C-based console calendar application that allows users to view any month and year with a visually formatted layout using Windows console APIs.

---

## Features

- Display any month and year in a structured calendar layout  
- Correctly handles leap years  
- Keyboard navigation using arrow keys:
  - **Up/Down**: Previous/Next month  
  - **Left/Right**: Previous/Next year  
- Jump to a specific month and year using **F key**  
- Colored day headers and borders for better readability  
- Uses cursor positioning (`gotoxy`) for precise layout  
- Compatible with Windows console (CP437 code page)

---

## How to Use

1. Compile the program with a C compiler on Windows (e.g., GCC or Visual Studio).  
2. Run the executable.  
3. Enter the year and month when prompted.  
4. Navigate the calendar using the arrow keys:
   - **Up**: Previous month  
   - **Down**: Next month  
   - **Left**: Previous year  
   - **Right**: Next year  
   - **F**: Enter a specific month and year  
   - **ESC**: Exit the program  

---

## Example

Enter year and month (month): 2026 2


- The program will display February 2026 in a neatly formatted calendar with colored headers.

---

## Technical Details

- **Language:** C  
- **Platform:** Windows  
- **Libraries Used:** `<stdio.h>`, `<conio.h>`, `<windows.h>`  
- **Console Handling:** `gotoxy`, `SetConsoleTextAttribute`, `SetConsoleOutputCP`  
- **Leap Year Logic:** Proper calculation for Gregorian calendar  
- **Special Characters:** Uses extended ASCII (CP437) for calendar borders and navigation symbols  

---

## Learning Outcomes

This project helped in understanding:

- Windows console programming (cursor control, colors, special characters)  
- Keyboard input handling with `getch()`  
- Leap year and calendar date calculations  
- Structuring console output for a visually appealing layout  

---

## Future Improvements

- Cross-platform support (Linux / macOS)  
- Unicode symbols for better visuals  
- Highlight current date  
- Support mouse input for navigation  
- Save or export calendar to a file  

---

## Author

**SPY Gaming** – Learning C programming and Windows console applications.  

---

