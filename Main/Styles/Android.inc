[Variables]
GW=(450*#scale#)
GH=(170*#scale#)
P=(22*#Scale#)

Shuffle=0
Control=1
Repeat=0
Heart=0
Prog=0
;==============================================================================================
;==============================================================================================
;==============================================================================================

[MainC]
Measure=Plugin
Plugin=Chameleon
Type=File
Path=[mCover]
Format=Dec
UpdateDivider=1

[DC1]
Measure=Plugin
Plugin=Chameleon
Parent=MainC
Color=Dark2
UpdateDivider=1
OnChangeAction=[!UpdateMeter B]


;==============================================================================================
;==============================================================================================
;==============================================================================================

[B]
Meter=Shape
Shape=Rectangle 0,0,#GW#,#GH#,#R#,#R# | StrokeWidth 0 | Fill Color [DC1]
DynamicVariables=1

[Shadow]
Meter=Shape
X=#P#
Y=#P#
Shape=Rectangle 0,0,(#GH#-#P#*2),(#GH#-#P#*2),(#R#/2),(#R#/2) | Fill Color 0,0,0,1 | StrokeWidth 5 | StrokeColor 0,0,0,50

[IC]
Meter=Shape
X=#P#
Y=#P#
Shape=Rectangle 0,0,(#GH#-#P#*2),(#GH#-#P#*2),(#R#/2),(#R#/2) | StrokeWidth 0

[I]
Meter=Image
ImageName=[mCover]
W=(#GH#-#P#*2)
H=(#GH#-#P#*2)
PreserveAspectRatio=2
Container=IC
DynamicVariables=1

[SName]
Meter=String
MeterStyle=S
X=#P#R
Y=((#GH#-#P#*2)/2-30/2)r
W=(#GW#-(#P#*2+(#GH#-#P#*2)))
ClipString=2
StringAlign=LeftCenter
FontWeight=600
Text=%1#CRLF#%2
FontSize=(15*#scale#)
FontColor=255,255,255
InLinePattern=#CRLF#(.*)
InlineSetting=Size | (10*#scale#)
InLinePattern2=#CRLF#(.*)
InlineSetting2=Weight | 450
InLinePattern3=#CRLF#(.*)
InlineSetting3=Color | 255,255,255,150
DynamicVariables=1
MeasureName=mTrack
MeasureName2=mArtist

[Previous]
Meter=Image
ImageName=#@#Icons\Previous.png
X=r
Y=(#GH#-30*#scale#-#P#)
W=(20*#scale#)
H=(20*#scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
ImageTint=[FGC2]
DynamicVariables=1
Group=DynamicColors
LeftMouseUpAction=[!CommandMeasure mState "Previous"]


[PlayPause]
Meter=Image
MeterStyle=
X=(20*#Scale#)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
ImageTint=[FGC2]
DynamicVariables=1
Group=DynamicColors
[Play]
ImageName=#@#Icons\Play.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Pause][!UpdateMeter PlayPause][!Redraw][!CommandMeasure mState "PlayPause"]
[Pause]
ImageName=#@#Icons\Pause.png
LeftMouseUpAction=[!SetOption PlayPause MeterStyle Play][!UpdateMeter PlayPause][!Redraw][!CommandMeasure mState "PlayPause"]

[Next]
Meter=Image
ImageName=#@#Icons\Next.png
X=(20*#Scale#)R
Y=r
W=(20*#scale#)
H=(20*#scale#)
Padding=(5*#scale#),(5*#scale#),(5*#scale#),(5*#scale#)
Grayscale=1
ImageTint=[FGC2]
DynamicVariables=1
Group=DynamicColors
LeftMouseUpAction=[!CommandMeasure mState "Next"]