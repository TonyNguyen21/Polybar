[Variables]
Discord_X=1305

[Metadata]
Name=Papirus\\Discord
Author=reddit.com/u/khanhas
Description=Click to show Discord status and control

[DiscordShape]
Meter=Shape
X=#Discord_X#
Y=(#Bar_OffsetY#+#Bar_Height#/2-#Section_Height#/2)
Shape=Rectangle 0,0,(#Section_Height#),(#Section_Height#),5 | StrokeWidth 0 | Extend Color
Shape2=Rectangle ([Discord_UnreadCountBadge:X]-#Discord_X#-3),-2,([Discord_UnreadCountBadge:W]+6*sgn([Discord_UnreadCountBadge:W])),([Discord_UnreadCountBadge:H]+2*sgn([Discord_UnreadCountBadge:W])),2 | StrokeWidth 0 | Fill Color #Color_Scheme4#
Color = Fill Color #Color_Scheme1#
DynamicVariables=1
MouseOverAction=[!WriteKeyValue Variables "Curr_X" "[DiscordXPos]" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\DiscordStatus.ini"][!WriteKeyValue Variables "Curr_Y" "[SubSkinYPositionCalc]" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\DiscordStatus.ini"][!WriteKeyValue Variables "Dir" "[SubSkinDirectionCalc]" "#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\DiscordStatus.ini"][!ActivateConfig "#ROOTCONFIG#\Themes\#Theme#\Additional_Comps_And_Scripts" "DiscordStatus.ini"][!CommandMeasure AdditionalSkinActionTimer "Stop 1"]
MouseLeaveAction=[!CommandMeasure AdditionalSkinActionTimer "Execute 1"]
LeftMouseUpAction=["discord://"]

[Discord_UnreadCountBadge]
Meter=String
MeasureName=DiscordNotice
FontFace=#Font_Face2#
FontSize=10
FontColor=#Color_Scheme2#
X=(#Discord_X#+#Section_Height#)
StringAlign=Center
Y=-2r
AntiAlias=1
DynamicVariables=1

[DiscordIcon]
Meter=Image
ImageName=#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\Discord.png
W=(#Font_Size#*20/14)
X=(#Discord_X#+#Section_Height#/2-[DiscordIcon:W]/2)
Y=(#Bar_OffsetY#+#Bar_Height#/2-[DiscordIcon:H]/2)
SolidColor=0,0,0,1
DynamicVariables=1
AntiAlias=1

[DiscordScript]
Measure=Script
ScriptFile=#ROOTCONFIGPATH#Themes\#Theme#\Additional_Comps_And_Scripts\script_Discord.lua
JSONFile = %appdata%\BetterDiscord\plugins\DiscordForRainmeter.config.json

[DiscordNotice]
Measure=Calc
Formula=[DiscordScript:GetNotification(true,true,true)]
IfCondition=DiscordNotice > 0 
IfTrueAction=[!SetOption DiscordShape Color "Fill Color #Color_Scheme3#"][!ShowMeter Discord_UnreadCountBadge]
IfFalseAction=[!SetOption DiscordShape Color "Fill Color #Color_Scheme1#"][!HideMeter Discord_UnreadCountBadge]
DynamicVariables=1

[DiscordXPos]
Measure=Calc
Formula=#CURRENTCONFIGX#+[DiscordIcon:X]+[DiscordIcon:W]/2
DynamicVariables=1
