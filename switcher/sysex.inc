<%

Option Explicit

// Sysex ID
Const MANUF_ID_0	= &H00
Const MANUF_ID_1	= &H7f
Const MANUF_ID_2	= &H19 // MIDI switcher patch

	
Const PARAMH_PORTA = 1
Const PARAMH_PORTB = 2
Const PARAMH_PORTC = 3
Const PARAMH_PORTD = 4
Const PARAMH_PORTE = 5
Const PARAMH_PORTF = 6
Const PARAMH_PORTG = 7
Const PARAMH_PORTH = 8
Const PARAMH_PORT_DEFAULT = 100

Const PARAML_TRIG_NONE = 0
Const PARAML_TRIG_NOTE = 1
Const PARAML_TRIG_CC = 2
Const PARAML_TRIG_PGM = 3
Const PARAML_TRIG_ALWAYS = 4

Const PARAML_TRIG2_CHAN			= 10
Const PARAML_TRIG2_VALUE_MIN	= 11
Const PARAML_TRIG2_VALUE_MAX	= 12

Const PARAML_ENV_SET = 50
Const PARAML_ENV_TYPE = 51
Const PARAML_ENV_HOLD = 52
Const PARAML_GAMMA = 60
Const PARAML_VEL_MOD_DEST = 70
Const PARAML_CC_MOD_DEST = 71
Const PARAML_CC_MOD_CHAN = 72
Const PARAML_CC_MOD_CC = 73

Const PARAMH_PGM_CHAN 	= 20
Const PARAMH_PGM_SLOT1 	= 11
Const PARAMH_PGM_SLOT2 	= 12
Const PARAMH_PGM_SLOT3 	= 13
Const PARAMH_PGM_SLOT4 	= 14
Const PARAMH_PGM_SLOT5 	= 15
Const PARAMH_PGM_SLOT6 	= 16
Const PARAMH_PGM_SLOT7 	= 17
Const PARAMH_PGM_SLOT8 	= 18
Const PARAMH_PGM_SLOT9 	= 19
Const PARAMH_PGM_SLOT10	= 20
Const PARAMH_PGM_SLOT11	= 21
Const PARAMH_PGM_SLOT12	= 22
Const PARAMH_PGM_SLOT13 = 23
Const PARAMH_PGM_SLOT14 = 24
Const PARAMH_PGM_SLOT15 = 25
Const PARAMH_PGM_SLOT16 = 26

Const PARAML_PGM_MATCH	= 1
Const PARAML_PGM_PORT	= 2

Const ChangeDefaultTag = ".ovr"
Const EnvHoldTimeTag = ".hold"
Const EnvTypeTag = ".env"
Const GammaTag = ".gamma"
Const ModCCChanTag = ".mccch"
Const ModCCDestTag = ".mccdst"
Const ModCCTag = ".mcc"
Const ModVelDestTag = ".mvdst"
Const Out1Tag = ".o1"
Const Out2Tag = ".o2"
Const Out3Tag = ".o3"
Const Out4Tag = ".o4"
Const Out5Tag = ".o5"
Const Out6Tag = ".o6"
Const Out7Tag = ".o7"
Const Out8Tag = ".o8"
Const PgmChanTag = ".pgmch"
Const PgmTag = ".pgm"
Const TrigCCTag = ".tcc" 
Const TrigChanTag = ".tch"
Const TrigMaxValueTag = ".tvmax"
Const TrigMinValueTag = ".tvmin"
Const TrigNoteTag = ".tnote" 
Const TrigTypeTag = ".trig"

	
Dim dictMappings

' =================================================================
Function IIF(c,a,b) 
	If c Then 
		IIF = a
	Else 
		IIF = b
	End If
End Function

' =================================================================
Function ForceInt(s) 
	Dim v
	v = Request.Form(s)
	If IsNumeric(v) then 
		ForceInt = CLng(v)
	Else	
		If v= "" Then 
			ForceInt = 0
		Else 
			If v = "on" then 
				ForceInt = 1
			'else
			'	ForceInt = 0
			'	Response.write"{" & s & "=" & v & "}"
			end if
		end if 
	End If
End Function 

' =================================================================
Function WriteParam(a,b,c,d)
'	Response.Write a & ", " & b & ", " & c & ", " & d & "<br>"
	Response.BinaryWrite ChrB(a) & ChrB(b) & ChrB(c) & ChrB(d) 
End Function


' =================================================================
' DEFAULT
' =================================================================
Class Defaults

	Public Key
	Public TrigChan 
	Public PgmChan 
	Public EnvType
	Public EnvHoldTime
	Public ModVelDest
	Public ModCCDest
	Public ModCCChan
	Public ModCC
	Public Gamma

	
	'--------------------------
	Public Sub Class_Initialize
		Me.Key = ""	
		Me.TrigChan = 1
		Me.PgmChan = 1
		Me.EnvType = 0
		Me.EnvHoldTime = 0
		Me.ModVelDest = 0
		Me.ModCCDest = 0
		Me.ModCCChan = 0
		Me.ModCC = 1
		Me.Gamma = 0
		
	End Sub
	'--------------------------	
	Public Sub ReadForm
		Me.TrigChan = ForceInt(Me.Key & TrigChanTag)
		Me.PgmChan = ForceInt(Me.Key & PgmChanTag)
		Me.EnvType= ForceInt(Me.Key & EnvTypeTag)
		Me.EnvHoldTime = ForceInt(Me.Key & EnvHoldTimeTag)
		Me.ModVelDest = ForceInt(Me.Key & ModVelDestTag)
		Me.ModCCDest = ForceInt(Me.Key & ModCCDestTag)
		Me.ModCCChan = ForceInt(Me.Key & ModCCChanTag)
		Me.ModCC = ForceInt(Me.Key & ModCCTag)
		Me.Gamma  = ForceInt(Me.Key & GammaTag)
	End Sub	
	'--------------------------		
	Public Sub WriteSysex(id)
	
		WriteParam id, PARAML_TRIG2_CHAN, 0, Me.TrigChan
		WriteParam id, PARAMH_PGM_CHAN, 0, Me.PgmChan
		WriteParam id, PARAML_ENV_TYPE, 0, Me.EnvType
		WriteParam id, PARAML_ENV_HOLD, CInt(Me.EnvHoldTime/128), Me.EnvHoldTime Mod 128
		WriteParam id, PARAML_GAMMA, 0, Me.Gamma
		WriteParam id, PARAML_VEL_MOD_DEST, 0, Me.ModVelDest
		WriteParam id, PARAML_CC_MOD_DEST, 0, Me.ModCCDest
		WriteParam id, PARAML_CC_MOD_CHAN, 0, Me.ModCCChan
		WriteParam id, PARAML_CC_MOD_CC, 0, Me.ModCC
	End Sub
	'--------------------------
	Public Sub ReadSysex(p1, p2, v1, v2)
		select case p2				
			Case PARAML_TRIG2_CHAN
				Me.TrigChan = v2
			Case PARAMH_PGM_CHAN
				Me.PgmChan = v2
			Case PARAML_ENV_TYPE
				Me.EnvType = v2
			Case PARAML_ENV_HOLD 
				Me.EnvHoldTime = 128 * v1 + v2			
			Case PARAML_GAMMA
				Me.Gamma = v2
			Case PARAML_VEL_MOD_DEST
				Me.ModVelDest = v2
			Case PARAML_CC_MOD_DEST
				Me.ModCCDest = v2
			Case PARAML_CC_MOD_CHAN
				Me.ModCCChan = v2
			Case PARAML_CC_MOD_CC
				Me.ModCC = v2
		end select
	End Sub
End Class

' =================================================================
' SWITCH OUTPUT
' =================================================================
Class SwitchOutput

	Public Key
	Public TrigType 
	Public TrigChan 
	Public TrigNote 
	Public TrigCC 
	Public TrigMinValue
	Public TrigMaxValue
	Public EnvType
	Public EnvHoldTime
	Public ChangeDefault
	Public Gamma
	Public ModVelDest
	Public ModCCDest
	Public ModCCChan
	Public ModCC
	
	'--------------------------
	Public Sub Class_Initialize
		Me.Key = ""	
		Me.TrigType = PARAML_TRIG_NONE
		Me.TrigChan = 0
		Me.TrigNote = 36 
		Me.TrigCC = 1
		Me.TrigMinValue = 1
		Me.TrigMaxValue = 127
		Me.EnvType = 0
		Me.EnvHoldTime = 0		
		Me.ChangeDefault = 0
		Me.Gamma = 0
		Me.ModVelDest = 0
		Me.ModCCDest = 0
		Me.ModCCChan = 0
		Me.ModCC = 1
		
	End Sub
	'--------------------------	
	Public Sub ReadForm
		Me.TrigType = ForceInt(Me.Key & TrigTypeTag)
		Me.TrigChan = ForceInt(Me.Key & TrigChanTag)
		Me.TrigNote = ForceInt(Me.Key & TrigNoteTag)
		Me.TrigCC = ForceInt(Me.Key & TrigCCTag)
		Me.TrigMinValue = ForceInt(Me.Key & TrigMinValueTag)
		Me.TrigMaxValue = ForceInt(Me.Key & TrigMaxValueTag)
		Me.ChangeDefault = ForceInt(Me.Key & ChangeDefaultTag)
		Me.EnvType= ForceInt(Me.Key & EnvTypeTag)
		Me.EnvHoldTime = ForceInt(Me.Key & EnvHoldTimeTag)
		Me.Gamma  = ForceInt(Me.Key & GammaTag)
		Me.ModVelDest = ForceInt(Me.Key & ModVelDestTag)
		Me.ModCCDest = ForceInt(Me.Key & ModCCDestTag)
		Me.ModCCChan = ForceInt(Me.Key & ModCCChanTag)
		Me.ModCC = ForceInt(Me.Key & ModCCTag)		
	End Sub	
	'--------------------------		
	Public Sub WriteSysex(id)					
		If Me.TrigType = PARAML_TRIG_CC Or Me.TrigType = PARAML_TRIG_NOTE Then
			If Me.TrigType = PARAML_TRIG_CC Then
				WriteParam id, PARAML_TRIG_CC, 0, Me.TrigCC
			Else
				WriteParam id, PARAML_TRIG_NOTE, 0, Me.TrigNote
			End If
			WriteParam id, PARAML_TRIG2_CHAN, 0, Me.TrigChan
			WriteParam id, PARAML_TRIG2_VALUE_MIN, 0, Me.TrigMinValue
			WriteParam id, PARAML_TRIG2_VALUE_MAX, 0, Me.TrigMaxValue
		Else
			WriteParam id, Me.TrigType, 0, 0
		End If
		
		If Me.TrigType <> PARAML_TRIG_NONE Then		
			WriteParam id, PARAML_ENV_SET, 0, Me.ChangeDefault
			If Me.ChangeDefault Then
				WriteParam id, PARAML_ENV_TYPE, 0, Me.EnvType				
				WriteParam id, PARAML_ENV_HOLD, Int(Me.EnvHoldTime/128), Me.EnvHoldTime Mod 128
				WriteParam id, PARAML_GAMMA , 0, Me.Gamma				
				WriteParam id, PARAML_VEL_MOD_DEST , 0, Me.ModVelDest				
				WriteParam id, PARAML_CC_MOD_DEST , 0, Me.ModCCDest				
				WriteParam id, PARAML_CC_MOD_CHAN , 0, Me.ModCCChan				
				WriteParam id, PARAML_CC_MOD_CC  , 0, Me.ModCC				
			End If
		End If
	End Sub
	'--------------------------
	Public Sub ReadSysex(p1, p2, v1, v2)
		select case p2		
			Case PARAML_TRIG_NONE, PARAML_TRIG_PGM, PARAML_TRIG_ALWAYS
				Me.TrigType = p2
			Case PARAML_TRIG_NOTE
				Me.TrigType = p2
				Me.TrigNote = v2				
			Case PARAML_TRIG_CC
				Me.TrigType = p2
				Me.TrigCC = v2				
			Case PARAML_TRIG2_CHAN
				Me.TrigChan = v2
			Case PARAML_TRIG2_VALUE_MIN
				Me.TrigMinValue = v2
				Me.TrigMaxValue = v2
			Case PARAML_TRIG2_VALUE_MAX	
				Me.TrigMaxValue = v2				
			Case PARAML_ENV_SET
				Me.ChangeDefault = v2				
			Case PARAML_ENV_TYPE
				Me.EnvType = v2
			Case PARAML_ENV_HOLD
				Me.EnvHoldTime = 128 * v1 + v2
			Case PARAML_GAMMA
				Me.Gamma = v2
			Case PARAML_VEL_MOD_DEST
				Me.ModVelDest = v2
			Case PARAML_CC_MOD_DEST
				Me.ModCCDest = v2
			Case PARAML_CC_MOD_CHAN
				Me.ModCCChan = v2
			Case PARAML_CC_MOD_CC
				Me.ModCC = v2
		end select
	End Sub
End Class

' =================================================================
' PROGRAM CHANGE
' =================================================================
Class ProgramChange

	Public Key
	Public TrigChan
	Public PGM 
	Public Out1
	Public Out2
	Public Out3
	Public Out4
	Public Out5
	Public Out6
	Public Out7
	Public Out8

	
	'--------------------------
	Public Sub Class_Initialize
		Me.Key = ""	
		Me.PGM = -1
		Me.Out1 = 0
		Me.Out2 = 0
		Me.Out3 = 0
		Me.Out4 = 0
		Me.Out5 = 0
		Me.Out6 = 0
		Me.Out7 = 0
		Me.Out8 = 0 
	End Sub
	'--------------------------	
	Public Sub ReadForm
		If Request.Form(Me.Key & PgmTag) = "-1" Then 
			Me.PGM = -1
		Else
			Me.PGM =ForceInt(Me.Key & PgmTag)
		End If
		Me.Out1 = IIF((Request.Form(Me.Key & Out1Tag)= "on"),1,0)
		Me.Out2 = IIF((Request.Form(Me.Key & Out2Tag)= "on"),1,0)
		Me.Out3 = IIF((Request.Form(Me.Key & Out3Tag)= "on"),1,0)
		Me.Out4 = IIF((Request.Form(Me.Key & Out4Tag)= "on"),1,0)
		Me.Out5 = IIF((Request.Form(Me.Key & Out5Tag)= "on"),1,0)
		Me.Out6 = IIF((Request.Form(Me.Key & Out6Tag)= "on"),1,0)
		Me.Out7= IIF((Request.Form(Me.Key & Out7Tag)= "on"),1,0)
		Me.Out8 = IIF((Request.Form(Me.Key & Out8Tag)= "on"),1,0)
	End Sub	
	'--------------------------		
	Public Sub WriteSysex(id)
		If Me.PGM = -1 Then 
			WriteParam id, PARAML_PGM_MATCH, 0, 0
			WriteParam id, PARAML_PGM_PORT, 1, 0
			WriteParam id, PARAML_PGM_PORT, 2, 0
			WriteParam id, PARAML_PGM_PORT, 3, 0
			WriteParam id, PARAML_PGM_PORT, 4, 0
			WriteParam id, PARAML_PGM_PORT, 5, 0
			WriteParam id, PARAML_PGM_PORT, 6, 0
			WriteParam id, PARAML_PGM_PORT, 7, 0
			WriteParam id, PARAML_PGM_PORT, 8, 0
		Else 
			WriteParam id, PARAML_PGM_MATCH, 1, Me.PGM
			WriteParam id, PARAML_PGM_PORT, 1, Me.Out1
			WriteParam id, PARAML_PGM_PORT, 2, Me.Out2
			WriteParam id, PARAML_PGM_PORT, 3, Me.Out3
			WriteParam id, PARAML_PGM_PORT, 4, Me.Out4
			WriteParam id, PARAML_PGM_PORT, 5, Me.Out5
			WriteParam id, PARAML_PGM_PORT, 6, Me.Out6
			WriteParam id, PARAML_PGM_PORT, 7, Me.Out7
			WriteParam id, PARAML_PGM_PORT, 8, Me.Out8
		End If
	End Sub
	'--------------------------
	Public Sub ReadSysex(p1, p2, v1, v2)
		select case p2		
			Case PARAML_PGM_MATCH
				If v1 = 1 then 
					Me.PGM = v2
				Else
					Me.PGM = -1
				End If
			Case PARAML_PGM_PORT
				Select Case v1
					Case 1
						Me.Out1 = v2
					Case 2
						Me.Out2 = v2
					Case 3
						Me.Out3 = v2
					Case 4
						Me.Out4 = v2
					Case 5
						Me.Out5 = v2
					Case 6
						Me.Out6 = v2
					Case 7
						Me.Out7 = v2
					Case 8
						Me.Out8 = v2
				End Select
		end select
	End Sub
End Class

Function InitMappings
	Dim o, i	
	Set dictMappings = Server.CreateObject("Scripting.Dictionary")

	Set o = New Defaults
	o.Key = "def"
	dictMappings.Add PARAMH_PORT_DEFAULT, o
	
	For i = 1 to 8
		Set o = New SwitchOutput
		o.Key = "out" & i
		o.TrigNote = 35+i
		dictMappings.Add i, o
	Next

	For i = 0 to 15
		Set o = New ProgramChange
		o.Key = "pc" & i
		dictMappings.Add 10+i, o
	Next
End Function

Function ReadForm
	Dim o
	For each o in dictMappings.Items
		o.ReadForm
	Next
End Function

Function WriteSysex
	Dim arrKeys, arrItems, i, o
	arrKeys = dictMappings.Keys
	arrItems = dictMappings.Items
	response.binarywrite chrb(&HF0) 
	response.binarywrite chrb(MANUF_ID_0) 
	response.binarywrite chrb(MANUF_ID_1) 
	response.binarywrite chrb(MANUF_ID_2) 		
	For i = 0 to UBound(arrKeys)
		Set o = arrItems(i)
		o.WriteSysex(arrKeys(i))
	Next
	response.binarywrite chrb(&HF7) 
End Function

function ReadSysEx
	Dim data, index, i
	ReadSysEx = false
	data = request.BinaryRead(request.TotalBytes)
	
	index = 0
	for i=1 to lenb(data) - 4
		if midb(data,i,4) = (chrb(13) & chrb(10) & chrb(13) & chrb(10)) then
			index = i + 4
			exit for
		end if
	next	
	if index = 0 then
		exit function 
	end if
    if (midb(data,index,4) <> (ChrB(&HF0) & ChrB(MANUF_ID_0) & ChrB(MANUF_ID_1) & ChrB(&H12))) and _   
		(midb(data,index,4) <> (ChrB(&HF0) & ChrB(MANUF_ID_0) & ChrB(MANUF_ID_1) & ChrB(MANUF_ID_2))) then
		exit function 
	end if
	index = index + 4
	
	do while index <= lenb(data) 
		if midb(data,index,1) = chrb(&hF7) then exit do
		if index + 4 >= lenb(data) then exit function
		Set o = dictMappings(ascb(midb(data,index,1)))
		o.ReadSysex _
			ascb(midb(data,index,1)), _
			ascb(midb(data,index+1,1)), _
			ascb(midb(data,index+2,1)), _
			ascb(midb(data,index+3,1))
		index = index + 4		
	loop
	ReadSysEx = true
end function
%>