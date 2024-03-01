# Physical Med Reminder

The Physical Med Reminder is a novel, Arduino-assisted pillbox solution crafted to simplify the management of a twice-daily medication schedule without necessitating a complex user interface. This intuitive device is designed to learn the user's medication times through their actions, making it an ideal choice for individuals looking for an efficient and user-friendly medication management system.

## Project Overview

- **Name:** physical-med-reminder
- **Description:** A user-friendly, Arduino-assisted physical pillbox that manages a twice-daily medication schedule. It learns the user's medication times based on their initial actions after power-up, eliminating the need for a complex user interface.
- **Usage:**
  - **Box 1:** For Monday morning through Thursday morning doses.
  - **Box 2:** For Thursday evening through Sunday evening doses.
  - **Setting Reminder Times:** Plug in the device and take medication as normal to set the reminder schedule.

## Rules and Operation

### Setup

- The pillbox is organized to support a twice-daily medication regimen. Each compartment corresponds to a specific day and time (morning/evening).
- Magnets are placed in the compartments to track medication intake.

### Interaction

- The Arduino system signals when it's time to take medication through audible reminders. These reminders escalate in urgency until the medication is taken.
- The system learns the medication schedule based on user interaction after initial power-up. No further interaction is required unless there is a change in the medication schedule.

### Management

- Designed for easy setup, users fill each compartment according to their medication schedule at the beginning of the week.
- A power supply from a wall adapter ensures consistent operation, while the Arduino's internal clock maintains the time.
- To reset the schedule in the event of a power outage or medication time change, unplug the device, plug it back in, and take the pills as normal.

### Error Handling

- The device confirms learning the medication times through audible signals. Error handling informs the user of successful setup or any issues detected.

## Getting Started

This section will guide you through the initial setup and use of your Physical Med Reminder:

1. **Plug in the device** to a power source using the wall adapter.
2. **Fill the compartments** according to your weekly medication schedule. Ensure Box 1 is for morning doses (Monday to Thursday) and Box 2 for evening doses (Thursday to Sunday).
3. **Take your medication** at the usual times. The device will learn and remember these times as your medication schedule.
4. **Listen for reminders.** The device will alert you with audible reminders when it's time for your next dose.

## Support and Maintenance

For any questions, troubleshooting, or support needs, please refer to the user manual or contact our support team. Regular maintenance includes checking the power supply and ensuring the compartments are correctly filled at the start of each week.

## Conclusion

The Physical Med Reminder is more than just a pillbox; it's a comprehensive medication management system designed to adapt to your schedule, ensuring you never miss a dose again. With its simple setup and intuitive design, managing your medication has never been easier.
