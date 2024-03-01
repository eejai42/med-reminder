# Med-Reminder

Med-Reminder is a comprehensive medication reminder app for Android and iOS that helps users to never miss their medications. The app comes with unique features which include setting multiple reminders per day, a decaying back-off system that increases urgency and decreases frequency, and marking reminders as taken.

## Rules

- Set multiple reminders per day, must be marked as taken
- Unique decaying back-off system, increasing urgency, decreasing frequency
- Single quiet beep for initial reminder, auto-snooze for 10 seconds
- Initial reminder gentle, w/ increasing intensity after subsequent auto-snoozes.
- Gradually louder, but less frequent beeps following Fibonacci sequence
- Reminders not marked as 'taken' auto-snoozed
- Reminder skipped even if pill intake marked early

### Use Case 1

Imagine a person who needs to take medication every six hours. They set the first reminder for 8 am and mark it as taken. At 11 am, the second reminder goes off, and they take their pills, marking it as taken. However, at 2 pm, the third reminder goes off, but they forget to take their pills. The app auto-snoozes the reminder but then rings again after a short while, with a slightly louder beep. This continues until the user marks the reminder as "taken," ensuring that they don't miss a dose.

### Use Case 2

Consider a person who takes several medications at different times of the day. They set reminders for each of their medications, and the app reminds them accordingly. If they forget to mark a reminder as "taken," the app auto-snoozes it and reminds them again later with gradually louder and less frequent beeps, ensuring that they take all their medications on time.

## Conclusion

The Med-Alarm app ensures that users never miss taking their medications by providing multiple reminders and using a decaying back-off system that increases urgency and decreases frequency. The app also helps users keep track of their medication intake by allowing them to mark reminders as "taken." These rules help users stay on top of their medication schedules and improve their health outcomes.