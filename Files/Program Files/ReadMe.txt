The new installer will copy the executable into:

32-bit Windows:
c:\program files\Raised Bar\LSAccess\

64-bit Windows:
c:\program files (x86)\Raised Bar\LSAccess\

The data files required for the application to run appear in the following (often hidden) path:

c:\programdata\Raised Bar\LSAccess

The first time you run LSAccess, an LSAccess.ini file will be created in a new path:

%appdata%\Raised Bar\LSAccess

You can get to this folder by holding down Windows+R (or Command+R on a Mac running Windows) and typing in the path as shown above before pressing Enter.

The default settings within the .ini file are:

- No MIDI input or output ports are specified, hence the -1 values. LSAccess should auto-detect a USB connection or prompt you for DIN connections if USB is not detected.

- Speaking of messages is turned on.

- Speaking of note names when you are in the main window and pads are played is turned on.

- A time-out value of 10ms is specified for when LSAccess queries the attached LinnStrument for its current settings.

Apart from the time-out, these settings can be changed within the Options menu. I haven't yet tested initialization when using DIN jacks and it's possible that DIN connections will need a different time-out value, so I may rename the setting to USBTimeOut and add a DINTimeOut, if necessary. I'd also appreciate any comments as to whether any time-out entries should be added to the Options menu.

My testing so far is reliably initializing the on-screen controls with the correct values from the hardware. Note that initialization queries are sent at the following times:

- Application start-up.

- when the hardware is disconnected from USB, but then inserted;

- When you select different DIN jacks from the Options menu.

- When you select "Refresh" from the Options menu.

Unfortunately, there's no way to be notified of individual parameter changes made by using commands on the hardware, so use "Refresh" if in doubt..

Changing values within the dialogs should cause changes on the hardware. however, I can't pretend that I've tested changing every control and having sighted help validate the change, so I'd greatly appreciate any feedback to confirm the accuracy of control changes. Please let me know if you change velocity sensitivity and your colors go haywire, or any other mismatch!

The layout andproperties of all the dialogs are now controlled by XML files held in the data folder mentioned above. Currently, all position and size values are set to -1, meaning that the values are automatically calculated by the wxWidgets GUI libraries to attempt a "best fit". Editing the XML will be necessary to improve the appearance further, but I need some sighted help for this.

Known issues:

Some radio box labels interfere with speech output of other control labels (particularly labels associated with spin controls). Most screen-readers use heuristics that look to the left and up from a control to find its label. I need to fine-tune control/label positioning to overcome this behaviour. Again, the new XML-based method should speed this up.

If you are not in any of the dialogs, the bottom line of the main window displays whatever notes are currently held down on the note pads. This does not always seem to completely overwrite the previous contents, so please check this, preferably with sighted help..

In the previous build, if you have speaking of notes turned on, you would have noticed that pressing a new note whilst the name of a previous note is still being announced does not silence the previous announcement. This should now be fixed and the speech should be a lot more snappy.

Please test the detection of the LinnStrument moving to/from the O/S update mode - you should hear the change in state if you have speaking of messages turned on.
