# Physical-Med-Reminder

## Project Overview

**Physical-Med-Reminder** is an innovative Arduino-assisted physical pillbox solution tailored to manage a twice-daily medication schedule efficiently. It stands out for its user-friendly design, eliminating the need for a complex interface by learning the user's medication times through their initial interactions. This project features two distinct pillboxes to cover a full week's medication regimen, leveraging Arduino technology for intelligent reminders and medication tracking.

### Description

This system is designed to simplify medication management without the need for constant reprogramming. Upon initial setup, the device learns the user's medication times based on their actions, setting up reminders accordingly. It employs a mechanical design with two separate units, each divided into seven compartments for a week's worth of medication, facilitating a straightforward morning and evening medication regimen.

### Usage

- **Box 1** is designated for Monday morning through Thursday morning doses.
- **Box 2** is used for Thursday evening through Sunday evening doses.
- Users set the reminder times by plugging in the device and taking their medication as usual. The device then schedules reminders based on these actions.

## Technical Specifications

### Wheel Configuration Overview

The system comprises two wheels (pillboxes), each divided into seven slices corresponding to days and times when medications need to be taken. These slices are equipped with magnets whose arrangements (read by hall effect sensors) serve to uniquely identify each slice, facilitating the system's ability to determine the current position and, consequently, the specific medication due for dispensing.

### Arduino Pin Configuration

The Physical-Med-Reminder system utilizes several pins on the Arduino for connecting various components such as speakers, LEDs, Hall effect sensors, and latching switches. Below is the updated pin configuration based on the latest information provided:

[Wheel and Pin Configuration Details](WheelAndPins.md)


### Time Settings
- **Day_time** and **Eve_time**: The system records the time of the first medication taken during the day and evening as the set reminder times for subsequent doses. This adaptive timing mechanism allows the system to align with the user's personal routine, ensuring medication reminders are timely and relevant.

### Binary Slice Identification
Each slice within the wheels is encoded with a binary representation, facilitating the identification process through the hall effect sensors. This coding allows the Arduino to determine not only which day's medication is due but also whether it's the day or evening dose, based on the unique binary slice ID associated with each compartment.

- **Example**: A slice with a binary code of `[0, 0, 1]` signals a specific position within the wheel, distinct from `[1, 1, 1]`, which represents a different day/time slot.

The **Movement State Machine** for the Physical-Med-Reminder project orchestrates the detection and handling of the mechanical movement of the pillbox wheels. This machine ensures the system accurately tracks the user's interaction with the pillbox, adjusting the reminder schedule accordingly. Below is an expanded and detailed explanation of each state and its role within the system.

[Movement State Machine Details](FSM.md)

### Operational Insight
This configuration ensures the Physical-Med-Reminder system can accurately track and manage the dispensing of medications throughout the week. By leveraging the binary slice IDs and the differentiation between day and evening times, the system provides a user-friendly, intuitive solution for medication adherence, minimizing the need for manual setup or frequent interaction.

## Arduino Settings

This section details the technical configuration of the Arduino hardware used in the Physical-Med-Reminder system. Understanding these settings is crucial for developers or technical users who wish to modify or further develop the system.




### Debounce Configuration

- **Wheel Turn Debounce (150 ms):** Minimizes noise or false triggers when detecting wheel rotation. It ensures that only intentional movements are registered.
- **Quick Turn Threshold (300 ms):** Differentiates between quick successive turns and slower, deliberate turns, aiding in accurately determining user interaction with the device.
- **Debounce Delay (500 ms):** Applied to all Hall effect sensors to filter out electrical noise and ensure stable readings.

### Timing

The med-reminder tracks only it's on start time, and the two pill times relative to that start time.  The actual time of day is not tracked.

[Timing Settings](Timing.md)


The **Technical Details** section outlines the hardware components and their functionalities within the Physical-Med-Reminder system. This system employs a blend of hall effect sensors, magnets, and a speaker to create a user-friendly medication management tool. Below, we delve into each component's role and how they integrate to form the operational backbone of the pillbox.

### Hardware Configuration

#### Hall Effect Sensors
- **Quantity**: 4
- **Functionality**: Hall effect sensors are crucial for detecting the presence of magnets in the pillbox slots. These sensors allow the system to identify which slot is currently positioned for dispensing medication. By reading the unique magnet configurations assigned to each slot, the system accurately tracks the user's medication schedule. This feature is key to the system's ability to learn and adapt to the user's medication-taking habits, ensuring timely reminders without the need for manual schedule inputs.

#### Magnets
- **Quantity**: 25
- **Functionality**: Magnets are embedded within the pillbox slots, each arranged in a unique configuration to correspond with a specific day and time of medication. This arrangement enables the hall effect sensors to distinguish between the different slots and, by extension, the specific times medication needs to be taken. The strategic placement of these magnets is essential for the accurate identification of slots, allowing for an automated tracking system that adjusts to the user's medication regimen.

#### Speaker
- **Quantity**: 1
- **Functionality**: The speaker serves as the primary interface for auditory communication with the user. It is programmed to emit different patterns of sounds based on the system's status or required user actions. For instance:
  - **Medication Reminder**: A distinct sound pattern is played when it's time for the user to take their medication, serving as an effective reminder.
  - **Slot Not Advanced Warning**: If the system detects that the medication has not been taken following a reminder (i.e., the box has not been advanced to the next slot), it emits a different sound pattern to alert the user.

### Operational Integration

- **Slot Identification**: Combining the use of hall effect sensors and magnets, the system can pinpoint exactly which slot of the pillbox is ready for the user to access. This identification process is vital for maintaining an accurate medication schedule, ensuring that users are reminded only when it's time to take their medication.
- **Audible Notifications**: The speaker's role in the system extends beyond mere reminders. It confirms successful interactions (e.g., when the user advances the pillbox to the next slot) and alerts to errors or missed medication times. This auditory feedback mechanism is designed to be intuitive, minimizing the learning curve for users and enhancing the system's usability.

The design of the Physical-Med-Reminder leverages these components to create a seamless and efficient medication management experience. By intelligently combining hardware elements with sophisticated programming, the system offers a reliable solution to the challenge of medication adherence, tailored to meet the needs of individuals with various schedules and lifestyles.

## Setup and Operation

### Initial Setup

1. Fill each compartment according to the medication schedule at the beginning of the week.
2. Plug in the device and proceed to take medication as normal to set the reminder schedule.

### Daily Use

- The device signals medication times through escalating audible reminders.
- Manual rotation of the pillbox's current slot is achieved through a central button, moving to the next scheduled dose.

## Error Handling

The system provides auditory signals to confirm successful learning of medication times. It is equipped to inform the user of successful setup or detect any issues, ensuring reliable medication management.

## Maintenance and Management

Designed for easy setup and minimal maintenance, the device requires only a weekly refill and occasional reset (in case of a power outage or schedule change) by unplugging and replugging the device, then taking
