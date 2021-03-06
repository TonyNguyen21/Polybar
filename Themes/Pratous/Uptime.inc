[Variables]
Uptime_X=295
;Left, Right or Center
Uptime_Anchor=Middle

[Metadata]
Name=Paper\\Uptime
Author=reddit.com/u/falconwingz
Description=Display up time.

[UptimeAnchor]
Measure=String
String = #Uptime_Anchor#
IfMatch = Center|center|Middle|middle
IfMatchAction = [!SetOption UptimeIcon X "(#Bar_OffsetX#+#*Uptime_X*#-([*UptimeIcon:W*]+[*Uptime:W*]+10)/2)"][!SetOption Uptime X 10R]
IfMatch2 = Right|right
IfMatchAction2 = [!SetOption UptimeIcon StringAlign RightCenter][!SetOption Uptime StringAlign RightCenter][!SetOption UptimeIcon X "([*Uptime:X*]-10)"][!SetOption Uptime X "(#Bar_OffsetX#+#*Uptime_X*#)"]

[MeasureUptime]
Measure=upTime
Format="%3!i!h, %2!i!m, %1!i!s"

[UptimeIcon]
Meter=String
Text=
FontFace=Material Icons
FontSize=(#Font_Size#*16/13)
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=(#Bar_OffsetX#+#Uptime_X#)
Y=(#Bar_OffsetY#+#Bar_Height#/2)
DynamicVariables=1

[Uptime]
Meter=String
MeasureName=MeasureUptime
FontFace=#Font_Face#
FontSize=#Font_Size#
FontColor=#Color_Scheme2#
AntiAlias=1
StringAlign=LeftCenter
X=10R
Y=r
