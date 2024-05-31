# Password Operated Device Control

## Project Description

This project showcases an electronic access control system that uses a keypad for password input and controls access using a microcontroller. When the correct password is entered, the system toggles the state of an electric bulb. If an incorrect password is entered, a red LED and a buzzer are activated to indicate an alert.

## Features

- **Password Entry**: Users enter a four-digit password using a 4x3 matrix keypad.
- **Feedback**: A 16x2 LCD provides feedback to the user, masking the password input with asterisks (`*`).
- **Access Control**: 
  - Correct password: Toggles the electric bulb.
  - Incorrect password: Activates a red LED and a buzzer.
  
## Components

- **Microcontroller**: AT89C51 (part of the 8051 microcontroller series)
- **Keypad**: 4x3 matrix keypad
- **Display**: 16x2 LCD
- **Relay Driver**: For controlling the electric bulb
- **Buzzer**: For audible alert on incorrect password
- **Red LED**: For visual alert on incorrect password
- **Electric Bulb**: Represents the access mechanism

## System Overview

1. **User Interface**: 
   - Keypad for input
   - LCD for feedback

2. **Password Security**: 
   - Four-digit password securely stored in system memory.
   - Password input is masked on the LCD to maintain security.

3. **Access Control**:
   - Correct password toggles the state of an electric bulb.
   - Incorrect password triggers an audible buzzer and a visual red LED alert.

## Circuit Description

The system consists of the following main components connected to the AT89C51 microcontroller:

- **Keypad**: Connected to Port 1 (P1) for reading user input.
- **LCD**: Connected to Port 2 (P2) and controlled using the control pins on Port 3 (P3^0 and P3^1).
- **Relay Driver**: Connected to Port 3 (P3^2) for controlling the electric bulb.
- **Red LED and Buzzer**: Connected to Port 3 (P3^3) for alerting incorrect password entries.

## Code Explanation

The provided C code for the AT89C51 microcontroller implements the following functionality:

1. **Initialization**:
   - Configures the LCD.
   - Sets initial states for the electric bulb, red LED, and buzzer.

2. **Password Input and Comparison**:
   - Reads input from the keypad.
   - Masks the input on the LCD.
   - Compares entered password with the stored password.
   - Toggles the electric bulb for correct password.
   - Activates the red LED and buzzer for incorrect password.

## Additional Notes

- Ensure the keypad connections match the port settings in the code.
- The default password is set to "6666". Modify it as needed in the `DefaultPassword` variable.
- This project can be extended to control different devices by modifying the `device` pin logic.
  
## .pdsprj File

The `.pdsprj` file is the project file used by the IDE (Integrated Development Environment) to manage the project settings and source files. Ensure that the project file includes the main C source file and any necessary library files. If you encounter issues with the project file, make sure it points to the correct paths for the source code and header files.

## License

This project is licensed under the MIT License. 

## Code of Conduct

We expect all project participants to adhere to the Contributor Covenant. Please read the full text so that you can understand what actions will and will not be tolerated.

---
